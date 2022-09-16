/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : Service                   ************/
/************ Version : 1.00                      ************/
/************ SWC     : RTOS                      ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "SYSTICK_interface.h"

#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"


/* Array that Contains all the Tasks */
RTOS_Task RTOS_SystemTasks[RTOS_TASKS_MAX_NO] = {0};


/* by assigning any RTOS_Task to this struct it will make all of it's elements equal zero */
RTOS_Task RTOS_EmptyTask = {0};


/**************************************************************
 * Name        : RTOS_voidScheduler                           *
 *                                                            *
 * Return type : void                                         *
 *                                                            *
 * Arguments   : void                                         *
 *                                                            *
 * Description : Scheduling the Tasks and Execute them        *
 **************************************************************/
void RTOS_voidScheduler(void)
{
	/* Counter to Loop on all Tasks */
	u8 Local_u8Counter;

	/* Loop on all tasks */
	for(Local_u8Counter = 0;  Local_u8Counter < RTOS_TASKS_MAX_NO; Local_u8Counter++)
	{
		/* Check if the Task Exist and in the Running State */
		if(RTOS_SystemTasks[Local_u8Counter].Task_Handler != RTOS_NoTaskExist && RTOS_SystemTasks[Local_u8Counter].Task_State == Task_Running)
		{
			/* Check if the Task must run at this Tick */
			if(RTOS_SystemTasks[Local_u8Counter].Task_Timing == 0)
			{
				/* Run the Task */
				RTOS_SystemTasks[Local_u8Counter].Task_Handler();

				/* Assign Task Timing to Task Periodicity */
				RTOS_SystemTasks[Local_u8Counter].Task_Timing = RTOS_SystemTasks[Local_u8Counter].Task_Periodicity;
			}
			else
			{
				/* Decrement the Task Timing */
				RTOS_SystemTasks[Local_u8Counter].Task_Timing--;
			}
		}

	}
}



/**************************************************************
 * Name        : RTOS_voidStartOS                             *
 *                                                            *
 * Return type : void                                         *
 *                                                            *
 * Arguments   : void                                         *
 *                                                            *
 * Description : Starts the Operating System                  *
 **************************************************************/
void RTOS_voidStartOS(void)
{
	/* Initiate SYSTICK as our Timer for the RTOS */
	SYSTICK_voidInit(RTOS_SYSTICK_CLK_SOURCE);

	/* Start the Scheduler */
	RTOS_voidScheduler();

	/* Repeats the Scheduler Periodically */
	SYSTICK_voidSetPeriodicInterval(RTOS_TICK_TIME, RTOS_voidScheduler);
}



/**************************************************************
 * Name        : RTOS_u8CreateTask                            *
 *                                                            *
 * Return type : u8                 --> Error State           *
 *                                                            *
 * Arguments   : Ptr_Task           --> pointer to function   *
 *               Copy_u8Priority    --> u8                    *
 *               Copy_u8Periodicity --> u8                    *
 *               Copy_u8FirstDelay  --> u8                    *
 *                                                            *
 * Description : Creates the Task                             *
 *               Initiate all Task Requirements               *
 *               --> Priority                                 *
 *               --> Periodicity                              *
 *               --> First Delay                              *
 *               --> Task Function                            *
 **************************************************************/
u8 RTOS_u8CreateTask(void(*Ptr_Task)(void), u8 Copy_u8Priority, u8 Copy_u8Periodicity, u8 Copy_u8FirstDelay)
{
	/* Variable to Detect if there is an Error */
	u8 Local_u8ErrorState = RTOS_NoError;

	/* Check that the Task ID passed is in the Range of our System Task array */
	/* if not the Task will be Assigned to wrong index                        */
	if(Copy_u8Priority < RTOS_TASKS_MAX_NO)
	{
		/* Check that the passed ID has no Tasks */
		if(RTOS_SystemTasks[Copy_u8Priority].Task_Handler == RTOS_NoTaskExist)
		{
			/* Assign Task Handler to passed Task */
			RTOS_SystemTasks[Copy_u8Priority].Task_Handler = Ptr_Task;

			/* Assign Task Periodicity to passed Periodicity */
			RTOS_SystemTasks[Copy_u8Priority].Task_Periodicity = Copy_u8Periodicity;

			/* Assign Task FirstDelay to passed FirstDelay */
			RTOS_SystemTasks[Copy_u8Priority].Task_First_Delay = Copy_u8FirstDelay;

			/* Assign Task Timing to passed Periodicity */
			RTOS_SystemTasks[Copy_u8Priority].Task_Timing = Copy_u8FirstDelay;

			/* By default assign Task State to Running State */
			RTOS_SystemTasks[Copy_u8Priority].Task_State = Task_Running;
		}
		else
		{
			/* Index is already Reserved */
			Local_u8ErrorState = RTOS_NoTaskExist;
		}
	}
	else
	{
		/* Wrong Index */
		Local_u8ErrorState = RTOS_WrongIndex;
	}

	return Local_u8ErrorState;
}


/**************************************************************
 * Name        : RTOS_u8DeleteTask                            *
 *                                                            *
 * Return type : u8                 --> Error State           *
 *                                                            *
 * Arguments   : Copy_u8Priority    --> u8                    *
 *                                                            *
 * Description : Deletes the Task                             *
 **************************************************************/
u8 RTOS_u8DeleteTask(u8 Copy_u8Priority)
{
	/* Variable to Detect if there is an Error */
	u8 Local_u8ErrorState = RTOS_NoError;

	/* Check that the Task ID passed is in the Range of our System Task array */
	if(Copy_u8Priority < RTOS_TASKS_MAX_NO)
	{
		/* Check if the Task exists or not */
		if(RTOS_SystemTasks[Copy_u8Priority].Task_Handler != RTOS_NoTaskExist)
		{
			/* Assign the Task to the Empty Task */
			RTOS_SystemTasks[Copy_u8Priority] = RTOS_EmptyTask;
		}
		else
		{
			/* Task not Exist */
			Local_u8ErrorState = RTOS_NoTaskExist;
		}
	}
	else
	{
		/* Wrong Index */
		Local_u8ErrorState = RTOS_WrongIndex;
	}

	return Local_u8ErrorState;
}



/**************************************************************
 * Name        : RTOS_u8SuspendTask                           *
 *                                                            *
 * Return type : u8                 --> Error State           *
 *                                                            *
 * Arguments   : Copy_u8Priority    --> u8                    *
 *                                                            *
 * Description : Suspends the Task                            *
 **************************************************************/
u8 RTOS_u8SuspendTask(u8 Copy_u8Priority)
{
	/* Variable to Detect if there is an Error */
	u8 Local_u8ErrorState = RTOS_NoError;

	/* Check that the Task ID passed is in the Range of our System Task array */
	if(Copy_u8Priority < RTOS_TASKS_MAX_NO)
	{
		/* Check if the Task exists or not */
		if(RTOS_SystemTasks[Copy_u8Priority].Task_Handler != RTOS_NoTaskExist)
		{
			/* Assign the Task State to Suspended */
			RTOS_SystemTasks[Copy_u8Priority].Task_State = Task_Suspended;
		}
		else
		{
			/* Task not Exist */
			Local_u8ErrorState = RTOS_NoTaskExist;
		}
	}
	else
	{
		/* Wrong Index */
		Local_u8ErrorState = RTOS_WrongIndex;
	}

	return Local_u8ErrorState;
}



/**************************************************************
 * Name        : RTOS_u8ResumeTask                            *
 *                                                            *
 * Return type : u8                 --> Error State           *
 *                                                            *
 * Arguments   : Copy_u8Priority    --> u8                    *
 *                                                            *
 * Description : Resumes the Suspended Task                   *
 **************************************************************/
u8 RTOS_u8ResumeTask(u8 Copy_u8Priority)
{
	/* Variable to Detect if there is an Error */
	u8 Local_u8ErrorState = RTOS_NoError;

	/* Check that the Task ID passed is in the Range of our System Task array */
	if(Copy_u8Priority < RTOS_TASKS_MAX_NO)
	{
		/* Check if the Task exists or not */
		if(RTOS_SystemTasks[Copy_u8Priority].Task_Handler != RTOS_NoTaskExist)
		{
			/* Assign the Task State to Running */
			RTOS_SystemTasks[Copy_u8Priority].Task_State = Task_Running;
		}
		else
		{
			/* Task not Exist */
			Local_u8ErrorState = RTOS_NoTaskExist;
		}
	}
	else
	{
		/* Wrong Index */
		Local_u8ErrorState = RTOS_WrongIndex;
	}

	return Local_u8ErrorState;
}
