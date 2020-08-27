/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   18/Aug/2020
 *  Type    :   Seven Segment Interface File
 *  Version :   V1.0
 */ 

#ifndef SEVEN_INTERFACE_H 
#define SEVEN_INTERFACE_H

/*
 * Defines CATHODE and ANODE modes
 */
#define CATHODE 0
#define ANODE   1
/*
 *
 *  Display Function prototype which takes the Display ID (First, Second,....)
 *  and the intended number to be displayed (1,2,3,4,...)
 */
void SEVEN_voidDisplayNo(u8 Copy_u8DisplayID, u8 Copy_u8Number);

#endif
