#include "pmsis.h"
#include "params.h"
#include "dt-loop.h"
#include "dt-loop-utils.h"



void rf2loop_prediction(INPUT_DATATYPE *input, struct Node **randomForest, int *vote_max_id, int n_estimators, int n_class)
{
	int score[N_CLASS] = {0};
	*vote_max_id = 0;

	for(int i = 0; i < N_TREES; i++) 
	{
		score[rf2loop(input,randomForest[i])]++;
	}

    for (int i = 1; i < N_CLASS; i++)
    { 
    	if (score[*vote_max_id] < score[i]) *vote_max_id = i;
    }
   
}



int rf2loop(INPUT_DATATYPE *input, struct Node *node)
{
    struct Node *current_node = node;
    int cmp = 0;
    while((current_node->value != -2))
    {
        cmp = ((input[current_node->index]) <= (current_node->value)); 
        current_node = (struct Node *) ((cmp * current_node->left) + (!cmp * current_node->right));
    }
    return current_node->right; 
}