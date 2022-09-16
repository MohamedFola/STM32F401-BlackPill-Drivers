/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : Service                   ************/
/************ Version : 1.00                      ************/
/************ SWC     : RTOS                      ************/
/*************************************************************/
/*************************************************************/

#ifndef _RTOS_INTERFACE_H_
#define _RTOS_INTERFACE_H_



/**************************************************************
 * Name        : RTOS_voidStartOS                             *
 *                                                            *
 * Return type : void                                         *
 *                                                            *
 * Arguments   : void                                         *
 *                                                            *
 * Description : Starts the Operating System                  *
 **************************************************************/
void RTOS_voidStartOS(void);



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
u8 RTOS_u8CreateTask(void(*Ptr_Task)(void), u8 Copy_u8Priority, u8 Copy_u8Periodicity, u8 Copy_u8FirstDelay);


/**************************************************************
 * Name        : RTOS_u8DeleteTask                            *
 *                                                            *
 * Return type : u8                 --> Error State           *
 *                                                            *
 * Arguments   : Copy_u8Priority    --> u8                    *
 *                                                            *
 * Description : Deletes the Task                             *
 **************************************************************/
u8 RTOS_u8DeleteTask(u8 Copy_u8Priority);


/**************************************************************
 * Name        : RTOS_u8SuspendTask                           *
 *                                                            *
 * Return type : u8                 --> Error State           *
 *                                                            *
 * Arguments   : Copy_u8Priority    --> u8                    *
 *                                                            *
 * Description : Suspends the Task                            *
 **************************************************************/
u8 RTOS_u8SuspendTask(u8 Copy_u8Priority);


/**************************************************************
 * Name        : RTOS_u8ResumeTask                            *
 *                                                            *
 * Return type : u8                 --> Error State           *
 *                                                            *
 * Arguments   : Copy_u8Priority    --> u8                    *
 *                                                            *
 * Description : Resumes the Suspended Task                   *
 **************************************************************/
u8 RTOS_u8ResumeTask(u8 Copy_u8Priority);


#endif /* _RTOS_INTERFACE_H_ */
