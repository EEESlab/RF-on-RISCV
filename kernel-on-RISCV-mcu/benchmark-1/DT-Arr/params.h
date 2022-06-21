#ifndef __PARAMS_H__
#define __PARAMS_H__


#define N_CORES (1)
#define STACK_SIZE (512)


#define DEBUG

//#define STATS
//#define STATS_CLUSTER
//#define STATS_FPU

//#define VEHICLE

//#define STALLFREE


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Input data-type: uint16_t */
/* Features data-type: int8_t */
/* Accuracy on Testing Set = 100.000000%*/
/* Accuracy on Real Testing Set = 80.314961%*/

#define N_TREES 48
#define N_CLASS 4
#define N_TEST 10
#define N_LOOP 10
#define DIM 18

#endif


#endif
