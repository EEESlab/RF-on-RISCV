from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from joblib import dump, load
import numpy as np
import os

from utils_dataset import dataset_selection


def rf_train(params = {"n_estimators":1}, dataset = ['digits'], exploration = 'test', scaler = False, feature_range = (0,255), input_bits = 16):
	n_dataset = len(dataset)
	accuracy = np.zeros(n_dataset)
	n_features = np.zeros(n_dataset)
	n_classes = np.zeros(n_dataset)
	model = []

	model_dir = 'trained-models/%s'%(exploration)
	os.makedirs(model_dir, exist_ok = True) 

	for i in range(0,n_dataset):
		__dataset = dataset[i]
		model_name 	= '/rf-%dtrees-%s.joblib'%(params["n_estimators"],__dataset)

		x_train, x_test, y_train, y_test, n_classes[i], n_features[i] = dataset_selection(dataset = __dataset, scaler = scaler, feature_range = feature_range, input_bits = input_bits)

		if (os.path.isfile(str(model_dir)+str(model_name))):
			model.append(load(str(model_dir)+str(model_name)))
		else:
			model.append(RandomForestClassifier(random_state = 12))
			model[i].set_params(**params)
			model[i].fit(x_train, y_train)
			dump(model[i],str(model_dir)+str(model_name))

		accuracy[i] = accuracy_score(y_test, model[i].predict(x_test)) * 100

	return model, accuracy, x_test, y_test, n_classes, n_features
