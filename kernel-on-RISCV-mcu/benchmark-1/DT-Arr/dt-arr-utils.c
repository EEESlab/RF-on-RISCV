#include "pmsis.h"
#include "params.h"

#if defined(BASELINE)
#include "dt-arr-baseline.h"
#elif defined(SHIFTLESS)
#include "dt-arr-shiftless.h"
#elif defined(STALLFREE)
#include "dt-arr-stallfree.h"
#endif

#include "dt-arr-utils.h"


// printf("decision node %d : (x_test[%d] = %d) <= %f)\n",current_node,current_feature,*((INPUT_DATATYPE *)(input_addr + current_feature)),*((THRESHOLD_DATATYPE *)(threshold_addr + current_node)));


void rf_arr(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   **features,
    THRESHOLD_DATATYPE  **threshold,
    CHILDREN_DATATYPE   **children_left,
    CHILDREN_DATATYPE   **children_right,
    int *vote_max_id

)
{
    *vote_max_id = 0;
    int score[N_CLASS] = {0};
    
    for(int i = 0; i < N_TREES; i++) 
    {
        #if defined(BASELINE)
        score[dt_arr_baseline(input, features[i], threshold[i], children_left[i], children_right[i])]++;
        #elif defined(SHIFTLESS)
        score[dt_arr_shiftless(input, features[i], threshold[i], children_left[i])]++;
        #elif defined(STALLFREE)
        score[dt_arr_stallfree(input, features[i], threshold[i], children_left[i])]++;
        #endif
    }

    for (int i = 1; i < N_CLASS; i++)
    { 
        if (score[*vote_max_id] < score[i]) *vote_max_id = i;
    }
}


#if defined(BASELINE)


CHILDREN_DATATYPE dt_arr_baseline(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children_left,
    CHILDREN_DATATYPE   *children_right

)
{
    uint32_t current_feature = features[0];
    uint32_t current_node = 0;
    
    do{
        uint32_t cmp = (input[current_feature] <= threshold[current_node]);
        current_node = cmp * children_left[current_node] + !cmp * children_right[current_node];
        current_feature = features[current_node];
    } while(current_feature != (WHILE_CONDITION));
    
    return children_left[current_node];
}


#elif defined(SHIFTLESS)


CHILDREN_DATATYPE dt_arr_v1(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

)
{
    uint32_t input_addr = (uint32_t) &input[0];
    uint32_t threshold_addr = (uint32_t) &threshold[0];
    uint32_t features_addr = (uint32_t) &features[0];
    uint32_t children_addr = (uint32_t) &children[0];

    int32_t current_feature = features[0];
    uint32_t current_node = 0;
    
    do{
        if (*((INPUT_DATATYPE *)(input_addr + current_feature)) <= *((THRESHOLD_DATATYPE *)(threshold_addr + current_node)))
        {
            current_node = *((CHILDREN_DATATYPE *)(children_addr + current_node));
        }
        else
        {
            current_node = *((CHILDREN_DATATYPE *)(children_addr + (current_node + CHILDREN_BYTES)));
        }
        current_feature = *((FEATURES_DATATYPE *)(features_addr + (current_node >> NODE2FEAT_DTYPE)));
    
    } while(current_feature != (WHILE_CONDITION));

    return (*(CHILDREN_DATATYPE *)(children_addr + current_node));

}



CHILDREN_DATATYPE dt_arr_shiftless(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

)
{
    uint32_t input_addr = (uint32_t) &input[0];
    uint32_t threshold_addr = (uint32_t) &threshold[0];
    uint32_t features_addr = (uint32_t) &features[0];
    uint32_t children_addr = (uint32_t) &children[0];
    
    uint32_t current_feature = features[0];
    uint32_t current_node = 0;
    
    do{
        uint32_t cmp = (*((INPUT_DATATYPE *)(input_addr + current_feature))  <= *((THRESHOLD_DATATYPE *)(threshold_addr + current_node)));
        current_node = cmp * (*(CHILDREN_DATATYPE *)(children_addr + current_node)) + !cmp * (*(CHILDREN_DATATYPE *)(children_addr + current_node + CHILDREN_BYTES));
        current_feature = *((FEATURES_DATATYPE *)(features_addr + (current_node >> NODE2FEAT_DTYPE)));
    } while(current_feature != (WHILE_CONDITION));

    return (*(CHILDREN_DATATYPE *)(children_addr + current_node));
}


#elif defined(STALLFREE)


CHILDREN_DATATYPE dt_arr_stallfree(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

)
{
    uint32_t input_addr = (uint32_t) &input[0];
    uint32_t threshold_addr = (uint32_t) &threshold[0];
    uint32_t features_addr = (uint32_t) &features[0];
    uint32_t children_addr = (uint32_t) &children[0];

    uint32_t current_feature = features[0];
    uint32_t current_node = 0;
    
    do{
        THRESHOLD_DATATYPE thresh_curr = *((THRESHOLD_DATATYPE *)(threshold_addr + current_node));
        INPUT_DATATYPE input_curr = *((INPUT_DATATYPE *)(input_addr + current_feature));
        uint32_t cmp = (input_curr > thresh_curr);
        BIGNODE_DATATYPE big_node = *((BIGNODE_DATATYPE *)(children_addr + current_node));
        current_node = (CHILDREN_DATATYPE)(big_node >> (cmp << CMP_SHIFT));
        current_feature = *((FEATURES_DATATYPE *)(features_addr + (current_node >> NODE2FEAT_DTYPE)));
    } while(current_feature != (WHILE_CONDITION));

    return (*(CHILDREN_DATATYPE *)(children_addr + current_node));
}


#endif