from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from joblib import dump, load
import numpy as np
import os 

from utils_dump import class_dtype, bytewidth, feature_to_unsigned_int, threshold_to_unsigned_int



def model_memory(model, f_bytewidth, thr_bytewidth, child_bytewidth, c_bytewidth, f_limit = -2):
	n_estimators = model.n_estimators
	treeMem = np.zeros(n_estimators)
	node_bytes = f_bytewidth + thr_bytewidth + child_bytewidth * 2 + c_bytewidth * 2
	
	for i in range(0,n_estimators):
		estimator = model.estimators_[i]
		for j in range(0,estimator.tree_.node_count):
			if estimator.tree_.feature[j] != f_limit:
				treeMem[i] += 1
		treeMem[i] = treeMem[i] * 0.001 * node_bytes 

	pointerMem = n_estimators * 4 * 0.001
	modelMem = np.sum(treeMem) + pointerMem
	return treeMem, pointerMem, modelMem



# Print rf as structures consisting of 6 fields
def dump_DT_Rec_kernel(model, file, n_classes, dataset, in_dtype, f_dtype, thr_dtype):
	file_c = file[0]
	file_h = file[1]
	n = len(dataset)

	child_dtype = 'uint32_t'
	child_bytewidth = 4

	# Dump "C" source file
	print("#include \"pmsis.h\"", 	 	file = file_c)
	print("#include \"params.h\"", 	 	file = file_c)
	print("#include \"dt-rec.h\"\n\n", 	file = file_c)

	for i in range(0, n):
		__model = model[i]
		__dataset = dataset[i]
		__class = int(n_classes[i])
		n_estimators = __model.n_estimators

		__,__,c_bytewidth = class_dtype(__class)
		treeMem, pointerMem, modelMem = model_memory(__model, bytewidth(f_dtype[i]), bytewidth(thr_dtype[i]), child_bytewidth, c_bytewidth)
		
		print("#ifdef ",__dataset.upper().replace("-","_"), 			file = file_c)
		print("\n/* %s Dataset */"%__dataset.upper(), 					file = file_c)
		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(modelMem), file = file_c)

		for j in range(0,n_estimators):
			print("/*    TREE %d    */"%j,	file = file_c)
			print("/* L1 Memory Requirements = %.2fkB */\n"%(treeMem[j]), file = file_c)
	
			estimator = __model.estimators_[j]
			n_nodes = estimator.tree_.node_count
			children_left = estimator.tree_.children_left
			children_right = estimator.tree_.children_right
			feature = estimator.tree_.feature
			threshold = estimator.tree_.threshold
			value = np.reshape(estimator.tree_.value,(-1,__class))
			
			classes = []
			for k in range(0,max(np.shape(value))):
				classes.append(value[k].argmax())

			for k in range(n_nodes - 2,-1,-1):
				if(feature[k] != -2):
					print("PI_CL_L1 struct Node tree%d_Node_%d = (struct Node) { %d, %ff, "%(j, k, feature[k], threshold[k]), end = '',file = file_c)
			
					if (children_left[children_left[k]] == -1 & children_right[children_left[k]] == -1):
						print("0, ", end = '',file = file_c)
					else:
						print("&tree%d_Node_%d, "%(j, children_left[k]), end = '',file = file_c)
			
					if (children_left[children_right[k]] == -1 & children_right[children_right[k]] == -1):
						print("0, ",end = '', file = file_c)
					else:
						print("&tree%d_Node_%d, "%(j, children_right[k]), end = '', file = file_c)
			
					if (children_left[children_left[k]] == -1 & children_right[children_left[k]] == -1):
						print("%d, "%classes[children_left[k]], end = '', file = file_c) 
					else:
						print("-1, ",end = '', file = file_c)
			
					if (children_left[children_right[k]] == -1 & children_right[children_right[k]] == -1):
						print("%d};"%classes[children_right[k]],file = file_c)
					else:
						print("-1};",file = file_c)
			print("",file = file_c)

		print("/*    Random Forest    */",file = file_c)
		print("PI_CL_L1 struct Node *randomForest[N_TREES] = \n{\n",file = file_c)
		for j in range(0,n_estimators):
			print("    &tree%d_Node_0,"%j,file = file_c)
		print("\n};",file = file_c)
		print("\n#endif \n\n", file = file_c)	

	# Dump "h" header file
	print("#ifndef __DT_REC_H__", 	 file = file_h)
	print("#define __DT_REC_H__", 	 file = file_h)
	
	for i in range(0, n):
		__model = model[i]
		__dataset = dataset[i]
		__class = int(n_classes[i])
		n_estimators = __model.n_estimators

		c_dtype,__,c_bytewidth = class_dtype(__class)
		treeMem, pointerMem, modelMem = model_memory(__model, bytewidth(f_dtype[i]), bytewidth(thr_dtype[i]), 4, c_bytewidth)

		print("\n\n#ifdef ",__dataset.upper().replace("-","_"), 			file = file_h)
		print("\n/* %s Dataset */"%__dataset.upper(), 						file = file_h)
		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(modelMem), file = file_h)

		print("struct /* __attribute__ ((__packed__)) */ Node", file = file_h)
		print("{", file = file_h)
		print("    %s index;"%f_dtype[i], file = file_h)
		print("    %s value;"%thr_dtype[i], file = file_h)
		print("    struct Node* left;", file = file_h)
		print("    struct Node* right;", file = file_h)
		print("    %s left_leaf;"%c_dtype, file = file_h)
		print("    %s right_leaf;"%c_dtype, file = file_h)
		print("};\n", file = file_h)

		print("#define INPUT_DATATYPE %s"%in_dtype[i],	file = file_h)
		print("#define FEATURES_DATATYPE %s"%f_dtype[i],	file = file_h)
		print("#define THRESHOLD_DATATYPE %s\n"%thr_dtype[i],	file = file_h)

		for j in range(0,n_estimators):
			print("/*    TREE %d    */"%j,file = file_h)
			print("/* L1 Memory Requirements = %.2fkB */\n"%(treeMem[j]), file = file_h)
	
			estimator = __model.estimators_[j]
			n_nodes = estimator.tree_.node_count
			feature = estimator.tree_.feature

			for k in range(n_nodes - 2,-1,-1):
				if(feature[k] != -2):
					print("struct Node tree%d_Node_%d;"%(j,k), file = file_h)
			
			print("",file = file_h)

		print("/*    Random Forest    */",file = file_h)
		print("struct Node *randomForest[N_TREES]; \n",file = file_h)
		print("#endif\n\n",file = file_h)

	print("#endif",file = file_h)



# dump_DT_Rec_Quantized_kernel takes model trained on quantized dataset, 
# converts feature to uint removing -2 value with max_feature + 1, converts
# threshold to uint rounding to lowest integer removing -2 value with 100.

def dump_DT_Rec_Quantized_kernel(model, file, n_classes, dataset, in_dtype):
	file_c = file[0]
	file_h = file[1]
	n = len(dataset)

	child_dtype = 'uint32_t'
	child_bytewidth = 4

	# Dump "C" source file
	print("#include \"pmsis.h\"", 	 	file = file_c)
	print("#include \"params.h\"", 	 	file = file_c)
	print("#include \"dt-rec-quantized.h\"\n\n", 	file = file_c)

	for i in range(0, n):
		__model = model[i]
		__dataset = dataset[i]
		__class = int(n_classes[i])
		n_estimators = __model.n_estimators

		__,__,c_bytewidth = class_dtype(__class)
		f, __, f_bytewidth, __, f_limit = feature_to_unsigned_int(__model)
		thr, __, thr_bytewidth, __ = threshold_to_unsigned_int(__model)
		treeMem, pointerMem, modelMem = model_memory(__model, f_bytewidth, thr_bytewidth, child_bytewidth, c_bytewidth, f_limit)

		print("#ifdef ",__dataset.upper().replace("-","_"), 			file = file_c)
		print("\n/* %s Dataset */"%__dataset.upper(), 					file = file_c)
		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(modelMem), file = file_c)

		for j in range(0,n_estimators):
			print("/*    TREE %d    */"%j,	file = file_c)
			print("/* L1 Memory Requirements = %.2fkB */\n"%(treeMem[j]), file = file_c)
	
			estimator = __model.estimators_[j]
			n_nodes = estimator.tree_.node_count
			children_left = estimator.tree_.children_left
			children_right = estimator.tree_.children_right
			__f = f[j]
			__thr = thr[j]
			value = np.reshape(estimator.tree_.value,(-1,__class))
			
			classes = []
			for k in range(0,max(np.shape(value))):
				classes.append(value[k].argmax())

			for k in range(n_nodes - 2,-1,-1):
				if(__f[k] != f_limit):
					print("PI_CL_L1 struct Node tree%d_Node_%d = (struct Node) { %d, %d, "%(j, k, __f[k], __thr[k]), end = '',file = file_c)
			
					if (children_left[children_left[k]] == -1 & children_right[children_left[k]] == -1):
						print("0, ", end = '',file = file_c)
					else:
						print("&tree%d_Node_%d, "%(j, children_left[k]), end = '',file = file_c)
			
					if (children_left[children_right[k]] == -1 & children_right[children_right[k]] == -1):
						print("0, ",end = '', file = file_c)
					else:
						print("&tree%d_Node_%d, "%(j, children_right[k]), end = '', file = file_c)
			
					if (children_left[children_left[k]] == -1 & children_right[children_left[k]] == -1):
						print("%d, "%classes[children_left[k]], end = '', file = file_c) 
					else:
						print("-1, ",end = '', file = file_c)
			
					if (children_left[children_right[k]] == -1 & children_right[children_right[k]] == -1):
						print("%d};"%classes[children_right[k]],file = file_c)
					else:
						print("-1};",file = file_c)
			print("",file = file_c)

		print("/*    Random Forest    */",file = file_c)
		print("PI_CL_L1 struct Node *randomForest[N_TREES] = \n{\n",file = file_c)
		for j in range(0,n_estimators):
			print("    &tree%d_Node_0,"%j,file = file_c)
		print("\n};",file = file_c)
		print("\n#endif \n\n", file = file_c)	

	# Dump "h" header file
	print("#ifndef __DT_REC_QUANTIZED_H__", 	 file = file_h)
	print("#define __DT_REC_QUANTIZED_H__", 	 file = file_h)
	
	for i in range(0, n):
		__model = model[i]
		__dataset = dataset[i]
		__class = int(n_classes[i])
		n_estimators = __model.n_estimators

		c_dtype,__,c_bytewidth = class_dtype(__class)
		f, f_dtype, f_bytewidth, __, f_limit = feature_to_unsigned_int(__model)
		__, thr_dtype, thr_bytewidth, __ = threshold_to_unsigned_int(__model)
		treeMem, pointerMem, modelMem = model_memory(__model, f_bytewidth, thr_bytewidth, child_bytewidth, c_bytewidth, f_limit)

		print("\n\n#ifdef ",__dataset.upper().replace("-","_"), 			file = file_h)
		print("\n/* %s Dataset */"%__dataset.upper(), 						file = file_h)
		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(modelMem), file = file_h)

		print("struct /* __attribute__ ((__packed__)) */ Node", file = file_h)
		print("{", file = file_h)
		print("    %s index;"%f_dtype, file = file_h)
		print("    %s value;"%thr_dtype, file = file_h)
		print("    struct Node* left;", file = file_h)
		print("    struct Node* right;", file = file_h)
		print("    %s left_leaf;"%c_dtype, file = file_h)
		print("    %s right_leaf;"%c_dtype, file = file_h)
		print("};\n", file = file_h)

		print("#define INPUT_DATATYPE %s"%in_dtype[i],	file = file_h)
		print("#define FEATURES_DATATYPE %s"%f_dtype,	file = file_h)
		print("#define THRESHOLD_DATATYPE %s\n"%thr_dtype,	file = file_h)

		for j in range(0,n_estimators):
			print("/*    TREE %d    */"%j,file = file_h)
			print("/* L1 Memory Requirements = %.2fkB */\n"%(treeMem[j]), file = file_h)
	
			estimator = __model.estimators_[j]
			n_nodes = estimator.tree_.node_count
			feature = estimator.tree_.feature

			for k in range(n_nodes - 2,-1,-1):
				if(feature[k] != f_limit):
					print("struct Node tree%d_Node_%d;"%(j,k), file = file_h)
			
			print("",file = file_h)

		print("/*    Random Forest    */",file = file_h)
		print("struct Node *randomForest[N_TREES]; \n",file = file_h)
		print("#endif\n\n",file = file_h)

	print("#endif",file = file_h)
