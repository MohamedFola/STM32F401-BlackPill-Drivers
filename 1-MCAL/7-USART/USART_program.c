/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : USART                     ************/
/*************************************************************/
/*************************************************************/


#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


/*******************************************************************/
/****************************** USART1 *****************************/
/*******************************************************************/

/***************************************************
 * Name        : USART1_voidInit                   *
 * Return type : void                              *
 * Arguments   : void                              *
 * description : Sets the Baud Rate                *
 **************************************************/
void USART1_voidInit(void)
{
	/* Set the Baud Rate */
	USART1->BRR = USART1_BAUD_RATE;

	/* Enable Transmitter */
	SET_BIT(USART1->CR1, TE);

	/* Enable Receiver */
	SET_BIT(USART1->CR1, RE);

	/* Enable Interrupt on Reception for Asynchronous Function */
	SET_BIT(USART1->CR1, RXNEIE);

	/* Parity Selection */
#if USART1_PARITY_ON != USART_NO_PARITY
	SET_BIT(USART1->CR1, PCE);
	USART1->CR1 |= (USART1_PARITY_ON << PS);
#endif

	/* Set Word Length */
	USART1->CR1 |= (USART1_WORD_LENGTH << M);

	/* Set Number of Stop bit */
	USART1->CR2 |= (USART1_STOP_BIT << STOP);

	/* Enable USART1 */
	SET_BIT(USART1->CR1, UE);
}


/***************************************************
 * Name        : USART1_voidSendData               *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> u8                *
 * description : Sends Data                        *
 **************************************************/
void USART1_voidSendData(u8 Copy_u8Data)
{
	/* Put the Data to Data Register */
	USART1->DR = Copy_u8Data;

	/* Wait until the Transmission is complete */
	while(!(READ_BIT(USART1->SR, TXE)));
}


/***************************************************
 * Name        : USART1_voidSendString             *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> array of u8       *
 * description : Sends Data                        *
 **************************************************/
void USART1_voidSendString(u8* Copy_u8Data)
{
	u8 Local_u8Counter = 0;

	/* While loop till we Reach the end of the String */
	while(Copy_u8Data[Local_u8Counter] != '\0')
	{
		/* Put the Data to Data Register */
		USART1->DR = Copy_u8Data[Local_u8Counter++];

		/* Wait until the Transmission is complete */
		while(!(READ_BIT(USART1->SR, TXE)));
	}
}


/***************************************************
 * Name        : USART1_voidSynchReceiveData       *
 * Return type : void                              *
 * Arguments   : Ptr_u8Data --> pointer to u8      *
 * description : Receives the Data                 *
 **************************************************/
void USART1_voidSynchReceiveData(u8* Ptr_u8Data)
{
	/* Check for the Pointer */
	if(Ptr_u8Data != NULL)
	{
		/* Wait until Reception is complete */
		while(!(READ_BIT(USART1->SR, RXEN)));

		/* Store the Data to the Pointer */
		*(Ptr_u8Data) = USART1->DR;
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING   */
	}
}



/*******************************************************************/
/****************************** USART2 *****************************/
/*******************************************************************/

/***************************************************
 * Name        : USART2_voidInit                   *
 * Return type : void                              *
 * Arguments   : void                              *
 * description : Set the Baud Rate                 *
 **************************************************/
void USART2_voidInit(void)
{
	/* Set the Baud Rate */
	USART2->BRR = USART2_BAUD_RATE;

	/* Enable Transmitter */
	SET_BIT(USART2->CR1, TE);

	/* Enable Receiver */
	SET_BIT(USART2->CR1, RE);

	/* Enable Interrupt on Reception for Asynchronous Function */
	SET_BIT(USART2->CR1, RXNEIE);

	/* Parity Selection */
#if USART2_PARITY_ON != USART_NO_PARITY
	SET_BIT(USART2->CR1, PCE);
	USART2->CR1 |= (USART2_PARITY_ON << PS);
#endif

	/* Set Word Length */
	USART2->CR1 |= (USART2_WORD_LENGTH << M);

	/* Set Number of Stop bit */
	USART2->CR2 |= (USART2_STOP_BIT << STOP);

	/* Enable USART1 */
	SET_BIT(USART2->CR1, UE);
}


/***************************************************
 * Name        : USART2_voidSendData               *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> u8                *
 * description : Send the Data                     *
 **************************************************/
void USART2_voidSendData(u8 Copy_u8Data)
{
	/* Put the Data to Data Register */
	USART2->DR = Copy_u8Data;

	/* Wait until the Transmission is complete */
	while(!(READ_BIT(USART2->SR, TXE)));
}


/***************************************************
 * Name        : USART2_voidSendString             *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> array of u8       *
 * description : Sends Data                        *
 **************************************************/
void USART2_voidSendString(u8* Copy_u8Data)
{
	u8 Local_u8Counter = 0;

	/* While loop till we Reach the end of the String */
	while(Copy_u8Data[Local_u8Counter] != '\0')
	{
		/* Put the Data to Data Register */
		USART2->DR = Copy_u8Data[Local_u8Counter++];

		/* Wait until the Transmission is complete */
		while(!(READ_BIT(USART2->SR, TXE)));
	}
}


/***************************************************
 * Name        : USART2_voidSynchReceiveData       *
 * Return type : void                              *
 * Arguments   : Ptr_u8Data --> pointer to u8      *
 * description : Receive the Data                  *
 **************************************************/
void USART2_voidSynchReceiveData(u8* Ptr_u8Data)
{
	/* Check for the Pointer */
	if(Ptr_u8Data != NULL)
	{
		/* Wait until Reception is complete */
		while(!(READ_BIT(USART2->SR, RXEN)));

		/* Store the Data to the Pointer */
		*(Ptr_u8Data) = USART2->DR;
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING   */
	}
}



/*******************************************************************/
/****************************** USART6 *****************************/
/*******************************************************************/

/***************************************************
 * Name        : USART6_voidInit                   *
 * Return type : void                              *
 * Arguments   : void                              *
 * description : Set the Baud Rate                 *
 **************************************************/
void USART6_voidInit(void)
{
	/* Set the Baud Rate */
	USART6->BRR = USART6_BAUD_RATE;

	/* Enable Transmitter */
	SET_BIT(USART6->CR1, TE);

	/* Enable Receiver */
	SET_BIT(USART6->CR1, RE);

	/* Enable Interrupt on Reception for Asynchronous Function */
	SET_BIT(USART6->CR1, RXNEIE);

	/* Parity Selection */
#if USART6_PARITY_ON != USART_NO_PARITY
	SET_BIT(USART6->CR1, PCE);
	USART6->CR1 |= (USART6_PARITY_ON << PS);
#endif

	/* Set Word Length */
	USART6->CR1 |= (USART6_WORD_LENGTH << M);

	/* Set Number of Stop bit */
	USART6->CR2 |= (USART6_STOP_BIT << STOP);

	/* Enable USART1 */
	SET_BIT(USART6->CR1, UE);
}


/***************************************************
 * Name        : USART2_voidSendData               *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> u8                *
 * description : Send the Data                     *
 **************************************************/
void USART6_voidSendData(u8 Copy_u8Data)
{
	/* Put the Data to Data Register */
	USART6->DR = Copy_u8Data;

	/* Wait until the Transmission is complete */
	while(!(READ_BIT(USART6->SR, TXE)));
}


/***************************************************
 * Name        : USART6_voidSendString             *
 * Return type : void                              *
 * Arguments   : Copy_u8Data --> array of u8       *
 * description : Sends Data                        *
 **************************************************/
void USART6_voidSendString(u8* Copy_u8Data)
{
	u8 Local_u8Counter = 0;

	/* While loop till we Reach the end of the String */
	while(Copy_u8Data[Local_u8Counter] != '\0')
	{
		/* Put the Data to Data Register */
		USART6->DR = Copy_u8Data[Local_u8Counter++];

		/* Wait until the Transmission is complete */
		while(!(READ_BIT(USART6->SR, TXE)));
	}
}


/***************************************************
 * Name        : USART6_voidSynchReceiveData       *
 * Return type : void                              *
 * Arguments   : Ptr_u8Data --> pointer to u8      *
 * description : Receive the Data                  *
 **************************************************/
void USART6_voidSynchReceiveData(u8* Ptr_u8Data)
{
	/* Check for the Pointer */
	if(Ptr_u8Data != NULL)
	{
		/* Wait until Reception is complete */
		while(!(READ_BIT(USART6->SR, RXEN)));

		/* Store the Data to the Pointer */
		*(Ptr_u8Data) = USART6->DR;
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING   */
	}
}



