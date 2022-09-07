/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : EXTI                      ************/
/*************************************************************/
/*************************************************************/


#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_ISR_Handler.h"



/*************************************************************************
 * Name        : EXTI_voidSelectTrigger                                  *
 * Return type : void                                                    *
 * Arguments   :                                                         *
 *			1 --> Copy_u8EXTI_line, u8                                   *
 *			2 --> Copy_u8TriggerSelection, u8                            *
 *											                             *
 * description : Configures the Trigger Signal EXTI for a certain line   *
 *************************************************************************/
void EXTI_voidSelectTrigger(u8 Copy_u8EXTI_line, u8 Copy_u8TriggerSelection)
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if(Copy_u8EXTI_line < 23)
	{
		/* Selecting trigger */

		if(Copy_u8TriggerSelection == EXTI_RISING_EDGE_TRIGGER)
		{
			/*
			 For Rising Edge only
			 Set EXTI line for Rising Trigger Selection Register
			 Clear EXTI line for Falling Trigger Selection Register
			 */

			SET_BIT(EXTI->RTSR, Copy_u8EXTI_line);
			CLEAR_BIT(EXTI->FTSR, Copy_u8EXTI_line);
		}
		else if(Copy_u8TriggerSelection == EXTI_FALLING_EDGE_TRIGGER)
		{
			/*
			 For Falling Edge only
			 Clear EXTI line for Rising Trigger Selection Register
			 Set EXTI line for Falling Trigger Selection Register
			 */

			CLEAR_BIT(EXTI->RTSR, Copy_u8EXTI_line);
			SET_BIT(EXTI->FTSR, Copy_u8EXTI_line);
		}
		else if(Copy_u8TriggerSelection == EXTI_FALLING_EDGE_TRIGGER)
		{
			/*
			 For Both Triggers
			 Set EXTI line for Rising Trigger Selection Register
			 Set EXTI line for Falling Trigger Selection Register
			 */

			SET_BIT(EXTI->RTSR, Copy_u8EXTI_line);
			SET_BIT(EXTI->FTSR, Copy_u8EXTI_line);
		}
		else
		{
			/* Wrong Trigger Selection */
			/* DO NOTHING */
		}
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}


/*******************************************************************
 * Name        : EXTI_voidControlLine                              *
 * Return type : void                                              *
 * Arguments   :                                                   *
 *			1 --> Copy_u8EXTI_line, u8                             *
 *			2 --> Copy_u8LineState, u8                             *
 *											                       *
 * description : Sets the State for a Specific EXTI line           *
 *******************************************************************/
void EXTI_voidControlLine(u8 Copy_u8EXTI_line, u8 Copy_u8LineState)
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if(Copy_u8EXTI_line < 23)
	{
		/*
		 Enable or Disable EXTI interrupt
		 If State is EXTI_ENABLE Set EXTI line for Interrupt Mask Register
		 If State is EXTI_DISABLE Clear EXTI line for Interrupt Mask Register
		 */

		if(Copy_u8LineState == EXTI_ENABLE)
		{
			SET_BIT(EXTI->IMR , Copy_u8EXTI_line);
		}
		else if(Copy_u8LineState == EXTI_DISABLE)
		{
			CLEAR_BIT(EXTI->IMR , Copy_u8EXTI_line);
		}
		else
		{
			/* Wrong EXTI line state */
			/* DO NOTHING */
		}
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}



/*************************************************************************
 * Name        : EXTI_voidSoftwareTrigger                            	 *
 * Return type : void                                                    *
 * Arguments   :                                                   		 *
 *			1 --> Copy_u8EXTI_line, u8                             		 *
 *											                           	 *
 * description : Sets the State for a Specific EXTI line by Software     *
 *************************************************************************/
void EXTI_voidSoftwareTrigger(u8 Copy_u8EXTI_line)
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if(Copy_u8EXTI_line < 23)
	{
		/* Set EXTI line for Software Interrupt Event Register */

		SET_BIT(EXTI->SWIER, Copy_u8EXTI_line);
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}



/*************************************************************************
 * Name        : EXTI_voidClearFlag                                 	 *
 * Return type : void                                                    *
 * Arguments   :                                                   		 *
 *			1 --> Copy_u8EXTI_line, u8                             		 *
 *											                           	 *
 * description : Clears Flag for a Specific EXTI line by Software        *
 *************************************************************************/
void EXTI_voidClearFlag(u8 Copy_u8EXTI_line)
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if(Copy_u8EXTI_line < 23)
	{
		/* Clear Bit for Pending Register by Writing one to it */

		SET_BIT(EXTI->PR, Copy_u8EXTI_line);
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}



/*************************************************************************
 * Name        : EXTI_voidSetCallBack                                 	 *
 * Return type : void                                                    *
 * Arguments   :                                                   		 *
 *			1 --> Copy_u8EXTI_line, u8                                   *
 *			2 --> ptr_Function, pointer to function                      *
 *											                           	 *
 * description : Sets the Call Back Function for a Specific EXTI line    *
 *************************************************************************/
void EXTI_voidSetCallBack(u8 Copy_u8EXTI_line, void(*ptr_Function)(void))
{
	/*
	 Check for EXTI number
	 If number is less than 23              --> applicable
	 If number is greater than or equal 23  --> not applicable
	 */

	if(Copy_u8EXTI_line < 23)
	{
		/* Set the Function Address to the Call Back Function */

		ptr_CallBack[Copy_u8EXTI_line] = ptr_Function;
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}



/****************************************************************
 * Name        : EXTI_voidSelectPort                            *
 * Return type : void                                           *
 * Arguments   :                                                *
 *			1 --> Copy_u8EXTI_line, u8                          *
 *			2 --> Copy_u8Pin, u8                                *
 *											                    *
 * description : Selects the pin for a Specific EXTI            *
 ****************************************************************/
void EXTI_voidSelectPort(u8 Copy_u8EXTI_line, u8 Copy_u8Port)
{
	/*
	 Check for Pin number
	 If number is less than 16              --> applicable
	 If number is greater than or equal 16  --> not applicable
	 */

	if(Copy_u8Port < 8 && Copy_u8Port != 5 && Copy_u8Port != 6 )
	{
		/*
		 Check for the EXTI number to Know Which Register to use
		 for EXTI0 to EXTI3   --> use SYSCFG_EXTICR1
		 for EXTI4 to EXTI7   --> use SYSCFG_EXTICR2
		 for EXTI8 to EXTI11  --> use SYSCFG_EXTICR3
		 for EXTI12 to EXTI5  --> use SYSCFG_EXTICR4
		 */

		if     (Copy_u8EXTI_line < 4)
		{
			SYSCFG_EXTICR1 &= ~(0b1111 << (4 * (Copy_u8EXTI_line)));
			SYSCFG_EXTICR1 |=  (Copy_u8Port << (4 * (Copy_u8EXTI_line)));
		}
		else if(Copy_u8EXTI_line < 8)
		{
			SYSCFG_EXTICR2 &= ~(0b1111 << (4 * (Copy_u8EXTI_line)));
			SYSCFG_EXTICR2 |= (Copy_u8Port << (4 * (Copy_u8EXTI_line - 4)));
		}
		else if(Copy_u8EXTI_line < 12)
		{
			SYSCFG_EXTICR3 &= ~(0b1111 << (4 * (Copy_u8EXTI_line)));
			SYSCFG_EXTICR3 |= (Copy_u8Port << (4 * (Copy_u8EXTI_line - 8)));
		}
		else if(Copy_u8EXTI_line < 16)
		{
			SYSCFG_EXTICR4 &= ~(0b1111 << (4 * (Copy_u8EXTI_line)));
			SYSCFG_EXTICR4 |= (Copy_u8Port << (4 * (Copy_u8EXTI_line - 12)));
		}
		else
		{
			/* DO NOTHING */;
		}
	}
	else
	{
		/* Wrong EXTI line number */
		/* DO NOTHING */
	}
}


