#ifndef __DT_ARR_H__
#define __DT_ARR_H__


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Total L1 Memory Requirements = 44.16kB */

#define NODES_TREE_0 	(195)
#define NODES_TREE_1 	(189)
#define NODES_TREE_2 	(221)
#define NODES_TREE_3 	(203)
#define NODES_TREE_4 	(207)
#define NODES_TREE_5 	(203)
#define NODES_TREE_6 	(225)
#define NODES_TREE_7 	(201)
#define NODES_TREE_8 	(201)
#define NODES_TREE_9 	(215)
#define NODES_TREE_10 	(203)
#define NODES_TREE_11 	(215)
#define NODES_TREE_12 	(201)
#define NODES_TREE_13 	(247)
#define NODES_TREE_14 	(195)
#define NODES_TREE_15 	(217)

/*    TREE 0    */
/* L1 Memory Requirements = 3.01kB */

int8_t features_tree0[NODES_TREE_0];
float threshold_tree0[NODES_TREE_0];
uint16_t children_tree0[NODES_TREE_0*2];

/*    TREE 1    */
/* L1 Memory Requirements = 2.46kB */

int8_t features_tree1[NODES_TREE_1];
float threshold_tree1[NODES_TREE_1];
uint16_t children_tree1[NODES_TREE_1*2];

/*    TREE 2    */
/* L1 Memory Requirements = 3.08kB */

int8_t features_tree2[NODES_TREE_2];
float threshold_tree2[NODES_TREE_2];
uint16_t children_tree2[NODES_TREE_2*2];

/*    TREE 3    */
/* L1 Memory Requirements = 2.58kB */

int8_t features_tree3[NODES_TREE_3];
float threshold_tree3[NODES_TREE_3];
uint16_t children_tree3[NODES_TREE_3*2];

/*    TREE 4    */
/* L1 Memory Requirements = 2.56kB */

int8_t features_tree4[NODES_TREE_4];
float threshold_tree4[NODES_TREE_4];
uint16_t children_tree4[NODES_TREE_4*2];

/*    TREE 5    */
/* L1 Memory Requirements = 2.96kB */

int8_t features_tree5[NODES_TREE_5];
float threshold_tree5[NODES_TREE_5];
uint16_t children_tree5[NODES_TREE_5*2];

/*    TREE 6    */
/* L1 Memory Requirements = 2.70kB */

int8_t features_tree6[NODES_TREE_6];
float threshold_tree6[NODES_TREE_6];
uint16_t children_tree6[NODES_TREE_6*2];

/*    TREE 7    */
/* L1 Memory Requirements = 2.84kB */

int8_t features_tree7[NODES_TREE_7];
float threshold_tree7[NODES_TREE_7];
uint16_t children_tree7[NODES_TREE_7*2];

/*    TREE 8    */
/* L1 Memory Requirements = 2.82kB */

int8_t features_tree8[NODES_TREE_8];
float threshold_tree8[NODES_TREE_8];
uint16_t children_tree8[NODES_TREE_8*2];

/*    TREE 9    */
/* L1 Memory Requirements = 2.63kB */

int8_t features_tree9[NODES_TREE_9];
float threshold_tree9[NODES_TREE_9];
uint16_t children_tree9[NODES_TREE_9*2];

/*    TREE 10    */
/* L1 Memory Requirements = 2.65kB */

int8_t features_tree10[NODES_TREE_10];
float threshold_tree10[NODES_TREE_10];
uint16_t children_tree10[NODES_TREE_10*2];

/*    TREE 11    */
/* L1 Memory Requirements = 2.75kB */

int8_t features_tree11[NODES_TREE_11];
float threshold_tree11[NODES_TREE_11];
uint16_t children_tree11[NODES_TREE_11*2];

/*    TREE 12    */
/* L1 Memory Requirements = 2.68kB */

int8_t features_tree12[NODES_TREE_12];
float threshold_tree12[NODES_TREE_12];
uint16_t children_tree12[NODES_TREE_12*2];

/*    TREE 13    */
/* L1 Memory Requirements = 2.87kB */

int8_t features_tree13[NODES_TREE_13];
float threshold_tree13[NODES_TREE_13];
uint16_t children_tree13[NODES_TREE_13*2];

/*    TREE 14    */
/* L1 Memory Requirements = 2.63kB */

int8_t features_tree14[NODES_TREE_14];
float threshold_tree14[NODES_TREE_14];
uint16_t children_tree14[NODES_TREE_14*2];

/*    TREE 15    */
/* L1 Memory Requirements = 2.75kB */

int8_t features_tree15[NODES_TREE_15];
float threshold_tree15[NODES_TREE_15];
uint16_t children_tree15[NODES_TREE_15*2];

/* L1 Memory Requirements = 0.19kB */
int8_t *features[N_TREES];
float *threshold[N_TREES];
uint16_t *children[N_TREES];

#endif


#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */
/* Total L1 Memory Requirements = 44.16kB */

#define NODES_TREE_0 	(229)
#define NODES_TREE_1 	(199)
#define NODES_TREE_2 	(213)
#define NODES_TREE_3 	(203)
#define NODES_TREE_4 	(243)
#define NODES_TREE_5 	(221)
#define NODES_TREE_6 	(227)
#define NODES_TREE_7 	(221)
#define NODES_TREE_8 	(219)
#define NODES_TREE_9 	(215)
#define NODES_TREE_10 	(221)
#define NODES_TREE_11 	(203)
#define NODES_TREE_12 	(207)
#define NODES_TREE_13 	(231)
#define NODES_TREE_14 	(241)
#define NODES_TREE_15 	(239)

/*    TREE 0    */
/* L1 Memory Requirements = 3.01kB */

FEATURES_DATATYPE features_tree0[NODES_TREE_0];
THRESHOLD_DATATYPE threshold_tree0[NODES_TREE_0];
CHILDREN_DATATYPE children_tree0[NODES_TREE_0*2];

/*    TREE 1    */
/* L1 Memory Requirements = 2.46kB */

FEATURES_DATATYPE features_tree1[NODES_TREE_1];
THRESHOLD_DATATYPE threshold_tree1[NODES_TREE_1];
CHILDREN_DATATYPE children_tree1[NODES_TREE_1*2];

/*    TREE 2    */
/* L1 Memory Requirements = 3.08kB */

FEATURES_DATATYPE features_tree2[NODES_TREE_2];
THRESHOLD_DATATYPE threshold_tree2[NODES_TREE_2];
CHILDREN_DATATYPE children_tree2[NODES_TREE_2*2];

/*    TREE 3    */
/* L1 Memory Requirements = 2.58kB */

FEATURES_DATATYPE features_tree3[NODES_TREE_3];
THRESHOLD_DATATYPE threshold_tree3[NODES_TREE_3];
CHILDREN_DATATYPE children_tree3[NODES_TREE_3*2];

/*    TREE 4    */
/* L1 Memory Requirements = 2.56kB */

FEATURES_DATATYPE features_tree4[NODES_TREE_4];
THRESHOLD_DATATYPE threshold_tree4[NODES_TREE_4];
CHILDREN_DATATYPE children_tree4[NODES_TREE_4*2];

/*    TREE 5    */
/* L1 Memory Requirements = 2.96kB */

FEATURES_DATATYPE features_tree5[NODES_TREE_5];
THRESHOLD_DATATYPE threshold_tree5[NODES_TREE_5];
CHILDREN_DATATYPE children_tree5[NODES_TREE_5*2];

/*    TREE 6    */
/* L1 Memory Requirements = 2.70kB */

FEATURES_DATATYPE features_tree6[NODES_TREE_6];
THRESHOLD_DATATYPE threshold_tree6[NODES_TREE_6];
CHILDREN_DATATYPE children_tree6[NODES_TREE_6*2];

/*    TREE 7    */
/* L1 Memory Requirements = 2.84kB */

FEATURES_DATATYPE features_tree7[NODES_TREE_7];
THRESHOLD_DATATYPE threshold_tree7[NODES_TREE_7];
CHILDREN_DATATYPE children_tree7[NODES_TREE_7*2];

/*    TREE 8    */
/* L1 Memory Requirements = 2.82kB */

FEATURES_DATATYPE features_tree8[NODES_TREE_8];
THRESHOLD_DATATYPE threshold_tree8[NODES_TREE_8];
CHILDREN_DATATYPE children_tree8[NODES_TREE_8*2];

/*    TREE 9    */
/* L1 Memory Requirements = 2.63kB */

FEATURES_DATATYPE features_tree9[NODES_TREE_9];
THRESHOLD_DATATYPE threshold_tree9[NODES_TREE_9];
CHILDREN_DATATYPE children_tree9[NODES_TREE_9*2];

/*    TREE 10    */
/* L1 Memory Requirements = 2.65kB */

FEATURES_DATATYPE features_tree10[NODES_TREE_10];
THRESHOLD_DATATYPE threshold_tree10[NODES_TREE_10];
CHILDREN_DATATYPE children_tree10[NODES_TREE_10*2];

/*    TREE 11    */
/* L1 Memory Requirements = 2.75kB */

FEATURES_DATATYPE features_tree11[NODES_TREE_11];
THRESHOLD_DATATYPE threshold_tree11[NODES_TREE_11];
CHILDREN_DATATYPE children_tree11[NODES_TREE_11*2];

/*    TREE 12    */
/* L1 Memory Requirements = 2.68kB */

FEATURES_DATATYPE features_tree12[NODES_TREE_12];
THRESHOLD_DATATYPE threshold_tree12[NODES_TREE_12];
CHILDREN_DATATYPE children_tree12[NODES_TREE_12*2];

/*    TREE 13    */
/* L1 Memory Requirements = 2.87kB */

FEATURES_DATATYPE features_tree13[NODES_TREE_13];
THRESHOLD_DATATYPE threshold_tree13[NODES_TREE_13];
CHILDREN_DATATYPE children_tree13[NODES_TREE_13*2];

/*    TREE 14    */
/* L1 Memory Requirements = 2.63kB */

FEATURES_DATATYPE features_tree14[NODES_TREE_14];
THRESHOLD_DATATYPE threshold_tree14[NODES_TREE_14];
CHILDREN_DATATYPE children_tree14[NODES_TREE_14*2];

/*    TREE 15    */
/* L1 Memory Requirements = 2.75kB */

FEATURES_DATATYPE features_tree15[NODES_TREE_15];
THRESHOLD_DATATYPE threshold_tree15[NODES_TREE_15];
CHILDREN_DATATYPE children_tree15[NODES_TREE_15*2];

/* L1 Memory Requirements = 0.19kB */
FEATURES_DATATYPE *features[N_TREES];
THRESHOLD_DATATYPE *threshold[N_TREES];
CHILDREN_DATATYPE *children[N_TREES];

#endif


#endif
