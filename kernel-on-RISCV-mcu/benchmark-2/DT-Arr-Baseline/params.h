#ifndef __PARAMS_H__
#define __PARAMS_H__


#define N_CORES (1)
#define STACK_SIZE (512)


#define DEBUG

//#define STATS
//#define STATS_CLUSTER
//#define STATS_FPU

//#define MFEAT_FACTORS


#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */
/* Input data-type: uint16_t */
/* Features data-type: int16_t */
/* Accuracy on Testing Set = 100.000000%*/
/* Accuracy on Real Testing Set = 96.500000%*/

#define N_TREES 96
#define N_CLASS 10
#define N_TEST 10
#define N_LOOP 10
#define DIM 216

#endif


#endif
