/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   18/Aug/2020
 *  Type    :   Seven Segment Configuration Executable File
 *  Version :   V1.0
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SEVEN_interface.h"
#include "SEVEN_config.h"
#include "SEVEN_private.h"


/*
 * This defines an array of structure of the configurations of EACH seven segment display
 *
 * Write the Seven Segment Display type (either cathode or anode)
 * Write the PORTS/GPIOs (GPIOA/GPIOB/GPIOC) of each pin
 * After each Pin PORT, write its corresponding Pin number (ex: pin0, pin1,..,pin15)
 *
 * PS. Don't forget to add a comma after each display structure except the last one
 */ 
SEVEN_strPinMap SEVEN_astrPinMap[Copy_u8DisplayQty]=
{
    {CATHODE,GPIOA, PIN0, GPIOA, PIN1, GPIOA, PIN2, GPIOA, PIN3, GPIOA, PIN4, GPIOA, PIN5, GPIOA, PIN6, GPIOA, PIN7},
    {CATHODE,GPIOB, PIN0, GPIOB, PIN1, GPIOB, PIN2, GPIOB, PIN3, GPIOB, PIN4, GPIOB, PIN5, GPIOB, PIN6, GPIOB, PIN7}
};
