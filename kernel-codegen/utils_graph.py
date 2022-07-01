from ortools.linear_solver import pywraplp
from joblib import dump, load
from sklearn import tree 
import numpy as np
import graphviz
import os


from utils_dataset import dataset_selection



def modelMaxNodes(model):
	maxNodes = int(np.amax(rfNodeCount(model)))
	return maxNodes



def modelFeatures(model):
	features = model.n_features_in_
	return features



def rfNodeCount(model):
	n_estimators = model.n_estimators
	nodes = np.zeros(n_estimators)

	for i in range(0,n_estimators):
		estimator = model.estimators_[i]
		nodes[i] = estimator.tree_.node_count

	return nodes 



def DT_votes(model, x_test):
	n_estimators = model.n_estimators
	for i in range(0, x_test.shape[0]):
		for j in range(0, n_estimators):
			estimator = model.estimators_[j]
			print("%d "%estimator.predict(x_test[i].reshape(1,-1)), end = '')
		print("--- Class %d"%model.predict(x_test[i].reshape(1,-1)))



# Retrieve tree decision path for x_test[0]
def DT_decision_path(tree, x_test):
	feature = tree.tree_.feature
	threshold = tree.tree_.threshold
	node_indicator = tree.decision_path(x_test)	
	leaf_id = tree.apply(x_test)

	sample_id = 0
	node_index = node_indicator.indices[
		node_indicator.indptr[sample_id]:
		node_indicator.indptr[sample_id + 1]
	]
	
	print('Decision path predicting sample {id}:\n'.format(id=sample_id))

	for node_id in node_index:

		if leaf_id[sample_id] == node_id:
			continue
		if (x_test[sample_id, feature[node_id]] <= threshold[node_id]):
			threshold_sign = "<="
		else:
			threshold_sign = ">"
	
		print("decision node {node} : (x_test[{sample}, {feature}] = {value}) "
			  "{inequality} {threshold})".format(
				  node=node_id,
				  sample=sample_id,
				  feature=feature[node_id],
				  value=x_test[sample_id, feature[node_id]],
				  inequality=threshold_sign,
				  threshold=threshold[node_id])
		)



def RF_check(exploration, test_number):
	model_dir   = 'trained-models/%s'%(exploration)
	n_models 	= len(os.listdir(model_dir))
	__x_test = n_models * [None]
	__y_test = n_models * [None]
	dataset = n_models * [None]
	model = n_models * [None]
	n_test = 10

	for i in range(0,n_models):
		model_name = os.listdir("trained-models/%s"%(exploration))[i]
		print("Model : %s"%model_name)

		dataset[i] = model_name.split('-',2)[-1].split('.')[0]
		__,x_test,__,y_test,__,__,__,__,__,__,__ = dataset_selection(dataset[i])

		model[i] = load(str(model_dir)+'/'+str(model_name))
		__x_test[i] = x_test[(int)(x_test.shape[0] - n_test):(int)(x_test.shape[0])].tolist()
		__y_test[i] = y_test[(int)(y_test.shape[0] - n_test):(int)(y_test.shape[0])].tolist()


		print("\nTesting the %d test :"%test_number)
		print("\n",__x_test[i][test_number])
		print("\nTest output : %d"%__y_test[i][test_number])
		print("\nDecision trees output : \n")
		DT_votes(model[i],np.array(__x_test[i][test_number]).reshape(1,-1))

		n_estimators = model[i].n_estimators
		for k in range(0,n_estimators):
			print("\n\nTree %d"%k)
			DT_decision_path(model[i].estimators_[k],np.array(__x_test[i][test_number]).reshape(1,-1))



def thresholds_quantization(exploration):
	model_dir   = 'trained-models/%s'%(exploration)
	n_models 	= len(os.listdir(model_dir))

	for i in range(0,n_models):
		model_name = os.listdir("trained-models/%s"%(exploration))[i]
		print("\n\nModel : %s\n"%model_name)

		model = load(str(model_dir)+'/'+str(model_name))
		n_estimators = model.n_estimators
		__bits = 0

		for j in range(0,n_estimators):
			feature = model.estimators_[j].tree_.feature
			threshold = model.estimators_[j].tree_.threshold
			for k in range(0,threshold.shape[0]):
				if (threshold[k] == -2):
					threshold[k] = 0

			max_bits = int(np.amax(threshold)).bit_length()
			min_bits = int(np.amin(threshold)).bit_length()
			sign = (np.amin(threshold) < 0)
			bits = max(min_bits,max_bits) + sign
			if (bits > __bits): __bits = bits
			print(threshold)
			print(feature)
			#print("Tree %d, _max = %f, _min = %f, max_bits = %d, min_bits = %d, sign = %d, bits = %d\n"%(j, _max, _min, max_bits, min_bits, sign, bits))

		print(__bits)