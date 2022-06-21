#ifndef __DT_ARR_STALLFREE_H__
#define __DT_ARR_STALLFREE_H__


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Total L2 Memory Requirements = 91.30kB */

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
#define CHILDREN_DATATYPE uint16_t
#define CHILDREN_BYTES (2)
#define CHILDREN_BITS (16)
#define BIGNODE_DATATYPE uint32_t
#define NODE2FEAT_DTYPE (2) /* div shift */
#define WHILE_CONDITION (-4)

/* Packed struct necessary to avoid padding between struct entries */
struct __attribute__ ((__packed__)) RandomForest {

	/*    TREE 0    */
	/* L2 Memory Requirements = 1.76kB */

	int8_t features_tree0[NODES_TREE_0];
	float threshold_tree0[NODES_TREE_0];
	uint16_t children_tree0[NODES_TREE_0*2];

	/*    TREE 1    */
	/* L2 Memory Requirements = 1.70kB */

	int8_t features_tree1[NODES_TREE_1];
	float threshold_tree1[NODES_TREE_1];
	uint16_t children_tree1[NODES_TREE_1*2];

	/*    TREE 2    */
	/* L2 Memory Requirements = 1.99kB */

	int8_t features_tree2[NODES_TREE_2];
	float threshold_tree2[NODES_TREE_2];
	uint16_t children_tree2[NODES_TREE_2*2];

	/*    TREE 3    */
	/* L2 Memory Requirements = 1.83kB */

	int8_t features_tree3[NODES_TREE_3];
	float threshold_tree3[NODES_TREE_3];
	uint16_t children_tree3[NODES_TREE_3*2];

	/*    TREE 4    */
	/* L2 Memory Requirements = 1.86kB */

	int8_t features_tree4[NODES_TREE_4];
	float threshold_tree4[NODES_TREE_4];
	uint16_t children_tree4[NODES_TREE_4*2];

	/*    TREE 5    */
	/* L2 Memory Requirements = 1.83kB */

	int8_t features_tree5[NODES_TREE_5];
	float threshold_tree5[NODES_TREE_5];
	uint16_t children_tree5[NODES_TREE_5*2];

	/*    TREE 6    */
	/* L2 Memory Requirements = 2.02kB */

	int8_t features_tree6[NODES_TREE_6];
	float threshold_tree6[NODES_TREE_6];
	uint16_t children_tree6[NODES_TREE_6*2];

	/*    TREE 7    */
	/* L2 Memory Requirements = 1.81kB */

	int8_t features_tree7[NODES_TREE_7];
	float threshold_tree7[NODES_TREE_7];
	uint16_t children_tree7[NODES_TREE_7*2];

	/*    TREE 8    */
	/* L2 Memory Requirements = 1.81kB */

	int8_t features_tree8[NODES_TREE_8];
	float threshold_tree8[NODES_TREE_8];
	uint16_t children_tree8[NODES_TREE_8*2];

	/*    TREE 9    */
	/* L2 Memory Requirements = 1.94kB */

	int8_t features_tree9[NODES_TREE_9];
	float threshold_tree9[NODES_TREE_9];
	uint16_t children_tree9[NODES_TREE_9*2];

	/*    TREE 10    */
	/* L2 Memory Requirements = 1.83kB */

	int8_t features_tree10[NODES_TREE_10];
	float threshold_tree10[NODES_TREE_10];
	uint16_t children_tree10[NODES_TREE_10*2];

	/*    TREE 11    */
	/* L2 Memory Requirements = 1.94kB */

	int8_t features_tree11[NODES_TREE_11];
	float threshold_tree11[NODES_TREE_11];
	uint16_t children_tree11[NODES_TREE_11*2];

	/*    TREE 12    */
	/* L2 Memory Requirements = 1.81kB */

	int8_t features_tree12[NODES_TREE_12];
	float threshold_tree12[NODES_TREE_12];
	uint16_t children_tree12[NODES_TREE_12*2];

	/*    TREE 13    */
	/* L2 Memory Requirements = 2.22kB */

	int8_t features_tree13[NODES_TREE_13];
	float threshold_tree13[NODES_TREE_13];
	uint16_t children_tree13[NODES_TREE_13*2];

	/*    TREE 14    */
	/* L2 Memory Requirements = 1.76kB */

	int8_t features_tree14[NODES_TREE_14];
	float threshold_tree14[NODES_TREE_14];
	uint16_t children_tree14[NODES_TREE_14*2];

	/*    TREE 15    */
	/* L2 Memory Requirements = 1.95kB */

	int8_t features_tree15[NODES_TREE_15];
	float threshold_tree15[NODES_TREE_15];
	uint16_t children_tree15[NODES_TREE_15*2];

	/*    TREE 16    */
	/* L2 Memory Requirements = 2.06kB */

	int8_t features_tree16[NODES_TREE_16];
	float threshold_tree16[NODES_TREE_16];
	uint16_t children_tree16[NODES_TREE_16*2];

	/*    TREE 17    */
	/* L2 Memory Requirements = 2.24kB */

	int8_t features_tree17[NODES_TREE_17];
	float threshold_tree17[NODES_TREE_17];
	uint16_t children_tree17[NODES_TREE_17*2];

	/*    TREE 18    */
	/* L2 Memory Requirements = 1.95kB */

	int8_t features_tree18[NODES_TREE_18];
	float threshold_tree18[NODES_TREE_18];
	uint16_t children_tree18[NODES_TREE_18*2];

	/*    TREE 19    */
	/* L2 Memory Requirements = 1.81kB */

	int8_t features_tree19[NODES_TREE_19];
	float threshold_tree19[NODES_TREE_19];
	uint16_t children_tree19[NODES_TREE_19*2];

	/*    TREE 20    */
	/* L2 Memory Requirements = 1.81kB */

	int8_t features_tree20[NODES_TREE_20];
	float threshold_tree20[NODES_TREE_20];
	uint16_t children_tree20[NODES_TREE_20*2];

	/*    TREE 21    */
	/* L2 Memory Requirements = 2.04kB */

	int8_t features_tree21[NODES_TREE_21];
	float threshold_tree21[NODES_TREE_21];
	uint16_t children_tree21[NODES_TREE_21*2];

	/*    TREE 22    */
	/* L2 Memory Requirements = 1.94kB */

	int8_t features_tree22[NODES_TREE_22];
	float threshold_tree22[NODES_TREE_22];
	uint16_t children_tree22[NODES_TREE_22*2];

	/*    TREE 23    */
	/* L2 Memory Requirements = 1.97kB */

	int8_t features_tree23[NODES_TREE_23];
	float threshold_tree23[NODES_TREE_23];
	uint16_t children_tree23[NODES_TREE_23*2];

	/*    TREE 24    */
	/* L2 Memory Requirements = 1.97kB */

	int8_t features_tree24[NODES_TREE_24];
	float threshold_tree24[NODES_TREE_24];
	uint16_t children_tree24[NODES_TREE_24*2];

	/*    TREE 25    */
	/* L2 Memory Requirements = 1.79kB */

	int8_t features_tree25[NODES_TREE_25];
	float threshold_tree25[NODES_TREE_25];
	uint16_t children_tree25[NODES_TREE_25*2];

	/*    TREE 26    */
	/* L2 Memory Requirements = 1.84kB */

	int8_t features_tree26[NODES_TREE_26];
	float threshold_tree26[NODES_TREE_26];
	uint16_t children_tree26[NODES_TREE_26*2];

	/*    TREE 27    */
	/* L2 Memory Requirements = 1.84kB */

	int8_t features_tree27[NODES_TREE_27];
	float threshold_tree27[NODES_TREE_27];
	uint16_t children_tree27[NODES_TREE_27*2];

	/*    TREE 28    */
	/* L2 Memory Requirements = 1.83kB */

	int8_t features_tree28[NODES_TREE_28];
	float threshold_tree28[NODES_TREE_28];
	uint16_t children_tree28[NODES_TREE_28*2];

	/*    TREE 29    */
	/* L2 Memory Requirements = 1.81kB */

	int8_t features_tree29[NODES_TREE_29];
	float threshold_tree29[NODES_TREE_29];
	uint16_t children_tree29[NODES_TREE_29*2];

	/*    TREE 30    */
	/* L2 Memory Requirements = 1.79kB */

	int8_t features_tree30[NODES_TREE_30];
	float threshold_tree30[NODES_TREE_30];
	uint16_t children_tree30[NODES_TREE_30*2];

	/*    TREE 31    */
	/* L2 Memory Requirements = 1.92kB */

	int8_t features_tree31[NODES_TREE_31];
	float threshold_tree31[NODES_TREE_31];
	uint16_t children_tree31[NODES_TREE_31*2];

	/*    TREE 32    */
	/* L2 Memory Requirements = 1.97kB */

	int8_t features_tree32[NODES_TREE_32];
	float threshold_tree32[NODES_TREE_32];
	uint16_t children_tree32[NODES_TREE_32*2];

	/*    TREE 33    */
	/* L2 Memory Requirements = 1.81kB */

	int8_t features_tree33[NODES_TREE_33];
	float threshold_tree33[NODES_TREE_33];
	uint16_t children_tree33[NODES_TREE_33*2];

	/*    TREE 34    */
	/* L2 Memory Requirements = 1.81kB */

	int8_t features_tree34[NODES_TREE_34];
	float threshold_tree34[NODES_TREE_34];
	uint16_t children_tree34[NODES_TREE_34*2];

	/*    TREE 35    */
	/* L2 Memory Requirements = 1.74kB */

	int8_t features_tree35[NODES_TREE_35];
	float threshold_tree35[NODES_TREE_35];
	uint16_t children_tree35[NODES_TREE_35*2];

	/*    TREE 36    */
	/* L2 Memory Requirements = 1.94kB */

	int8_t features_tree36[NODES_TREE_36];
	float threshold_tree36[NODES_TREE_36];
	uint16_t children_tree36[NODES_TREE_36*2];

	/*    TREE 37    */
	/* L2 Memory Requirements = 1.84kB */

	int8_t features_tree37[NODES_TREE_37];
	float threshold_tree37[NODES_TREE_37];
	uint16_t children_tree37[NODES_TREE_37*2];

	/*    TREE 38    */
	/* L2 Memory Requirements = 1.77kB */

	int8_t features_tree38[NODES_TREE_38];
	float threshold_tree38[NODES_TREE_38];
	uint16_t children_tree38[NODES_TREE_38*2];

	/*    TREE 39    */
	/* L2 Memory Requirements = 1.99kB */

	int8_t features_tree39[NODES_TREE_39];
	float threshold_tree39[NODES_TREE_39];
	uint16_t children_tree39[NODES_TREE_39*2];

	/*    TREE 40    */
	/* L2 Memory Requirements = 1.94kB */

	int8_t features_tree40[NODES_TREE_40];
	float threshold_tree40[NODES_TREE_40];
	uint16_t children_tree40[NODES_TREE_40*2];

	/*    TREE 41    */
	/* L2 Memory Requirements = 2.10kB */

	int8_t features_tree41[NODES_TREE_41];
	float threshold_tree41[NODES_TREE_41];
	uint16_t children_tree41[NODES_TREE_41*2];

	/*    TREE 42    */
	/* L2 Memory Requirements = 1.90kB */

	int8_t features_tree42[NODES_TREE_42];
	float threshold_tree42[NODES_TREE_42];
	uint16_t children_tree42[NODES_TREE_42*2];

	/*    TREE 43    */
	/* L2 Memory Requirements = 1.86kB */

	int8_t features_tree43[NODES_TREE_43];
	float threshold_tree43[NODES_TREE_43];
	uint16_t children_tree43[NODES_TREE_43*2];

	/*    TREE 44    */
	/* L2 Memory Requirements = 1.79kB */

	int8_t features_tree44[NODES_TREE_44];
	float threshold_tree44[NODES_TREE_44];
	uint16_t children_tree44[NODES_TREE_44*2];

	/*    TREE 45    */
	/* L2 Memory Requirements = 1.90kB */

	int8_t features_tree45[NODES_TREE_45];
	float threshold_tree45[NODES_TREE_45];
	uint16_t children_tree45[NODES_TREE_45*2];

	/*    TREE 46    */
	/* L2 Memory Requirements = 1.88kB */

	int8_t features_tree46[NODES_TREE_46];
	float threshold_tree46[NODES_TREE_46];
	uint16_t children_tree46[NODES_TREE_46*2];

	/*    TREE 47    */
	/* L2 Memory Requirements = 1.97kB */

	int8_t features_tree47[NODES_TREE_47];
	float threshold_tree47[NODES_TREE_47];
	uint16_t children_tree47[NODES_TREE_47*2];

} randomforest;


/* L1 Memory Requirements = 0.77kB */

uint32_t treeDim[N_TREES];
uint32_t paramAddr[N_TREES*3];


#endif


#endif 


