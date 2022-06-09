import numpy as np
import pandas as pd
import sys
import os

def dump_test_data(x_test, y_test, memoryLoc, dataset, features, in_dtype, in_bytewidth, file):
	n_dataset = len(dataset)
	fileC = file[0]
	fileH = file[1]

	print("#include \"pmsis.h\"",   	file = fileC)
	print("#include \"params.h\"",  	file = fileC)
	print("#include \"data.h\"",  		file = fileC)
	print("\n\n/* Testing Data */\n", 	file = fileC)

	for i in range(0, n_dataset):		
		__x_test = np.asarray(x_test[i])
		__y_test = np.asarray(y_test[i]).reshape(-1,1)
		__dataset = dataset[i]
		__features = int(features[i])
		__in_dtype = in_dtype[i]
		__in_bytewidth = in_bytewidth[i]
		__x_test_dim = np.asarray(__x_test).shape[0]

		if memoryLoc == "L2": 
			memAttr = "PI_L2"
			L1Mem = 1 * __x_test_dim * 0.001
			L2Mem = __x_test_dim * __features * __in_bytewidth *  0.001
		else:
			memAttr = "PI_CL_L1"
			L1Mem = (__features * __in_bytewidth + 1) * __x_test_dim * 0.001
			L2Mem = 0

		print("\n#ifdef ",__dataset.upper().replace("-","_"), file = fileC)
		print("\n/* %s Dataset */"%__dataset.upper(), 		  file = fileC)
		print("/* Total L1 Memory Requirements = %.2fkB */ "%(L1Mem), file = fileC)
		print("/* Total L2 Memory Requirements = %.2fkB */\n"%(L2Mem), file = fileC)

		print("%s %s x_test[DIM*N_TEST] = {\n"%(memAttr,__in_dtype), file = fileC)
		for j in range(0,__x_test_dim):
			for k in range(0, __features):
				print(" %f,"%__x_test[j,k], end = '', file = fileC)
			print("", file = fileC)
		print("\n};\n", file = fileC)
	
		print("PI_CL_L1 uint8_t y_test[N_TEST] = {\n", file = fileC)
		for j in range(0,__x_test_dim):
			print(" %d,"%__y_test[j], end = '', file = fileC)
		print("\n\n};\n", file = fileC)
		print("#endif \n", file = fileC)

	print("#ifndef __DATA_H__", 	  file = fileH)
	print("#define __DATA_H__", 	  file = fileH)
	print("\n\n/* Testing Data */\n", file = fileH)

	for i in range(0, n_dataset):
		__dataset = dataset[i]
		__features = int(features[i])
		__in_dtype = in_dtype[i]
		__in_bytewidth = in_bytewidth[i]

		if memoryLoc == "L2": 
			memAttr = "PI_L2"
			L1Mem = 1 * __x_test_dim * 0.001
			L2Mem = __x_test_dim * __features * __in_bytewidth *  0.001
		else:
			memAttr = "PI_CL_L1"
			L1Mem = (__features * __in_bytewidth + 1) * __x_test_dim * 0.001
			L2Mem = 0

		print("\n#ifdef ",__dataset.upper().replace("-","_"), file = fileH)
		print("\n/* %s Dataset */"%__dataset.upper(), 		  file = fileH)
		print("/* Total L1 Memory Requirements = %.2fkB */ "%(L1Mem), file = fileH)
		print("/* Total L2 Memory Requirements = %.2fkB */\n"%(L2Mem), file = fileH)
		print("%s x_test[DIM*N_TEST];"%(__in_dtype), file = fileH)
		print("uint8_t y_test[N_TEST];\n", file = fileH)
		print("#endif \n", file = fileH)

	print("\n#endif", file = fileH)

	return L1Mem, L2Mem



def dump_params(n_test, classes, dataset, n_loop, features, n_estimators, accuracy, metadata, outputFile):
	n_dataset = len(dataset)
	trueAcc = np.asarray(accuracy[0])
	testAcc = np.asarray(accuracy[1])
	inputDataType = metadata[0]
	featuresDataType = metadata[1]

	print("#ifndef __PARAMS_H__", file = outputFile)
	print("#define __PARAMS_H__\n\n", file = outputFile)
	print("#define N_CORES (1)", file = outputFile)
	print("#define STACK_SIZE (512)\n\n", file = outputFile)
	print("#define DEBUG\n", file = outputFile)
	print("//#define STATS", file = outputFile)
	print("//#define STATS_CLUSTER", file = outputFile)
	print("//#define STATS_FPU\n", file = outputFile)
	
	for i in range(0, n_dataset):
		__dataset = dataset[i]
		print("//#define %s"%__dataset.upper().replace("-","_"), file = outputFile)
	
	for i in range(0, n_dataset):
		__features = int(features[i])
		__classes = int(classes[i])
		__dataset = dataset[i]
		print("\n\n#ifdef ",__dataset.upper().replace("-","_"), file = outputFile)
		print("\n/* %s Dataset */"%__dataset.upper(), file = outputFile)
		print("/* Input data-type: %s */"%(inputDataType[i]), file = outputFile)
		print("/* Features data-type: %s */"%(featuresDataType[i]), file = outputFile)
		print("/* Accuracy on Testing Set = %f%%*/"%testAcc[i], file = outputFile)
		print("/* Accuracy on Real Testing Set = %f%%*/\n"%trueAcc[i], file = outputFile)	
		print("#define N_TREES",n_estimators, file = outputFile)
		print("#define N_CLASS",__classes, file = outputFile)
		print("#define N_TEST",n_test, file = outputFile)
		print("#define N_LOOP",n_loop, file = outputFile)
		print("#define DIM",__features,	file = outputFile)
		print("\n#endif",file = outputFile)
	
	print("\n\n#endif", file = outputFile)