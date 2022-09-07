/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : NVIC                      ************/
/*************************************************************/
/*************************************************************/

#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_

/*
 * This enum is for STM32F401 "Black Pill"
 * You can change the enum according to your Microcontroller's interrupt vector table
 */
typedef enum
{
	NVIC_WWDG,
	NVIC_EXTI16_PVD,
	NVIC_EXTI21_TAMP_STAMP,
	NVIC_EXTI22_RTC_WKUP,
	NVIC_FLASH,
	NVIC_RCC,
	NVIC_EXTI0,
	NVIC_EXTI1,
	NVIC_EXTI2,
	NVIC_EXTI3,
	NVIC_EXTI4,
	NVIC_DMA1_Stream0,
	NVIC_DMA1_Stream1,
	NVIC_DMA1_Stream2,
	NVIC_DMA1_Stream3,
	NVIC_DMA1_Stream4,
	NVIC_DMA1_Stream5,
	NVIC_DMA1_Stream6,
	NVIC_ADC,
	NVIC_EXTI9_5 = 23,
	NVIC_TIM1_BRK_TIM9,
	NVIC_TIM1_UP_TIM10,
	NVIC_TIM1_TRG_COM_TIM11,
	NVIC_TIM1_CC,
	NVIC_TIM2,
	NVIC_TIM3,
	NVIC_TIM4,
	NVIC_I2C1_EV,
	NVIC_I2C1_ER,
	NVIC_I2C2_EV,
	NVIC_I2C2_ER,
	NVIC_SPI1,
	NVIC_SPI2,
	NVIC_USART1,
	NVIC_USART2,
	NVIC_EXTI15_10 = 40,
	NVIC_EXTI17_RTC_Alarm,
	NVIC_EXTI18_OTG_FS_WKUP,
	NVIC_DMA1_Stream7,
	NVIC_SDIO = 49,
	NVIC_TIM5,
	NVIC_SPI3,
	NVIC_DMA2_Stream0 = 56,
	NVIC_DMA2_Stream1,
	NVIC_DMA2_Stream2,
	NVIC_DMA2_Stream3,
	NVIC_DMA2_Stream4,
	NVIC_OTG_FS = 67,
	NVIC_DMA2_Stream5,
	NVIC_DMA2_Stream6,
	NVIC_DMA2_Stream7,
	NVIC_USART6,
	NVIC_I2C3_EV,
	NVIC_I2C3_ER,
	NVIC_FPU = 81,
	NVIC_SPI4 = 84,
}NVIC_Table_t;



/*********************************************************************
 * Name        : NVIC_voidInit              						 *
 * Return type : void                       						 *
 * Arguments   : void                       						 *
 * description : Sets the Priority Model for group & sub-priorities  *
 *********************************************************************/
void NVIC_voidInit(void);


/*********************************************************************
 * Name        : NVIC_voidSetPriority	             				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition  --> u8                    *
 * 				 Copy_u8GroupPriority 	   --> u8                  	 *
 * 				 Copy_u8SubPriority 	   --> u8  					 *
 * description : Sets the priority for a specific interrupt		     *
 *********************************************************************/
void NVIC_voidSetPriority(u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);


/*********************************************************************
 * Name        : NVIC_voidEnableInterrupt              				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * description : Sets the NVIC enable pin for a specific interrupt   *
 *********************************************************************/
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptPosition);


/*********************************************************************
 * Name        : NVIC_voidDisableInterrupt             				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * description : Sets the NVIC disable pin for a specific interrupt  *
 *********************************************************************/
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptPosition);


/*********************************************************************
 * Name        : NVIC_voidSetPendingFlag             				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * description : Sets the NVIC enable pin for a specific interrupt   *
 *********************************************************************/
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptPosition);


/*********************************************************************
 * Name        : NVIC_voidClearPendingFlag             				 *
 * Return type : void                       						 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * description : Sets the NVIC disable pin for a specific interrupt  *
 *********************************************************************/
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptPosition);


/*********************************************************************
 * Name        : NVIC_u8GetActiveFlag                				 *
 * Return type : u8                       				  			 *
 * Arguments   : Copy_u8InterruptPosition --> u8                   	 *
 * description : Gets the active flag for a specific interrupt 		 *
 *********************************************************************/
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptPosition);




#endif /* _NVIC_INTERFACE_H_ */
