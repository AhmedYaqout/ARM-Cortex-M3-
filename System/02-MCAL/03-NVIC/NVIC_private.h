/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   21/Aug/2020
 *  Type    :   NVIC Private File
 *  Version :   V1.0
 */ 

#ifndef NVIC_PRIVATE_H 
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS   0xE000E100
#define SCB_BASE_ADDRESS    0xE000ED00
#define NVIC_ISER0  NVIC_BASE_ADDRESS /* Enable External Interrupts fro 0 to 31*/
#define NVIC_ISER1  *((u32*)(NVIC_BASE_ADDRESS+0x004)) 
#define NVIC_ISER2  *((u32*)(NVIC_BASE_ADDRESS+0x008))
#define NVIC_ICER0  *((u32*)(NVIC_BASE_ADDRESS+0x080))
#define NVIC_ICER1  *((u32*)(NVIC_BASE_ADDRESS+0x084))
#define NVIC_ICER2  *((u32*)(NVIC_BASE_ADDRESS+0x088))
#define NVIC_ISPR0  *((u32*)(NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1  *((u32*)(NVIC_BASE_ADDRESS+0x104))
#define NVIC_ISPR2  *((u32*)(NVIC_BASE_ADDRESS+0x108))
#define NVIC_ICPR0  *((u32*)(NVIC_BASE_ADDRESS+0x180))
#define NVIC_ICPR1  *((u32*)(NVIC_BASE_ADDRESS+0x184))
#define NVIC_ICPR2  *((u32*)(NVIC_BASE_ADDRESS+0x188))
#define NVIC_IABR0  *((volatile u32*)(NVIC_BASE_ADDRESS+0x200))
#define NVIC_IABR1  *((volatile u32*)(NVIC_BASE_ADDRESS+0x204))
#define NVIC_IABR2  *((volatile u32*)(NVIC_BASE_ADDRESS+0x208))
#define NVIC_IPR    ((u32*)(NVIC_BASE_ADDRESS+0x300))
#define SCB_AIRCR   *((volatile u32 *)  SCB_BASE_ADDRESS+0x0C)


#define NVIC_STIR   (NVIC_BASE_ADDRESS+0xE00)


#endif