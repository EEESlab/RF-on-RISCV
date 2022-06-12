from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from sklearn.tree import _tree
from joblib import dump, load
import numpy as np
import os

from utils_dataset import dataset_selection



# Print DT structure in C code
def dt2code_body(tree, file):
	tree_ = tree.tree_
	feature_name = ['features[%d]'%i for i in tree_.feature]

	def recurse(node, depth, file):
		indent = "    " * depth
		if tree_.feature[node] != _tree.TREE_UNDEFINED:
			name = feature_name[node]
			threshold = tree_.threshold[node]
			print("{}if({} <= {}f)".format(indent, name, threshold),file=file)
			print("{}".format(indent) + "{",file=file)
			recurse(tree_.children_left[node], depth + 1, file = file)
			print("{}".format(indent) + "}",file=file)
			print("{}".format(indent) + "else" + " // if {} > {}f".format(name, threshold),file=file)
			print("{}".format(indent) + "{",file=file)
			recurse(tree_.children_right[node], depth + 1, file = file)
			print("{}".format(indent) + "}",file=file)
		else:
			result = max(tree_.value[node]).tolist()
			for i in range(0,len(result)):
				if result[i] != 0:
					print("{}classes_tree[{}] += {};".format(indent, i, int(result[i])), file=file)

	recurse(0, 1, file=file)



# Print RF structure in C code for sequential execution
def dump_DT_Naive_kernel(models, file, n_classes, dataset):
	file_c = file[0]
	file_h = file[1]

	# Dump .c source file
	print("#include \"pmsis.h\"", 	 		file = file_c)
	print("#include \"params.h\"", 	 		file = file_c)
	print("#include \"dt-naive.h\"\n\n", 	 		file = file_c)

	n_dataset = len(dataset)

	for k in range(0, n_dataset):

		rf_model = models[k]
		dataset_tmp = dataset[k]
		classes_tmp = int(n_classes[k])

		print("#ifdef ",dataset_tmp.upper().replace("-","_"), 			file = file_c)
		print("\n/* %s Dataset */"%dataset_tmp.upper(), 	file = file_c)
		
		n_estimators = rf_model.n_estimators

		print("\nvoid randomForest(float *features, int *class_rf_idx)", file = file_c)
		print("{\n", 										file = file_c)
		print("    *class_rf_idx = 0;", 					file = file_c)
		print("    int class_tree_idx = 0;", 				file = file_c)
		print("    int class_tree_val = 0;", 				file = file_c)
		print("    int classes_rf[%d]   = {0};"%n_classes[k], 	file = file_c)
		print("    int classes_tree[%d] = {0};\n"%n_classes[k],  file = file_c)

		for i in range(0, n_estimators):
	
			print("    /*    TREE %d    */"%i, 						file = file_c)
			dt2code_body(tree = rf_model.estimators_[i], 			file = file_c)
			print("", 												file = file_c)
			print("    class_tree_idx = 0;", 						file = file_c)
			print("    class_tree_val = classes_tree[0];", 			file = file_c)
			print("    classes_tree[0] = 0;", 						file = file_c)
			print("    for (int i = 1; i < %d; i++)"%n_classes[k], 		file = file_c)
			print("    {", 											file = file_c)
			print("        if (classes_tree[i] > class_tree_val)", 	file = file_c)
			print("        {", 										file = file_c)
			print("            class_tree_idx = i;", 				file = file_c)
			print("            class_tree_val = classes_tree[i];", 	file = file_c)
			print("        }", 										file = file_c)
			print("        classes_tree[i] = 0;", 					file = file_c)
			print("    }", 											file = file_c)
			print("    classes_rf[class_tree_idx]++;", 				file = file_c)
			print("", 												file = file_c)
	
		print("    int class_rf_val = classes_rf[0];", 		file = file_c)
		print("    for (int i = 1; i < %d; i++)"%n_classes[k], 	file = file_c)
		print("    {", 										file = file_c)
		print("        if (classes_rf[i] > class_rf_val)", 	file = file_c)
		print("        {", 									file = file_c)
		print("            *class_rf_idx = i;", 			file = file_c)
		print("            class_rf_val = classes_rf[i];", 	file = file_c)
		print("        }", 									file = file_c)
		print("    }", 										file = file_c)
		print("};", 										file = file_c)
		print("\n#endif \n\n", file = file_c)


	# Dump .h header file
	print("#ifndef __DT_NAIVE_H__", 									file = file_h)
	print("#define __DT_NAIVE_H__", 									file = file_h)
	print("", 														file = file_h)

	for k in range(0, n_dataset):

		dataset_tmp = dataset[k]
		print("/* %s Dataset */"%dataset_tmp.upper(), 							file = file_h)

	print("", 														file = file_h)
	print("void randomForest(float *features, int *class_rf_idx);", file = file_h)
	print("", 														file = file_h)
	print("\n#endif", 												file = file_h)
