#ifndef __DT_LOOP_UTILS_H__
#define __DT_LOOP_UTILS_H__


void rf2loop_prediction(float *input, struct Node **randomForest, int *vote_max_id, int n_estimators, int n_class);
int rf2loop(float *input, struct Node *node);


#endif