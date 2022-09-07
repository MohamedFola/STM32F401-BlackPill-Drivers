/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : USART                     ************/
/*************************************************************/
/*************************************************************/

#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_

/*******************************************************************/
/****************************** USART1 *****************************/
/*******************************************************************/

/***************************************************
 * Name        : USART1_voidInit                   *
 * Return type : void                              *
 * Arguments   : void                              *
 * description : Sets the Baud Rate                *
 **************************************************/
void USART1_voidInit(void);


/***************************************************
 * Name        : USART1_voidSendData               *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> u8                *
 * description : Sends Data                        *
 **************************************************/
void USART1_voidSendData(u8 Copy_u8Data);


/***************************************************
 * Name        : USART1_voidSendString             *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> array of u8       *
 * description : Sends Data                        *
 **************************************************/
void USART1_voidSendString(u8* Copy_u8Data);


/***************************************************
 * Name        : USART1_voidSynchReceiveData       *
 * Return type : void                              *
 * Arguments   : Ptr_u8Data --> pointer to u8      *
 * description : Receives the Data                 *
 **************************************************/
void USART1_voidSynchReceiveData(u8* Ptr_u8Data);



/*******************************************************************/
/****************************** USART2 *****************************/
/*******************************************************************/

/***************************************************
 * Name        : USART2_voidInit                   *
 * Return type : void                              *
 * Arguments   : void                              *
 * description : Set the Baud Rate                 *
 **************************************************/
void USART2_voidInit(void);


/***************************************************
 * Name        : USART2_voidSendData               *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> u8                *
 * description : Send the Data                     *
 **************************************************/
void USART2_voidSendData(u8 Copy_u8Data);


/***************************************************
 * Name        : USART2_voidSendString             *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> array of u8       *
 * description : Sends Data                        *
 **************************************************/
void USART2_voidSendString(u8* Copy_u8Data);


/***************************************************
 * Name        : USART2_voidSynchReceiveData       *
 * Return type : void                              *
 * Arguments   : Ptr_u8Data --> pointer to u8      *
 * description : Receive the Data                  *
 **************************************************/
void USART2_voidSynchReceiveData(u8* Ptr_u8Data);


/*******************************************************************/
/****************************** USART6 *****************************/
/*******************************************************************/

/***************************************************
 * Name        : USART6_voidInit                   *
 * Return type : void                              *
 * Arguments   : void                              *
 * description : Set the Baud Rate                 *
 **************************************************/
void USART6_voidInit(void);


/***************************************************
 * Name        : USART2_voidSendData               *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> u8                *
 * description : Send the Data                     *
 **************************************************/
void USART6_voidSendData(u8 Copy_u8Data);


/***************************************************
 * Name        : USART6_voidSendString             *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> array of u8       *
 * description : Sends Data                        *
 **************************************************/
void USART6_voidSendString(u8* Copy_u8Data);


/***************************************************
 * Name        : USART6_voidSynchReceiveData       *
 * Return type : void                              *
 * Arguments   : Ptr_u8Data --> pointer to u8      *
 * description : Receive the Data                  *
 **************************************************/
void USART6_voidSynchReceiveData(u8* Ptr_u8Data);


#endif /* _USART_INTERFACE_H_ */
