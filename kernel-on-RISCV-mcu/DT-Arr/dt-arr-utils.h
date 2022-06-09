#ifndef __DT_ARR_UTILS_H__
#define __DT_ARR_UTILS_H__  


void rf_arr_vehicle(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   **features,
    THRESHOLD_DATATYPE  **threshold,
    CHILDREN_DATATYPE   **children,
    int *vote_max_id

);


void rf_arr_mfeat_factors(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   **features,
    THRESHOLD_DATATYPE  **threshold,
    CHILDREN_DATATYPE   **children,
    int *vote_max_id,
    int *score

);


uint16_t dt_arr(

    float *input, 
    int8_t *features,
    float *threshold,
    uint16_t *children

);


CHILDREN_DATATYPE dt_arr_v0(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

);


CHILDREN_DATATYPE dt_arr_v1(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

);


CHILDREN_DATATYPE dt_arr_opt(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

);


#endif