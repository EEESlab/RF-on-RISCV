#ifndef __DT_REC_UTILS_H__
#define __DT_REC_UTILS_H__


int dt_rec(float *input, struct Node *decision_tree);
void rf_rec(float *input, struct Node **randomForest, int *vote_max_id, int n_estimators, int n_class);


#endif