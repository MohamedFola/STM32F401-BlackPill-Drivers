/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL                       ************/
/************ Version : 1.00                      ************/
/************ SWC     : Shift Register            ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "GPIO_interface.h"

#include "ShiftRegister_interface.h"
#include "ShiftRegister_private.h"
#include "ShiftRegister_config.h"


/***************************************************
 * Name        : ShiftRegister_voidSendData        *
 * Return type : void                              *
 * Arguments   : Copy_ShiftReg  --> ShiftRegister  *
 *               Copy_u8Data    --> u8             *
 * description : Sends Data to Shift Register      *
 ***************************************************/
void ShiftRegister_voidSendData(ShiftRegister Copy_ShiftReg, u8 Copy_u8Data)
{
	GPIO_SetPinValue(Copy_ShiftReg.Output_Enable_Port, Copy_ShiftReg.Output_Enable_Pin, GPIO_PIN_LOW);

	GPIO_SetPinValue(Copy_ShiftReg.Latch_Clock_Port, Copy_ShiftReg.Latch_Clock_Pin, GPIO_PIN_LOW);

	for(int Local_intIterator = 7; Local_intIterator > -1 ; Local_intIterator--)
	{
		GPIO_SetPinValue(Copy_ShiftReg.Shift_Clock_Port, Copy_ShiftReg.Shift_Clock_Pin, GPIO_PIN_LOW);
		GPIO_SetPinValue(Copy_ShiftReg.Data_Port, Copy_ShiftReg.Data_Pin, READ_BIT(Copy_u8Data, Local_intIterator));
		GPIO_SetPinValue(Copy_ShiftReg.Shift_Clock_Port, Copy_ShiftReg.Shift_Clock_Pin, GPIO_PIN_HIGH);
	}

	GPIO_SetPinValue(Copy_ShiftReg.Latch_Clock_Port, Copy_ShiftReg.Latch_Clock_Pin, GPIO_PIN_HIGH);
}


/**************************************************************
 * Name        : ShiftRegister_voidSendDataForTwoModules      *
 * Return type : void                                         *
 * Arguments   : Copy_ShiftReg1  --> ShiftRegister            *
 *               Copy_u8Data1    --> u8                       *
 *               Copy_ShiftReg2  --> ShiftRegister            *
 *               Copy_u8Data2    --> u8                       *
 * description : Sends Data to Tow Shift Registers            *
 **************************************************************/
void ShiftRegister_voidSendDataForTwoModules(ShiftRegister Copy_ShiftReg1, u8 Copy_u8Data1, ShiftRegister Copy_ShiftReg2, u8 Copy_u8Data2)
{
	GPIO_SetPinValue(Copy_ShiftReg1.Output_Enable_Port, Copy_ShiftReg1.Output_Enable_Pin, GPIO_PIN_LOW);
	GPIO_SetPinValue(Copy_ShiftReg2.Output_Enable_Port, Copy_ShiftReg2.Output_Enable_Pin, GPIO_PIN_LOW);

	GPIO_SetPinValue(Copy_ShiftReg1.Latch_Clock_Port, Copy_ShiftReg1.Latch_Clock_Pin, GPIO_PIN_LOW);

	for(int Local_intIterator = 7; Local_intIterator > -1 ; Local_intIterator--)
	{
		GPIO_SetPinValue(Copy_ShiftReg1.Shift_Clock_Port, Copy_ShiftReg1.Shift_Clock_Pin, GPIO_PIN_LOW);
		GPIO_SetPinValue(Copy_ShiftReg1.Data_Port, Copy_ShiftReg1.Data_Pin, READ_BIT(Copy_u8Data1, Local_intIterator));
		GPIO_SetPinValue(Copy_ShiftReg2.Data_Port, Copy_ShiftReg2.Data_Pin, READ_BIT(Copy_u8Data2, Local_intIterator));
		GPIO_SetPinValue(Copy_ShiftReg1.Shift_Clock_Port, Copy_ShiftReg1.Shift_Clock_Pin, GPIO_PIN_HIGH);
	}

	GPIO_SetPinValue(Copy_ShiftReg1.Latch_Clock_Port, Copy_ShiftReg1.Latch_Clock_Pin, GPIO_PIN_HIGH);

}



