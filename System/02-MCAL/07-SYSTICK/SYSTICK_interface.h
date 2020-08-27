/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   25/Aug/2020
 *  Type    :   SysTick Interface File
 *  Version :   V1.0
 */

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#define SYSTICK_AHB_FREQUENCY       8000000
#define SYSTICK_AHB_DIV_8           0x0000
#define SYSTICK_AHB                 0x0004
#define SYSTICK_INTERRUPT_EN        0x0002
#define SYSTICK_INTERRUPT_NOT_EN    0x0000
#define SYSTICK_ENABLE              0x0001
#define SYSTICK_DISABLE             0x0000

#define SYSTICK_CLKSOURCE_LOCATION      2
#define SYSTICK_TICKINT_LOCATION        1
#define SYSTICK_ENABLE_LOCATION         0
#define SYSTICK_COUNTFLAG_LOCATION      16

void SYSTICK_voidInit(Copy_u8ClkSrc);
void SYSTICK_voidSetBusyWait(void);
void SYSTICK_voidDelayMs(u32 Copy_u32TimeValue, void (*Copy_pfFunction)(void));
void SYSTICK_voidPeriodicDelayMs(u32 Copy_u32TimeValue, void (*Copy_pfFunction)(void));
void SYSTICK_voidStopTimer(void);
void SYSTICK_voidGetElapsedTime(u32 * Copy_Pu32Time);
void SYSTICK_voidGetRemainingTime(u32 * Copy_Pu32Time);

#endif