/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : EXTI                      ************/
/*************************************************************/
/*************************************************************/

#ifndef _EXTI_ISR_HANDLER_H_
#define _EXTI_ISR_HANDLER_H_


static void(*ptr_CallBack[23])(void) = {NULL};



/* ISR for EXTI0 */
void EXTI0_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI0_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[0] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[0]();
		EXTI_voidClearFlag(EXTI_0);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI1 */
void EXTI1_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI1_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[1] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[1]();
		EXTI_voidClearFlag(EXTI_1);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI2 */
void EXTI2_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI2_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[2] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[2]();
		EXTI_voidClearFlag(EXTI_2);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI3 */
void EXTI3_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI3_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[3] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[3]();
		EXTI_voidClearFlag(EXTI_3);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI4 */
void EXTI4_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI4_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[4] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[4]();
		EXTI_voidClearFlag(EXTI_4);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI5 */
void EXTI5_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI5_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[5] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[5]();
		EXTI_voidClearFlag(EXTI_5);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI6 */
void EXTI6_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI6_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[6] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[6]();
		EXTI_voidClearFlag(EXTI_6);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI7 */
void EXTI7_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI7_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[7] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[7]();
		EXTI_voidClearFlag(EXTI_7);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI8 */
void EXTI8_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI8_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[8] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[8]();
		EXTI_voidClearFlag(EXTI_8);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}




/* ISR for EXTI9 */
void EXTI9_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI9_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[9] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[9]();
		EXTI_voidClearFlag(EXTI_9);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI10 */
void EXTI10_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI10_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[10] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[10]();
		EXTI_voidClearFlag(EXTI_10);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI11 */
void EXTI11_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI11_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[11] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[11]();
		EXTI_voidClearFlag(EXTI_11);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI12 */
void EXTI12_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI12_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[12] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[12]();
		EXTI_voidClearFlag(EXTI_12);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI13 */
void EXTI13_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI13_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[13] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[13]();
		EXTI_voidClearFlag(EXTI_13);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI14 */
void EXTI14_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI14_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[14] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[14]();
		EXTI_voidClearFlag(EXTI_14);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI15 */
void EXTI15_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI15_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[15] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[15]();
		EXTI_voidClearFlag(EXTI_15);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}


/* ISR for EXTI16 */
void EXTI16_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI16_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[16] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[16]();
		EXTI_voidClearFlag(EXTI_16);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI17 */
void EXTI17_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI17_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[17] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[18]();
		EXTI_voidClearFlag(EXTI_17);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI18 */
void EXTI18_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI18_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[18] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[18]();
		EXTI_voidClearFlag(EXTI_18);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



/* ISR for EXTI21 */
void EXTI21_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI21_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[21] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[21]();
		EXTI_voidClearFlag(EXTI_21);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}




/* ISR for EXTI22 */
void EXTI22_IRQHandler(void)
{
	/*
	 Handling the ISR of a Specific EXTI Interrupt
	 If EXTI22_CallBack not NULL then Call the Function
	 */

	if(ptr_CallBack[22] != NULL)
	{
		/* Call the Function and Clear the Flag */

		ptr_CallBack[22]();
		EXTI_voidClearFlag(EXTI_22);
	}
	else
	{
		/* NULL POINTER */
		/* DO NOTHING */
	}
}



#endif /* _EXTI_ISR_HANDLER_H_ */
