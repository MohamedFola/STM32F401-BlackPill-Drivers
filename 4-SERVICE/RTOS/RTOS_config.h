/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : Service                   ************/
/************ Version : 1.00                      ************/
/************ SWC     : RTOS                      ************/
/*************************************************************/
/*************************************************************/

#ifndef _RTOS_CONFIG_H_
#define _RTOS_CONFIG_H_


/*******************************************
 * Define the SYSTICK Clock Source         *
 * Options:                                *
 *         1 --> SYSTICK_AHB_DIV_8_CLK     *
 *         2 --> SYSTICK_AHB_CLK           *
 *******************************************/
#define RTOS_SYSTICK_CLK_SOURCE       SYSTICK_AHB_DIV_8_CLK


/* Define the Total number of Tasks in the System */
#define RTOS_TASKS_MAX_NO             1


/* Define the Tick Time */
#define RTOS_TICK_TIME                10000   // it will tick every 1mS


#endif /* _RTOS_CONFIG_H_ */
