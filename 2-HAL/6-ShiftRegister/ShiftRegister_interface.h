/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL                       ************/
/************ Version : 1.00                      ************/
/************ SWC     : Shift Register            ************/
/*************************************************************/
/*************************************************************/

#ifndef _SHIFTREGISTER_INTERFACE_H_
#define _SHIFTREGISTER_INTERFACE_H_


typedef struct _ShiftRegister_ ShiftRegister;

struct _ShiftRegister_
{
	u8 Data_Port;
	u8 Data_Pin;
	u8 Shift_Clock_Port;
	u8 Shift_Clock_Pin;
	u8 Latch_Clock_Port;
	u8 Latch_Clock_Pin;
	u8 Output_Enable_Port;
	u8 Output_Enable_Pin;
};


/***************************************************
 * Name        : ShiftRegister_voidSendData        *
 * Return type : void                              *
 * Arguments   : Copy_ShiftReg  --> ShiftRegister  *
 *               Copy_u8Data    --> u8             *
 * description : Sends Data to Shift Register      *
 ***************************************************/
void ShiftRegister_voidSendData(ShiftRegister Copy_ShiftReg, u8 Copy_u8Data);



/**************************************************************
 * Name        : ShiftRegister_voidSendDataForTwoModules      *
 * Return type : void                                         *
 * Arguments   : Copy_ShiftReg1  --> ShiftRegister            *
 *               Copy_u8Data1    --> u8                       *
 *               Copy_ShiftReg2  --> ShiftRegister            *
 *               Copy_u8Data2    --> u8                       *
 * description : Sends Data to Tow Shift Registers            *
 **************************************************************/
void ShiftRegister_voidSendDataForTwoModules(ShiftRegister Copy_ShiftReg1, u8 Copy_u8Data1, ShiftRegister Copy_ShiftReg2, u8 Copy_u8Data2);

#endif /* _SHIFTREGISTER_INTERFACE_H_ */
