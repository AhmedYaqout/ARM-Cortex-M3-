/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   24/Aug/2020
 *  Type    :   External Interrupts Configuration File
 *  Version :   V1.0
 */ 

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H


/*
* Defines the line of the External Interrupt
*   Options:
*           LINE0
*           LINE1
*           .
*           .
*           .
*           LINE15
*/

#define EXTI_LINE   LINE0

/*
* Defines the mode of the External Interrupt
*   Options:
*           RISING
*           FALLING
*           ON_CHANGE
*/

#define EXTI_MODE   RISING

#endif