from joblib import dump, load
import numpy as np
import os 
from ortools.linear_solver import pywraplp



def min_max_optimizer(costs, num_workers, print_solution = False, timeout = True):
	solver = pywraplp.Solver.CreateSolver('SCIP')
	num_tasks = len(costs)

	if timeout == True:
		solver.SetTimeLimit(60*1000)
	
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
def L1_Buffer_Compute(model):
	dma_tree_burst_size = []
	n_estimators = model.n_estimators
	nodes = np.zeros(n_estimators)

	# Compute tree nodes and dma tree burst sizes
	for i in range(1,n_estimators + 1):
		nodes[i - 1] = model.estimators_[i - 1].tree_.node_count
		if (n_estimators % i == 0):
			dma_tree_burst_size.append(i)

	sorted_nodes = sorted(nodes, reverse = True)

	# Max
	l1_buffer_max = np.zeros(len(dma_tree_burst_size))
	max_nodes = sorted_nodes[0]

	for i in range(0,len(dma_tree_burst_size)):
		l1_buffer_max[i] = max_nodes * dma_tree_burst_size[i]

	print(l1_buffer_max)

	# Static
	l1_buffer_static = np.zeros(len(dma_tree_burst_size))

	for i in range(0,len(dma_tree_burst_size)):
		for j in range(0,dma_tree_burst_size[i]):
			l1_buffer_static[i] += sorted_nodes[j]

	print(l1_buffer_static)

	# Dynamic
	l1_buffer_dynamic = np.zeros(len(dma_tree_burst_size))

	for i in range(0,len(dma_tree_burst_size)):
		__dma_tree_burst_size = dma_tree_burst_size[i] 
		for j in range(0,n_estimators,__dma_tree_burst_size):
			__tmp = 0
			for k in range(0,__dma_tree_burst_size):
				__tmp += nodes[j + k]
			if (__tmp > l1_buffer_dynamic[i]):
				l1_buffer_dynamic[i] = __tmp

	print(l1_buffer_dynamic)

	# Optimizing the minimum
	l1_buffer_reordering = np.zeros(len(dma_tree_burst_size))

	for i in range(0,len(dma_tree_burst_size)):
		__, __, l1_buffer_reordering[i] = min_max_optimizer(nodes, num_workers = (int)(n_estimators/dma_tree_burst_size[i]))

	print(l1_buffer_reordering)

	return l1_buffer_static, l1_buffer_dynamic, l1_buffer_reordering