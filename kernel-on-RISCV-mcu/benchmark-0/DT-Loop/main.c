#include <stdint.h>
#include <stdio.h>

/* PMSIS includes */
#include "pmsis.h"
#include "params.h"
#include "data.h"
#include "dt-loop.h"
#include "dt-loop-utils.h"
#include "debug.h"
#include "stats.h"
#include "stats_fpu.h"

PI_CL_L1 int class_idx = 0;

#ifdef MFEAT_FACTORS

PI_CL_L1 INPUT_DATATYPE *dmaTestBuffer1 = NULL;
PI_CL_L1 INPUT_DATATYPE *dmaTestBuffer2 = NULL;
PI_CL_L1 INPUT_DATATYPE *testBuffer = NULL;
PI_CL_L1 INPUT_DATATYPE *testBufferArr[2] = {NULL};

#endif

INIT_DEBUG();
INIT_STATS();
INIT_STATS_FPU();

/* Task executed by cluster cores. */
void cluster_rf(void *arg)
{

    ENTER_LOOP_FPU();
    START_STATS_FPU();

    uint32_t core_id = pi_core_id();

    rf2loop_prediction(arg, randomForest, &class_idx, N_TREES, N_CLASS);

    STOP_STATS_FPU();
    EXIT_LOOP_FPU();

}

/* Cluster main entry, executed by core 0. */
void cluster_delegate(void *arg)
{
    printf("Cluster master core entry\n");

#ifdef MFEAT_FACTORS

    uint32_t input_idx = 0;

    pi_cl_dma_cmd_t DmaR_Evt1;
    pi_cl_dma_cmd_t DmaR_Evt2;
    pi_cl_dma_cmd_t *DmaR_EvtInput[2]   = {&DmaR_Evt1, &DmaR_Evt2};

    /* Transfer 1st test Input */
    pi_cl_dma_cmd((uint32_t) (x_test), (uint32_t) testBufferArr[input_idx], DIM*INPUT_BYTES,  PI_CL_DMA_DIR_EXT2LOC, DmaR_EvtInput[input_idx]);
    pi_cl_dma_cmd_wait(DmaR_EvtInput[input_idx]);
    
    ENTER_LOOP_STATS();
    START_STATS();

    for (int i = 1; i < N_LOOP; i++)
    {
        /* Transfer ith test Input */
        pi_cl_dma_cmd((uint32_t) (x_test + i*DIM), (uint32_t) testBufferArr[!input_idx], DIM*INPUT_BYTES,  PI_CL_DMA_DIR_EXT2LOC, DmaR_EvtInput[!input_idx]);
        
        testBuffer = testBufferArr[input_idx];
        pi_cl_team_fork(N_CORES, cluster_rf, ((INPUT_DATATYPE *) testBuffer));
        START_DEBUG_1();

        pi_cl_dma_cmd_wait(DmaR_EvtInput[!input_idx]);
        input_idx = !input_idx;
    }

    testBuffer = testBufferArr[input_idx];
    pi_cl_team_fork(N_CORES, cluster_rf, ((INPUT_DATATYPE *) testBuffer));

    START_DEBUG_2();

#else

    ENTER_LOOP_STATS();
    START_STATS();

   for (int i = 0; i < N_LOOP; i++)
   {
       /* Task dispatch to cluster cores. */
       pi_cl_team_fork(N_CORES, cluster_rf, ((INPUT_DATATYPE *) x_test) + i*DIM);
       START_DEBUG();
   }

#endif

    STOP_STATS();
    EXIT_LOOP_STATS();
    PRINT_STATS_FPU();
    PRINT_DEBUG_RESULT();

    printf("Cluster master core exit\n");
}

void fabric_controller(void)
{
    printf("Entering main controller\n");

    int errors = 0;
    int core_id = pi_core_id(), cluster_id = pi_cluster_id();
    printf("[%d %d] Starting rf2loop Sequential!\n", cluster_id, core_id);

    struct pi_device cluster_dev = {0};
    struct pi_cluster_conf cl_conf = {0};

    /* Init cluster configuration structure. */
    pi_cluster_conf_init(&cl_conf);

    /* Set cluster ID. */
    cl_conf.id = 0;               
    
    /* Configure & open cluster. */
    pi_open_from_conf(&cluster_dev, &cl_conf);
    
    if (pi_cluster_open(&cluster_dev))
    {
        printf("Cluster open failed !\n");
        pmsis_exit(-1);
    }

    #ifdef MFEAT_FACTORS

    /* Allocating DMA Double-Buffering buffers in L1 */
    dmaTestBuffer1 = (INPUT_DATATYPE *) pi_cl_l1_malloc(&cluster_dev, (uint32_t) (INPUT_BYTES*DIM));
    dmaTestBuffer2 = (INPUT_DATATYPE *) pi_cl_l1_malloc(&cluster_dev, (uint32_t) (INPUT_BYTES*DIM));

    testBufferArr[0] = dmaTestBuffer1;
    testBufferArr[1] = dmaTestBuffer2;

    for (int i = 0; i < DIM; i++)
    {
        dmaTestBuffer1[i] = 0;
        dmaTestBuffer2[i] = 0;
    }

    #endif

    /* Prepare cluster task and send it to cluster. */
    struct pi_cluster_task cl_task = {0};
    pi_cluster_task(&cl_task, cluster_delegate, NULL);
    cl_task.stack_size = (uint32_t) STACK_SIZE;

    pi_cluster_send_task_to_cl(&cluster_dev, &cl_task);
    pi_cluster_close(&cluster_dev);

    printf("Test success !\n");
    pmsis_exit(errors);
}


/* Program Entry. */
int main(void)
{
    printf("\n\n\t *** PMSIS rf2loop Sequential ***\n\n");
    return pmsis_kickoff((void *) fabric_controller);
}