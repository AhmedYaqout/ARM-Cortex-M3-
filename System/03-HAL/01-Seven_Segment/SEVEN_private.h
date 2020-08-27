/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   18/Aug/2020
 *  Type    :   Seven Segment Private File
 *  Version :   V1.0
 */ 

#ifndef SEVEN_PRIVATE_H 
#define SEVEN_PRIVATE_H
/* declares structure type with these parameters  */
typedef struct {
    u8 SEVEN_u8Mode;
    u8 SEVEN_u8PinPortA;
    u8 SEVEN_u8PinA;
    u8 SEVEN_u8PinPortB;
    u8 SEVEN_u8PinB;
    u8 SEVEN_u8PinPortC;
    u8 SEVEN_u8PinC;
    u8 SEVEN_u8PinPortD;
    u8 SEVEN_u8PinD;
    u8 SEVEN_u8PinPortE;
    u8 SEVEN_u8PinE;
    u8 SEVEN_u8PinPortF;
    u8 SEVEN_u8PinF;
    u8 SEVEN_u8PinPortG;
    u8 SEVEN_u8PinG;
    u8 SEVEN_u8PinPortDot;
    u8 SEVEN_u8PinDot;
}SEVEN_strPinMap;

/* declares a SPECIFIC structure which is defined in config.c as it will be compiled in the runtime */
extern SEVEN_strPinMap SEVEN_astrPinMap[Copy_u8DisplayQty];
#endif
