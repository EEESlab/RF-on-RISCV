#ifndef __DEBUG_H__
#define __DEBUG_H__

#ifdef DEBUG

#define INIT_DEBUG() \
	PI_CL_L1 float acc = 0;

#define START_DEBUG() \
	if (class_idx == y_test[i]) acc++;

#define START_DEBUG_1() \
	if (class_idx == y_test[i - 1]) acc++;

#define START_DEBUG_2() \
	if (class_idx == y_test[N_LOOP - 1]) acc++;

#define START_DEBUG_3() \
	for (int i = 0; i < N_LOOP; ++i) if (class_idx[i] == y_test[i]) acc++;

#define PRINT_DEBUG_RESULT() \
	printf("Model Accuracy = %f%%\n",(acc/N_LOOP)*100);

#else // !DEBUG

#define INIT_DEBUG()
#define START_DEBUG()
#define START_DEBUG_1()
#define START_DEBUG_2()
#define START_DEBUG_3()
#define PRINT_DEBUG_RESULT()

#endif

#endif