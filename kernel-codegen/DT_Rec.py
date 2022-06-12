from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from joblib import dump, load
import numpy as np
import os 

from utils_dataset import dataset_selection, class_spec



# Print rf as structures consisting of 6 fields
def dump_DT_Rec_kernel(models, file, n_classes, dataset):
	file_c = file[0]
	file_h = file[1]
	n_dataset = len(dataset)

	# Dump "C" source file
	print("#include \"pmsis.h\"", 	 	file = file_c)
	print("#include \"params.h\"", 	 	file = file_c)
	print("#include \"dt-rec.h\"\n\n", 	file = file_c)

	for k in range(0, n_dataset):
		rf_model = models[k]
		n_estimators = rf_model.n_estimators
		dataset_tmp = dataset[k]
		classes_tmp = int(n_classes[k])

		__,__,__,__,__,__,__,f_bytewidth,__,__,__ = dataset_selection(dataset[k])
		__,__,__,c_bytewidth = class_spec(classes_tmp)

		print("#ifdef ",dataset_tmp.upper().replace("-","_"), 			file = file_c)
		print("\n/* %s Dataset */"%dataset_tmp.upper(), file = file_c)

		memory = np.zeros(n_estimators)
		l1_memory = 0
		total_byte = 4*3 + f_bytewidth + 2*c_bytewidth
		for i in range(0,n_estimators):
			estimator = rf_model.estimators_[i]
			for j in range(0,estimator.tree_.node_count):
				if estimator.tree_.feature[j] != -2:
					memory[i] += 1
			memory[i] = memory[i] * 0.001 * total_byte 
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
	
			for i in range(n_nodes - 2,-1,-1):
				if(feature[i] != -2):
					print("PI_CL_L1 struct Node tree%d_Node_%d = (struct Node) { %d, %ff, "%(j, i, feature[i], threshold[i]), end = '',file = file_c)
			
					if (children_left[children_left[i]] == -1 & children_right[children_left[i]] == -1):
						print("0, ", end = '',file = file_c)
					else:
						print("&tree%d_Node_%d, "%(j, children_left[i]), end = '',file = file_c)
			
					if (children_left[children_right[i]] == -1 & children_right[children_right[i]] == -1):
						print("0, ",end = '', file = file_c)
					else:
						print("&tree%d_Node_%d, "%(j, children_right[i]), end = '', file = file_c)
			
					if (children_left[children_left[i]] == -1 & children_right[children_left[i]] == -1):
						print("%d, "%classes[children_left[i]], end = '', file = file_c) 
					else:
						print("-1, ",end = '', file = file_c)
			
					if (children_left[children_right[i]] == -1 & children_right[children_right[i]] == -1):
						print("%d};"%classes[children_right[i]],file = file_c)
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
	
	for k in range(0, n_dataset):
		rf_model = models[k]
		n_estimators = rf_model.n_estimators
		dataset_tmp = dataset[k]
		classes_tmp = int(n_classes[k])

		__,__,__,__,__,__,f_dtype,__,__,__,__ = dataset_selection(dataset[k])
		__,c_dtype,__,__ = class_spec(classes_tmp)

		memory = np.zeros(n_estimators)
		l1_memory = 0
		total_byte = 4*3 + f_bytewidth + 2*c_bytewidth
		for i in range(0,n_estimators):
			estimator = rf_model.estimators_[i]
			for j in range(0,estimator.tree_.node_count):
				if estimator.tree_.feature[j] != -2:
					memory[i] += 1
			memory[i] = memory[i] * 0.001 * total_byte 
			l1_memory += memory[i]

		print("\n\n#ifdef ",dataset_tmp.upper().replace("-","_"), 			file = file_h)
		print("\n/* %s Dataset */"%dataset_tmp.upper(), file = file_h)
		print("/* Total L1 Memory Requirements = %.2fkB */\n"%(l1_memory + total_byte*n_estimators*0.001), file = file_h)

		print("struct Node", file = file_h)
		print("{", file = file_h)
		print("    %s index;"%f_dtype, file = file_h)
		print("    float value;", file = file_h)
		print("    struct Node* left;", file = file_h)
		print("    struct Node* right;", file = file_h)
		print("    %s left_leaf;"%c_dtype, file = file_h)
		print("    %s right_leaf;"%c_dtype, file = file_h)
		print("};\n", file = file_h)

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
	
			for i in range(n_nodes - 2,-1,-1):
				if(feature[i] != -2):
					print("struct Node tree%d_Node_%d;"%(j,i), file = file_h)
			
			print("",file = file_h)

		print("/*    Random Forest    */",file = file_h)
		print("struct Node *randomForest[N_TREES]; \n",file = file_h)
		print("#endif\n\n",file = file_h)

	print("#endif",file = file_h)

	return l1_memory
