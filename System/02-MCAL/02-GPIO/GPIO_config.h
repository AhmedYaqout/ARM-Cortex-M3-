/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   17/Aug/2020
 *  Type    :   GPIO Configuration File
 *  Version :   V1.0
 */ 

#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#define INPUT_ANALOG                0b0000
#define INPUT_FLOATING              0b0100
#define INPUT_PULL_UP_DOWN          0b1000

#define OUTPUT_GP_PP_10MHZ          0b0001
#define OUTPUT_GP_PP_2MHZ           0b0010
#define OUTPUT_GP_PP_50MHZ          0b0011

#define OUTPUT_GP_OD_10MHZ          0b0101
#define OUTPUT_GP_OD_2MHZ           0b0110
#define OUTPUT_GP_OD_50MHZ          0b0111

#define OUTPUT_AF_PP_10MHZ          0b1001
#define OUTPUT_AF_PP_2MHZ           0b1010
#define OUTPUT_AF_PP_50MHZ          0b1011

#define OUTPUT_AF_OD_10MHZ          0b1101
#define OUTPUT_AF_OD_2MHZ           0b1110
#define OUTPUT_AF_OD_50MHZ          0b1111
#endif