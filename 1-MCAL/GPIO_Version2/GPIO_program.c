/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 2.00                      ************/
/************ SWC     : GPIO                      ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "GPIO_private.h"
#include "GPIO_interface.h"

void GPIO_SetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u16 Copy_u8Value)
{

	if(Copy_u8PortName <= GPIO_PORTC && Copy_u8PinNumber < 16 && Copy_u8Value < 2)
	{
		switch(Copy_u8PortName)
		{
		case GPIO_PORTA:
			if(Copy_u8Value == GPIO_PIN_HIGH) SET_BIT(GPIOA->BSRR_Set, Copy_u8PinNumber);
			else 							  SET_BIT(GPIOA->BSRR_Reset, Copy_u8PinNumber);
			break;

		case GPIO_PORTB:
			if(Copy_u8Value == GPIO_PIN_HIGH) SET_BIT(GPIOB->BSRR_Set, Copy_u8PinNumber);
			else 							  SET_BIT(GPIOB->BSRR_Reset, Copy_u8PinNumber);
			break;

		case GPIO_PORTC:
			if(Copy_u8Value == GPIO_PIN_HIGH) SET_BIT(GPIOC->BSRR_Set, Copy_u8PinNumber);
			else 							  SET_BIT(GPIOC->BSRR_Reset, Copy_u8PinNumber);
			break;
		}
	}
	else
	{
		/* DO NOTHING */
	}

}


void GPIO_SetChannelGroupValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8ChannelLength, u16 Copy_u8Value)
{

	if(Copy_u8PortName <= GPIO_PORTC && Copy_u8PinNumber < 16 && Copy_u8ChannelLength <= (16 - Copy_u8PinNumber))
	{
		switch(Copy_u8PortName)
		{
		case GPIO_PORTA:
			GPIOA->BSRR_Set   = BitManipulationSetBits(GPIOA->BSRR_Set, Copy_u8PinNumber, Copy_u8ChannelLength, Copy_u8Value);
			GPIOA->BSRR_Reset = BitManipulationSetBits(GPIOA->BSRR_Reset, Copy_u8PinNumber, Copy_u8ChannelLength, ~(Copy_u8Value));
			break;

		case GPIO_PORTB:
			GPIOB->BSRR_Set   = BitManipulationSetBits(GPIOB->BSRR_Set, Copy_u8PinNumber, Copy_u8ChannelLength, Copy_u8Value);
			GPIOB->BSRR_Reset = BitManipulationSetBits(GPIOB->BSRR_Reset, Copy_u8PinNumber, Copy_u8ChannelLength, ~(Copy_u8Value));
			break;

		case GPIO_PORTC:
			GPIOC->BSRR_Set   = BitManipulationSetBits(GPIOC->BSRR_Set, Copy_u8PinNumber, Copy_u8ChannelLength, Copy_u8Value);
			GPIOC->BSRR_Reset = BitManipulationSetBits(GPIOC->BSRR_Reset, Copy_u8PinNumber, Copy_u8ChannelLength, ~(Copy_u8Value));
			break;
		}
	}
	else
	{
		/* DO NOTHING */
	}

}


void GPIO_SetPortValue(u8 Copy_u8PortName, u16 Copy_u8Value)
{

	if(Copy_u8PortName <= GPIO_PORTC)
	{
		switch(Copy_u8PortName)
		{
		case GPIO_PORTA:
			GPIOA->BSRR_Set   = Copy_u8Value;
			GPIOA->BSRR_Reset = ~(Copy_u8Value);
			break;

		case GPIO_PORTB:
			GPIOB->BSRR_Set   = Copy_u8Value;
			GPIOB->BSRR_Reset = ~(Copy_u8Value);
			break;

		case GPIO_PORTC:
			GPIOC->BSRR_Set   = Copy_u8Value;
			GPIOC->BSRR_Reset = ~(Copy_u8Value);
			break;
		}
	}
	else
	{
		/* DO NOTHING */
	}

}


u8 GPIO_GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u16* ptr_u16Value)
{

	u8 Local_u8ErrorStatus = OK;
	
	if(ptr_u16Value != NULL && Copy_u8PortName <= GPIO_PORTC && Copy_u8PinNumber < 16)
	{
		switch(Copy_u8PortName)
		{
		case GPIO_PORTA:
			*ptr_u16Value = READ_BIT(GPIOA->IDR, Copy_u8PinNumber);
			break;
		case GPIO_PORTB:
			*ptr_u16Value = READ_BIT(GPIOB->IDR, Copy_u8PinNumber);
			break;
		case GPIO_PORTC:
			*ptr_u16Value = READ_BIT(GPIOC->IDR, Copy_u8PinNumber);
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}
	
	return Local_u8ErrorStatus;
}


u8 GPIO_GetChannelGroupValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8ChannelLength, u16* ptr_u16Value)
{

	u8 Local_u8ErrorStatus = OK;
	
	if(ptr_u16Value != NULL && Copy_u8PortName <= GPIO_PORTC && Copy_u8PinNumber < 16 && Copy_u8ChannelLength <= (16 - Copy_u8PinNumber))
	{
		switch(Copy_u8PortName)
		{
		case GPIO_PORTA:
			*ptr_u16Value = (u16)BitManipulationGetBits(GPIOA->IDR, Copy_u8PinNumber, Copy_u8ChannelLength);
			break;
		case GPIO_PORTB:
			*ptr_u16Value = (u16)BitManipulationGetBits(GPIOB->IDR, Copy_u8PinNumber, Copy_u8ChannelLength);
			break;
		case GPIO_PORTC:
			*ptr_u16Value = (u16)BitManipulationGetBits(GPIOC->IDR, Copy_u8PinNumber, Copy_u8ChannelLength);
			break;
		}
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}
	
	
	return Local_u8ErrorStatus;
}
