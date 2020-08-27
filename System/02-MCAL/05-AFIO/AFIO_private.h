/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   24/Aug/2020
 *  Type    :   Alternative Functions Private File
 *  Version :   V1.0
 */ 

#ifndef AFIO_PRIVATE_H 
#define AFIO_PRIVATE_H

typedef struct 
{
    volatile u32   EVCR;     /* Event control register */
    volatile u32   MAPR;     /* AF remap and debug I/O configuration register */
    volatile u32   EXTICR[4];    /* External interrupt configuration registers [1 - 4]  */
    volatile u32   MAPR2;      /* AF remap and debug I/O configuration register 2  */
} AFIO_t;

#define AFIO    *((volatile AFIO_t *) 0x40010000)
#endif