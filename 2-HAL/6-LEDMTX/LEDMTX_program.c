/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL                       ************/
/************ Version : 1.00                      ************/
/************ SWC     : LED Matrix                ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMTX_config.h"
#include "LEDMTX_interface.h"
#include "LEDMTX_private.h"




/***********************************************
 * Name        : LEDMTX_voidInit               *
 * Return type : void                          *
 * Arguments   : void                          *
 * Description : Initiate the LED Matrix       *
 **********************************************/
void LEDMTX_voidInit(void)
{
	/* Initiate the SYSTICK */
	SYSTICK_voidInit(SYSTICK_AHB_DIV_8_CLK);
}


static void LEDMTX_voidDisableAllColumns(void)
{
	/* Set All Columns to HIGH */
	for(int i=0; i<LEDMTX_NO_COLUMNS; i++)
	{
		GPIO_SetPinValue(
				LEDMTX_u8ColumnsArray[i].LEDMTX_PORT,
				LEDMTX_u8ColumnsArray[i].LEDMTX_PIN,
				GPIO_PIN_HIGH);
	}
}

static void LEDMTX_voidSetRowValues(u8 Copy_u8Frame)
{
	/* Write the Value to it's corresponding Pin */
	for(int i=0; i<LEDMTX_NO_ROWS; i++)
	{
		GPIO_SetPinValue(
				LEDMTX_u8RowsArray[i].LEDMTX_PORT,
				LEDMTX_u8RowsArray[i].LEDMTX_PIN,
				READ_BIT(Copy_u8Frame, i));
	}
}

static void LEDMTX_voidSetCurrentColumn(u8 Copy_u8ColumnNumber)
{
	/* Set the Current Column to LOW */
	GPIO_SetPinValue(
			LEDMTX_u8ColumnsArray[Copy_u8ColumnNumber].LEDMTX_PORT,
			LEDMTX_u8ColumnsArray[Copy_u8ColumnNumber].LEDMTX_PIN,
			GPIO_PIN_LOW);
}

/*****************************************************
 * Name        : LEDMTX_voidDisplayFrame             *
 * Return type : void                                *
 * Arguments   : Copy_u8Frame    --> array of u8     *
 *               Copy_FrameDelay --> u32             *
 * Description : Displays a Frame on the LED Matrix  *
 *****************************************************/
void LEDMTX_voidDisplayFrame(u8 Copy_u8Frame[], u32 Copy_FrameDelay)
{
	u32 Local_intCounter = 0;

	/* Check for the period to Display Frame */

	if(Copy_FrameDelay != LEDMTX_WORKFOREVER)
	{
		/* Display Frame for a certain Time */
		for(Local_intCounter = 0; Local_intCounter < (Copy_FrameDelay); Local_intCounter++)
		{
			/* Loop to all Columns */
			for(u32 Local_u32ColumnCounter = 0; Local_u32ColumnCounter < LEDMTX_NO_COLUMNS; Local_u32ColumnCounter++)
			{
				/* Disable All Columns */
				LEDMTX_voidDisableAllColumns();

				/* Set Row Values */
				LEDMTX_voidSetRowValues(Copy_u8Frame[Local_u32ColumnCounter]);

				/* Set Current Column */
				LEDMTX_voidSetCurrentColumn(Local_u32ColumnCounter);

				/* Delay for the Suitable time */
				SYSTICK_voidSetBusyWait(LEDMTX_SCAN_TIME);
			}
		}
	}
	else
	{
		/* Display the Frame forever */
		while(1)
		{
			/* Disable All Columns */
			LEDMTX_voidDisableAllColumns();

			/* Set Row Values */
			LEDMTX_voidSetRowValues(Copy_u8Frame[Local_intCounter]);

			/* Set Current Column */
			LEDMTX_voidSetCurrentColumn(Local_intCounter++);

			/* Delay for the Suitable time */
			SYSTICK_voidSetBusyWait(LEDMTX_SCAN_TIME);

			/* Keep Counter in the Range */
			if(Local_intCounter > LEDMTX_NO_COLUMNS) Local_intCounter = 0;
		}
	}

}
