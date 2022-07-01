#ifndef __DT_NAIVE_H__
#define __DT_NAIVE_H__

#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */

#define INPUT_DATATYPE uint16_t
#define THRESHOLD_DATATYPE float

void randomForest(uint16_t *input, int *class_rf_idx);

#endif 


#ifdef  VEHICLE

/* VEHICLE Dataset */

#define INPUT_DATATYPE uint16_t
#define THRESHOLD_DATATYPE float

void randomForest(uint16_t *input, int *class_rf_idx);

#endif 



#endif
