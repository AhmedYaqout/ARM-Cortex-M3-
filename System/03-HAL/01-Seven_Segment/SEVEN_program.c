/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   18/Aug/2020
 *  Type    :   Seven Segment Program Executable File
 *  Version :   V1.0
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SEVEN_interface.h"
#include "SEVEN_config.h"
#include "SEVEN_private.h"

void SEVEN_voidDisplayNo(u8 Copy_u8DisplayID, u8 Copy_u8Number)
{					/*
 * The algorithm goes as follows:
 * Step 1: Declaring the GPIO of the first pin connection
 * Step 2: Declaring the Pin number in that GPIO of the first pin
 * Step 3: Declaring the state of that pin as either high or low ----> Get to the intended "number" to display from the array
 *  and look up the bit position from the 8 bits and its state
 * Step 4: Repeat with the rest of the pins (from pinB--->pinG)
 * Example: GPIO_voidSetPinValue(GPIOA , PIN0 , HIGH, GPIOA, PIN1, LOW,...);*/

	/*
	 * Declaring the truth table of the numbers in the cathode seven segment display
	 */
    u8 SEVEN_u8NumberData[10]={0x3F , 0x06 , 0x5B , 0x4F , 0x66 ,0x6D ,0x7D ,0x07 ,0x7F,0x6F };

    /*
     * Checking the type of the seven segment either anode or cathode
     * The only difference in the code will be the complementing (1-->0/ 0-->1) of the bits due to the nature of the common anode
     */
    if(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8Mode == ANODE){
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortA,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinA,~GET_BIT(SEVEN_u8NumberData[Copy_u8Number],0));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortB,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinB,~GET_BIT(SEVEN_u8NumberData[Copy_u8Number],1));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortC,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinC,~GET_BIT(SEVEN_u8NumberData[Copy_u8Number],2));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortD,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinD,~GET_BIT(SEVEN_u8NumberData[Copy_u8Number],3));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortE,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinE,~GET_BIT(SEVEN_u8NumberData[Copy_u8Number],4));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortF,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinF,~GET_BIT(SEVEN_u8NumberData[Copy_u8Number],5));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortG,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinG,~GET_BIT(SEVEN_u8NumberData[Copy_u8Number],6));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortDot,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinDot,~GET_BIT(SEVEN_u8NumberData[Copy_u8Number],7));
    }
    	/*
         * Checking the type of the seven segment either anode or cathode
         */
    else if (SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8Mode == CATHODE)
    {

        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortA,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinA,GET_BIT(SEVEN_u8NumberData[Copy_u8Number],0));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortB,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinB,GET_BIT(SEVEN_u8NumberData[Copy_u8Number],1));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortC,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinC,GET_BIT(SEVEN_u8NumberData[Copy_u8Number],2));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortD,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinD,GET_BIT(SEVEN_u8NumberData[Copy_u8Number],3));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortE,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinE,GET_BIT(SEVEN_u8NumberData[Copy_u8Number],4));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortF,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinF,GET_BIT(SEVEN_u8NumberData[Copy_u8Number],5));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortG,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinG,GET_BIT(SEVEN_u8NumberData[Copy_u8Number],6));
        GPIO_voidSetPinValue(SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinPortDot,SEVEN_astrPinMap[Copy_u8DisplayID].SEVEN_u8PinDot,GET_BIT(SEVEN_u8NumberData[Copy_u8Number],7));
     
    }
}
