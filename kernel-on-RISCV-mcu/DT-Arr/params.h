#ifndef __PARAMS_H__
#define __PARAMS_H__


#define N_CORES (1)
#define STACK_SIZE (512)


//#define DEBUG

//#define STATS
//#define STATS_FPU

//#define VEHICLE
//#define MFEAT_FACTORS

//#define RF2ARR_V0
//#define RF2ARR_V1
//#define RF2ARR_OPT

//#define UNROLL

#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Accuracy on Testing Set = 80.000000%*/
/* Accuracy on Real Testing Set = 74.056604%*/

#define N_TREES 16
#define N_CLASS 4
#define N_TEST 10
#define N_LOOP 10
#define DIM 18

#define INPUT_DATATYPE 		float
#define FEATURES_DATATYPE	int8_t
#define THRESHOLD_DATATYPE	float
#define CHILDREN_DATATYPE	uint16_t

#define BIGNODE_DATATYPE	uint32_t

#define WHILE_CONDITION (-8)
#define FEAT2INPUT_SHIFT (0)
#define NODE2FEAT_SHIFT  (2)
#define CMP_SHIFT  		 (4)

#endif


#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */
/* Accuracy on Testing Set = 100.000000%*/
/* Accuracy on Real Testing Set = 94.833333%*/

#define N_TREES 16
#define N_CLASS 10
#define N_TEST 10
#define N_LOOP 10
#define DIM 216

#define INPUT_DATATYPE 		float
#define FEATURES_DATATYPE	uint8_t
#define THRESHOLD_DATATYPE	float
#define CHILDREN_DATATYPE	uint16_t

#define BIGNODE_DATATYPE	uint32_t

#define WHILE_CONDITION (255)
#define FEAT2INPUT_SHIFT (2)
#define NODE2FEAT_SHIFT  (2)
#define CMP_SHIFT  		 (4)

#endif


#endif
