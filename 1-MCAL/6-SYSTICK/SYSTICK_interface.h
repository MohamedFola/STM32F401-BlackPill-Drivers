/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : SYSTICK                   ************/
/*************************************************************/
/*************************************************************/

#ifndef _SYSTICK_INTERFACE_H_
#define _SYSTICK_INTERFACE_H_


/* Clock Source Macros */
#define SYSTICK_AHB_DIV_8_CLK             0
#define SYSTICK_AHB_CLK                   1


/***************************************/
/************** Functions **************/
/***************************************/

/***********************************************
 * Name        : SYSTICK_voidInit              *
 * Return type : void                          *
 * Arguments   : Copy_u8ClockSource --> u8     *
 * Description : - Choosing the Clock Source   *
 * 				 - Enable Interrupt            *
 **********************************************/
void SYSTICK_voidInit(u8 Copy_u8ClockSource);


/*****************************************************
 * Name        : SYSTICK_voidStopTimer               *
 * Return type : void                                *
 * Arguments   : void                                *
 * Description : Stops the Timer                     *
 *****************************************************/
void SYSTICK_voidStopTimer(void);


/*****************************************************
 * Name        : SYSTICK_voidSetBusyWait             *
 * Return type : void                                *
 * Arguments   : Copy_u8Ticks --> u32                *
 * Type        : Synchronous                         *
 * Description : Busy Waiting for a Certain time     *
 *****************************************************/
void SYSTICK_voidSetBusyWait(u32 Copy_u8Ticks);


/*************************************************************
 * Name        : SYSTICK_voidSetSingleInterval               *
 * Return type : void                                        *
 * Arguments   : Copy_u8Ticks     --> u32                    *
 *               CallBackFunction --> pointer to function    *
 * Type        : Asynchronous                                *
 * Description : Starts a Single Interval Asynchronous Wait  *
 *************************************************************/
void SYSTICK_voidSetSingleInterval(u32 Copy_u8Ticks, void (*CallBackFunction)(void));


/***************************************************************
 * Name        : SYSTICK_voidSetPeriodicInterval               *
 * Return type : void                                          *
 * Arguments   : Copy_u8Ticks     --> u32                      *
 *               CallBackFunction --> pointer to function      *
 * Type        : Asynchronous                                  *
 * Description : Starts a Periodic Interval Asynchronous Wait  *
 ***************************************************************/
void SYSTICK_voidSetPeriodicInterval(u32 Copy_u8Ticks, void (*CallBackFunction)(void));


/***************************************************************
 * Name        : SYSTICK_u32GetElapsedTicks                    *
 * Return type : u32                                           *
 * Arguments   : void                                          *
 * Type        : Synchronous                                   *
 * Description : Returns the Ticks that has been Ticked        *
 ***************************************************************/
u32 SYSTICK_u32GetElapsedTicks(void);


/**************************************************
 * Name        : SYSTICK_u32GetRemainingTicks     *
 * Return type : u32                              *
 * Arguments   : void                             *
 * Type        : Synchronous                      *
 * Description : Returns the Remaining Ticks      *
 **************************************************/
u32 SYSTICK_u32GetRemainingTicks(void);


#endif /* _SYSTICK_INTERFACE_H_ */
