#ifndef __PARAMS_H__
#define __PARAMS_H__


#define N_CORES (1)
#define STACK_SIZE (512)


//#define DEBUG

//#define STATS
//#define STATS_FPU

//#define VEHICLE
//#define MFEAT_FACTORS


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Accuracy on Testing Set = 80.000000%*/
/* Accuracy on Real Testing Set = 74.056604%*/

#define N_TREES 16
#define N_CLASS 4
#define N_TEST 10
#define N_LOOP 10
#define DIM 18

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

#endif


#endif
