from RF_train import rf_train
from RF_dump import dump_RF

from joblib import dump, load


rf_train(params = {"n_estimators":192}, dataset = ['cifar10'], exploration = 'benchmark-3', scaler = False)
# dump_RF(exploration = "benchmark-2", kernel = "DT-Arr-Baseline-Quantized", scaler = True, double_buffering = True)
# dump_RF(exploration = "benchmark-2", kernel = "DT-Arr-Baseline", scaler = True, double_buffering = True)
