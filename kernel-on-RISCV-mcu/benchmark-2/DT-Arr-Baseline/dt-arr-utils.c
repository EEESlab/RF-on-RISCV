#include "pmsis.h"
#include "params.h"
#include "dt-arr-baseline.h"
#include "dt-arr-utils.h"


// printf("decision node %d : (x_test[%d] = %d) <= %f)\n",current_node,current_feature,*((INPUT_DATATYPE *)(input_addr + current_feature)),*((THRESHOLD_DATATYPE *)(threshold_addr + current_node)));


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
