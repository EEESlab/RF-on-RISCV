#ifndef __DT_ARR_BASELINE_QUANTIZED_H__
#define __DT_ARR_BASELINE_QUANTIZED_H__


#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */
/* Total L2 Memory Requirements = 104.64kB */

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
#define NODES_TREE_16 	(223)
#define NODES_TREE_17 	(209)
#define NODES_TREE_18 	(221)
#define NODES_TREE_19 	(209)
#define NODES_TREE_20 	(205)
#define NODES_TREE_21 	(219)
#define NODES_TREE_22 	(221)
#define NODES_TREE_23 	(219)
#define NODES_TREE_24 	(233)
#define NODES_TREE_25 	(221)
#define NODES_TREE_26 	(185)
#define NODES_TREE_27 	(219)
#define NODES_TREE_28 	(221)
#define NODES_TREE_29 	(221)
#define NODES_TREE_30 	(213)
#define NODES_TREE_31 	(221)
#define NODES_TREE_32 	(225)
#define NODES_TREE_33 	(211)
#define NODES_TREE_34 	(229)
#define NODES_TREE_35 	(183)
#define NODES_TREE_36 	(237)
#define NODES_TREE_37 	(209)
#define NODES_TREE_38 	(209)
#define NODES_TREE_39 	(219)
#define NODES_TREE_40 	(233)
#define NODES_TREE_41 	(199)
#define NODES_TREE_42 	(229)
#define NODES_TREE_43 	(221)
#define NODES_TREE_44 	(215)
#define NODES_TREE_45 	(219)
#define NODES_TREE_46 	(221)
#define NODES_TREE_47 	(233)
#define NODES_TREE_48 	(221)
#define NODES_TREE_49 	(219)
#define NODES_TREE_50 	(195)
#define NODES_TREE_51 	(221)
#define NODES_TREE_52 	(217)
#define NODES_TREE_53 	(225)
#define NODES_TREE_54 	(239)
#define NODES_TREE_55 	(221)
#define NODES_TREE_56 	(203)
#define NODES_TREE_57 	(197)
#define NODES_TREE_58 	(223)
#define NODES_TREE_59 	(233)
#define NODES_TREE_60 	(213)
#define NODES_TREE_61 	(199)
#define NODES_TREE_62 	(213)
#define NODES_TREE_63 	(203)
#define NODES_TREE_64 	(215)
#define NODES_TREE_65 	(235)
#define NODES_TREE_66 	(213)
#define NODES_TREE_67 	(223)
#define NODES_TREE_68 	(235)
#define NODES_TREE_69 	(221)
#define NODES_TREE_70 	(187)
#define NODES_TREE_71 	(201)
#define NODES_TREE_72 	(205)
#define NODES_TREE_73 	(197)
#define NODES_TREE_74 	(229)
#define NODES_TREE_75 	(211)
#define NODES_TREE_76 	(187)
#define NODES_TREE_77 	(203)
#define NODES_TREE_78 	(211)
#define NODES_TREE_79 	(203)
#define NODES_TREE_80 	(211)
#define NODES_TREE_81 	(221)
#define NODES_TREE_82 	(255)
#define NODES_TREE_83 	(243)
#define NODES_TREE_84 	(219)
#define NODES_TREE_85 	(223)
#define NODES_TREE_86 	(209)
#define NODES_TREE_87 	(195)
#define NODES_TREE_88 	(227)
#define NODES_TREE_89 	(207)
#define NODES_TREE_90 	(219)
#define NODES_TREE_91 	(213)
#define NODES_TREE_92 	(209)
#define NODES_TREE_93 	(239)
#define NODES_TREE_94 	(237)
#define NODES_TREE_95 	(203)

#define INPUT_DATATYPE uint16_t
#define FEATURES_DATATYPE uint8_t
#define THRESHOLD_DATATYPE uint16_t
#define CHILDREN_DATATYPE uint8_t

/* Packed struct necessary to avoid padding between struct entries */
struct __attribute__ ((__packed__)) RandomForest {

	/*    TREE 0    */
	/* L2 Memory Requirements = 1.15kB */

	uint8_t features_tree0[NODES_TREE_0];
	uint16_t threshold_tree0[NODES_TREE_0];
	uint8_t children_left_tree0[NODES_TREE_0];
	uint8_t children_right_tree0[NODES_TREE_0];

	/*    TREE 1    */
	/* L2 Memory Requirements = 0.99kB */

	uint8_t features_tree1[NODES_TREE_1];
	uint16_t threshold_tree1[NODES_TREE_1];
	uint8_t children_left_tree1[NODES_TREE_1];
	uint8_t children_right_tree1[NODES_TREE_1];

	/*    TREE 2    */
	/* L2 Memory Requirements = 1.06kB */

	uint8_t features_tree2[NODES_TREE_2];
	uint16_t threshold_tree2[NODES_TREE_2];
	uint8_t children_left_tree2[NODES_TREE_2];
	uint8_t children_right_tree2[NODES_TREE_2];

	/*    TREE 3    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree3[NODES_TREE_3];
	uint16_t threshold_tree3[NODES_TREE_3];
	uint8_t children_left_tree3[NODES_TREE_3];
	uint8_t children_right_tree3[NODES_TREE_3];

	/*    TREE 4    */
	/* L2 Memory Requirements = 1.22kB */

	uint8_t features_tree4[NODES_TREE_4];
	uint16_t threshold_tree4[NODES_TREE_4];
	uint8_t children_left_tree4[NODES_TREE_4];
	uint8_t children_right_tree4[NODES_TREE_4];

	/*    TREE 5    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree5[NODES_TREE_5];
	uint16_t threshold_tree5[NODES_TREE_5];
	uint8_t children_left_tree5[NODES_TREE_5];
	uint8_t children_right_tree5[NODES_TREE_5];

	/*    TREE 6    */
	/* L2 Memory Requirements = 1.14kB */

	uint8_t features_tree6[NODES_TREE_6];
	uint16_t threshold_tree6[NODES_TREE_6];
	uint8_t children_left_tree6[NODES_TREE_6];
	uint8_t children_right_tree6[NODES_TREE_6];

	/*    TREE 7    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree7[NODES_TREE_7];
	uint16_t threshold_tree7[NODES_TREE_7];
	uint8_t children_left_tree7[NODES_TREE_7];
	uint8_t children_right_tree7[NODES_TREE_7];

	/*    TREE 8    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree8[NODES_TREE_8];
	uint16_t threshold_tree8[NODES_TREE_8];
	uint8_t children_left_tree8[NODES_TREE_8];
	uint8_t children_right_tree8[NODES_TREE_8];

	/*    TREE 9    */
	/* L2 Memory Requirements = 1.07kB */

	uint8_t features_tree9[NODES_TREE_9];
	uint16_t threshold_tree9[NODES_TREE_9];
	uint8_t children_left_tree9[NODES_TREE_9];
	uint8_t children_right_tree9[NODES_TREE_9];

	/*    TREE 10    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree10[NODES_TREE_10];
	uint16_t threshold_tree10[NODES_TREE_10];
	uint8_t children_left_tree10[NODES_TREE_10];
	uint8_t children_right_tree10[NODES_TREE_10];

	/*    TREE 11    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree11[NODES_TREE_11];
	uint16_t threshold_tree11[NODES_TREE_11];
	uint8_t children_left_tree11[NODES_TREE_11];
	uint8_t children_right_tree11[NODES_TREE_11];

	/*    TREE 12    */
	/* L2 Memory Requirements = 1.03kB */

	uint8_t features_tree12[NODES_TREE_12];
	uint16_t threshold_tree12[NODES_TREE_12];
	uint8_t children_left_tree12[NODES_TREE_12];
	uint8_t children_right_tree12[NODES_TREE_12];

	/*    TREE 13    */
	/* L2 Memory Requirements = 1.16kB */

	uint8_t features_tree13[NODES_TREE_13];
	uint16_t threshold_tree13[NODES_TREE_13];
	uint8_t children_left_tree13[NODES_TREE_13];
	uint8_t children_right_tree13[NODES_TREE_13];

	/*    TREE 14    */
	/* L2 Memory Requirements = 1.21kB */

	uint8_t features_tree14[NODES_TREE_14];
	uint16_t threshold_tree14[NODES_TREE_14];
	uint8_t children_left_tree14[NODES_TREE_14];
	uint8_t children_right_tree14[NODES_TREE_14];

	/*    TREE 15    */
	/* L2 Memory Requirements = 1.20kB */

	uint8_t features_tree15[NODES_TREE_15];
	uint16_t threshold_tree15[NODES_TREE_15];
	uint8_t children_left_tree15[NODES_TREE_15];
	uint8_t children_right_tree15[NODES_TREE_15];

	/*    TREE 16    */
	/* L2 Memory Requirements = 1.11kB */

	uint8_t features_tree16[NODES_TREE_16];
	uint16_t threshold_tree16[NODES_TREE_16];
	uint8_t children_left_tree16[NODES_TREE_16];
	uint8_t children_right_tree16[NODES_TREE_16];

	/*    TREE 17    */
	/* L2 Memory Requirements = 1.04kB */

	uint8_t features_tree17[NODES_TREE_17];
	uint16_t threshold_tree17[NODES_TREE_17];
	uint8_t children_left_tree17[NODES_TREE_17];
	uint8_t children_right_tree17[NODES_TREE_17];

	/*    TREE 18    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree18[NODES_TREE_18];
	uint16_t threshold_tree18[NODES_TREE_18];
	uint8_t children_left_tree18[NODES_TREE_18];
	uint8_t children_right_tree18[NODES_TREE_18];

	/*    TREE 19    */
	/* L2 Memory Requirements = 1.04kB */

	uint8_t features_tree19[NODES_TREE_19];
	uint16_t threshold_tree19[NODES_TREE_19];
	uint8_t children_left_tree19[NODES_TREE_19];
	uint8_t children_right_tree19[NODES_TREE_19];

	/*    TREE 20    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree20[NODES_TREE_20];
	uint16_t threshold_tree20[NODES_TREE_20];
	uint8_t children_left_tree20[NODES_TREE_20];
	uint8_t children_right_tree20[NODES_TREE_20];

	/*    TREE 21    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree21[NODES_TREE_21];
	uint16_t threshold_tree21[NODES_TREE_21];
	uint8_t children_left_tree21[NODES_TREE_21];
	uint8_t children_right_tree21[NODES_TREE_21];

	/*    TREE 22    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree22[NODES_TREE_22];
	uint16_t threshold_tree22[NODES_TREE_22];
	uint8_t children_left_tree22[NODES_TREE_22];
	uint8_t children_right_tree22[NODES_TREE_22];

	/*    TREE 23    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree23[NODES_TREE_23];
	uint16_t threshold_tree23[NODES_TREE_23];
	uint8_t children_left_tree23[NODES_TREE_23];
	uint8_t children_right_tree23[NODES_TREE_23];

	/*    TREE 24    */
	/* L2 Memory Requirements = 1.17kB */

	uint8_t features_tree24[NODES_TREE_24];
	uint16_t threshold_tree24[NODES_TREE_24];
	uint8_t children_left_tree24[NODES_TREE_24];
	uint8_t children_right_tree24[NODES_TREE_24];

	/*    TREE 25    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree25[NODES_TREE_25];
	uint16_t threshold_tree25[NODES_TREE_25];
	uint8_t children_left_tree25[NODES_TREE_25];
	uint8_t children_right_tree25[NODES_TREE_25];

	/*    TREE 26    */
	/* L2 Memory Requirements = 0.93kB */

	uint8_t features_tree26[NODES_TREE_26];
	uint16_t threshold_tree26[NODES_TREE_26];
	uint8_t children_left_tree26[NODES_TREE_26];
	uint8_t children_right_tree26[NODES_TREE_26];

	/*    TREE 27    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree27[NODES_TREE_27];
	uint16_t threshold_tree27[NODES_TREE_27];
	uint8_t children_left_tree27[NODES_TREE_27];
	uint8_t children_right_tree27[NODES_TREE_27];

	/*    TREE 28    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree28[NODES_TREE_28];
	uint16_t threshold_tree28[NODES_TREE_28];
	uint8_t children_left_tree28[NODES_TREE_28];
	uint8_t children_right_tree28[NODES_TREE_28];

	/*    TREE 29    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree29[NODES_TREE_29];
	uint16_t threshold_tree29[NODES_TREE_29];
	uint8_t children_left_tree29[NODES_TREE_29];
	uint8_t children_right_tree29[NODES_TREE_29];

	/*    TREE 30    */
	/* L2 Memory Requirements = 1.06kB */

	uint8_t features_tree30[NODES_TREE_30];
	uint16_t threshold_tree30[NODES_TREE_30];
	uint8_t children_left_tree30[NODES_TREE_30];
	uint8_t children_right_tree30[NODES_TREE_30];

	/*    TREE 31    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree31[NODES_TREE_31];
	uint16_t threshold_tree31[NODES_TREE_31];
	uint8_t children_left_tree31[NODES_TREE_31];
	uint8_t children_right_tree31[NODES_TREE_31];

	/*    TREE 32    */
	/* L2 Memory Requirements = 1.12kB */

	uint8_t features_tree32[NODES_TREE_32];
	uint16_t threshold_tree32[NODES_TREE_32];
	uint8_t children_left_tree32[NODES_TREE_32];
	uint8_t children_right_tree32[NODES_TREE_32];

	/*    TREE 33    */
	/* L2 Memory Requirements = 1.05kB */

	uint8_t features_tree33[NODES_TREE_33];
	uint16_t threshold_tree33[NODES_TREE_33];
	uint8_t children_left_tree33[NODES_TREE_33];
	uint8_t children_right_tree33[NODES_TREE_33];

	/*    TREE 34    */
	/* L2 Memory Requirements = 1.15kB */

	uint8_t features_tree34[NODES_TREE_34];
	uint16_t threshold_tree34[NODES_TREE_34];
	uint8_t children_left_tree34[NODES_TREE_34];
	uint8_t children_right_tree34[NODES_TREE_34];

	/*    TREE 35    */
	/* L2 Memory Requirements = 0.92kB */

	uint8_t features_tree35[NODES_TREE_35];
	uint16_t threshold_tree35[NODES_TREE_35];
	uint8_t children_left_tree35[NODES_TREE_35];
	uint8_t children_right_tree35[NODES_TREE_35];

	/*    TREE 36    */
	/* L2 Memory Requirements = 1.19kB */

	uint8_t features_tree36[NODES_TREE_36];
	uint16_t threshold_tree36[NODES_TREE_36];
	uint8_t children_left_tree36[NODES_TREE_36];
	uint8_t children_right_tree36[NODES_TREE_36];

	/*    TREE 37    */
	/* L2 Memory Requirements = 1.04kB */

	uint8_t features_tree37[NODES_TREE_37];
	uint16_t threshold_tree37[NODES_TREE_37];
	uint8_t children_left_tree37[NODES_TREE_37];
	uint8_t children_right_tree37[NODES_TREE_37];

	/*    TREE 38    */
	/* L2 Memory Requirements = 1.04kB */

	uint8_t features_tree38[NODES_TREE_38];
	uint16_t threshold_tree38[NODES_TREE_38];
	uint8_t children_left_tree38[NODES_TREE_38];
	uint8_t children_right_tree38[NODES_TREE_38];

	/*    TREE 39    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree39[NODES_TREE_39];
	uint16_t threshold_tree39[NODES_TREE_39];
	uint8_t children_left_tree39[NODES_TREE_39];
	uint8_t children_right_tree39[NODES_TREE_39];

	/*    TREE 40    */
	/* L2 Memory Requirements = 1.17kB */

	uint8_t features_tree40[NODES_TREE_40];
	uint16_t threshold_tree40[NODES_TREE_40];
	uint8_t children_left_tree40[NODES_TREE_40];
	uint8_t children_right_tree40[NODES_TREE_40];

	/*    TREE 41    */
	/* L2 Memory Requirements = 0.99kB */

	uint8_t features_tree41[NODES_TREE_41];
	uint16_t threshold_tree41[NODES_TREE_41];
	uint8_t children_left_tree41[NODES_TREE_41];
	uint8_t children_right_tree41[NODES_TREE_41];

	/*    TREE 42    */
	/* L2 Memory Requirements = 1.15kB */

	uint8_t features_tree42[NODES_TREE_42];
	uint16_t threshold_tree42[NODES_TREE_42];
	uint8_t children_left_tree42[NODES_TREE_42];
	uint8_t children_right_tree42[NODES_TREE_42];

	/*    TREE 43    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree43[NODES_TREE_43];
	uint16_t threshold_tree43[NODES_TREE_43];
	uint8_t children_left_tree43[NODES_TREE_43];
	uint8_t children_right_tree43[NODES_TREE_43];

	/*    TREE 44    */
	/* L2 Memory Requirements = 1.07kB */

	uint8_t features_tree44[NODES_TREE_44];
	uint16_t threshold_tree44[NODES_TREE_44];
	uint8_t children_left_tree44[NODES_TREE_44];
	uint8_t children_right_tree44[NODES_TREE_44];

	/*    TREE 45    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree45[NODES_TREE_45];
	uint16_t threshold_tree45[NODES_TREE_45];
	uint8_t children_left_tree45[NODES_TREE_45];
	uint8_t children_right_tree45[NODES_TREE_45];

	/*    TREE 46    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree46[NODES_TREE_46];
	uint16_t threshold_tree46[NODES_TREE_46];
	uint8_t children_left_tree46[NODES_TREE_46];
	uint8_t children_right_tree46[NODES_TREE_46];

	/*    TREE 47    */
	/* L2 Memory Requirements = 1.17kB */

	uint8_t features_tree47[NODES_TREE_47];
	uint16_t threshold_tree47[NODES_TREE_47];
	uint8_t children_left_tree47[NODES_TREE_47];
	uint8_t children_right_tree47[NODES_TREE_47];

	/*    TREE 48    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree48[NODES_TREE_48];
	uint16_t threshold_tree48[NODES_TREE_48];
	uint8_t children_left_tree48[NODES_TREE_48];
	uint8_t children_right_tree48[NODES_TREE_48];

	/*    TREE 49    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree49[NODES_TREE_49];
	uint16_t threshold_tree49[NODES_TREE_49];
	uint8_t children_left_tree49[NODES_TREE_49];
	uint8_t children_right_tree49[NODES_TREE_49];

	/*    TREE 50    */
	/* L2 Memory Requirements = 0.97kB */

	uint8_t features_tree50[NODES_TREE_50];
	uint16_t threshold_tree50[NODES_TREE_50];
	uint8_t children_left_tree50[NODES_TREE_50];
	uint8_t children_right_tree50[NODES_TREE_50];

	/*    TREE 51    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree51[NODES_TREE_51];
	uint16_t threshold_tree51[NODES_TREE_51];
	uint8_t children_left_tree51[NODES_TREE_51];
	uint8_t children_right_tree51[NODES_TREE_51];

	/*    TREE 52    */
	/* L2 Memory Requirements = 1.08kB */

	uint8_t features_tree52[NODES_TREE_52];
	uint16_t threshold_tree52[NODES_TREE_52];
	uint8_t children_left_tree52[NODES_TREE_52];
	uint8_t children_right_tree52[NODES_TREE_52];

	/*    TREE 53    */
	/* L2 Memory Requirements = 1.12kB */

	uint8_t features_tree53[NODES_TREE_53];
	uint16_t threshold_tree53[NODES_TREE_53];
	uint8_t children_left_tree53[NODES_TREE_53];
	uint8_t children_right_tree53[NODES_TREE_53];

	/*    TREE 54    */
	/* L2 Memory Requirements = 1.20kB */

	uint8_t features_tree54[NODES_TREE_54];
	uint16_t threshold_tree54[NODES_TREE_54];
	uint8_t children_left_tree54[NODES_TREE_54];
	uint8_t children_right_tree54[NODES_TREE_54];

	/*    TREE 55    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree55[NODES_TREE_55];
	uint16_t threshold_tree55[NODES_TREE_55];
	uint8_t children_left_tree55[NODES_TREE_55];
	uint8_t children_right_tree55[NODES_TREE_55];

	/*    TREE 56    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree56[NODES_TREE_56];
	uint16_t threshold_tree56[NODES_TREE_56];
	uint8_t children_left_tree56[NODES_TREE_56];
	uint8_t children_right_tree56[NODES_TREE_56];

	/*    TREE 57    */
	/* L2 Memory Requirements = 0.98kB */

	uint8_t features_tree57[NODES_TREE_57];
	uint16_t threshold_tree57[NODES_TREE_57];
	uint8_t children_left_tree57[NODES_TREE_57];
	uint8_t children_right_tree57[NODES_TREE_57];

	/*    TREE 58    */
	/* L2 Memory Requirements = 1.11kB */

	uint8_t features_tree58[NODES_TREE_58];
	uint16_t threshold_tree58[NODES_TREE_58];
	uint8_t children_left_tree58[NODES_TREE_58];
	uint8_t children_right_tree58[NODES_TREE_58];

	/*    TREE 59    */
	/* L2 Memory Requirements = 1.17kB */

	uint8_t features_tree59[NODES_TREE_59];
	uint16_t threshold_tree59[NODES_TREE_59];
	uint8_t children_left_tree59[NODES_TREE_59];
	uint8_t children_right_tree59[NODES_TREE_59];

	/*    TREE 60    */
	/* L2 Memory Requirements = 1.06kB */

	uint8_t features_tree60[NODES_TREE_60];
	uint16_t threshold_tree60[NODES_TREE_60];
	uint8_t children_left_tree60[NODES_TREE_60];
	uint8_t children_right_tree60[NODES_TREE_60];

	/*    TREE 61    */
	/* L2 Memory Requirements = 0.99kB */

	uint8_t features_tree61[NODES_TREE_61];
	uint16_t threshold_tree61[NODES_TREE_61];
	uint8_t children_left_tree61[NODES_TREE_61];
	uint8_t children_right_tree61[NODES_TREE_61];

	/*    TREE 62    */
	/* L2 Memory Requirements = 1.06kB */

	uint8_t features_tree62[NODES_TREE_62];
	uint16_t threshold_tree62[NODES_TREE_62];
	uint8_t children_left_tree62[NODES_TREE_62];
	uint8_t children_right_tree62[NODES_TREE_62];

	/*    TREE 63    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree63[NODES_TREE_63];
	uint16_t threshold_tree63[NODES_TREE_63];
	uint8_t children_left_tree63[NODES_TREE_63];
	uint8_t children_right_tree63[NODES_TREE_63];

	/*    TREE 64    */
	/* L2 Memory Requirements = 1.07kB */

	uint8_t features_tree64[NODES_TREE_64];
	uint16_t threshold_tree64[NODES_TREE_64];
	uint8_t children_left_tree64[NODES_TREE_64];
	uint8_t children_right_tree64[NODES_TREE_64];

	/*    TREE 65    */
	/* L2 Memory Requirements = 1.18kB */

	uint8_t features_tree65[NODES_TREE_65];
	uint16_t threshold_tree65[NODES_TREE_65];
	uint8_t children_left_tree65[NODES_TREE_65];
	uint8_t children_right_tree65[NODES_TREE_65];

	/*    TREE 66    */
	/* L2 Memory Requirements = 1.06kB */

	uint8_t features_tree66[NODES_TREE_66];
	uint16_t threshold_tree66[NODES_TREE_66];
	uint8_t children_left_tree66[NODES_TREE_66];
	uint8_t children_right_tree66[NODES_TREE_66];

	/*    TREE 67    */
	/* L2 Memory Requirements = 1.11kB */

	uint8_t features_tree67[NODES_TREE_67];
	uint16_t threshold_tree67[NODES_TREE_67];
	uint8_t children_left_tree67[NODES_TREE_67];
	uint8_t children_right_tree67[NODES_TREE_67];

	/*    TREE 68    */
	/* L2 Memory Requirements = 1.18kB */

	uint8_t features_tree68[NODES_TREE_68];
	uint16_t threshold_tree68[NODES_TREE_68];
	uint8_t children_left_tree68[NODES_TREE_68];
	uint8_t children_right_tree68[NODES_TREE_68];

	/*    TREE 69    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree69[NODES_TREE_69];
	uint16_t threshold_tree69[NODES_TREE_69];
	uint8_t children_left_tree69[NODES_TREE_69];
	uint8_t children_right_tree69[NODES_TREE_69];

	/*    TREE 70    */
	/* L2 Memory Requirements = 0.94kB */

	uint8_t features_tree70[NODES_TREE_70];
	uint16_t threshold_tree70[NODES_TREE_70];
	uint8_t children_left_tree70[NODES_TREE_70];
	uint8_t children_right_tree70[NODES_TREE_70];

	/*    TREE 71    */
	/* L2 Memory Requirements = 1.01kB */

	uint8_t features_tree71[NODES_TREE_71];
	uint16_t threshold_tree71[NODES_TREE_71];
	uint8_t children_left_tree71[NODES_TREE_71];
	uint8_t children_right_tree71[NODES_TREE_71];

	/*    TREE 72    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree72[NODES_TREE_72];
	uint16_t threshold_tree72[NODES_TREE_72];
	uint8_t children_left_tree72[NODES_TREE_72];
	uint8_t children_right_tree72[NODES_TREE_72];

	/*    TREE 73    */
	/* L2 Memory Requirements = 0.98kB */

	uint8_t features_tree73[NODES_TREE_73];
	uint16_t threshold_tree73[NODES_TREE_73];
	uint8_t children_left_tree73[NODES_TREE_73];
	uint8_t children_right_tree73[NODES_TREE_73];

	/*    TREE 74    */
	/* L2 Memory Requirements = 1.15kB */

	uint8_t features_tree74[NODES_TREE_74];
	uint16_t threshold_tree74[NODES_TREE_74];
	uint8_t children_left_tree74[NODES_TREE_74];
	uint8_t children_right_tree74[NODES_TREE_74];

	/*    TREE 75    */
	/* L2 Memory Requirements = 1.05kB */

	uint8_t features_tree75[NODES_TREE_75];
	uint16_t threshold_tree75[NODES_TREE_75];
	uint8_t children_left_tree75[NODES_TREE_75];
	uint8_t children_right_tree75[NODES_TREE_75];

	/*    TREE 76    */
	/* L2 Memory Requirements = 0.94kB */

	uint8_t features_tree76[NODES_TREE_76];
	uint16_t threshold_tree76[NODES_TREE_76];
	uint8_t children_left_tree76[NODES_TREE_76];
	uint8_t children_right_tree76[NODES_TREE_76];

	/*    TREE 77    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree77[NODES_TREE_77];
	uint16_t threshold_tree77[NODES_TREE_77];
	uint8_t children_left_tree77[NODES_TREE_77];
	uint8_t children_right_tree77[NODES_TREE_77];

	/*    TREE 78    */
	/* L2 Memory Requirements = 1.05kB */

	uint8_t features_tree78[NODES_TREE_78];
	uint16_t threshold_tree78[NODES_TREE_78];
	uint8_t children_left_tree78[NODES_TREE_78];
	uint8_t children_right_tree78[NODES_TREE_78];

	/*    TREE 79    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree79[NODES_TREE_79];
	uint16_t threshold_tree79[NODES_TREE_79];
	uint8_t children_left_tree79[NODES_TREE_79];
	uint8_t children_right_tree79[NODES_TREE_79];

	/*    TREE 80    */
	/* L2 Memory Requirements = 1.05kB */

	uint8_t features_tree80[NODES_TREE_80];
	uint16_t threshold_tree80[NODES_TREE_80];
	uint8_t children_left_tree80[NODES_TREE_80];
	uint8_t children_right_tree80[NODES_TREE_80];

	/*    TREE 81    */
	/* L2 Memory Requirements = 1.10kB */

	uint8_t features_tree81[NODES_TREE_81];
	uint16_t threshold_tree81[NODES_TREE_81];
	uint8_t children_left_tree81[NODES_TREE_81];
	uint8_t children_right_tree81[NODES_TREE_81];

	/*    TREE 82    */
	/* L2 Memory Requirements = 1.28kB */

	uint8_t features_tree82[NODES_TREE_82];
	uint16_t threshold_tree82[NODES_TREE_82];
	uint8_t children_left_tree82[NODES_TREE_82];
	uint8_t children_right_tree82[NODES_TREE_82];

	/*    TREE 83    */
	/* L2 Memory Requirements = 1.22kB */

	uint8_t features_tree83[NODES_TREE_83];
	uint16_t threshold_tree83[NODES_TREE_83];
	uint8_t children_left_tree83[NODES_TREE_83];
	uint8_t children_right_tree83[NODES_TREE_83];

	/*    TREE 84    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree84[NODES_TREE_84];
	uint16_t threshold_tree84[NODES_TREE_84];
	uint8_t children_left_tree84[NODES_TREE_84];
	uint8_t children_right_tree84[NODES_TREE_84];

	/*    TREE 85    */
	/* L2 Memory Requirements = 1.11kB */

	uint8_t features_tree85[NODES_TREE_85];
	uint16_t threshold_tree85[NODES_TREE_85];
	uint8_t children_left_tree85[NODES_TREE_85];
	uint8_t children_right_tree85[NODES_TREE_85];

	/*    TREE 86    */
	/* L2 Memory Requirements = 1.04kB */

	uint8_t features_tree86[NODES_TREE_86];
	uint16_t threshold_tree86[NODES_TREE_86];
	uint8_t children_left_tree86[NODES_TREE_86];
	uint8_t children_right_tree86[NODES_TREE_86];

	/*    TREE 87    */
	/* L2 Memory Requirements = 0.97kB */

	uint8_t features_tree87[NODES_TREE_87];
	uint16_t threshold_tree87[NODES_TREE_87];
	uint8_t children_left_tree87[NODES_TREE_87];
	uint8_t children_right_tree87[NODES_TREE_87];

	/*    TREE 88    */
	/* L2 Memory Requirements = 1.14kB */

	uint8_t features_tree88[NODES_TREE_88];
	uint16_t threshold_tree88[NODES_TREE_88];
	uint8_t children_left_tree88[NODES_TREE_88];
	uint8_t children_right_tree88[NODES_TREE_88];

	/*    TREE 89    */
	/* L2 Memory Requirements = 1.03kB */

	uint8_t features_tree89[NODES_TREE_89];
	uint16_t threshold_tree89[NODES_TREE_89];
	uint8_t children_left_tree89[NODES_TREE_89];
	uint8_t children_right_tree89[NODES_TREE_89];

	/*    TREE 90    */
	/* L2 Memory Requirements = 1.09kB */

	uint8_t features_tree90[NODES_TREE_90];
	uint16_t threshold_tree90[NODES_TREE_90];
	uint8_t children_left_tree90[NODES_TREE_90];
	uint8_t children_right_tree90[NODES_TREE_90];

	/*    TREE 91    */
	/* L2 Memory Requirements = 1.06kB */

	uint8_t features_tree91[NODES_TREE_91];
	uint16_t threshold_tree91[NODES_TREE_91];
	uint8_t children_left_tree91[NODES_TREE_91];
	uint8_t children_right_tree91[NODES_TREE_91];

	/*    TREE 92    */
	/* L2 Memory Requirements = 1.04kB */

	uint8_t features_tree92[NODES_TREE_92];
	uint16_t threshold_tree92[NODES_TREE_92];
	uint8_t children_left_tree92[NODES_TREE_92];
	uint8_t children_right_tree92[NODES_TREE_92];

	/*    TREE 93    */
	/* L2 Memory Requirements = 1.20kB */

	uint8_t features_tree93[NODES_TREE_93];
	uint16_t threshold_tree93[NODES_TREE_93];
	uint8_t children_left_tree93[NODES_TREE_93];
	uint8_t children_right_tree93[NODES_TREE_93];

	/*    TREE 94    */
	/* L2 Memory Requirements = 1.19kB */

	uint8_t features_tree94[NODES_TREE_94];
	uint16_t threshold_tree94[NODES_TREE_94];
	uint8_t children_left_tree94[NODES_TREE_94];
	uint8_t children_right_tree94[NODES_TREE_94];

	/*    TREE 95    */
	/* L2 Memory Requirements = 1.02kB */

	uint8_t features_tree95[NODES_TREE_95];
	uint16_t threshold_tree95[NODES_TREE_95];
	uint8_t children_left_tree95[NODES_TREE_95];
	uint8_t children_right_tree95[NODES_TREE_95];

} randomforest;


/* L1 Memory Requirements = 0.48kB */

uint32_t treeDim[N_TREES];
uint32_t paramAddr[N_TREES*3];


#endif


#endif 


