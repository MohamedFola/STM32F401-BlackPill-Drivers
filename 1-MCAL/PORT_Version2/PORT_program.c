/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : PORT                      ************/
/*************************************************************/
/*************************************************************/

#include "STD_Types.h"
#include "Bit_Manipulation.h"

#include "PORT_interface.h"
#include "GPIO_private.h"
#include "PORT_config.h"
#include "PORT_private.h"



void PORT_voidInit(void)
{
	/* Load the mode to GPIOx_MODER register */
	GPIOA->MODER = GPIOA_Mode;
	GPIOB->MODER = GPIOB_Mode;
	GPIOC->MODER = GPIOC_Mode;
	
	/* Load the output type to GPIOx_OTYPER register */
	GPIOA->OTYPER = GPIOA_Output_Type;
	GPIOB->OTYPER = GPIOB_Output_Type;
	GPIOC->OTYPER = GPIOC_Output_Type;
	
	/* Load Speed to OSPEEDR */
	GPIOA->OSPEEDR = GPIOA_Speed ;
    GPIOB->OSPEEDR = GPIOB_Speed ;
    GPIOC->OSPEEDR = GPIOC_Speed ;
	
	/* Load Pull up or Pull down to GPIOx_PUPDR register */
	GPIOA->PUPDR = GPIOA_PUPD ;
	GPIOB->PUPDR = GPIOB_PUPD ;
	GPIOC->PUPDR = GPIOC_PUPD ;


	/* Alternative function selection */
	GPIOA->AFRL = BitManipulationGetBits(GPIOA_AF, 0, 32);
	GPIOB->AFRL = BitManipulationGetBits(GPIOB_AF, 0, 32);
	GPIOC->AFRL = BitManipulationGetBits(GPIOC_AF, 0 ,32);
	
	GPIOA->AFRH = BitManipulationGetBits(GPIOA_AF, 32, 32);
    GPIOB->AFRH = BitManipulationGetBits(GPIOB_AF, 32, 32);
    GPIOC->AFRH = BitManipulationGetBits(GPIOC_AF, 32, 32);
	
}
