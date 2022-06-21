#ifndef __DT_ARR_UTILS_H__
#define __DT_ARR_UTILS_H__  


void rf_arr(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   **features,
    THRESHOLD_DATATYPE  **threshold,
    CHILDREN_DATATYPE   **children_left,
    CHILDREN_DATATYPE   **children_right,
    int *vote_max_id

);



CHILDREN_DATATYPE dt_arr_v1(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

);



CHILDREN_DATATYPE dt_arr_baseline(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children_left,
    CHILDREN_DATATYPE   *children_right

);



CHILDREN_DATATYPE dt_arr_shiftless(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

);



CHILDREN_DATATYPE dt_arr_stallfree(

    INPUT_DATATYPE      *input, 
    FEATURES_DATATYPE   *features,
    THRESHOLD_DATATYPE  *threshold,
    CHILDREN_DATATYPE   *children

);


#endif