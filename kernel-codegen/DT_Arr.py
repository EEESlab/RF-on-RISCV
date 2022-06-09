from sklearn.metrics import accuracy_score
from joblib import dump, load
import numpy as np
import os 

from dataset_utils import dataset_selection
from data_utils import dump_params, dump_test_data
from graph_utils import rfNodeCount, modelMaxNodes, modelFeatures



uint_dtype = ['uint8_t','uint16_t','uint32_t']
int_dtype = ['int8_t','int16_t','int32_t']
int_bytewidth = [1, 2, 4]



def determine_model_memory(model, f_bytewidth, thr_bytewidth, child_bytewidth):
	n_estimators = model.n_estimators
	treeNodes = rfNodeCount(model)
	nodeBytes = f_bytewidth + thr_bytewidth + child_bytewidth * 2
	treeMem = treeNodes * nodeBytes * 0.001
	pointerMem = n_estimators * nodeBytes * 0.001
	modelMem = np.sum(treeMem) + pointerMem
	return treeMem, pointerMem, modelMem 



def determine_model_dtype(model):
	max_nodes = int(np.amax(rfNodeCount(model)))
	node_bits = max_nodes.bit_length()

	if (0 < node_bits <= 8):
		node_dtype = 'uint8_t'
		node_bytewidth = 1
	elif (8 < node_bits <= 16):
		node_dtype = 'uint16_t'
		node_bytewidth = 2
	elif (16 < node_bits):
		node_dtype = 'uint32_t'
		node_bytewidth = 4

	thr_dtype = 'float'
	thr_bytewidth = 4
	thr_bits = 32

	return node_dtype, node_bits, node_bytewidth, thr_dtype, thr_bits, thr_bytewidth



def check_params(model, f_const, f_bytewidth, f_dtype, child_const, child_bytewidth, child_dtype):
	# f: features
	f = modelFeatures(model)
	max_nodes = modelMaxNodes(model)

	__max_nodes = max_nodes * child_const
	__f = f * f_const

	if (__f > ((2**((f_bytewidth*8) - 1)) - 1)): 
		for i in range(0,len(int_bytewidth)):
			if f_bytewidth == int_bytewidth[i]:
				f_bytewidth = int_bytewidth[i + 1]
				f_dtype = uint_dtype[i + 1]
				break

	if (__max_nodes > ((2**(child_bytewidth*8)) - 1)): 
		for i in range(0,len(int_bytewidth)):
			if child_bytewidth == int_bytewidth[i]:
				child_bytewidth = int_bytewidth[i + 1]
				child_dtype = uint_dtype[i + 1]
				break

	return f_bytewidth, f_dtype, child_bytewidth, child_dtype



def determine_model_const(in_bytewidth, f_bytewidth, thr_bytewidth, child_bytewidth):
	# f: features, in: input, thr: thresholds
	f_const = in_bytewidth
	f2in = 1 
	f2in_op = 'mul'

	child_const = child_bytewidth * 2
	child2node = 1
	child2in_op = 'mul'

	right_offset = child_bytewidth
	output_rs = child_bytewidth * 8

	thr_const = 1
	thr2node = int(thr_bytewidth/child_const)
	thr2node_op = 'mul'

	if (f_bytewidth < child_const):
		f2node_op = 'div'
		f2node = int(child_const/f_bytewidth)
	else:
		f2node_op = 'mul'
		f2node = int(f_bytewidth/child_const)

	return (f_const, f2in, f2in_op), (child_const, child2node, child2in_op), (thr_const, thr2node, thr2node_op), (f2node, f2node_op), right_offset, output_rs



def determine_model_params(model, dataset, f, __in):
	# f: features, __in: input, thr: thresholds
	n = len(dataset)
	f_bytewidth = f[0]
	f_dtype = f[1]
	in_bytewidth = __in[0]
	in_dtype = __in[1]

	thr_bytewidth = np.zeros(n, dtype = int)
	thr_dtype = [None] * n
	child_bytewidth = np.zeros(n, dtype = int)
	child_dtype = [None] * n

	f_const = np.zeros(n, dtype = int)
	f2in = np.zeros(n, dtype = int)
	f2in_op = [None] * n
	child_const = np.zeros(n, dtype = int)
	child2node = np.zeros(n, dtype = int)
	child2node_op = [None] * n
	thr_const = np.zeros(n, dtype = int)
	thr2node = np.zeros(n, dtype = int)
	thr2node_op = [None] * n
	f2node = np.zeros(n, dtype = int)
	f2node_op = [None] * n
	right_offset = np.zeros(n, dtype = int)
	output_rs = np.zeros(n, dtype = int)
	
	for i in range(0,n):
		__model = model[i]
		child_dtype[i], __, child_bytewidth[i], thr_dtype[i], __, thr_bytewidth[i] = determine_model_dtype(__model)

		(f_const[i], f2in[i], f2in_op[i]), (child_const[i], child2node[i], child2node_op[i]), \
			(thr_const[i], thr2node[i], thr2node_op[i]), (f2node[i], f2node_op[i]), \
			right_offset[i], output_rs[i] = determine_model_const(in_bytewidth[i], f_bytewidth[i], thr_bytewidth[i], child_bytewidth[i])

		f_bytewidth[i], f_dtype[i], child_bytewidth[i], child_dtype[i] = \
			check_params(__model, f_const[i], f_bytewidth[i], f_dtype[i], child_const[i], child_bytewidth[i], child_dtype[i])

		(f_const[i], f2in[i], f2in_op[i]), (child_const[i], child2node[i], child2node_op[i]), \
			(thr_const[i], thr2node[i], thr2node_op[i]), (f2node[i], f2node_op[i]), \
			right_offset[i], output_rs[i] = determine_model_const(in_bytewidth[i], f_bytewidth[i], thr_bytewidth[i], child_bytewidth[i])

	f_params = [f_const, f2in, f2in_op, f2node, f2node_op]
	thr_params = [thr_const, thr2node, thr2node_op]
	child_params = [child_const, child2node, child2node_op]
	oths_params = [right_offset, output_rs]

	__in = [in_bytewidth, in_dtype]
	f = [f_bytewidth, f_dtype]
	thr = [thr_bytewidth,  thr_dtype]
	child = [child_bytewidth,  child_dtype]

	return f_params, thr_params, child_params, oths_params, __in, f, thr, child



def dump_DT_Arr_kernel(model, n_classes, dataset, f, __in, file):
	n = len(dataset)
	f_bytewidth = f[0]
	f_dtype = f[1]
	in_bytewidth = __in[0]
	in_dtype = __in[1]
	
	f_params, thr_params, child_params, oths_params, __in, f, thr, child = \
		determine_model_params(model = model, dataset = dataset,f =f, __in = __in)

	f_const = f_params[0]
	f2in = f_params[1]
	f2in_op = f_params[2]
	f2node = f_params[3]
	f2node_op = f_params[4]
	thr_const = thr_params[0]
	thr2node = thr_params[1]
	thr2node_op = thr_params[2]
	child_const = child_params[0]
	child2node = child_params[1]
	child2node_op = child_params[2]

	right_offset = oths_params[0]
	output_rs = oths_params[1]
	in_bytewidth = __in[0]
	in_dtype = __in[1]
	f_bytewidth = f[0] 
	f_dtype = f[1] 
	thr_bytewidth = thr[0]  
	thr_dtype = thr[1] 
	child_bytewidth = child[0]  
	child_dtype = child[1]

	fileC = file[0]
	fileH = file[1]

	# Dump source code
	print("#include \"pmsis.h\"", file = fileC)
	print("#include \"params.h\"", file = fileC)
	print("#include \"dt-arr.h\"\n\n", file = fileC)
	
	# Dump header code
	print("#ifndef __DT_ARR_H__", 	 file = fileH)
	print("#define __DT_ARR_H__\n\n", 	 file = fileH)

	for k in range(0,n):

		__model = model[k]
		__dataset = dataset[k]
		__classes = int(n_classes[k])
		n_estimators = __model.n_estimators

		treeMem, pointerMem, modelMem = determine_model_memory(__model, f_bytewidth[k], thr_bytewidth[k], child_bytewidth[k])

		# Dump header code
		print("#ifdef ",__dataset.upper().replace("-","_"), 			file = fileH)
		print("\n/* %s Dataset */"%__dataset.upper(), file = fileH)
		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(modelMem), file = fileH)
		
		for j in range(0,n_estimators):
			estimator = __model.estimators_[j]
			n_nodes = estimator.tree_.node_count
			print("#define NODES_TREE_%d 	(%d)"%(j,n_nodes), file = fileH)

		print("\n#define INPUT_DATATYPE %s"%in_dtype[k],	file = fileH)
		print("#define FEATURES_DATATYPE %s"%f_dtype[k],	file = fileH)
		print("#define THRESHOLD_DATATYPE %s"%thr_dtype[k],	file = fileH)
		print("#define CHILDREN_DATATYPE %s"%child_dtype[k],	file = fileH)

		print("\n#define FEAT2INPUT (%d) /* %s Op */"%(f2in[k],f2in_op[k]),	file = fileH)
		print("#define CHILD2NODE (%d) /* %s Op */"%(child2node[k],child2node_op[k]),	file = fileH)
		print("#define THRESH2NODE (%d) /* %s Op */"%(thr2node[k],thr2node_op[k]),	file = fileH)
		print("#define FEAT2NODE (%d) /* %s Op */"%(f2node[k],f2node_op[k]),	file = fileH)
		print("#define RIGHT_OFFSET (%d)"%(right_offset[k]),	file = fileH)
		print("#define OUTPUT_RS (%d)"%(output_rs[k]),	file = fileH)

		for j in range(0,n_estimators):
			print("\n/*    TREE %d    */"%j,	file = fileH)
			print("/* L1 Memory Requirements = %.2fkB */\n"%(treeMem[j]), file = fileH)
	
			estimator = __model.estimators_[j]
			n_nodes = estimator.tree_.node_count
	
			print("%s features_tree%d[NODES_TREE_%d];"%(f_dtype[k],j,j), file = fileH);
			print("%s threshold_tree%d[NODES_TREE_%d];"%(thr_dtype[k],j,j), file = fileH);
			print("%s children_tree%d[NODES_TREE_%d*2];"%(child_dtype[k],j,j), file = fileH);

		print("\n/* L1 Memory Requirements = %.2fkB */"%(pointerMem),file = fileH)
		print("%s *features[N_TREES];"%(f_dtype[k]), file = fileH)
		print("%s *threshold[N_TREES];"%(thr_dtype[k]), file = fileH)
		print("%s *children[N_TREES];"%(child_dtype[k]), file = fileH)

		print("\n#endif\n\n",file = fileH)

		# Dump source code
		print("#ifdef ",__dataset.upper().replace("-","_"), file = fileC)
		print("\n/* %s Dataset */"%__dataset.upper(), file = fileC)

		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(modelMem), file = fileC)
	
		for j in range(0,n_estimators):
			print("/*    TREE %d    */"%j,	file = fileC)
			print("/* L1 Memory Requirements = %.2fkB */\n"%(treeMem[j]), file = fileC)
	
			estimator = __model.estimators_[j]
			n_nodes = estimator.tree_.node_count
			children_left = estimator.tree_.children_left
			children_right = estimator.tree_.children_right
			feature = estimator.tree_.feature
			threshold = estimator.tree_.threshold
			value = np.reshape(estimator.tree_.value,(-1,__classes))

			classes = []
			for i in range(0,max(np.shape(value))):
				classes.append(value[i].argmax())
	
			print("PI_CL_L1 %s features_tree%d[NODES_TREE_%d] = { "%(f_dtype[k],j,j), end = '', file = fileC);
			for i in range(0, n_nodes):
				print("%d, "%(feature[i] * f_const[k]),  end = '', file = fileC)
			print("};", file = fileC)
	
			print("PI_CL_L1 %s threshold_tree%d[NODES_TREE_%d] = { "%(thr_dtype[k],j,j), end = '', file = fileC);
			for i in range(0, n_nodes):
				print("%f, "%(threshold[i] * thr_const[k]),  end = '', file = fileC)
			print("};", file = fileC)

			print("PI_CL_L1 %s children_tree%d[NODES_TREE_%d*2] = { "%(child_dtype[k],j,j), end = '', file = fileC);
			for i in range(0, n_nodes):			
				if (children_left[i] == -1):
					print("%d, "%(classes[i]), end = '',file = fileC)
				else:
					print("%d, "%(children_left[i] * child_const[k]),  end = '', file = fileC)
				if (children_right[i] == -1):
					print("%d, "%(classes[i]), end = '',file = fileC)
				else:
					print("%d, "%(children_right[i] * child_const[k]),  end = '', file = fileC)
			print("};\n", file = fileC)
	
		print("/*    Random Forest    */",file = fileC)
		print("/* L1 Memory Requirements = %.2fkB */"%(pointerMem),file = fileC)
		print("\nPI_CL_L1 %s *features[N_TREES] = { "%(f_dtype[k]), end = '', file = fileC)
		for j in range(0,n_estimators):
			print("&features_tree%d[0], "%j, end = '', file = fileC)
		print("};",file = fileC)	
	
		print("PI_CL_L1 %s *threshold[N_TREES] = { "%(thr_dtype[k]), end = '', file = fileC)
		for j in range(0,n_estimators):
			print("&threshold_tree%d[0], "%j, end = '', file = fileC)
		print("};",file = fileC)		
	
		print("PI_CL_L1 %s *children[N_TREES] = { "%(child_dtype[k]), end = '', file = fileC)
		for j in range(0,n_estimators):
			print("&children_tree%d[0], "%j, end = '', file = fileC)
		print("};",file = fileC)	

		print("\n#endif \n\n", file = fileC)

	# Dump header code
	print("#endif \n\n", file = fileH)
