from sklearn.metrics import accuracy_score
from joblib import dump, load
import numpy as np
import os 

from dataset_utils import dataset_selection
from data_utils import dump_test_data, dump_params



# Print rf as loop
def dump_DT_Loop_kernel(models, file, n_classes, dataset):
	file_c = file[0]
	file_h = file[1]

	# Dump "C" source file
	print("#include \"pmsis.h\"", 	 		file = file_c)
	print("#include \"params.h\"", 	 		file = file_c)
	print("#include \"dt-loop.h\"\n\n", 		file = file_c)

	n_dataset = len(dataset)

	for k in range(0, n_dataset):

		rf_model = models[k]
		dataset_tmp = dataset[k]
		classes_tmp = int(n_classes[k])

		__,__,__,__,__,__,__,f_bytewidth,__,__,__ = dataset_selection(dataset[k])

		print("#ifdef ",dataset_tmp.upper().replace("-","_"), 			file = file_c)
		print("\n/* %s Dataset */"%dataset_tmp.upper(), file = file_c)

		n_estimators = rf_model.n_estimators

		memory = np.zeros(n_estimators)
		l1_memory = 0
		total_byte = 3*4 + f_bytewidth
		for i in range(0,n_estimators):
			estimator = rf_model.estimators_[i]
			n_nodes = estimator.tree_.node_count
			memory[i] = n_nodes*total_byte*0.001 
			l1_memory += memory[i]

		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(l1_memory+ total_byte*n_estimators*0.001), file = file_c)

		for j in range(0,n_estimators):
			print("/*    TREE %d    */"%j,	file = file_c)
			print("/* L1 Memory Requirements = %.2fkB */\n"%(memory[j]), file = file_c)
	
			estimator = rf_model.estimators_[j]
			n_nodes = estimator.tree_.node_count
			children_left = estimator.tree_.children_left
			children_right = estimator.tree_.children_right
			feature = estimator.tree_.feature
			threshold = estimator.tree_.threshold
			value = estimator.tree_.value
			value = np.reshape(value,(-1,classes_tmp))
			
			classes = []
			for i in range(0,max(np.shape(value))):
				classes.append(value[i].argmax())
	
			vote_classes = []
			for i in range(0,max(np.shape(value))):
				vote_classes.append(int(value[i,value[i].argmax()]))		
	
			for i in range(n_nodes - 1,-1,-1):
				print("PI_CL_L1 struct Node tree%d_Node_%d = (struct Node) { %d, %ff, "%(j, i, feature[i], threshold[i]), end = '',	file = file_c)
		
				if (children_left[i] == -1):
					print("%d, "%classes[i], end = '',file = file_c)
				else:
					print("(int) &tree%d_Node_%d, "%(j, children_left[i]), end = '', file = file_c)
		
				if (children_right[i] == -1):
					print("%d};"%classes[i], file = file_c)
				else:
					print("(int) &tree%d_Node_%d};"%(j, children_right[i]), file = file_c)
			
			print("", file = file_c)

		print("/*    Random Forest    */",file = file_c)
		print("PI_CL_L1 struct Node *randomForest[N_TREES] = \n{\n",file = file_c)
		for j in range(0,n_estimators):
			print("    &tree%d_Node_0,"%j,file = file_c)
		print("\n};",file = file_c)
		print("\n#endif \n\n", file = file_c)		

	# Dump "h" header file
	print("#ifndef __DT_LOOP_H__", 	 file = file_h)
	print("#define __DT_LOOP_H__", 	 file = file_h)

	for k in range(0, n_dataset):
		rf_model = models[k]
		dataset_tmp = dataset[k]
		classes_tmp = int(n_classes[k])

		__,__,__,__,__,__,f_dtype,__,__,__,__ = dataset_selection(dataset[k])

		print("\n\n#ifdef ",dataset_tmp.upper().replace("-","_"), 			file = file_h)
		print("\n/* %s Dataset */"%dataset_tmp.upper(), file = file_h)
		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(l1_memory + total_byte*n_estimators*0.001), file = file_h)

		n_estimators = rf_model.n_estimators

		print("struct Node", file = file_h)
		print("{", file = file_h)
		print("    %s index;"%f_dtype, file = file_h)
		print("    float value;", file = file_h)
		print("    uint32_t left;", file = file_h)
		print("    uint32_t right;", file = file_h)
		print("};\n\n", file = file_h)

		for j in range(0,n_estimators):
			print("/*    TREE %d    */"%j,file = file_h)
			print("/* L1 Memory Requirements = %.2fkB */\n"%(memory[j]), file = file_h)
	
			estimator = rf_model.estimators_[j]
			n_nodes = estimator.tree_.node_count
			children_left = estimator.tree_.children_left
			children_right = estimator.tree_.children_right
			feature = estimator.tree_.feature
			threshold = estimator.tree_.threshold
			value = estimator.tree_.value
			value = np.reshape(value,(-1,classes_tmp))
			
			classes = []
			for i in range(0,max(np.shape(value))):
				classes.append(value[i].argmax())
	
			vote_classes = []
			for i in range(0,max(np.shape(value))):
				vote_classes.append(int(value[i,value[i].argmax()]))		
	
			for i in range(n_nodes - 1,-1,-1):
					print("struct Node tree%d_Node_%d;"%(j,i), file = file_h)
		
			print("",file = file_h)
	
		print("/*    Random Forest    */",file = file_h)
		print("struct Node *randomForest[N_TREES];\n",file = file_h)
		print("#endif\n\n",file = file_h)

	print("#endif",file = file_h)

	return l1_memory
