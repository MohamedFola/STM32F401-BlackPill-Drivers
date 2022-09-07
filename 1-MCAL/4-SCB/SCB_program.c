/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : SCB                       ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"

void SCB_voidControlInterruptGrouping(u32 Copy_u32GroupingMode)
{
	SCB_AIRCR = SCB_AIRCR_WRITE_VALUE + ((Copy_u32GroupingMode + 3) << 8);
}
