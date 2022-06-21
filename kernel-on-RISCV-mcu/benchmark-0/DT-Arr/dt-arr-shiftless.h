#ifndef __DT_ARR_H__
#define __DT_ARR_H__


#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */
/* Total L1 Memory Requirements = 35.48kB */

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

#define INPUT_DATATYPE uint16_t
#define FEATURES_DATATYPE int16_t
#define THRESHOLD_DATATYPE float
#define CHILDREN_DATATYPE uint16_t
#define WHILE_CONDITION (-4)
#define CHILDREN_BYTES (2)
#define NODE2FEAT_DTYPE (1) /* div shift */

/*    TREE 0    */
/* L1 Memory Requirements = 2.29kB */

int16_t features_tree0[NODES_TREE_0];
float threshold_tree0[NODES_TREE_0];
uint16_t children_tree0[NODES_TREE_0*2];

/*    TREE 1    */
/* L1 Memory Requirements = 1.99kB */

int16_t features_tree1[NODES_TREE_1];
float threshold_tree1[NODES_TREE_1];
uint16_t children_tree1[NODES_TREE_1*2];

/*    TREE 2    */
/* L1 Memory Requirements = 2.13kB */

int16_t features_tree2[NODES_TREE_2];
float threshold_tree2[NODES_TREE_2];
uint16_t children_tree2[NODES_TREE_2*2];

/*    TREE 3    */
/* L1 Memory Requirements = 2.03kB */

int16_t features_tree3[NODES_TREE_3];
float threshold_tree3[NODES_TREE_3];
uint16_t children_tree3[NODES_TREE_3*2];

/*    TREE 4    */
/* L1 Memory Requirements = 2.43kB */

int16_t features_tree4[NODES_TREE_4];
float threshold_tree4[NODES_TREE_4];
uint16_t children_tree4[NODES_TREE_4*2];

/*    TREE 5    */
/* L1 Memory Requirements = 2.21kB */

int16_t features_tree5[NODES_TREE_5];
float threshold_tree5[NODES_TREE_5];
uint16_t children_tree5[NODES_TREE_5*2];

/*    TREE 6    */
/* L1 Memory Requirements = 2.27kB */

int16_t features_tree6[NODES_TREE_6];
float threshold_tree6[NODES_TREE_6];
uint16_t children_tree6[NODES_TREE_6*2];

/*    TREE 7    */
/* L1 Memory Requirements = 2.21kB */

int16_t features_tree7[NODES_TREE_7];
float threshold_tree7[NODES_TREE_7];
uint16_t children_tree7[NODES_TREE_7*2];

/*    TREE 8    */
/* L1 Memory Requirements = 2.19kB */

int16_t features_tree8[NODES_TREE_8];
float threshold_tree8[NODES_TREE_8];
uint16_t children_tree8[NODES_TREE_8*2];

/*    TREE 9    */
/* L1 Memory Requirements = 2.15kB */

int16_t features_tree9[NODES_TREE_9];
float threshold_tree9[NODES_TREE_9];
uint16_t children_tree9[NODES_TREE_9*2];

/*    TREE 10    */
/* L1 Memory Requirements = 2.21kB */

int16_t features_tree10[NODES_TREE_10];
float threshold_tree10[NODES_TREE_10];
uint16_t children_tree10[NODES_TREE_10*2];

/*    TREE 11    */
/* L1 Memory Requirements = 2.03kB */

int16_t features_tree11[NODES_TREE_11];
float threshold_tree11[NODES_TREE_11];
uint16_t children_tree11[NODES_TREE_11*2];

/*    TREE 12    */
/* L1 Memory Requirements = 2.07kB */

int16_t features_tree12[NODES_TREE_12];
float threshold_tree12[NODES_TREE_12];
uint16_t children_tree12[NODES_TREE_12*2];

/*    TREE 13    */
/* L1 Memory Requirements = 2.31kB */

int16_t features_tree13[NODES_TREE_13];
float threshold_tree13[NODES_TREE_13];
uint16_t children_tree13[NODES_TREE_13*2];

/*    TREE 14    */
/* L1 Memory Requirements = 2.41kB */

int16_t features_tree14[NODES_TREE_14];
float threshold_tree14[NODES_TREE_14];
uint16_t children_tree14[NODES_TREE_14*2];

/*    TREE 15    */
/* L1 Memory Requirements = 2.39kB */

int16_t features_tree15[NODES_TREE_15];
float threshold_tree15[NODES_TREE_15];
uint16_t children_tree15[NODES_TREE_15*2];

/* L1 Memory Requirements = 0.16kB */
int16_t *features[N_TREES];
float *threshold[N_TREES];
uint16_t *children[N_TREES];

#endif


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Total L1 Memory Requirements = 30.19kB */

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

#define INPUT_DATATYPE uint16_t
#define FEATURES_DATATYPE int8_t
#define THRESHOLD_DATATYPE float
#define CHILDREN_DATATYPE uint16_t
#define WHILE_CONDITION (-4)
#define CHILDREN_BYTES (2)
#define NODE2FEAT_DTYPE (2) /* div shift */

/*    TREE 0    */
/* L1 Memory Requirements = 1.76kB */

int8_t features_tree0[NODES_TREE_0];
float threshold_tree0[NODES_TREE_0];
uint16_t children_tree0[NODES_TREE_0*2];

/*    TREE 1    */
/* L1 Memory Requirements = 1.70kB */

int8_t features_tree1[NODES_TREE_1];
float threshold_tree1[NODES_TREE_1];
uint16_t children_tree1[NODES_TREE_1*2];

/*    TREE 2    */
/* L1 Memory Requirements = 1.99kB */

int8_t features_tree2[NODES_TREE_2];
float threshold_tree2[NODES_TREE_2];
uint16_t children_tree2[NODES_TREE_2*2];

/*    TREE 3    */
/* L1 Memory Requirements = 1.83kB */

int8_t features_tree3[NODES_TREE_3];
float threshold_tree3[NODES_TREE_3];
uint16_t children_tree3[NODES_TREE_3*2];

/*    TREE 4    */
/* L1 Memory Requirements = 1.86kB */

int8_t features_tree4[NODES_TREE_4];
float threshold_tree4[NODES_TREE_4];
uint16_t children_tree4[NODES_TREE_4*2];

/*    TREE 5    */
/* L1 Memory Requirements = 1.83kB */

int8_t features_tree5[NODES_TREE_5];
float threshold_tree5[NODES_TREE_5];
uint16_t children_tree5[NODES_TREE_5*2];

/*    TREE 6    */
/* L1 Memory Requirements = 2.02kB */

int8_t features_tree6[NODES_TREE_6];
float threshold_tree6[NODES_TREE_6];
uint16_t children_tree6[NODES_TREE_6*2];

/*    TREE 7    */
/* L1 Memory Requirements = 1.81kB */

int8_t features_tree7[NODES_TREE_7];
float threshold_tree7[NODES_TREE_7];
uint16_t children_tree7[NODES_TREE_7*2];

/*    TREE 8    */
/* L1 Memory Requirements = 1.81kB */

int8_t features_tree8[NODES_TREE_8];
float threshold_tree8[NODES_TREE_8];
uint16_t children_tree8[NODES_TREE_8*2];

/*    TREE 9    */
/* L1 Memory Requirements = 1.94kB */

int8_t features_tree9[NODES_TREE_9];
float threshold_tree9[NODES_TREE_9];
uint16_t children_tree9[NODES_TREE_9*2];

/*    TREE 10    */
/* L1 Memory Requirements = 1.83kB */

int8_t features_tree10[NODES_TREE_10];
float threshold_tree10[NODES_TREE_10];
uint16_t children_tree10[NODES_TREE_10*2];

/*    TREE 11    */
/* L1 Memory Requirements = 1.94kB */

int8_t features_tree11[NODES_TREE_11];
float threshold_tree11[NODES_TREE_11];
uint16_t children_tree11[NODES_TREE_11*2];

/*    TREE 12    */
/* L1 Memory Requirements = 1.81kB */

int8_t features_tree12[NODES_TREE_12];
float threshold_tree12[NODES_TREE_12];
uint16_t children_tree12[NODES_TREE_12*2];

/*    TREE 13    */
/* L1 Memory Requirements = 2.22kB */

int8_t features_tree13[NODES_TREE_13];
float threshold_tree13[NODES_TREE_13];
uint16_t children_tree13[NODES_TREE_13*2];

/*    TREE 14    */
/* L1 Memory Requirements = 1.76kB */

int8_t features_tree14[NODES_TREE_14];
float threshold_tree14[NODES_TREE_14];
uint16_t children_tree14[NODES_TREE_14*2];

/*    TREE 15    */
/* L1 Memory Requirements = 1.95kB */

int8_t features_tree15[NODES_TREE_15];
float threshold_tree15[NODES_TREE_15];
uint16_t children_tree15[NODES_TREE_15*2];

/* L1 Memory Requirements = 0.14kB */
int8_t *features[N_TREES];
float *threshold[N_TREES];
uint16_t *children[N_TREES];

#endif


#endif 


