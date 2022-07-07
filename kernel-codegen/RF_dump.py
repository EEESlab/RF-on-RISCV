from sklearn.metrics import accuracy_score
from joblib import dump, load
import numpy as np
import os 

from DT_Naive import dump_DT_Naive_kernel, dump_DT_Naive_Quantized_kernel
from DT_Loop import dump_DT_Loop_kernel, dump_DT_Loop_Quantized_kernel
from DT_Rec import dump_DT_Rec_kernel, dump_DT_Rec_Quantized_kernel
from DT_Arr import dump_DT_Arr_Stallfree_L1, dump_DT_Arr_Stallfree_L2, dump_DT_Arr_Shiftless_L2, dump_DT_Arr_Shiftless_L1, dump_DT_Arr_Baseline_L2, dump_DT_Arr_Baseline_L1
from DT_Arr import dump_DT_Arr_Baseline_Quantized_L1, dump_DT_Arr_Baseline_Quantized_L2

from utils_dump import feature_dtype, input_dtype, threshold_dtype
from utils_graph import DT_votes, DT_decision_path
from utils_data import dump_params, dump_test_data
from utils_dataset import dataset_selection



def dump_RF(exploration, kernel, scaler = False, double_buffering = False):	
	runtime_dir = 'dump-models/%s/%s'%(exploration,kernel)
	model_dir   = 'trained-models/%s'%(exploration)
	n_models 	= len(os.listdir(model_dir))

	os.makedirs(runtime_dir, exist_ok = True)
	kernel_c = open(str(runtime_dir) + "/%s.c"%kernel.lower	(),"w")
	kernel_h = open(str(runtime_dir) + "/%s.h"%kernel.lower(),"w")
	data_c 	 = open(str(runtime_dir) + "/data.c","w")
	data_h 	 = open(str(runtime_dir) + "/data.h","w")
	params_h = open(str(runtime_dir) + "/params.h","w")

	n_features = np.zeros(n_models)
	n_classes = np.zeros(n_models)
	f_dtype = n_models * [None]
	f_bytewidth = np.zeros(n_models)
	in_dtype = n_models * [None]
	in_bytewidth = np.zeros(n_models)
	thr_dtype = n_models * [None]
	thr_bytewidth = np.zeros(n_models)

	__fake_acc = np.zeros(n_models)
	__true_acc = np.zeros(n_models)
	n_features = np.zeros(n_models)
	n_classes = np.zeros(n_models)

	n_test = 10
	dataset = n_models * [None]
	__x_test = n_models * [None]
	__y_test = n_models * [None]
	model = n_models * [None]
	params = n_models * [None]

	for i in range(0,n_models):
		model_name = os.listdir("trained-models/%s"%(exploration))[i]
		dataset[i] = model_name.split('-',2)[-1].split('.')[0]
		model[i] = load(str(model_dir)+'/'+str(model_name))
		params[i] = model[i].get_params()

		x_train, x_test, __, y_test, n_classes[i], n_features[i] = dataset_selection(dataset[i], scaler = scaler)
		__, in_dtype[i], __, in_bytewidth[i] = input_dtype(np.concatenate((x_train,x_test)))
		__, f_dtype[i], __, f_bytewidth[i] = feature_dtype(model[i])
		__, thr_dtype[i], __, thr_bytewidth[i] = threshold_dtype(model[i])

		__x_test[i] = x_test[(int)(x_test.shape[0] - n_test):(int)(x_test.shape[0])].tolist()
		__y_test[i] = y_test[(int)(y_test.shape[0] - n_test):(int)(y_test.shape[0])].tolist()
		__fake_acc[i] = accuracy_score(__y_test[i], model[i].predict(__x_test[i])) * 100
		__true_acc[i] = accuracy_score(y_test, model[i].predict(x_test)) * 100

	dump_test_data(__x_test, __y_test, "L1", dataset, n_features, in_dtype, in_bytewidth, [data_c, data_h])
	dump_params(n_test, n_classes, dataset, n_test, n_features, params[i]["n_estimators"], [__true_acc,__fake_acc], [in_dtype,f_dtype], params_h)

	if (kernel == 'DT-Naive'):
		dump_DT_Naive_kernel(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype,f_dtype,thr_dtype)
	if (kernel == 'DT-Naive-Quantized'):
		dump_DT_Naive_Quantized_kernel(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype)

	if (kernel == 'DT-Loop'):
		dump_DT_Loop_kernel(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype,f_dtype,thr_dtype)
	if (kernel == 'DT-Loop-Quantized'):
		dump_DT_Loop_Quantized_kernel(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype)

	if (kernel == 'DT-Rec'):
		dump_DT_Rec_kernel(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype,f_dtype,thr_dtype)
	if (kernel == 'DT-Rec-Quantized'):
		dump_DT_Rec_Quantized_kernel(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype)

	if (kernel == 'DT-Arr-Baseline'):
		if double_buffering == False:
			dump_DT_Arr_Baseline_L1(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype,f_dtype,thr_dtype)
		else:
			dump_DT_Arr_Baseline_L2(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype,f_dtype,thr_dtype)

	if (kernel == 'DT-Arr-Baseline-Quantized'):
		if double_buffering == False:
			dump_DT_Arr_Baseline_Quantized_L1(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype)
		else:
			dump_DT_Arr_Baseline_Quantized_L2(model,[kernel_c,kernel_h],n_classes,dataset,in_dtype)

	if (kernel == 'DT-Arr-Shiftless'):
		if double_buffering == False:
			dump_DT_Arr_Shiftless_L1(model,n_classes,dataset,[f_bytewidth,f_dtype],[in_bytewidth,in_dtype],[kernel_c,kernel_h])
		else:
			dump_DT_Arr_Shiftless_L2(model,n_classes,dataset,[f_bytewidth,f_dtype],[in_bytewidth,in_dtype],[kernel_c,kernel_h])

	if (kernel == 'DT-Arr-Stallfree'):
		if double_buffering == False:
			dump_DT_Arr_Stallfree_L1(model,n_classes,dataset,[f_bytewidth,f_dtype],[in_bytewidth,in_dtype],[kernel_c,kernel_h])
		else:
			dump_DT_Arr_Stallfree_L2(model,n_classes,dataset,[f_bytewidth,f_dtype],[in_bytewidth,in_dtype],[kernel_c,kernel_h])
