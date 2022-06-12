#include "pmsis.h"
#include "params.h"
#include "dt-arr-utils.h"

void rf_arr_vehicle(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   **features,
    THRESHOLD_DATATYPE  **threshold,
    CHILDREN_DATATYPE   **children,
    int *vote_max_id

)
{
    *vote_max_id = 0;
    int score[N_CLASS] = {0};
    
    #ifdef UNROLL
    
    score[dt_arr_opt(input, features[0],  threshold[0],  children[0])]++;
    score[dt_arr_opt(input, features[1],  threshold[1],  children[1])]++;
    score[dt_arr_opt(input, features[2],  threshold[2],  children[2])]++;
    score[dt_arr_opt(input, features[3],  threshold[3],  children[3])]++;
    score[dt_arr_opt(input, features[4],  threshold[4],  children[4])]++;
    score[dt_arr_opt(input, features[5],  threshold[5],  children[5])]++;
    score[dt_arr_opt(input, features[6],  threshold[6],  children[6])]++;
    score[dt_arr_opt(input, features[7],  threshold[7],  children[7])]++;
    score[dt_arr_opt(input, features[8],  threshold[8],  children[8])]++;
    score[dt_arr_opt(input, features[9],  threshold[9],  children[9])]++;
    score[dt_arr_opt(input, features[10], threshold[10], children[10])]++;
    score[dt_arr_opt(input, features[11], threshold[11], children[11])]++;
    score[dt_arr_opt(input, features[12], threshold[12], children[12])]++;
    score[dt_arr_opt(input, features[13], threshold[13], children[13])]++;
    score[dt_arr_opt(input, features[14], threshold[14], children[14])]++;
    score[dt_arr_opt(input, features[15], threshold[15], children[15])]++;
    
    #else
    
    for(int i = 0; i < N_TREES; i++) 
    {
        #if defined RF2ARR_V0
        score[dt_arr_v0(input, features[i], threshold[i], children[i])]++;
        #elif defined RF2ARR_V1
        score[dt_arr_v1(input, features[i], threshold[i], children[i])]++;
        #elif defined RF2ARR_V2
        score[dt_arr_v2(input, features[i], threshold[i], children[i])]++;
        #elif defined RF2ARR_OPT
        score[dt_arr_opt(input, features[i], threshold[i], children[i])]++;
        #endif
    }

    #endif

    for (int i = 1; i < N_CLASS; i++)
    { 
        if (score[*vote_max_id] < score[i]) *vote_max_id = i;
    }
   
}



void rf_arr_mfeat_factors(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   **features,
    THRESHOLD_DATATYPE  **threshold,
    CHILDREN_DATATYPE   **children,
    int *vote_max_id,
    int *score

)
{
    *vote_max_id = 0;
    for (int i = 0; i < N_CLASS; i++) score[i] = 0;
    
    #ifdef UNROLL
    
    score[dt_arr_opt(input, features[0],  threshold[0],  children[0])]++;
    score[dt_arr_opt(input, features[1],  threshold[1],  children[1])]++;
    score[dt_arr_opt(input, features[2],  threshold[2],  children[2])]++;
    score[dt_arr_opt(input, features[3],  threshold[3],  children[3])]++;
    score[dt_arr_opt(input, features[4],  threshold[4],  children[4])]++;
    score[dt_arr_opt(input, features[5],  threshold[5],  children[5])]++;
    score[dt_arr_opt(input, features[6],  threshold[6],  children[6])]++;
    score[dt_arr_opt(input, features[7],  threshold[7],  children[7])]++;
    score[dt_arr_opt(input, features[8],  threshold[8],  children[8])]++;
    score[dt_arr_opt(input, features[9],  threshold[9],  children[9])]++;
    score[dt_arr_opt(input, features[10], threshold[10], children[10])]++;
    score[dt_arr_opt(input, features[11], threshold[11], children[11])]++;
    score[dt_arr_opt(input, features[12], threshold[12], children[12])]++;
    score[dt_arr_opt(input, features[13], threshold[13], children[13])]++;
    score[dt_arr_opt(input, features[14], threshold[14], children[14])]++;
    score[dt_arr_opt(input, features[15], threshold[15], children[15])]++;
    
    #else
    
    for(int i = 0; i < N_TREES; i++) 
    {
        #if defined RF2ARR_V0
        score[dt_arr_v0(input, features[i], threshold[i], children[i])]++;
        #elif defined RF2ARR_V1
        score[dt_arr_v1(input, features[i], threshold[i], children[i])]++;
        #elif defined RF2ARR_V2
        score[dt_arr_v2(input, features[i], threshold[i], children[i])]++;
        #elif defined RF2ARR_OPT
        score[dt_arr_opt(input, features[i], threshold[i], children[i])]++;
        #endif
    }

    #endif

    for (int i = 1; i < N_CLASS; i++)
    { 
        if (score[*vote_max_id] < score[i]) *vote_max_id = i;
    }
   
}



uint16_t dt_arr_v2(

    float *input, 
    int8_t *features,
    float *threshold,
    uint16_t *children

)
{
    uint32_t input_addr = (uint32_t) &input[0];
    uint32_t threshold_addr = (uint32_t) &threshold[0];
    uint32_t features_addr = (uint32_t) &features[0];
    uint32_t children_addr = (uint32_t) &children[0];

    int32_t current_feature = features[0];
    uint32_t current_node = 0;
    
    do{
        if (*((float *)(input_addr + current_feature)) <= *((float *)(threshold_addr + current_node)))
        {
            current_node = *((uint16_t *)(children_addr + current_node));
        }
        else
        {
            current_node = *((uint16_t *)(children_addr + (current_node + 2)));
        }
        current_feature = *((int8_t *)(features_addr + (current_node >> 2)));
    
    } while(current_feature != (-8));

    return (uint16_t) (*((uint32_t *)(children_addr + current_node)) >> 18);

}



CHILDREN_DATATYPE dt_arr_v0(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

)
{
    uint32_t current_feature = features[0];
    uint32_t current_node = 0;
    
    do{
        uint32_t cmp = (input[current_feature] <= threshold[current_node]);
        current_node = cmp * children[2*current_node] + !cmp * children[2*current_node + 1];
        current_feature = features[current_node];
    } while(current_feature != (WHILE_CONDITION));
    
    return children[2*current_node];
}



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
    
    uint32_t current_feature = features[0];
    uint32_t current_node = 0;
    
    do{
        uint32_t cmp = (*((INPUT_DATATYPE *)(input_addr + (current_feature << FEAT2INPUT_SHIFT))) <= *((THRESHOLD_DATATYPE *)(threshold_addr + current_node)));
        current_node = cmp * (*(CHILDREN_DATATYPE *)(children_addr + current_node)) + !cmp * (*(CHILDREN_DATATYPE *)(children_addr + current_node + 2));
        current_feature = *((FEATURES_DATATYPE *)(features_addr + (current_node >> NODE2FEAT_SHIFT)));
    } while(current_feature != (WHILE_CONDITION));

    return (*(CHILDREN_DATATYPE *)(children_addr + current_node))>>2;
}



CHILDREN_DATATYPE dt_arr_opt(

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
        INPUT_DATATYPE input_curr = *((INPUT_DATATYPE *)(input_addr + (current_feature << FEAT2INPUT_SHIFT)));
        uint32_t cmp = (input_curr > thresh_curr);
        BIGNODE_DATATYPE big_node = *((BIGNODE_DATATYPE *)(children_addr + current_node));
        current_node = (CHILDREN_DATATYPE)(big_node >> (cmp << CMP_SHIFT));
        current_feature = *((FEATURES_DATATYPE *)(features_addr + (current_node >> NODE2FEAT_SHIFT)));

    } while(current_feature != (WHILE_CONDITION));

    return (CHILDREN_DATATYPE) (*((BIGNODE_DATATYPE *)(children_addr + current_node)) >> 18);

}