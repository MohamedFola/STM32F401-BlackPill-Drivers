/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : SYSTICK                   ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


static u8 SYSTICK_u8IntervalType = SYSTICK_SINGLE_INTERVAL;

static void(*SYSTICK_CallBackFucntion)(void) = NULL;


/***********************************************
 * Name        : SYSTICK_voidInit              *
 * Return type : void                          *
 * Arguments   : Copy_u8ClockSource --> u8     *
 * Description : - Choosing the Clock Source   *
 * 				 - Enable Interrupt            *
 **********************************************/
void SYSTICK_voidInit(u8 Copy_u8ClockSource)
{
	/* Set Clock Source --> AHB/8 */
	SYSTICK->CTRL |= (Copy_u8ClockSource << CLKSOURCE);
}


/*****************************************************
 * Name        : SYSTICK_voidStopTimer               *
 * Return type : void                                *
 * Arguments   : void                                *
 * Description : Stops the Timer                     *
 *****************************************************/
void SYSTICK_voidStopTimer(void)
{
	CLEAR_BIT(SYSTICK->CTRL, ENABLE);
}



/*****************************************************
 * Name        : SYSTICK_voidSetBusyWait             *
 * Return type : void                                *
 * Arguments   : Copy_u8Ticks --> u32                *
 * Type        : Synchronous                         *
 * Description : Busy Waiting for a Certain time     *
 *****************************************************/
void SYSTICK_voidSetBusyWait(u32 Copy_u8Ticks)
{
	/* Disable Interrupt */
	CLEAR_BIT(SYSTICK->CTRL, TICKINT);

	/* Load the Ticks to Load Register */
	SYSTICK->LOAD = Copy_u8Ticks & 0x00FFFFFF;

	/* Make Sure that VAL is Empty to load the Value form LOAD to VAL */
	SYSTICK->VAL = 0;

	/* Enable Timer */
	SET_BIT(SYSTICK->CTRL, ENABLE);

	/* Polling */
	while(!READ_BIT(SYSTICK->CTRL, COUNTFLAG));

	/* Stop Timer */
	CLEAR_BIT(SYSTICK->CTRL, ENABLE);
}


/*************************************************************
 * Name        : SYSTICK_voidSetSingleInterval               *
 * Return type : void                                        *
 * Arguments   : Copy_u8Ticks     --> u32                    *
 *               CallBackFunction --> pointer to function    *
 * Type        : Asynchronous                                *
 * Description : Starts a Single Interval Asynchronous Wait  *
 *************************************************************/
void SYSTICK_voidSetSingleInterval(u32 Copy_u8Ticks, void (*CallBackFunction)(void))
{
	/* Set Interval Type to Single */
	SYSTICK_u8IntervalType = SYSTICK_SINGLE_INTERVAL;

	/* Set the Call Back Function */
	SYSTICK_CallBackFucntion = CallBackFunction;

	/* Load the Ticks to Load Register */
	SYSTICK->LOAD = Copy_u8Ticks & 0x00FFFFFF;

	/* Make Sure that VAL is Empty to load the Value form LOAD to VAL */
	SYSTICK->VAL = 0;

	/* Enable Interrupt */
	SET_BIT(SYSTICK->CTRL, TICKINT);

	/* Enable Timer */
	SET_BIT(SYSTICK->CTRL, ENABLE);
}



/***************************************************************
 * Name        : SYSTICK_voidSetPeriodicInterval               *
 * Return type : void                                          *
 * Arguments   : Copy_u8Ticks     --> u32                      *
 *               CallBackFunction --> pointer to function      *
 * Type        : Asynchronous                                  *
 * Description : Starts a Periodic Interval Asynchronous Wait  *
 ***************************************************************/
void SYSTICK_voidSetPeriodicInterval(u32 Copy_u8Ticks, void (*CallBackFunction)(void))
{
	/* Set Interval Type to Periodic */
	SYSTICK_u8IntervalType = SYSTICK_PERIODIC_INTERVAL;

	/* Set the Call Back Function */
	SYSTICK_CallBackFucntion = CallBackFunction;

	/* Load the Ticks to Load Register */
	SYSTICK->LOAD = (Copy_u8Ticks - 1) & 0x00FFFFFF;

	/* Make Sure that VAL is Empty to load the Value form LOAD to VAL */
	SYSTICK->VAL = 0;

	/* Enable Interrupt */
	SET_BIT(SYSTICK->CTRL, TICKINT);

	/* Enable Timer */
	SET_BIT(SYSTICK->CTRL, ENABLE);
}


/***************************************************************
 * Name        : SYSTICK_u32GetElapsedTicks                    *
 * Return type : u32                                           *
 * Arguments   : void                                          *
 * Type        : Synchronous                                   *
 * Description : Returns the Ticks that has been Ticked        *
 ***************************************************************/
u32 SYSTICK_u32GetElapsedTicks(void)
{
	return (SYSTICK->LOAD) - (SYSTICK->VAL);
}


/**************************************************
 * Name        : SYSTICK_u32GetRemainingTicks     *
 * Return type : u32                              *
 * Arguments   : void                             *
 * Type        : Synchronous                      *
 * Description : Returns the Remaining Ticks      *
 **************************************************/
u32 SYSTICK_u32GetRemainingTicks(void)
{
	return SYSTICK->VAL;
}



/* ISR Handler */

void SysTick_Handler(void)
{
	/* Check if the Pointer not Points to a Null and then Execute the Function the Pointer Points to */
	if(SYSTICK_CallBackFucntion != NULL) SYSTICK_CallBackFucntion();

	if(SYSTICK_u8IntervalType == SYSTICK_SINGLE_INTERVAL)
	{
		/* Stop Timer */
		CLEAR_BIT(SYSTICK->CTRL, ENABLE);
	}

	/* Clear Flag by Writing to VAL Register */
	SYSTICK->VAL = 0;
}
