/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 2.00                      ************/
/************ SWC     : RCC                       ************/
/*************************************************************/
/*************************************************************/

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_


typedef enum
{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOH   = 7,
	CRC     = 12,
	DMA1    = 21,
	DMA2,
	OTGFS   = 30,
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	WWDG    = 42,
	SPI2    = 45,
	SPI3,
	USART2  = 48,
	I2C1    = 52,
	I2C2,
	I2C3,
	PWR     = 59,
	TIM1,
	USART1  = 64,
	USART6,
	ADC1    = 68,
	SDIO    = 71,
	SPI1,
	SPI4,
	SYSCFG,
	TIM9    = 76,
	TIM10,
	TIM11,
}Peripherals_t;



/********************************************
 * Name        : RCC_voidSystemClockEnable  *
 * Return type : void                       *
 * Arguments   : void                       *
 * description : Enables System Clock       *
 *******************************************/
void RCC_voidSystemClockEnable(void);

/************************************************************************
 * Name        : RCC_voidPeripheralClockEnable                          *
 * Return type : void                                                   *
 * Arguments   : Copy_u8PerphiralName --> Peripherals_t, (enum values)  *
 * description : Enables Clock for a certain Peripheral                 *
 ***********************************************************************/
void RCC_voidPeripheralClockEnable(Peripherals_t Copy_PeripheralName);

/************************************************************************
 * Name        : RCC_voidPeripheralClockDisable                         *
 * Return type : void                                                   *
 * Arguments   : Copy_u8PerphiralName --> Peripherals_t, (enum values)  *
 * description : Disables Clock for a certain Peripheral                *
 ***********************************************************************/
void RCC_voidPeripheralClockDisable(Peripherals_t Copy_PeripheralName);


#endif /* RCC_INTERFACE_H_ */
