/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 2.00                      ************/
/************ SWC     : GPIO                      ************/
/*************************************************************/
/*************************************************************/

#ifndef _GPIO_REGISTERS_H_
#define _GPIO_REGISTERS_H_

/* base addresses of the GPIO registers */
#define GPIOC_BASE_ADDRESS                 (u32)(0x40020800)
#define GPIOB_BASE_ADDRESS                 (u32)(0x40020400)
#define GPIOA_BASE_ADDRESS                 (u32)(0x40020000)


typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u16 BSRR_Set;
	volatile u16 BSRR_Reset;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIO_Port_t;

#define GPIOA      ((volatile GPIO_Port_t*)(GPIOA_BASE_ADDRESS))  /* PORTA base address */
#define GPIOB      ((volatile GPIO_Port_t*)(GPIOB_BASE_ADDRESS))  /* PORTB base address */
#define GPIOC      ((volatile GPIO_Port_t*)(GPIOC_BASE_ADDRESS))  /* PORTC base address */



#endif
