from sklearn.datasets import make_classification, fetch_openml, load_digits
from sklearn.model_selection import train_test_split
from keras.datasets import cifar10, cifar100, mnist, fashion_mnist
from extra_keras_datasets import usps

import numpy as np
import pandas as pd
import sys
import os



dataset_supported = [

	'synthetic_control',
	'vehicle',
	'qsar-biodeg' ,
	'ozone-level-8hr',
	'vowel',
	'LED-display-domain-7digit' ,
	'steel-plates-fault',
	'hill-valley',
	'cnae-9' ,
	'cardiotocography',
	'autoUniv-au6-400',
	'autoUniv-au6-1000' ,
	'mfeat-factors',
	'semeion',
	'one-hundred-plants-shape'

]



def dataset_spec(x):
	# f: features
	# in:input

	f = x.shape[1]
	f_int = True
	f_bits = f.bit_length() + 1
	
	if f_int == True:
		if (0 < f_bits <= 8):
			f_dtype = 'int8_t'
			f_bytewidth = 1
		elif (8 < f_bits <= 16):
			f_dtype = 'int16_t'
			f_bytewidth = 2
		elif (16 < f_bits):
			f_dtype = 'int32_t'
			f_bytewidth = 4

	in_int = (x.astype(int) == x).all()
	in_max_bits = int(np.amax(x)).bit_length()
	in_min_bits = int(np.amin(x)).bit_length()
	sign = (np.amin(x) < 0)
	in_bits = max(in_min_bits,in_max_bits) + sign

	if in_int == True:
		if (0 < in_bits <= 8):
			in_bytewidth = 1
			if (sign == 0):
				in_dtype = 'uint8_t'
			else:
				in_dtype = 'int8_t'
		
		elif (8 < in_bits <= 16):
			in_bytewidth = 2
			if (sign == 0):
				in_dtype = 'uint16_t'
			else:
				in_dtype = 'int16_t'
		
		elif (16 < in_bits):
			in_bytewidth = 4
			if (sign == 0):
				in_dtype = 'uint32_t'
			else:
				in_dtype = 'int32_t'
	else:
		in_bytewidth = 4
		in_dtype = 'float'

	return f_int, f_dtype, f_bits, f_bytewidth, in_int, in_dtype, in_bits, in_bytewidth



def class_spec(classes):
	c_int = True
	c_max_bits = int(classes-1).bit_length()
	c_min_bits = int(0).bit_length()
	c_bits = max(c_min_bits,c_max_bits)

	if (0 < c_bits <= 8):
		c_bytewidth = 1
		c_dtype = 'uint8_t'
	elif (8 < c_bits <= 16):
		c_bytewidth = 2
		c_dtype = 'uint16_t'
	elif (16 < c_bits):
		c_bytewidth = 4
		c_dtype = 'uint32_t'

	return c_int, c_dtype, c_bits, 	c_bytewidth



def dataset_selection(dataset, version = 1, train_size = 0.7):

	if (dataset == 'fashion-mnist'):

		(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()
		n_features = x_test.shape[1] * x_test.shape[2] 

	elif (dataset == 'mnist'):

		(x_train, y_train), (x_test, y_test) = mnist.load_data()
		n_features = x_test.shape[1] * x_test.shape[2] 

	elif (dataset == 'cifar10'):

		(x_train, y_train), (x_test, y_test) = cifar10.load_data()
		n_features = x_test.shape[1] * x_test.shape[2] * x_test.shape[3]

	elif (dataset == 'cifar100'):

		(x_train, y_train), (x_test, y_test) = cifar100.load_data()
		n_features = x_test.shape[1] * x_test.shape[2] * x_test.shape[3]

	elif (dataset == 'usps'):

		(x_train, y_train), (x_test, y_test) = usps.load_data()
		n_features = x_test.shape[1] * x_test.shape[2]

	elif (dataset in dataset_supported):

		data_openml = fetch_openml(dataset, version = version, as_frame = True)
		df = pd.DataFrame(data_openml.data, columns = data_openml.feature_names)
		df['Class'] = pd.Series(data_openml.target)

		if (dataset == 'synthetic_control'):
			mapping = {'Normal':0, 'Cyclic':1, 'Increasing_trend':2, 'Decreasing_trend':3, 'Upward_shift':4, 'Downward_shift':5}
			df['Class'] = df['Class'].map(mapping)

		if (dataset == 'vehicle'):
			mapping = {'van' : 0, 'saab' : 1, 'bus' : 2, 'opel' : 3}
			df['Class'] = df['Class'].map(mapping)

		# if (dataset == 'qsar-biodeg'):
		# if (dataset == 'ozone-level-8hr'):

		if (dataset == 'vowel'):
			mapping = {'hId' : 0, 'hid' : 1, 'hOd' : 2, 'had' : 3, 'hUd' : 4, 'hAd' : 5, 'hed' : 6, 'hYd' : 7, 'hud' : 8, 'hod' : 9, 'hEd' : 10}
			mapping_0 = {'Penny' : 0, 'Nick' : 1, 'Wendy' : 2, 'Jo'  : 3, 'Kate' : 4, 'Bill'  : 5, 'Rich'  : 6, 'Mike'  : 7, 'Andrew'  : 8, 'David'  : 9, 'Rose' : 10, 'Sarah' : 11, 'Mark' : 12, 'Tim' : 13, 'Sue' : 14}
			mapping_1 = {'Male' : 0, 'Female' : 1}
			df['Class'] = df['Class'].map(mapping)
			df['Speaker_Number'] = df['Speaker_Number'].map(mapping_0)
			df['Sex'] = df['Sex'].map(mapping_1)

		if (dataset == 'LED-display-domain-7digit'):
			mapping = {'1' : 0, '2' : 1, '3' : 2, '4' : 3, '5' : 4, '6' : 5, '7' : 6, '8' : 7, '9' : 8, '10' : 9}
			df['Class'] = df['Class'].map(mapping)

		if (dataset == 'steel-plates-fault'):
			mapping = {'Pastry' : 1, 'Z_Scratch' : 2, 'K_Scratch' : 3, 'Stains' : 4, 'Dirtiness' : 5, 'Bumps' : 6, 'Other_Faults' : 7 }
			df['Class'] = df['Class'].map(mapping)
		
		# if (dataset == 'hill-valley'):
		# if (dataset == 'cnae-9'):
		# if (dataset == 'cardiotocography'):

		if (dataset == 'autoUniv-au6-400'):
			mapping_0 = {'v1' : 1, 'v2' : 2, 'v3' : 3 }
			mapping = {'class1' : 0, 'class2' : 1, 'class3' : 2, 'class4' : 3, 'class5' : 4, 'class6' : 5, 'class7' : 6, 'class8' : 7}
			df['V12'] = df['V12'].map(mapping_0)
			df['V31'] = df['V31'].map(mapping_0)
			df['V40'] = df['V40'].map(mapping_0)
			df['Class'] = df['Class'].map(mapping)

		if (dataset == 'autoUniv-au6-1000'):
			mapping_0 = {'v1' : 1, 'v2' : 2, 'v3' : 3 }
			mapping = {'class1' : 1, 'class2' : 2, 'class3' : 3, 'class4' : 4, 'class5' : 5, 'class6' : 6, 'class7' : 7, 'class8' : 8}
			df['V12'] = df['V12'].map(mapping_0)
			df['V31'] = df['V31'].map(mapping_0)
			df['V40'] = df['V40'].map(mapping_0)
			df['Class'] = df['Class'].map(mapping)

		if (dataset == 'mfeat-factors'):
			mapping = {'1' : 0, '2' : 1, '3' : 2, '4' : 3, '5' : 4, '6' : 5, '7' : 6, '8' : 7, '9' : 8, '10' : 9}
			df['Class'] = df['Class'].map(mapping)

		# if (dataset == 'semeion'):
		# if (dataset == 'one-hundred-plants-shape'):

		x = df.loc[:, df.columns != 'Class']
		y = df.loc[:, df.columns == 'Class']
		x_train, x_test, y_train, y_test = train_test_split(x, y, train_size = train_size, random_state = 12)

		x_train = x_train.to_numpy() 
		y_train = y_train.to_numpy() 
		x_test  = x_test.to_numpy()
		y_test  = y_test.to_numpy()

		n_features = x_test.shape[1]

	elif dataset == 'digits':

		(x, y) = load_digits(return_X_y = True)
		
		x_train, x_test, y_train, y_test = train_test_split(x, y, train_size = train_size, random_state = 12)
		n_features = x_test.shape[1]

	__, f_dtype, __, f_bytewidth, in_int, in_dtype, __, in_bytewidth = dataset_spec(np.concatenate((x_train,x_test)))
	n_classes  = np.unique(y_test).shape[0]
	y_test  = y_test.ravel()
	y_train = y_train.ravel()
	
	return x_train, x_test, y_train, y_test, n_classes, n_features, f_dtype, f_bytewidth, in_int, in_dtype, in_bytewidth