/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL "STM32F401"           ************/
/************ Version : 1.00                      ************/
/************ SWC     : LED                       ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"

#include "GPIO_interface.h"
#include "LED_interface.h"

void LED_Status(LED Copy_led, u8 Copy_u8Status)
{
	GPIO_SetPinValue(Copy_led.PORT, Copy_led.PIN, (Copy_u8Status) ^ (Copy_led.Connection_Type));
}
