from utils_double_buffering import opt_l1_buffer
from joblib import dump, load

opt_l1_buffer(load('trained-models/benchmark-2/rf-96trees-mfeat-factors.joblib'))
