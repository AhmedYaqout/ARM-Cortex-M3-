/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   21/Aug/2020
 *  Type    :   NVIC Interface File
 *  Version :   V1.0
 */ 

#ifndef NVIC_INTERFACE_H 
#define NVIC_INTERFACE_H

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNo);
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNo);
void NVIC_voidEnablePendingInterrupt(u8 Copy_u8InterruptNo);
void NVIC_voidDisablePendingInterrupt(u8 Copy_u8InterruptNo);
u8 NVIC_u8GetActiveInterrupt(u8 Copy_u8InterruptNo);
#define GROUP3  0x05FA0300  /* 4 Bits for group  (IPR)*/
#define GROUP4  0x05FA0400/* 3 Bits for group  and 1 bit for sub(IPR)*/
#define GROUP5  0x05FA0500/* 2 Bits for group and 2 bits for subgroup  (IPR)*/
#define GROUP6  0x05FA0600/* 1 Bit for group and 3 bits for subgroup (IPR)*/
#define GROUP7  0x05FA0700/* no Bits for group and 4 bits for subgroup  (IPR)*/

#endif