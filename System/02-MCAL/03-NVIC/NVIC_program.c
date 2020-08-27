/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   21/Aug/2020
 *  Type    :   NVIC Program Executable File
 *  Version :   V1.0
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptNo)
{
    if (Copy_u8InterruptNo <= 31)
    {
        NVIC_ISER0 = (1<<Copy_u8InterruptNo);
    }
    else if (Copy_u8InterruptNo <= 59)
    {
        Copy_u8InterruptNo -= 32;
        NVIC_ISER1 = (1<<Copy_u8InterruptNo);
    }
    else
    {
     /* Return Error*/
    }
    
}

void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptNo)
{
    if (Copy_u8InterruptNo <= 31)
    {
        NVIC_ICER0 = (1<<Copy_u8InterruptNo);
    }
    else if (Copy_u8InterruptNo <= 59)
    {
        Copy_u8InterruptNo -= 32;
        NVIC_ICER1 = (1<<Copy_u8InterruptNo);
    }
    else
    {
     /* Return Error*/
    }
    
}

void NVIC_voidEnablePendingInterrupt(u8 Copy_u8InterruptNo)
{
    if (Copy_u8InterruptNo <= 31)
    {
        NVIC_ISPR0 = (1<<Copy_u8InterruptNo);
    }
    else if (Copy_u8InterruptNo <= 59)
    {
        Copy_u8InterruptNo -= 32;
        NVIC_ISPR1 = (1<<Copy_u8InterruptNo);
    }
    else
    {
     /* Return Error*/
    }
    
}

void NVIC_voidDisablePendingInterrupt(u8 Copy_u8InterruptNo)
{
    if (Copy_u8InterruptNo <= 31)
    {
        NVIC_ICPR0 = (1<<Copy_u8InterruptNo);
    }
    else if (Copy_u8InterruptNo <= 59)
    {
        Copy_u8InterruptNo -= 32;
        NVIC_ICPR1 = (1<<Copy_u8InterruptNo);
    }
    else
    {
     /* Return Error*/
    }
    
}

u8 NVIC_u8GetActiveInterrupt(u8 Copy_u8InterruptNo)
{
    u8 Local_u8Result = 0;
     if (Copy_u8InterruptNo <= 31)
    {
        Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8InterruptNo);

    }
    else if (Copy_u8InterruptNo <= 59)
    {
        Copy_u8InterruptNo -= 32;
        Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8InterruptNo);
    }
    else
    {
     /* Return Error*/
    }
    return Local_u8Result;
}

void NVIC_voidSetPriority(s8 Copy_s8InterruptID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u32Group)
{   u8 Local_u8Priority =   (Copy_u32Group - 0x05FA0300)/256; 
    /*External Peripheral*/
    if (Copy_s8InterruptID >= 0)
    {

    }
    
    
    /*Internal Peripheral*/

}