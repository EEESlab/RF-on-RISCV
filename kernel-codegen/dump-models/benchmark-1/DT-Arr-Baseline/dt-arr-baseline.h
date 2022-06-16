#ifndef __DT_ARR_BASELINE_H__
#define __DT_ARR_BASELINE_H__


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Total L2 Memory Requirements = 71.01kB */

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
#define NODES_TREE_16 	(229)
#define NODES_TREE_17 	(249)
#define NODES_TREE_18 	(217)
#define NODES_TREE_19 	(201)
#define NODES_TREE_20 	(201)
#define NODES_TREE_21 	(227)
#define NODES_TREE_22 	(215)
#define NODES_TREE_23 	(219)
#define NODES_TREE_24 	(219)
#define NODES_TREE_25 	(199)
#define NODES_TREE_26 	(205)
#define NODES_TREE_27 	(205)
#define NODES_TREE_28 	(203)
#define NODES_TREE_29 	(201)
#define NODES_TREE_30 	(199)
#define NODES_TREE_31 	(213)
#define NODES_TREE_32 	(219)
#define NODES_TREE_33 	(201)
#define NODES_TREE_34 	(201)
#define NODES_TREE_35 	(193)
#define NODES_TREE_36 	(215)
#define NODES_TREE_37 	(205)
#define NODES_TREE_38 	(197)
#define NODES_TREE_39 	(221)
#define NODES_TREE_40 	(215)
#define NODES_TREE_41 	(233)
#define NODES_TREE_42 	(211)
#define NODES_TREE_43 	(207)
#define NODES_TREE_44 	(199)
#define NODES_TREE_45 	(211)
#define NODES_TREE_46 	(209)
#define NODES_TREE_47 	(219)

#define INPUT_DATATYPE uint16_t
#define FEATURES_DATATYPE int8_t
#define THRESHOLD_DATATYPE float
#define CHILDREN_DATATYPE uint8_t

/* Packed struct necessary to avoid padding between struct entries */
struct __attribute__ ((__packed__)) RandomForest {

	/*    TREE 0    */
	/* L2 Memory Requirements = 1.36kB */

	int8_t features_tree0[NODES_TREE_0];
	float threshold_tree0[NODES_TREE_0];
	uint8_t children_left_tree0[NODES_TREE_0];
	uint8_t children_right_tree0[NODES_TREE_0];

	/*    TREE 1    */
	/* L2 Memory Requirements = 1.32kB */

	int8_t features_tree1[NODES_TREE_1];
	float threshold_tree1[NODES_TREE_1];
	uint8_t children_left_tree1[NODES_TREE_1];
	uint8_t children_right_tree1[NODES_TREE_1];

	/*    TREE 2    */
	/* L2 Memory Requirements = 1.55kB */

	int8_t features_tree2[NODES_TREE_2];
	float threshold_tree2[NODES_TREE_2];
	uint8_t children_left_tree2[NODES_TREE_2];
	uint8_t children_right_tree2[NODES_TREE_2];

	/*    TREE 3    */
	/* L2 Memory Requirements = 1.42kB */

	int8_t features_tree3[NODES_TREE_3];
	float threshold_tree3[NODES_TREE_3];
	uint8_t children_left_tree3[NODES_TREE_3];
	uint8_t children_right_tree3[NODES_TREE_3];

	/*    TREE 4    */
	/* L2 Memory Requirements = 1.45kB */

	int8_t features_tree4[NODES_TREE_4];
	float threshold_tree4[NODES_TREE_4];
	uint8_t children_left_tree4[NODES_TREE_4];
	uint8_t children_right_tree4[NODES_TREE_4];

	/*    TREE 5    */
	/* L2 Memory Requirements = 1.42kB */

	int8_t features_tree5[NODES_TREE_5];
	float threshold_tree5[NODES_TREE_5];
	uint8_t children_left_tree5[NODES_TREE_5];
	uint8_t children_right_tree5[NODES_TREE_5];

	/*    TREE 6    */
	/* L2 Memory Requirements = 1.57kB */

	int8_t features_tree6[NODES_TREE_6];
	float threshold_tree6[NODES_TREE_6];
	uint8_t children_left_tree6[NODES_TREE_6];
	uint8_t children_right_tree6[NODES_TREE_6];

	/*    TREE 7    */
	/* L2 Memory Requirements = 1.41kB */

	int8_t features_tree7[NODES_TREE_7];
	float threshold_tree7[NODES_TREE_7];
	uint8_t children_left_tree7[NODES_TREE_7];
	uint8_t children_right_tree7[NODES_TREE_7];

	/*    TREE 8    */
	/* L2 Memory Requirements = 1.41kB */

	int8_t features_tree8[NODES_TREE_8];
	float threshold_tree8[NODES_TREE_8];
	uint8_t children_left_tree8[NODES_TREE_8];
	uint8_t children_right_tree8[NODES_TREE_8];

	/*    TREE 9    */
	/* L2 Memory Requirements = 1.51kB */

	int8_t features_tree9[NODES_TREE_9];
	float threshold_tree9[NODES_TREE_9];
	uint8_t children_left_tree9[NODES_TREE_9];
	uint8_t children_right_tree9[NODES_TREE_9];

	/*    TREE 10    */
	/* L2 Memory Requirements = 1.42kB */

	int8_t features_tree10[NODES_TREE_10];
	float threshold_tree10[NODES_TREE_10];
	uint8_t children_left_tree10[NODES_TREE_10];
	uint8_t children_right_tree10[NODES_TREE_10];

	/*    TREE 11    */
	/* L2 Memory Requirements = 1.51kB */

	int8_t features_tree11[NODES_TREE_11];
	float threshold_tree11[NODES_TREE_11];
	uint8_t children_left_tree11[NODES_TREE_11];
	uint8_t children_right_tree11[NODES_TREE_11];

	/*    TREE 12    */
	/* L2 Memory Requirements = 1.41kB */

	int8_t features_tree12[NODES_TREE_12];
	float threshold_tree12[NODES_TREE_12];
	uint8_t children_left_tree12[NODES_TREE_12];
	uint8_t children_right_tree12[NODES_TREE_12];

	/*    TREE 13    */
	/* L2 Memory Requirements = 1.73kB */

	int8_t features_tree13[NODES_TREE_13];
	float threshold_tree13[NODES_TREE_13];
	uint8_t children_left_tree13[NODES_TREE_13];
	uint8_t children_right_tree13[NODES_TREE_13];

	/*    TREE 14    */
	/* L2 Memory Requirements = 1.36kB */

	int8_t features_tree14[NODES_TREE_14];
	float threshold_tree14[NODES_TREE_14];
	uint8_t children_left_tree14[NODES_TREE_14];
	uint8_t children_right_tree14[NODES_TREE_14];

	/*    TREE 15    */
	/* L2 Memory Requirements = 1.52kB */

	int8_t features_tree15[NODES_TREE_15];
	float threshold_tree15[NODES_TREE_15];
	uint8_t children_left_tree15[NODES_TREE_15];
	uint8_t children_right_tree15[NODES_TREE_15];

	/*    TREE 16    */
	/* L2 Memory Requirements = 1.60kB */

	int8_t features_tree16[NODES_TREE_16];
	float threshold_tree16[NODES_TREE_16];
	uint8_t children_left_tree16[NODES_TREE_16];
	uint8_t children_right_tree16[NODES_TREE_16];

	/*    TREE 17    */
	/* L2 Memory Requirements = 1.74kB */

	int8_t features_tree17[NODES_TREE_17];
	float threshold_tree17[NODES_TREE_17];
	uint8_t children_left_tree17[NODES_TREE_17];
	uint8_t children_right_tree17[NODES_TREE_17];

	/*    TREE 18    */
	/* L2 Memory Requirements = 1.52kB */

	int8_t features_tree18[NODES_TREE_18];
	float threshold_tree18[NODES_TREE_18];
	uint8_t children_left_tree18[NODES_TREE_18];
	uint8_t children_right_tree18[NODES_TREE_18];

	/*    TREE 19    */
	/* L2 Memory Requirements = 1.41kB */

	int8_t features_tree19[NODES_TREE_19];
	float threshold_tree19[NODES_TREE_19];
	uint8_t children_left_tree19[NODES_TREE_19];
	uint8_t children_right_tree19[NODES_TREE_19];

	/*    TREE 20    */
	/* L2 Memory Requirements = 1.41kB */

	int8_t features_tree20[NODES_TREE_20];
	float threshold_tree20[NODES_TREE_20];
	uint8_t children_left_tree20[NODES_TREE_20];
	uint8_t children_right_tree20[NODES_TREE_20];

	/*    TREE 21    */
	/* L2 Memory Requirements = 1.59kB */

	int8_t features_tree21[NODES_TREE_21];
	float threshold_tree21[NODES_TREE_21];
	uint8_t children_left_tree21[NODES_TREE_21];
	uint8_t children_right_tree21[NODES_TREE_21];

	/*    TREE 22    */
	/* L2 Memory Requirements = 1.51kB */

	int8_t features_tree22[NODES_TREE_22];
	float threshold_tree22[NODES_TREE_22];
	uint8_t children_left_tree22[NODES_TREE_22];
	uint8_t children_right_tree22[NODES_TREE_22];

	/*    TREE 23    */
	/* L2 Memory Requirements = 1.53kB */

	int8_t features_tree23[NODES_TREE_23];
	float threshold_tree23[NODES_TREE_23];
	uint8_t children_left_tree23[NODES_TREE_23];
	uint8_t children_right_tree23[NODES_TREE_23];

	/*    TREE 24    */
	/* L2 Memory Requirements = 1.53kB */

	int8_t features_tree24[NODES_TREE_24];
	float threshold_tree24[NODES_TREE_24];
	uint8_t children_left_tree24[NODES_TREE_24];
	uint8_t children_right_tree24[NODES_TREE_24];

	/*    TREE 25    */
	/* L2 Memory Requirements = 1.39kB */

	int8_t features_tree25[NODES_TREE_25];
	float threshold_tree25[NODES_TREE_25];
	uint8_t children_left_tree25[NODES_TREE_25];
	uint8_t children_right_tree25[NODES_TREE_25];

	/*    TREE 26    */
	/* L2 Memory Requirements = 1.44kB */

	int8_t features_tree26[NODES_TREE_26];
	float threshold_tree26[NODES_TREE_26];
	uint8_t children_left_tree26[NODES_TREE_26];
	uint8_t children_right_tree26[NODES_TREE_26];

	/*    TREE 27    */
	/* L2 Memory Requirements = 1.44kB */

	int8_t features_tree27[NODES_TREE_27];
	float threshold_tree27[NODES_TREE_27];
	uint8_t children_left_tree27[NODES_TREE_27];
	uint8_t children_right_tree27[NODES_TREE_27];

	/*    TREE 28    */
	/* L2 Memory Requirements = 1.42kB */

	int8_t features_tree28[NODES_TREE_28];
	float threshold_tree28[NODES_TREE_28];
	uint8_t children_left_tree28[NODES_TREE_28];
	uint8_t children_right_tree28[NODES_TREE_28];

	/*    TREE 29    */
	/* L2 Memory Requirements = 1.41kB */

	int8_t features_tree29[NODES_TREE_29];
	float threshold_tree29[NODES_TREE_29];
	uint8_t children_left_tree29[NODES_TREE_29];
	uint8_t children_right_tree29[NODES_TREE_29];

	/*    TREE 30    */
	/* L2 Memory Requirements = 1.39kB */

	int8_t features_tree30[NODES_TREE_30];
	float threshold_tree30[NODES_TREE_30];
	uint8_t children_left_tree30[NODES_TREE_30];
	uint8_t children_right_tree30[NODES_TREE_30];

	/*    TREE 31    */
	/* L2 Memory Requirements = 1.49kB */

	int8_t features_tree31[NODES_TREE_31];
	float threshold_tree31[NODES_TREE_31];
	uint8_t children_left_tree31[NODES_TREE_31];
	uint8_t children_right_tree31[NODES_TREE_31];

	/*    TREE 32    */
	/* L2 Memory Requirements = 1.53kB */

	int8_t features_tree32[NODES_TREE_32];
	float threshold_tree32[NODES_TREE_32];
	uint8_t children_left_tree32[NODES_TREE_32];
	uint8_t children_right_tree32[NODES_TREE_32];

	/*    TREE 33    */
	/* L2 Memory Requirements = 1.41kB */

	int8_t features_tree33[NODES_TREE_33];
	float threshold_tree33[NODES_TREE_33];
	uint8_t children_left_tree33[NODES_TREE_33];
	uint8_t children_right_tree33[NODES_TREE_33];

	/*    TREE 34    */
	/* L2 Memory Requirements = 1.41kB */

	int8_t features_tree34[NODES_TREE_34];
	float threshold_tree34[NODES_TREE_34];
	uint8_t children_left_tree34[NODES_TREE_34];
	uint8_t children_right_tree34[NODES_TREE_34];

	/*    TREE 35    */
	/* L2 Memory Requirements = 1.35kB */

	int8_t features_tree35[NODES_TREE_35];
	float threshold_tree35[NODES_TREE_35];
	uint8_t children_left_tree35[NODES_TREE_35];
	uint8_t children_right_tree35[NODES_TREE_35];

	/*    TREE 36    */
	/* L2 Memory Requirements = 1.51kB */

	int8_t features_tree36[NODES_TREE_36];
	float threshold_tree36[NODES_TREE_36];
	uint8_t children_left_tree36[NODES_TREE_36];
	uint8_t children_right_tree36[NODES_TREE_36];

	/*    TREE 37    */
	/* L2 Memory Requirements = 1.44kB */

	int8_t features_tree37[NODES_TREE_37];
	float threshold_tree37[NODES_TREE_37];
	uint8_t children_left_tree37[NODES_TREE_37];
	uint8_t children_right_tree37[NODES_TREE_37];

	/*    TREE 38    */
	/* L2 Memory Requirements = 1.38kB */

	int8_t features_tree38[NODES_TREE_38];
	float threshold_tree38[NODES_TREE_38];
	uint8_t children_left_tree38[NODES_TREE_38];
	uint8_t children_right_tree38[NODES_TREE_38];

	/*    TREE 39    */
	/* L2 Memory Requirements = 1.55kB */

	int8_t features_tree39[NODES_TREE_39];
	float threshold_tree39[NODES_TREE_39];
	uint8_t children_left_tree39[NODES_TREE_39];
	uint8_t children_right_tree39[NODES_TREE_39];

	/*    TREE 40    */
	/* L2 Memory Requirements = 1.51kB */

	int8_t features_tree40[NODES_TREE_40];
	float threshold_tree40[NODES_TREE_40];
	uint8_t children_left_tree40[NODES_TREE_40];
	uint8_t children_right_tree40[NODES_TREE_40];

	/*    TREE 41    */
	/* L2 Memory Requirements = 1.63kB */

	int8_t features_tree41[NODES_TREE_41];
	float threshold_tree41[NODES_TREE_41];
	uint8_t children_left_tree41[NODES_TREE_41];
	uint8_t children_right_tree41[NODES_TREE_41];

	/*    TREE 42    */
	/* L2 Memory Requirements = 1.48kB */

	int8_t features_tree42[NODES_TREE_42];
	float threshold_tree42[NODES_TREE_42];
	uint8_t children_left_tree42[NODES_TREE_42];
	uint8_t children_right_tree42[NODES_TREE_42];

	/*    TREE 43    */
	/* L2 Memory Requirements = 1.45kB */

	int8_t features_tree43[NODES_TREE_43];
	float threshold_tree43[NODES_TREE_43];
	uint8_t children_left_tree43[NODES_TREE_43];
	uint8_t children_right_tree43[NODES_TREE_43];

	/*    TREE 44    */
	/* L2 Memory Requirements = 1.39kB */

	int8_t features_tree44[NODES_TREE_44];
	float threshold_tree44[NODES_TREE_44];
	uint8_t children_left_tree44[NODES_TREE_44];
	uint8_t children_right_tree44[NODES_TREE_44];

	/*    TREE 45    */
	/* L2 Memory Requirements = 1.48kB */

	int8_t features_tree45[NODES_TREE_45];
	float threshold_tree45[NODES_TREE_45];
	uint8_t children_left_tree45[NODES_TREE_45];
	uint8_t children_right_tree45[NODES_TREE_45];

	/*    TREE 46    */
	/* L2 Memory Requirements = 1.46kB */

	int8_t features_tree46[NODES_TREE_46];
	float threshold_tree46[NODES_TREE_46];
	uint8_t children_left_tree46[NODES_TREE_46];
	uint8_t children_right_tree46[NODES_TREE_46];

	/*    TREE 47    */
	/* L2 Memory Requirements = 1.53kB */

	int8_t features_tree47[NODES_TREE_47];
	float threshold_tree47[NODES_TREE_47];
	uint8_t children_left_tree47[NODES_TREE_47];
	uint8_t children_right_tree47[NODES_TREE_47];

} randomforest;


/* L1 Memory Requirements = 0.77kB */

uint32_t treeDim[N_TREES];
uint32_t paramAddr[N_TREES*3];


#endif


#endif 


