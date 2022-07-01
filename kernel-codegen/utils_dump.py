from utils_graph import rfNodeCount
import numpy as np



uint_dtype = ['uint8_t','uint16_t','uint32_t']
int_dtype = ['int8_t','int16_t','int32_t']
int_bytewidth = [1, 2, 4]



def bytewidth(dtype):
	if dtype == 'uint8_t' or dtype == 'int8_t':
		bytewidth = 1
	if dtype == 'uint16_t' or dtype == 'int16_t':
		bytewidth = 2
	if dtype == 'uint32_t' or dtype == 'int32_t':
		bytewidth = 4
	if dtype == 'float':
		bytewidth = 4

	return bytewidth



def input_dtype(x_input):
	in_int = (x_input.astype(int) == x_input).all()
	in_max_bits = int(np.amax(x_input)).bit_length()
	in_min_bits = int(np.absolute(np.amin(x_input))).bit_length()
	sign = (np.amin(x_input) < 0)
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

	return in_int, in_dtype, in_bits, in_bytewidth



def feature_dtype(model):
	n_dt = model.n_estimators
	f_dtype = ''
	f_bytewidth = 0
	f_bits = 0

	for i in range(0,n_dt):
		__f = model.estimators_[i].tree_.feature
		__f_int = (__f.astype(int) == __f).all()
		__f_sign = (np.amin(__f) < 0)
		max_f_bits = int(np.amax(__f)).bit_length()
		min_f_bits = int(np.absolute(np.amin(__f))).bit_length()
		__f_bits = max(max_f_bits,min_f_bits) + __f_sign

		if __f_int == True:
			if (0 < __f_bits <= 8):
				__f_bytewidth = 1
				if (__f_sign == 0):
					__f_dtype = 'uint8_t'
				else:
					__f_dtype = 'int8_t'
			
			elif (8 < __f_bits <= 16):
				__f_bytewidth = 2
				if (__f_sign == 0):
					__f_dtype = 'uint16_t'
				else:
					__f_dtype = 'int16_t'
			
			elif (16 < __f_bits):
				__f_bytewidth = 4
				if (__f_sign == 0):
					__f_dtype = 'uint32_t'
				else:
					__f_dtype = 'int32_t'
		else:
			raise Exception('Float Features: Error!')

		if (__f_bytewidth > f_bytewidth): 
			f_bytewidth = __f_bytewidth
			f_dtype = __f_dtype

		if (__f_bits > f_bits): 
			f_bits = __f_bits

		f_int = __f_int

	return f_int, f_dtype, f_bits, f_bytewidth



def threshold_dtype(model):
	n_dt = model.n_estimators
	thr_dtype = ''
	thr_bytewidth = 0
	thr_bits = 0

	for i in range(0,n_dt):
		__thr = model.estimators_[i].tree_.threshold
		__thr_int = (__thr.astype(int) == __thr).all()
		__thr_sign = (np.amin(__thr) < 0)
		max_f_bits = int(np.amax(__thr)).bit_length()
		min_f_bits = int(np.absolute(np.amin(__thr))).bit_length()
		__thr_bits = max(max_f_bits,min_f_bits) + __thr_sign

		if __thr_int == True:
			if (0 < __thr_bits <= 8):
				__thr_bytewidth = 1
				if (__thr_sign == 0):
					__thr_dtype = 'uint8_t'
				else:
					__thr_dtype = 'int8_t'
			
			elif (8 < __thr_bits <= 16):
				__thr_bytewidth = 2
				if (__thr_sign == 0):
					__thr_dtype = 'uint16_t'
				else:
					__thr_dtype = 'int16_t'
			
			elif (16 < __thr_bits):
				__thr_bytewidth = 4
				if (__thr_sign == 0):
					__thr_dtype = 'uint32_t'
				else:
					__thr_dtype = 'int32_t'
		else:
			__thr_dtype = 'float'
			__thr_bytewidth = 4

		if 'float' == __thr_dtype:
			thr_bytewidth = __thr_bytewidth
			thr_dtype = __thr_dtype
		else:
			if (__thr_bytewidth > thr_bytewidth): 
				thr_bytewidth = __thr_bytewidth
				thr_dtype = __thr_dtype
			if (__thr_bits > thr_bits): 
				thr_bits = __thr_bits

		thr_int = __thr_int

	return thr_int, thr_dtype, thr_bits, thr_bytewidth



def children_dtype(model):
	max_nodes = int(np.amax(rfNodeCount(model)))
	child_bits = max_nodes.bit_length()

	if (0 < child_bits <= 8):
		child_dtype = 'uint8_t'
		child_bytewidth = 1
	elif (8 < child_bits <= 16):
		child_dtype = 'uint16_t'
		child_bytewidth = 2
	elif (16 < child_bits):
		child_dtype = 'uint32_t'
		child_bytewidth = 4

	return child_dtype, child_bits, child_bytewidth



def class_dtype(classes):
	c_max_bits = int(np.amax(classes)).bit_length()
	c_min_bits = int(np.absolute(np.amin(classes))).bit_length()
	c_sign = (np.amin(classes) < 0)
	c_bits = max(c_min_bits,c_max_bits) + c_sign
	
	if (0 < c_bits <= 8):
		c_bytewidth = 1
		if (c_sign == 0):
			c_dtype = 'uint8_t'
		else:
			c_dtype = 'int8_t'
	
	elif (8 < c_bits <= 16):
		c_bytewidth = 2
		if (c_sign == 0):
			c_dtype = 'uint16_t'
		else:
			c_dtype = 'int16_t'
	
	elif (16 < c_bits):
		c_bytewidth = 4
		if (c_sign == 0):
			c_dtype = 'uint32_t'
		else:
			c_dtype = 'int32_t'		

	return c_dtype, c_bits, c_bytewidth



def feature_to_unsigned_int(model, debug = False):
	n_dt = model.n_estimators
	f = [None] * n_dt
	f_dtype = ''
	f_bytewidth = 0
	f_bits = 0
	f_limit = model.n_features_

	for i in range(0,n_dt):
		__f = model.estimators_[i].tree_.feature
	
		for j in range(0,__f.shape[0]):
			if __f[j] == -2:
				__f[j] = f_limit

		f[i] = __f
		__f_max = np.amax(__f)
		__f_min = np.amin(__f)
		max_f_bits = int(__f_max).bit_length()
		min_f_bits = int(np.absolute(__f_min)).bit_length()
		__f_bits = max(max_f_bits,min_f_bits)
	
		if (0 < __f_bits <= 8):
			__f_dtype = 'uint8_t'
			__f_bytewidth = 1
		elif (8 < __f_bits <= 16):
			__f_dtype = 'uint16_t'
			__f_bytewidth = 2
		elif (16 < __f_bits):
			__f_dtype = 'uint32_t'
			__f_bytewidth = 4

		if (__f_bytewidth > f_bytewidth): 
			f_bytewidth = __f_bytewidth
			f_dtype = __f_dtype

		if (__f_bits > f_bits): 
			f_bits = __f_bits


	if (debug == True):
		print("\n\n 	Feature Optimization to Unsigned Integer\n")
		print("Feature bits : %d, Feature Bytes = %d, Feature Data Type : %s\n\n"%(f_bits,f_bytewidth,f_dtype))

	return f, f_dtype, f_bytewidth, f_bits, f_limit



def threshold_to_unsigned_int(model, debug = False):
	n_dt = model.n_estimators
	thr = [None] * n_dt
	thr_dtype = ''
	thr_bytewidth = 0
	thr_bits = 0

	for i in range(0,n_dt):
		__thr = model.estimators_[i].tree_.threshold
	
		for j in range(0,__thr.shape[0]):
			if __thr[j] == -2:
				__thr[j] = 100

		__thr = np.int32(__thr)
		thr[i] = __thr
		__thr_max = np.amax(__thr)
		__thr_min = np.amin(__thr)
		max_thr_bits = int(__thr_max).bit_length()
		min_thr_bits = int(np.absolute(__thr_min)).bit_length()
		__thr_bits = max(max_thr_bits,min_thr_bits)
	
		if (0 < __thr_bits <= 8):
			__thr_dtype = 'uint8_t'
			__thr_bytewidth = 1
		elif (8 < __thr_bits <= 16):
			__thr_dtype = 'uint16_t'
			__thr_bytewidth = 2
		elif (16 < __thr_bits):
			__thr_dtype = 'uint32_t'
			__thr_bytewidth = 4

		if (__thr_bytewidth > thr_bytewidth): 
			thr_bytewidth = __thr_bytewidth
			thr_dtype = __thr_dtype

		if (__thr_bits > thr_bits): 
			thr_bits = __thr_bits

	if (debug == True):
		print("\n\n 	Threshold Optimization to Unsigned Integer\n")
		print("Threshold bits : %d, Threshold Bytes = %d, Threshold Data Type : %s\n\n"%(thr_bits,thr_bytewidth,thr_dtype))

	return thr, thr_dtype, thr_bytewidth, thr_bits
