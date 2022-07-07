#include <stdint.h>
#include <stdio.h>

/* PMSIS includes */
#include "pmsis.h"
#include "params.h"
#include "data.h"
#include "dt-arr-baseline.h"
#include "dt-arr-utils.h"
#include "debug.h"
#include "stats.h"
#include "stats_fpu.h"

#define N_SOL           (12)
#define DMA_TREES       (12)

#define DMA_NODES_MAX ({ \
    uint32_t id = 0; \
    for (int i = 0; i < N_SOL; i++) \
        if (DMA_TREES == dma_trees[i]) id = i;\
    max_nodes[id]; \
})

#define FEATURE_BYTES   (2) 
#define THRESHOLD_BYTES (4) 
#define CHILDREN_BYTES  (1) 
#define NODE_BYTES      (FEATURE_BYTES + THRESHOLD_BYTES + 2*CHILDREN_BYTES)

#define DMA_ITER (N_TREES/DMA_TREES)
 
#define DMA_TRANSFER_BYTESIZE(start, trees) ({ \
    uint32_t retval = 0; \
    for (int k = start*trees; k < (start + 1)*trees; ++k) \
        retval += treeDim[k] * NODE_BYTES; \
    retval; \
})

PI_CL_L1 uint32_t max_nodes[N_SOL] = {255, 498, 741, 982, 1460, 1936, 2876, 3806, 5626, 7402, 10930, 20832};
PI_CL_L1 uint32_t dma_trees[N_SOL] = {1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48, 96};

PI_CL_L1 uint32_t class_idx[N_LOOP] = {0};
PI_CL_L1 uint32_t score[N_CLASS] = {0};
PI_CL_L1 uint32_t transferID = 0;

PI_CL_L1 uint8_t *dmaModelBuffer1 = NULL;
PI_CL_L1 uint8_t *dmaModelBuffer2 = NULL;
PI_CL_L1 uint8_t *modelBuffer = NULL;
PI_CL_L1 uint8_t *modelBufferArr[2] = {NULL};

INIT_DEBUG();
INIT_STATS();
INIT_STATS_FPU();


/* Task executed by cluster cores. */
void cluster_rf(void *arg)
{
    ENTER_LOOP_FPU();
    START_STATS_FPU();

    int16_t *__features = (int16_t *)(modelBuffer);
    float *__threshold = (float *)(__features + treeDim[transferID*DMA_TREES]);
    uint8_t *__children_left = (uint8_t *)(__threshold + treeDim[transferID*DMA_TREES]);
    uint8_t *__children_right = (uint8_t *)(__children_left + treeDim[transferID*DMA_TREES]);
    score[dt_arr_baseline(arg , __features, __threshold, __children_left, __children_right)]++;

    for (int i = 1; i < DMA_TREES; ++i)
    {    
        __features = (int16_t *)(__children_right + treeDim[transferID*DMA_TREES + i - 1]);
        __threshold = (float *)(__features + treeDim[transferID*DMA_TREES + i]);
        __children_left = (uint8_t *)(__threshold + treeDim[transferID*DMA_TREES + i]);
        __children_right = (uint8_t *)(__children_left + treeDim[transferID*DMA_TREES + i]);   
        score[dt_arr_baseline(arg , __features, __threshold, __children_left, __children_right)]++;
    }

    STOP_STATS_FPU();
    EXIT_LOOP_FPU();
}


/* Cluster main entry, executed by core 0. */
void cluster_delegate(void *arg)
{
    printf("Cluster master core entry\n");

    uint32_t idx = 0;

    pi_cl_dma_cmd_t DmaR_Evt1;
    pi_cl_dma_cmd_t DmaR_Evt2;
    pi_cl_dma_cmd_t *DmaR_EvtModel[2] = {&DmaR_Evt1, &DmaR_Evt2};

    uint32_t dma_transfer_size[DMA_ITER] = {0};
    for (int j = 0; j < DMA_ITER; j++) 
        dma_transfer_size[j] = DMA_TRANSFER_BYTESIZE(j,DMA_TREES);
  
    /* Transfer 1st param chunck */
    pi_cl_dma_cmd((uint32_t) (paramAddr[0*(DMA_TREES*3)]), (uint32_t) modelBufferArr[idx], dma_transfer_size[0], PI_CL_DMA_DIR_EXT2LOC, DmaR_EvtModel[idx]);
    pi_cl_dma_cmd_wait(DmaR_EvtModel[idx]);

    ENTER_LOOP_STATS();
    START_STATS();

    for (int i = 0; i < N_LOOP; ++i)
    {
        for (int j = 1; j < DMA_ITER; j++)
        {
            /* Transfer ith param chunk */
            pi_cl_dma_cmd((uint32_t) (paramAddr[j*(DMA_TREES*3)]),  (uint32_t) modelBufferArr[!idx], dma_transfer_size[j], PI_CL_DMA_DIR_EXT2LOC, DmaR_EvtModel[!idx]);
        
            //START_STATS();
            /* Task dispatch to cluster cores. */
            modelBuffer = modelBufferArr[idx];
            pi_cl_team_fork(N_CORES, cluster_rf, (INPUT_DATATYPE *) (x_test + i*DIM));
            transferID++;
            //STOP_STATS();

            pi_cl_dma_cmd_wait(DmaR_EvtModel[!idx]);
            idx = !idx;
        }

        pi_cl_dma_cmd((uint32_t) (paramAddr[0*(DMA_TREES*3)]), (uint32_t) modelBufferArr[!idx], dma_transfer_size[0], PI_CL_DMA_DIR_EXT2LOC, DmaR_EvtModel[!idx]);
        
        //START_STATS();
        modelBuffer = modelBufferArr[idx];    
        pi_cl_team_fork(N_CORES, cluster_rf, (INPUT_DATATYPE *) (x_test + i*DIM));
        transferID = 0;
        //STOP_STATS();

        pi_cl_dma_cmd_wait(DmaR_EvtModel[!idx]);    
        idx = !idx;
        
        #ifdef DEBUG
        for (int j = 1; j < N_CLASS; j++) if (score[class_idx[i]] < score[j]) class_idx[i] = j;
        for (int j = 0; j < N_CLASS; j++) score[j] = 0;
        #endif

    }

    STOP_STATS();    
    START_DEBUG_3();
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
    printf("[%d %d] Starting rf2arr Double Buffer Sequential!\n", cluster_id, core_id);

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

    /* Allocating DMA Double-Buffering buffers in L1 */
    dmaModelBuffer1 = (uint8_t *) pi_cl_l1_malloc(&cluster_dev, (uint32_t) (NODE_BYTES * DMA_NODES_MAX));
    dmaModelBuffer2 = (uint8_t *) pi_cl_l1_malloc(&cluster_dev, (uint32_t) (NODE_BYTES * DMA_NODES_MAX));

    modelBufferArr[0] = dmaModelBuffer1;
    modelBufferArr[1] = dmaModelBuffer2;

    for (int i = 0; i < (NODE_BYTES * DMA_NODES_MAX); i++)
    {
        dmaModelBuffer1[i] = 0;
        dmaModelBuffer2[i] = 0;
    }

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
    printf("\n\n\t *** PMSIS ***\n\n");
    return pmsis_kickoff((void *) fabric_controller);
}