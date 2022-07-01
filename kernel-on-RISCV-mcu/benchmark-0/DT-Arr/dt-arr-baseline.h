#ifndef __DT_ARR_BASELINE_H__
#define __DT_ARR_BASELINE_H__


#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */
/* Total L1 Memory Requirements = 28.38kB */

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
#define CHILDREN_DATATYPE uint8_t
#define WHILE_CONDITION (-2)

/*    TREE 0    */
/* L1 Memory Requirements = 1.83kB */

int16_t features_tree0[NODES_TREE_0];
float threshold_tree0[NODES_TREE_0];
uint8_t children_left_tree0[NODES_TREE_0];
uint8_t children_right_tree0[NODES_TREE_0];

/*    TREE 1    */
/* L1 Memory Requirements = 1.59kB */

int16_t features_tree1[NODES_TREE_1];
float threshold_tree1[NODES_TREE_1];
uint8_t children_left_tree1[NODES_TREE_1];
uint8_t children_right_tree1[NODES_TREE_1];

/*    TREE 2    */
/* L1 Memory Requirements = 1.70kB */

int16_t features_tree2[NODES_TREE_2];
float threshold_tree2[NODES_TREE_2];
uint8_t children_left_tree2[NODES_TREE_2];
uint8_t children_right_tree2[NODES_TREE_2];

/*    TREE 3    */
/* L1 Memory Requirements = 1.62kB */

int16_t features_tree3[NODES_TREE_3];
float threshold_tree3[NODES_TREE_3];
uint8_t children_left_tree3[NODES_TREE_3];
uint8_t children_right_tree3[NODES_TREE_3];

/*    TREE 4    */
/* L1 Memory Requirements = 1.94kB */

int16_t features_tree4[NODES_TREE_4];
float threshold_tree4[NODES_TREE_4];
uint8_t children_left_tree4[NODES_TREE_4];
uint8_t children_right_tree4[NODES_TREE_4];

/*    TREE 5    */
/* L1 Memory Requirements = 1.77kB */

int16_t features_tree5[NODES_TREE_5];
float threshold_tree5[NODES_TREE_5];
uint8_t children_left_tree5[NODES_TREE_5];
uint8_t children_right_tree5[NODES_TREE_5];

/*    TREE 6    */
/* L1 Memory Requirements = 1.82kB */

int16_t features_tree6[NODES_TREE_6];
float threshold_tree6[NODES_TREE_6];
uint8_t children_left_tree6[NODES_TREE_6];
uint8_t children_right_tree6[NODES_TREE_6];

/*    TREE 7    */
/* L1 Memory Requirements = 1.77kB */

int16_t features_tree7[NODES_TREE_7];
float threshold_tree7[NODES_TREE_7];
uint8_t children_left_tree7[NODES_TREE_7];
uint8_t children_right_tree7[NODES_TREE_7];

/*    TREE 8    */
/* L1 Memory Requirements = 1.75kB */

int16_t features_tree8[NODES_TREE_8];
float threshold_tree8[NODES_TREE_8];
uint8_t children_left_tree8[NODES_TREE_8];
uint8_t children_right_tree8[NODES_TREE_8];

/*    TREE 9    */
/* L1 Memory Requirements = 1.72kB */

int16_t features_tree9[NODES_TREE_9];
float threshold_tree9[NODES_TREE_9];
uint8_t children_left_tree9[NODES_TREE_9];
uint8_t children_right_tree9[NODES_TREE_9];

/*    TREE 10    */
/* L1 Memory Requirements = 1.77kB */

int16_t features_tree10[NODES_TREE_10];
float threshold_tree10[NODES_TREE_10];
uint8_t children_left_tree10[NODES_TREE_10];
uint8_t children_right_tree10[NODES_TREE_10];

/*    TREE 11    */
/* L1 Memory Requirements = 1.62kB */

int16_t features_tree11[NODES_TREE_11];
float threshold_tree11[NODES_TREE_11];
uint8_t children_left_tree11[NODES_TREE_11];
uint8_t children_right_tree11[NODES_TREE_11];

/*    TREE 12    */
/* L1 Memory Requirements = 1.66kB */

int16_t features_tree12[NODES_TREE_12];
float threshold_tree12[NODES_TREE_12];
uint8_t children_left_tree12[NODES_TREE_12];
uint8_t children_right_tree12[NODES_TREE_12];

/*    TREE 13    */
/* L1 Memory Requirements = 1.85kB */

int16_t features_tree13[NODES_TREE_13];
float threshold_tree13[NODES_TREE_13];
uint8_t children_left_tree13[NODES_TREE_13];
uint8_t children_right_tree13[NODES_TREE_13];

/*    TREE 14    */
/* L1 Memory Requirements = 1.93kB */

int16_t features_tree14[NODES_TREE_14];
float threshold_tree14[NODES_TREE_14];
uint8_t children_left_tree14[NODES_TREE_14];
uint8_t children_right_tree14[NODES_TREE_14];

/*    TREE 15    */
/* L1 Memory Requirements = 1.91kB */

int16_t features_tree15[NODES_TREE_15];
float threshold_tree15[NODES_TREE_15];
uint8_t children_left_tree15[NODES_TREE_15];
uint8_t children_right_tree15[NODES_TREE_15];

/* L1 Memory Requirements = 0.13kB */
int16_t *features[N_TREES];
float *threshold[N_TREES];
uint8_t *children_left[N_TREES];
uint8_t *children_right[N_TREES];

#endif


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Total L1 Memory Requirements = 23.48kB */

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
#define CHILDREN_DATATYPE uint8_t
#define WHILE_CONDITION (-2)

/*    TREE 0    */
/* L1 Memory Requirements = 1.36kB */

int8_t features_tree0[NODES_TREE_0];
float threshold_tree0[NODES_TREE_0];
uint8_t children_left_tree0[NODES_TREE_0];
uint8_t children_right_tree0[NODES_TREE_0];

/*    TREE 1    */
/* L1 Memory Requirements = 1.32kB */

int8_t features_tree1[NODES_TREE_1];
float threshold_tree1[NODES_TREE_1];
uint8_t children_left_tree1[NODES_TREE_1];
uint8_t children_right_tree1[NODES_TREE_1];

/*    TREE 2    */
/* L1 Memory Requirements = 1.55kB */

int8_t features_tree2[NODES_TREE_2];
float threshold_tree2[NODES_TREE_2];
uint8_t children_left_tree2[NODES_TREE_2];
uint8_t children_right_tree2[NODES_TREE_2];

/*    TREE 3    */
/* L1 Memory Requirements = 1.42kB */

int8_t features_tree3[NODES_TREE_3];
float threshold_tree3[NODES_TREE_3];
uint8_t children_left_tree3[NODES_TREE_3];
uint8_t children_right_tree3[NODES_TREE_3];

/*    TREE 4    */
/* L1 Memory Requirements = 1.45kB */

int8_t features_tree4[NODES_TREE_4];
float threshold_tree4[NODES_TREE_4];
uint8_t children_left_tree4[NODES_TREE_4];
uint8_t children_right_tree4[NODES_TREE_4];

/*    TREE 5    */
/* L1 Memory Requirements = 1.42kB */

int8_t features_tree5[NODES_TREE_5];
float threshold_tree5[NODES_TREE_5];
uint8_t children_left_tree5[NODES_TREE_5];
uint8_t children_right_tree5[NODES_TREE_5];

/*    TREE 6    */
/* L1 Memory Requirements = 1.57kB */

int8_t features_tree6[NODES_TREE_6];
float threshold_tree6[NODES_TREE_6];
uint8_t children_left_tree6[NODES_TREE_6];
uint8_t children_right_tree6[NODES_TREE_6];

/*    TREE 7    */
/* L1 Memory Requirements = 1.41kB */

int8_t features_tree7[NODES_TREE_7];
float threshold_tree7[NODES_TREE_7];
uint8_t children_left_tree7[NODES_TREE_7];
uint8_t children_right_tree7[NODES_TREE_7];

/*    TREE 8    */
/* L1 Memory Requirements = 1.41kB */

int8_t features_tree8[NODES_TREE_8];
float threshold_tree8[NODES_TREE_8];
uint8_t children_left_tree8[NODES_TREE_8];
uint8_t children_right_tree8[NODES_TREE_8];

/*    TREE 9    */
/* L1 Memory Requirements = 1.51kB */

int8_t features_tree9[NODES_TREE_9];
float threshold_tree9[NODES_TREE_9];
uint8_t children_left_tree9[NODES_TREE_9];
uint8_t children_right_tree9[NODES_TREE_9];

/*    TREE 10    */
/* L1 Memory Requirements = 1.42kB */

int8_t features_tree10[NODES_TREE_10];
float threshold_tree10[NODES_TREE_10];
uint8_t children_left_tree10[NODES_TREE_10];
uint8_t children_right_tree10[NODES_TREE_10];

/*    TREE 11    */
/* L1 Memory Requirements = 1.51kB */

int8_t features_tree11[NODES_TREE_11];
float threshold_tree11[NODES_TREE_11];
uint8_t children_left_tree11[NODES_TREE_11];
uint8_t children_right_tree11[NODES_TREE_11];

/*    TREE 12    */
/* L1 Memory Requirements = 1.41kB */

int8_t features_tree12[NODES_TREE_12];
float threshold_tree12[NODES_TREE_12];
uint8_t children_left_tree12[NODES_TREE_12];
uint8_t children_right_tree12[NODES_TREE_12];

/*    TREE 13    */
/* L1 Memory Requirements = 1.73kB */

int8_t features_tree13[NODES_TREE_13];
float threshold_tree13[NODES_TREE_13];
uint8_t children_left_tree13[NODES_TREE_13];
uint8_t children_right_tree13[NODES_TREE_13];

/*    TREE 14    */
/* L1 Memory Requirements = 1.36kB */

int8_t features_tree14[NODES_TREE_14];
float threshold_tree14[NODES_TREE_14];
uint8_t children_left_tree14[NODES_TREE_14];
uint8_t children_right_tree14[NODES_TREE_14];

/*    TREE 15    */
/* L1 Memory Requirements = 1.52kB */

int8_t features_tree15[NODES_TREE_15];
float threshold_tree15[NODES_TREE_15];
uint8_t children_left_tree15[NODES_TREE_15];
uint8_t children_right_tree15[NODES_TREE_15];

/* L1 Memory Requirements = 0.11kB */
int8_t *features[N_TREES];
float *threshold[N_TREES];
uint8_t *children_left[N_TREES];
uint8_t *children_right[N_TREES];

#endif


#endif 


