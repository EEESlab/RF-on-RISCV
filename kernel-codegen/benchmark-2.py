from RF_train import rf_train
from utils_graph import thresholds_quantization
from RF_dump import dump_RF
from utils_graph import RF_check
 	

#thresholds_quantization(exploration = "benchmark-0")

#print(rf_train(params = {"n_estimators":16}, dataset = ['mfeat-factors'], exploration = 'test', scaler = True))
#thresholds_quantization(exploration = "test")

#dump_RF(exploration = "test", kernel = "dump_DT_Arr_Baseline_Opt_L1", double_buffering = False)