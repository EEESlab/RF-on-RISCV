#ifndef __DATA_H__
#define __DATA_H__


/* Testing Data */


#ifdef  MFEAT_FACTORS

/* MFEAT-FACTORS Dataset */
/* Total L1 Memory Requirements = 4.33kB */ 
/* Total L2 Memory Requirements = 0.00kB */

uint16_t x_test[DIM*N_TEST];
uint8_t y_test[N_TEST];

#endif 


#ifdef  VEHICLE

/* VEHICLE Dataset */
/* Total L1 Memory Requirements = 0.37kB */ 
/* Total L2 Memory Requirements = 0.00kB */

uint16_t x_test[DIM*N_TEST];
uint8_t y_test[N_TEST];

#endif 


#endif
