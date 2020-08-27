/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   25/Aug/2020
 *  Type    :   SysTick Private File
 *  Version :   V1.0
 */

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

typedef struct
{
    volatile u32 CTRL;   /* SysTick control and status register */
    volatile u32 LOAD;  /* SysTick reload value register */
    volatile u32 VAL;   /* SysTick current value register */
    volatile u32 CALIB; /* SysTick current value register */
} SYSTICK_t;


#define SYSTICK *((volatile SYSTICK_t *)0xE000E010)
#endif