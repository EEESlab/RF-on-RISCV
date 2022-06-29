#ifndef __DT_REC_UTILS_H__
#define __DT_REC_UTILS_H__


int dt_rec(INPUT_DATATYPE *input, struct Node *decision_tree);
void rf_rec(INPUT_DATATYPE *input, struct Node **randomForest, int *vote_max_id, int n_estimators, int n_class);


#endif