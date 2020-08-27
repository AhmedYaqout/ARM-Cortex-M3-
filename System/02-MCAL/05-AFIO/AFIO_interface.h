/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   24/Aug/2020
 *  Type    :   Alternative Functions Interface File
 *  Version :   V1.0
 */ 

#ifndef AFIO_INTERFACE_H 
#define AFIO_INTERFACE_H

#define AFIO_PA     0b0000
#define AFIO_PB     0b0001
#define AFIO_PC     0b0010
#define AFIO_PD     0b0011
#define AFIO_PE     0b0100
#define AFIO_PF     0b0101
#define AFIO_PG     0b0110


void AFIO_voidSetEXTIConfig(u8 Copy_u8Line, u8 Copy_u8PortMap);
#endif