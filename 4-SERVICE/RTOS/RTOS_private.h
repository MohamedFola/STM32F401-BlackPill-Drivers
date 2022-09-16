/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : Service                   ************/
/************ Version : 1.00                      ************/
/************ SWC     : RTOS                      ************/
/*************************************************************/
/*************************************************************/

#ifndef _RTOS_PRIVATE_H_
#define _RTOS_PRIVATE_H_


#define RTOS_NO_TASK_ERROR        0

/* Error enum */
typedef enum rtos_errors
{
	RTOS_NoTaskExist,
	RTOS_NoError,
	RTOS_WrongIndex,
	RTOS_ReservedIndex,
}RTOS_Errors;

/* Task State enum */
typedef enum rtos_taskstate
{
	Task_Running,
	Task_Suspended,
}RTOS_TaskState;


/* Task Body */
typedef struct
{
	void           (*Task_Handler)(void);
	u8              Task_Periodicity;
	u8              Task_First_Delay;
	u8              Task_Timing;
	RTOS_TaskState  Task_State;
}RTOS_Task;



/**************************************************************
 * Name        : RTOS_voidScheduler                           *
 *                                                            *
 * Return type : void                                         *
 *                                                            *
 * Arguments   : void                                         *
 *                                                            *
 * Description : Scheduling the Tasks and Execute them        *
 **************************************************************/
void RTOS_voidScheduler(void);


#endif /* _RTOS_PRIVATE_H_ */
