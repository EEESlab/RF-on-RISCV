from joblib import dump, load
import numpy as np
import os 
from ortools.linear_solver import pywraplp
from ortools.sat.python import cp_model

from utils_graph import rfNodeCount, RF_decision_path
from utils_dataset import dataset_selection
from utils_dump import feature_dtype
from utils_dump import threshold_dtype
from utils_dump import children_dtype

def min_max_optimizer(costs, num_workers, print_solution = False, timeout = True):
	solver = pywraplp.Solver.CreateSolver('SCIP')
	num_tasks = len(costs)

	if timeout == True:
		solver.SetTimeLimit(10*60*1000)
	
	# Variables
	x = {}
	
	for i in range(num_workers):
		for j in range(num_tasks):
			x[i, j] = solver.IntVar(0, 1, '')

	# Constraint: each task is assigned to only one worker.
	for j in range(num_tasks):
		solver.Add(solver.Sum([x[i,j] for i in range(num_workers)]) == 1)

	# Objective
	M = solver.IntVar(0, sum(costs[i] for i in range(num_tasks)), '')

	for i in range(num_workers):
		acc = 0
		for j in range(num_tasks):
			acc += costs[j] * x[i,j]
		solver.Add(acc <= M)

	solver.Minimize(M)

	# Solve
	status = solver.Solve()

	# Print solution.
	if print_solution == True:
		if status == pywraplp.Solver.OPTIMAL:
			print('Total cost = ', solver.Objective().Value(), '\n')
			print()
			for i in range(num_workers):
				for j in range(num_tasks):
					if x[i, j].solution_value() > 0.5:
						print('Worker ', i, ' assigned to task ', j, '  Cost = ',
							  costs[j])
		else:
			print('No optimal solution found.')

	opt_tree_scheduling = []
	cost_per_core = []
	if status == pywraplp.Solver.OPTIMAL:
		for i in range(num_workers):
			cost = 0
			for j in range(num_tasks):
				if x[i, j].solution_value() > 0.5:
					cost += costs[j]
					opt_tree_scheduling.append(j)
			cost_per_core.append(cost)
	else:
		print('No optimal solution found.')

	total_cost = solver.Objective().Value()

	return cost_per_core, opt_tree_scheduling, total_cost



# Compute L1 buffer size for double-buffering using 3 approaches: max, static, dynamic, and reordering.
def opt_l1_buffer(model):
	dma_transfer_size = []
	n_dt = model.n_estimators
	nodes = np.zeros(n_dt)

	# Compute tree nodes and dma transfers size
	for i in range(1,n_dt + 1):
		nodes[i - 1] = model.estimators_[i - 1].tree_.node_count
		if (n_dt % i == 0):
			dma_transfer_size.append(i)

	sorted_nodes = sorted(nodes, reverse = True)

	# Max
	l1_buffer_max = np.zeros(len(dma_transfer_size))
	max_nodes = sorted_nodes[0]

	for i in range(0,len(dma_transfer_size)):
		l1_buffer_max[i] = max_nodes * dma_transfer_size[i]

	print("Max Approach\n\n",l1_buffer_max)

	# Static
	l1_buffer_static = np.zeros(len(dma_transfer_size))

	for i in range(0,len(dma_transfer_size)):
		for j in range(0,dma_transfer_size[i]):
			l1_buffer_static[i] += sorted_nodes[j]

	print("\nStatic Approach\n\n",l1_buffer_static)

	# Dynamic
	l1_buffer_dynamic = np.zeros(len(dma_transfer_size))

	for i in range(0,len(dma_transfer_size)):
		for j in range(0,n_dt,dma_transfer_size[i]):
			tmp = 0
			for k in range(0,dma_transfer_size[i]):
				tmp += nodes[j + k]
			if (tmp > l1_buffer_dynamic[i]):
				l1_buffer_dynamic[i] = tmp

	print("\nDynamic Approach\n\n",l1_buffer_dynamic)

	# Reordering: Optimizing the minimum
	l1_buffer_reordering = np.zeros(len(dma_transfer_size))

	for i in range(0,len(dma_transfer_size)):
		__, __, l1_buffer_reordering[i] = min_max_optimizer(nodes, num_workers = (int)(n_dt/dma_transfer_size[i]))

	print("\nOR-Tools Approach\n\n",l1_buffer_reordering)

	return l1_buffer_static, l1_buffer_dynamic, l1_buffer_reordering



def dma_tranfer_params(model, node_bytes, mem_size = 25000):
	n_dt = model.n_estimators
	trees_dma_transfer = []
	dma_calls = []

	for i in range(1, n_dt + 1):
		if n_dt % i == 0:
			trees_dma_transfer.append(i)
			dma_calls.append(n_dt/i)

	n_dma_transfers = len(trees_dma_transfer)
	nodes = rfNodeCount(model)
	bytes_dma_transfer = []

	for i in range(0, n_dma_transfers):
		__bytes_dma_transfer = []
		for j in range(0, n_dt, trees_dma_transfer[i]):
			__burst_bytes = 0
		
			for k in range(0, trees_dma_transfer[i]):
				__burst_bytes += nodes[k + j] * node_bytes  

			__bytes_dma_transfer.append(__burst_bytes)

		if max(__bytes_dma_transfer) > mem_size:
			break
		else:
			bytes_dma_transfer.append(__bytes_dma_transfer)
	
	for i in range(0, n_dma_transfers - len(bytes_dma_transfer)):
		dma_calls.pop()
		trees_dma_transfer.pop()

	n_dma_transfers = len(bytes_dma_transfer)

	return dma_calls, n_dma_transfers, trees_dma_transfer, bytes_dma_transfer



def opt_dma_transfer(exploration, dma_bw = 8, dma_oh_cyc = 51):
	model_dir   = 'trained-models/%s'%(exploration)
	n_models 	= len(os.listdir(model_dir))
	dataset = n_models * [None]
	model = n_models * [None]
	n_test = 10

	for i in range(0, n_models):
		model_name = os.listdir("trained-models/%s"%(exploration))[i]
		dataset[i] = model_name.split('-',2)[-1].split('.')[0]
		model[i] = load(str(model_dir)+'/'+str(model_name))

		__, x_test, __, __, __, __ = dataset_selection(dataset[i], scaler = True)
		__, __, __, f_bytes = feature_dtype(model[i])
		__, __, __, thr_bytes = threshold_dtype(model[i])
		__, __, child_bytes = children_dtype(model[i])
		node_bytes = f_bytes + thr_bytes + 2 * child_bytes

		__x_test = x_test[(int)(x_test.shape[0] - n_test):(int)(x_test.shape[0])].tolist()
		decisions, __, __ = RF_decision_path(model[i], np.array(__x_test))

		dma_calls, n_dma_transfers, trees_dma_transfer, bytes_dma_transfer = dma_tranfer_params(model[i], node_bytes)
		dma_cyc = []
		compute_cyc = []

		for j in range(0, n_dma_transfers):

			trans = trees_dma_transfer[j]
			calls = dma_calls[j]

			instr = calls * (39 + 4 * trans +  26 * (trans - 1)) + 15 * decisions
			ld = calls * (13 + 3 * trans +  4 * (trans - 1)) + 5 * decisions
			br = calls * (2 + 1 * (trans - 1)) + 1 * decisions
			ext_ld = calls
			mis_stall_ld = 0.42253 * ld

			compute_cyc.append(round(instr + mis_stall_ld + 3 * br + 15 * ext_ld))

			__dma_cyc = 0
			bytes_transfer = bytes_dma_transfer[j]

			for k in range(0,int(calls)):
				__dma_cyc += bytes_transfer[k] / dma_bw

			dma_cyc.append(round(__dma_cyc + dma_oh_cyc * calls))

		cyc_dist = [round(abs(a - b)) for a, b in zip(dma_cyc, compute_cyc)]

		opt_trees_dma_transfer = trees_dma_transfer[np.argmin(cyc_dist)]
		opt_dma_cyc = dma_cyc[np.argmin(cyc_dist)]
		opt_compute_cyc = compute_cyc[np.argmin(cyc_dist)]
	
	return dma_cyc, compute_cyc, cyc_dist, opt_trees_dma_transfer, opt_dma_cyc, opt_compute_cyc
