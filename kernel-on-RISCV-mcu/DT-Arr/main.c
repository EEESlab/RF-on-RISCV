#include <stdint.h>
#include <stdio.h>

/* PMSIS includes */
#include "pmsis.h"
#include "params.h"
#include "data.h"
#include "dt-arr.h"
#include "dt-arr-utils.h"
#include "debug.h"
#include "stats.h"
#include "stats_fpu.h"

PI_CL_L1 int class_idx = 0;

#ifdef MFEAT_FACTORS
PI_CL_L1 int score[N_CLASS] = {0};
#endif

INIT_DEBUG();
INIT_STATS();
INIT_STATS_FPU();

/* Task executed by cluster cores. */
void cluster_rf(void *arg)
{

    ENTER_LOOP_FPU();
    START_STATS_FPU();

    #if defined VEHICLE
    rf_arr_vehicle((float *) arg, features, threshold, children, &class_idx);
    #elif defined MFEAT_FACTORS
    rf_arr_mfeat_factors((float *) arg, features, threshold, children, &class_idx, score);
    #endif

    STOP_STATS_FPU();
    EXIT_LOOP_FPU();

}

/* Cluster main entry, executed by core 0. */
void cluster_delegate(void *arg)
{
    printf("Cluster master core entry\n");

    #ifdef RF2ARR_V0
    int nodes[N_TREES] = {NODES_TREE_0 ,NODES_TREE_1 ,NODES_TREE_2 ,NODES_TREE_3 ,NODES_TREE_4 ,NODES_TREE_5 ,NODES_TREE_6 ,NODES_TREE_7 ,NODES_TREE_8 ,NODES_TREE_9 ,NODES_TREE_10 ,NODES_TREE_11 ,NODES_TREE_12 ,NODES_TREE_13 ,NODES_TREE_14 ,NODES_TREE_15};    
    for (int i = 0; i < N_TREES; ++i)
    {
        for (int j = 0; j < nodes[i]; ++j)
        {
            #ifdef VEHICLE
            if (*(features[i] + j) != (WHILE_CONDITION)) *(features[i] + j) = *(features[i] + j) / 4;
            #endif
            *(children[i] + 2*j    ) = *(children[i] + 2*j    ) / 4;
            *(children[i] + 2*j + 1) = *(children[i] + 2*j + 1) / 4;
        }
    }
    #endif

    ENTER_LOOP_STATS();
    START_STATS();
    
    for (int i = 0; i < N_LOOP; i++)
    {
        /* Task dispatch to cluster cores. */
        pi_cl_team_fork(N_CORES, cluster_rf, ((float *) (x_test + i*DIM)));
        START_DEBUG();
    }

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
    printf("[%d %d] Starting RF!\n", cluster_id, core_id);

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
    printf("\n\n\t *** PMSIS start ***\n\n");
    return pmsis_kickoff((void *) fabric_controller);
}