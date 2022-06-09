#include "pmsis.h"
#include "params.h"
#include "dt-rec.h"
#include "dt-rec-utils.h"

int dt_rec(float *input, struct Node *decision_tree)
{

	if(input[decision_tree->index] <= decision_tree->value)
    {
        if(decision_tree->left != 0)
        {
            return dt_rec(input,decision_tree->left);
        }
        else
        {
            return decision_tree->left_leaf;
        }
    } else {
        if(decision_tree->right != 0)
        {
            return dt_rec(input, decision_tree->right);
        }
        else
        {
            return decision_tree->right_leaf;
        }
    }
}

void rf_rec(float *input, struct Node **randomForest, int *vote_max_id, int n_estimators, int n_class)
{
	int score[N_CLASS] = {0};
	*vote_max_id = 0;

	for(int i = 0; i < N_TREES; i++) 
	{
		score[dt_rec(input,randomForest[i])]++;
	}

    for (int i = 1; i < N_CLASS; i++)
    { 
    	if (score[*vote_max_id] < score[i]) *vote_max_id = i;
    }
    
}
