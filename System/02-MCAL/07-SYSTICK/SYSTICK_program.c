/*
 *  Author  :   Ahmad Yaqoot
 *  Date    :   25/Aug/2020
 *  Type    :   SysTick Program Executable File
 *  Version :   V1.0
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
(void)(*Global_pfCallback)(void);
void SYSTICK_voidInit(Copy_u8ClkSrc)
{ /* reset clock source bit */
    SYSTICK->CTRL &= ~(1 << SYSTICK_CLKSOURCE_LOCATION);
    /* switch on the clock source mode */
    switch (Copy_u8ClkSrc)
    {
        /* if it is set to AHB/8 then set the bit to zero */
    case SYSTICK_AHB_DIV_8:
        SYSTICK->CTRL |= SYSTICK_AHB_DIV_8;
        break;

        /* if the mode is set to AHB, then set the bit to one */
    case SYSTICK_AHB:
        SYSTICK->CTRL |= SYSTICK_AHB;
        break;

        /* return error here if otherwise is written */
    default:
        /* error */
        break;
    }
}

void SYSTICK_voidSetBusyDelayMs(u32 Copy_u32TimeValue)
{ /* disable the system timer */
    SYSTICK->CTRL |= SYSTICK_DISABLE;
    /* clear load value */
    SYSTICK->LOAD = 0;
    /* get the clock source  */
    u8 Local_u8ClkSrc = GET_BIT(SYSTICK->CTRL, SYSTICK_CLKSOURCE_LOCATION);
    /* initialize local variable to store the actual working frequency */
    u32 Local_u32CurrentAHBFrequency = 0;
    /* initialize local variable to store the amount of ticks desired */
    u32 Local_u32DesiredTicks = 0;
    /* initialize local variable to store the number of overflows that are required */
    u32 Local_u32Overflow = 0;

    /* switch to get the actual working frequency */
    switch (Local_u8ClkSrc)
    {
        /* case the mode is AHB/8 */
    case SYSTICK_AHB_DIV_8:
        /* divide the original AHB frequency by 8 and then store them in the local variable*/
        Local_u32CurrentAHBFrequency = (SYSTICK_AHB_FREQUENCY / 8);
        break;
        /* case the mode is AHB */
    case SYSTICK_AHB:
        /* store the original frequency in the local variable  */
        Local_u32CurrentAHBFrequency = SYSTICK_AHB_FREQUENCY;
        break;

    default:
        /* Return Error */
        break;
    }
    /* convert the desired time, which is in milliseconds, to the required ticks */
    Local_u32DesiredTicks = ((Copy_u8TimeValue / 1000) * Local_CurrentAHBFrequency);
    /* checking if the number of ticks is within the resolution of the timer */
    if (Local_u32DesiredTicks <= 0x00FFFFFF)
    { /* load the desired ticks immediately on the RELOAD register */
        SYSTICK->LOAD = Local_u32DesiredTicks;
        /* Clear the value register which will clear the countflag as well */
        SYSTICK->VAL = 0;
        /* Enable the timer itself to start counting down */
        SYSTICK->CTRL |= SYSTICK_ENABLE;
        /* wait till the flag is risen to proceed */
        while (GET_BIT(SYSTICK->CTRL, SYSTICK_COUNTFLAG_LOCATION) != 1)
            ;
    }
    else
    {
        /* On the condition that the desired ticks exceed the resolution, then the number of required overflows is calculated */
        Local_u32Overflow = Local_u32DesiredTicks / 0x00FFFFFF;
        /* initialize overflow counter */
        u8 i = 0;
        for (i = 0; i < Local_u32Overflow; i++)
        { /* set the load register to the maximum value the timer can handle */
            SYSTICK->LOAD = 0x00FFFFFF;
            /* Clear the value register which will clear the countflag as well */
            SYSTICK->VAL = 0;
            /* Enable the timer itself to start counting down */
            SYSTICK->CTRL |= SYSTICK_ENABLE;
            /* wait till the flag is risen to proceed */
            while (GET_BIT(SYSTICK->CTRL, SYSTICK_COUNTFLAG_LOCATION) != 1)
                ;
            /* subtract that max value from the desired amount of ticks */
            Local_u32DesiredTicks -= 0x00FFFFFF;
        }
        /* At this stage, the desired amount of ticks should be less than resolution of timer */
        /* Set the remaining to the load register and repeat the same process like above */
        SYSTICK->LOAD = Local_u32DesiredTicks;
        SYSTICK->VAL = 0;
        SYSTICK->CTRL |= SYSTICK_ENABLE;
        while (GET_BIT(SYSTICK->CTRL, SYSTICK_COUNTFLAG_LOCATION) != 1)
            ;
    }
}

void SYSTICK_voidDelayMs(u32 Copy_u32TimeValue, void (*Copy_pfFunction)(void))
{
    Global_pfCallback = Copy_pfFunction;
    /* disable the system timer */
    SYSTICK->CTRL |= SYSTICK_DISABLE;
    /* Clear the interrupt pin*/
    CLR_BIT(SYSTICK->CTRL, SYSTICK_TICKINT_LOCATION);
    /* clear load value */
    SYSTICK->LOAD = 0;
    /* get the clock source  */
    u8 Local_u8ClkSrc = GET_BIT(SYSTICK->CTRL, SYSTICK_CLKSOURCE_LOCATION);
    /* initialize local variable to store the actual working frequency */
    u32 Local_u32CurrentAHBFrequency = 0;
    /* initialize local variable to store the amount of ticks desired */
    u32 Local_u32DesiredTicks = 0;
    /* initialize local variable to store the number of overflows that are required */
    u32 Local_u32Overflow = 0;

    /* switch to get the actual working frequency */
    switch (Local_u8ClkSrc)
    {
        /* case the mode is AHB/8 */
    case SYSTICK_AHB_DIV_8:
        /* divide the original AHB frequency by 8 and then store them in the local variable*/
        Local_u32CurrentAHBFrequency = (SYSTICK_AHB_FREQUENCY / 8);
        break;
        /* case the mode is AHB */
    case SYSTICK_AHB:
        /* store the original frequency in the local variable  */
        Local_u32CurrentAHBFrequency = SYSTICK_AHB_FREQUENCY;
        break;

    default:
        /* Return Error */
        break;
    }
    /* convert the desired time, which is in milliseconds, to the required ticks */
    Local_u32DesiredTicks = ((Copy_u8TimeValue / 1000) * Local_CurrentAHBFrequency);
    /* checking if the number of ticks is within the resolution of the timer */
    if (Local_u32DesiredTicks <= 0x00FFFFFF)
    { /* load the desired ticks immediately on the RELOAD register */
        SYSTICK->LOAD = Local_u32DesiredTicks;
        /* Clear the value register which will clear the countflag as well */
        SYSTICK->VAL = 0;
        /* Enable the sytem timer interrupt */
        SYSTICK->CTRL |= SYSTICK_INTERRUPT_EN;
        /* Enable the timer itself to start counting down */
        SYSTICK->CTRL |= SYSTICK_ENABLE;
        /* wait till the flag is risen to proceed */
    }
    else
    {
        /* On the condition that the desired ticks exceed the resolution, then the number of required overflows is calculated */
        Local_u32Overflow = Local_u32DesiredTicks / 0x00FFFFFF;
        /* initialize overflow counter */
        u8 i = 0;
        for (i = 0; i < Local_u32Overflow; i++)
        { /* set the load register to the maximum value the timer can handle */
            SYSTICK->LOAD = 0x00FFFFFF;
            /* Clear the value register which will clear the countflag as well */
            SYSTICK->VAL = 0;
            /* Enable the sytem timer interrupt */
            SYSTICK->CTRL |= SYSTICK_INTERRUPT_EN;
            /* Enable the timer itself to start counting down */
            SYSTICK->CTRL |= SYSTICK_ENABLE;
            /* subtract that max value from the desired amount of ticks */
            Local_u32DesiredTicks -= 0x00FFFFFF;
        }
        /* At this stage, the desired amount of ticks should be less than resolution of timer */
        /* Set the remaining to the load register and repeat the same process like above */
        SYSTICK->LOAD = Local_u32DesiredTicks;
        SYSTICK->VAL = 0;
        SYSTICK->CTRL |= SYSTICK_INTERRUPT_EN;
        SYSTICK->CTRL |= SYSTICK_ENABLE;
    }
}

void SYSTICK_voidPeriodicDelayMs(u32 Copy_u32TimeValue, void (*Copy_pfFunction)(void))
{
    Global_pfCallback = Copy_pfFunction;
    /* disable the system timer */
    SYSTICK->CTRL |= SYSTICK_DISABLE;
    /* Clear the interrupt pin*/
    CLR_BIT(SYSTICK->CTRL, SYSTICK_TICKINT_LOCATION);
    /* clear load value */
    SYSTICK->LOAD = 0;
    /* get the clock source  */
    u8 Local_u8ClkSrc = GET_BIT(SYSTICK->CTRL, SYSTICK_CLKSOURCE_LOCATION);
    /* initialize local variable to store the actual working frequency */
    u32 Local_u32CurrentAHBFrequency = 0;
    /* initialize local variable to store the amount of ticks desired */
    u32 Local_u32DesiredTicks = 0;
    /* initialize local variable to store the number of overflows that are required */
    u32 Local_u32Overflow = 0;

    /* switch to get the actual working frequency */
    switch (Local_u8ClkSrc)
    {
        /* case the mode is AHB/8 */
    case SYSTICK_AHB_DIV_8:
        /* divide the original AHB frequency by 8 and then store them in the local variable*/
        Local_u32CurrentAHBFrequency = (SYSTICK_AHB_FREQUENCY / 8);
        break;
        /* case the mode is AHB */
    case SYSTICK_AHB:
        /* store the original frequency in the local variable  */
        Local_u32CurrentAHBFrequency = SYSTICK_AHB_FREQUENCY;
        break;

    default:
        /* Return Error */
        break;
    }
    /* convert the desired time, which is in milliseconds, to the required ticks */
    Local_u32DesiredTicks = ((Copy_u8TimeValue / 1000) * Local_CurrentAHBFrequency);
    /* checking if the number of ticks is within the resolution of the timer */
    if (Local_u32DesiredTicks <= 0x00FFFFFF)
    { /* load the desired ticks immediately on the RELOAD register */
        SYSTICK->LOAD = Local_u32DesiredTicks - 1;
        /* Clear the value register which will clear the countflag as well */
        SYSTICK->VAL = 0;
        /* Enable the sytem timer interrupt */
        SYSTICK->CTRL |= SYSTICK_INTERRUPT_EN;
        /* Enable the timer itself to start counting down */
        SYSTICK->CTRL |= SYSTICK_ENABLE;
        /* wait till the flag is risen to proceed */
    }
    else
    {
        /* On the condition that the desired ticks exceed the resolution, then the number of required overflows is calculated */
        Local_u32Overflow = Local_u32DesiredTicks / 0x00FFFFFF;
        /* initialize overflow counter */
        u8 i = 0;
        for (i = 0; i < Local_u32Overflow; i++)
        { /* set the load register to the maximum value the timer can handle */
            SYSTICK->LOAD = 0x00FFFFFF;
            /* Clear the value register which will clear the countflag as well */
            SYSTICK->VAL = 0;
            /* Enable the sytem timer interrupt */
            SYSTICK->CTRL |= SYSTICK_INTERRUPT_EN;
            /* Enable the timer itself to start counting down */
            SYSTICK->CTRL |= SYSTICK_ENABLE;
            /* subtract that max value from the desired amount of ticks */
            Local_u32DesiredTicks -= 0x00FFFFFF;
        }
        /* At this stage, the desired amount of ticks should be less than resolution of timer */
        /* Set the remaining to the load register and repeat the same process like above */
        SYSTICK->LOAD = Local_u32DesiredTicks - 1;
        SYSTICK->VAL = 0;
        SYSTICK->CTRL |= SYSTICK_INTERRUPT_EN;
        SYSTICK->CTRL |= SYSTICK_ENABLE;
    }
}

void SYSTICK_voidStopTimer(void)
{
    CLR_BIT(SYSTICK->CTRL,SYSTICK_ENABLE_LOCATION);
}
void SYSTICK_voidGetElapsedTime(u32 *Copy_Pu32Time)
{
    *Copy_Pu32Time = (SYSTICK->LOAD - SYSTICK->VAL);
}
void SYSTICK_voidGetRemainingTime(u32 *Copy_Pu32Time)
{
    *Copy_Pu32Time = SYSTICK->VAL;
}

void Systick_Handler(void)
{
    Global_pfCallback();
}
