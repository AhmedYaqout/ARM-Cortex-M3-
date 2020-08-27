/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   24/Aug/2020
 *  Type    :   Alternative Functions Program Executable File
 *  Version :   V1.0
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void AFIO_voidSetEXTIConfig(u8 Copy_u8Line, u8 Copy_u8PortMap)
{
    u8 Local_u8RegisterIndex      =   0;
    u8 Local_u8LineIndex          =   0;
    
    /*This local variable heads to the right EXTICR Register 
     * [0-3]/4 will give ZERO so ------> EXTICR[0]
     * [4-7]/4 will give ONE so ------> EXTICR[1]
     * [8-11]/4 will give TWO so ------> EXTICR[2]
     * [12-15]/4 will give THREE so ------> EXTICR[3]     
     */
    Local_u8RegisterIndex = Copy_u8Line/4;

    /* This local variable heads to the right EXTICR INDEX 
     * Example: 9%4 = 1 , then 1 x 4 = 4 ---> so it starts from index 4 of the EXTICR      
     */
    Local_u8LineIndex = (Copy_u8Line%4)*4;

    /*
     * Switch cases on the Ports
     * Example: if GPIOA, then it will apply the 0b0000 binary
     */
    switch (Copy_u8PortMap)
    {
    case AFIO_PA:   AFIO->EXTICR[Local_u8RegisterIndex] &=  ~((0b1111)<<Local_u8LineIndex); /*Resets the bits to ensure nothing is overwritten */
                    AFIO->EXTICR[Local_u8RegisterIndex] |=  ((AFIO_PA)<<Local_u8LineIndex);      /*Set the bits to PB*/
                                                                            break;
    case AFIO_PB:   AFIO->EXTICR[Local_u8RegisterIndex] &=  ~((0b1111)<<Local_u8LineIndex);  /*Resets the bits to ensure nothing is overwritten*/ 
                    AFIO->EXTICR[Local_u8RegisterIndex] |=  ((AFIO_PB)<<Local_u8LineIndex);      /*Set the bits to PB*/
                                                                            break;
    case AFIO_PC:   AFIO->EXTICR[Local_u8RegisterIndex] &=  ~((0b1111)<<Local_u8LineIndex);  /*Resets the bits to ensure nothing is overwritten*/
                    AFIO->EXTICR[Local_u8RegisterIndex] |=  ((AFIO_PC)<<Local_u8LineIndex);   /*Set the bits to PC*/
                                                                            break;
    default:  break;
    }
}