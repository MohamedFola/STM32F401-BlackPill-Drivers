/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HCAL " STM32F401 "        ************/
/************ Version : 1.00                      ************/
/************ SWC     : Keypad                    ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "GPIO_interface.h"

#include "KeyPad_config.h"
#include "KeyPad_interface.h"
#include "KeyPad_private.h"

u8 KPD_GetPressedKey()
{
	u8 Local_u8RowIndex, Local_u8ColumnIndex;
	u16 Local_u16PinState;
	static u8 Local_u8KPDArr[KPD_ROW_NUMBER][KPD_COLUMN_NUMBER] = KPD_ARR_VALUES;
	static u8 Local_u8KPDColumnArr[KPD_COLUMN_NUMBER] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[KPD_ROW_NUMBER] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	
	for(Local_u8ColumnIndex = 0; Local_u8ColumnIndex<KPD_COLUMN_NUMBER; Local_u8ColumnIndex++)
	{
		/* Activate current Column */
	GPIO_SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], GPIO_PIN_LOW);
		
		for(Local_u8RowIndex = 0; Local_u8RowIndex<KPD_ROW_NUMBER; Local_u8RowIndex++)
		{
			/* Read current Row */
			GPIO_GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIndex], &Local_u16PinState);
			
			/* Check the PIN Value */
			if(GPIO_PIN_LOW == Local_u16PinState)
			{
				/* Polling(Busy Waiting) */
				while(GPIO_PIN_LOW == Local_u16PinState) GPIO_GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIndex], &Local_u16PinState);
				return Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
			}
		}
		
		/* Deactivate current Column */
		GPIO_SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIndex], GPIO_PIN_HIGH);
	}
	
	
	return KPD_NO_PRESSED_KEY;
}
