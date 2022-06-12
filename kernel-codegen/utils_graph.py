from ortools.linear_solver import pywraplp
from sklearn import tree 
import numpy as np
import graphviz



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
