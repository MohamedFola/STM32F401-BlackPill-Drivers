/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL " STM32F401 "         ************/
/************ Version : 1.00                      ************/
/************ SWC     : Buzzer                    ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "GPIO_interface.h"

#include "BUZZER_interface.h"

void BUZZER_Status(BUZZER Copy_Buzzer, u8 Copy_u8Status)
{
	GPIO_SetPinValue(Copy_Buzzer.PORT, Copy_Buzzer.PIN, Copy_u8Status);
}

