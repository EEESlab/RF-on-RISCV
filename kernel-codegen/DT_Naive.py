from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from sklearn.tree import _tree
from joblib import dump, load
import numpy as np
import os

from utils_dump import threshold_to_unsigned_int



# Print DT structure in C code
def dt2code_body(tree, file):
	tree_ = tree.tree_
	feature_name = ['input[%d]'%i for i in tree_.feature]

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
def dump_DT_Naive_kernel(models, file, n_classes, dataset, in_dtype, f_dtype, thr_dtype):
	file_c = file[0]
	file_h = file[1]
	n = len(dataset)

	# Dump .c source file
	print("#include \"pmsis.h\"", 	 		file = file_c)
	print("#include \"params.h\"", 	 		file = file_c)
	print("#include \"dt-naive.h\"\n\n", 	 		file = file_c)

	for i in range(0, n):
		__model = models[i]
		__dataset = dataset[i]
		n_estimators = __model.n_estimators

		print("#ifdef ",__dataset.upper().replace("-","_"), file = file_c)
		print("\n/* %s Dataset */"%__dataset.upper(), 		file = file_c)
	
		print("\nvoid randomForest(%s *input, int *class_rf_idx)"%(in_dtype[i]), file = file_c)
		print("{\n", 										file = file_c)
		print("    *class_rf_idx = 0;", 					file = file_c)
		print("    int class_tree_idx = 0;", 				file = file_c)
		print("    int class_tree_val = 0;", 				file = file_c)
		print("    int classes_rf[%d]   = {0};"%n_classes[i], 	file = file_c)
		print("    int classes_tree[%d] = {0};\n"%n_classes[i],  file = file_c)

		for j in range(0, n_estimators):
	
			print("    /*    TREE %d    */"%j, 						file = file_c)
			dt2code_body(tree = __model.estimators_[j], 			file = file_c)
			print("", 												file = file_c)
			print("    class_tree_idx = 0;", 						file = file_c)
			print("    class_tree_val = classes_tree[0];", 			file = file_c)
			print("    classes_tree[0] = 0;", 						file = file_c)
			print("    for (int i = 1; i < %d; i++)"%n_classes[i], 	file = file_c)
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
		print("    for (int i = 1; i < %d; i++)"%n_classes[i], 	file = file_c)
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

	for i in range(0, n):
		__model = models[i]
		__dataset = dataset[i]
		print("#ifdef ",__dataset.upper().replace("-","_"), 			file = file_h)
		print("\n/* %s Dataset */\n"%__dataset.upper(), 				file = file_h)

		print("#define INPUT_DATATYPE %s"%in_dtype[i],	file = file_h)
		print("#define THRESHOLD_DATATYPE %s\n"%thr_dtype[i],	file = file_h)
		print("void randomForest(%s *input, int *class_rf_idx);"%(in_dtype[i]), file = file_h)

		print("\n#endif \n\n", file = file_h)

	print("\n#endif", 												file = file_h)



def dt2code_body_quantized(tree, threshold, file):
	tree_ = tree.tree_
	feature_name = ['input[%d]'%i for i in tree_.feature]

	def recurse(node, depth, file):
		indent = "    " * depth
		if tree_.feature[node] != _tree.TREE_UNDEFINED:
			name = feature_name[node]
			__threshold = threshold[node]
			print("{}if({} <= {})".format(indent, name, __threshold),file=file)
			print("{}".format(indent) + "{",file=file)
			recurse(tree_.children_left[node], depth + 1, file = file)
			print("{}".format(indent) + "}",file=file)
			print("{}".format(indent) + "else" + " // if {} > {}".format(name, __threshold),file=file)
			print("{}".format(indent) + "{",file=file)
			recurse(tree_.children_right[node], depth + 1, file = file)
			print("{}".format(indent) + "}",file=file)
		else:
			result = max(tree_.value[node]).tolist()
			for i in range(0,len(result)):
				if result[i] != 0:
					print("{}classes_tree[{}] += {};".format(indent, i, int(result[i])), file=file)

	recurse(0, 1, file=file)



# dump_DT_Naive_Quantized_kernel takes model trained on quantized dataset, 
# converts threshold to uint rounding to lowest integer removing -2 value 
# with 100.

def dump_DT_Naive_Quantized_kernel(models, file, n_classes, dataset, in_dtype):
	file_c = file[0]
	file_h = file[1]
	n = len(dataset)

	# Dump .c source file
	print("#include \"pmsis.h\"", 	 		file = file_c)
	print("#include \"params.h\"", 	 		file = file_c)
	print("#include \"dt-naive-quantized.h\"\n\n", 	 		file = file_c)

	for i in range(0, n):
		__model = models[i]
		__dataset = dataset[i]
		n_estimators = __model.n_estimators

		thr,__,__,__ = threshold_to_unsigned_int(__model)

		print("#ifdef ",__dataset.upper().replace("-","_"), file = file_c)
		print("\n/* %s Dataset */"%__dataset.upper(), 		file = file_c)
	
		print("\nvoid randomForest(%s *input, int *class_rf_idx)"%(in_dtype[i]), file = file_c)
		print("{\n", 										file = file_c)
		print("    *class_rf_idx = 0;", 					file = file_c)
		print("    int class_tree_idx = 0;", 				file = file_c)
		print("    int class_tree_val = 0;", 				file = file_c)
		print("    int classes_rf[%d]   = {0};"%n_classes[i], 	file = file_c)
		print("    int classes_tree[%d] = {0};\n"%n_classes[i],  file = file_c)

		for j in range(0, n_estimators):
	
			print("    /*    TREE %d    */"%j, 						file = file_c)
			dt2code_body_quantized(tree = __model.estimators_[j], threshold = thr[j], file = file_c)
			print("", 												file = file_c)
			print("    class_tree_idx = 0;", 						file = file_c)
			print("    class_tree_val = classes_tree[0];", 			file = file_c)
			print("    classes_tree[0] = 0;", 						file = file_c)
			print("    for (int i = 1; i < %d; i++)"%n_classes[i], 	file = file_c)
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
		print("    for (int i = 1; i < %d; i++)"%n_classes[i], 	file = file_c)
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
	print("#ifndef __DT_NAIVE_QUANTIZED_H__", 					file = file_h)
	print("#define __DT_NAIVE_QUANTIZED_H__", 					file = file_h)
	print("", 														file = file_h)

	for i in range(0, n):
		__model = models[i]
		__dataset = dataset[i]
		__,thr_dtype,__,__ = threshold_to_unsigned_int(__model)

		print("#ifdef ",__dataset.upper().replace("-","_"), 			file = file_h)
		print("\n/* %s Dataset */\n"%__dataset.upper(), 				file = file_h)

		print("#define INPUT_DATATYPE %s"%in_dtype[i],	file = file_h)
		print("#define THRESHOLD_DATATYPE %s\n"%thr_dtype,	file = file_h)
		print("void randomForest(%s *input, int *class_rf_idx);"%(in_dtype[i]), file = file_h)

		print("\n#endif \n\n", file = file_h)

	print("\n#endif", 												file = file_h)
