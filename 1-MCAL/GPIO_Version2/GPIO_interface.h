/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 2.00                      ************/
/************ SWC     : GPIO                      ************/
/*************************************************************/
/*************************************************************/
/*************************************************************
                         PA14    PA13
                    |      |      |      |
                    ----------------------
1  :              -|                      |-              : 40
2  :    PC13      -|                      |-              : 39
3  :    PC14      -|                      |-              : 38
4  :    PC15      -|                      |-       PB9    : 37
5  :              -|                      |-       PB8    : 36
6  :    PA0       -|      STM32F401       |-       PB7    : 35
7  :    PA1       -|                      |-       PB6    : 34
8  :    PA2       -|     Based on ARM     |-       PB5    : 33
9  :    PA3       -|                      |-       PB4    : 32
10 :    PA4       -|                      |-       PB3    : 31
11 :    PA5       -|                      |-       PA15   : 30
12 :    PA6       -|                      |-       PA12   : 29
13 :    PA7       -|                      |-       PA11   : 28
14 :    PB0       -|                      |-       PA10   : 27
15 :    PB1       -|                      |-       PA9    : 26
16 :    PB2       -|                      |-       PA8    : 25
17 :    PB10      -|                      |-       PB15   : 24
18 :              -|                      |-       PB14   : 23
19 :              -|                      |-       PB13   : 22
20 :              -|                      |-       PB12   : 21
                    ----------------------

**************************************************************/


#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_


#define GPIO_PIN_HIGH       1
#define GPIO_PIN_LOW        0

#define GPIO_PORT_HIGH      0xFFFF
#define GPIO_PORT_LOW       0x0000

typedef enum
{
	GPIOx_PORTA,
	GPIOx_PORTB,
	GPIOx_PORTC
}GPIOxPorts_t;


#define GPIO_PORTA          0
#define GPIO_PORTB          1
#define GPIO_PORTC          2

typedef enum
{
	GPIOx_PIN0,
	GPIOx_PIN1,
	GPIOx_PIN2,
	GPIOx_PIN3,
	GPIOx_PIN4,
	GPIOx_PIN5,
	GPIOx_PIN6,
	GPIOx_PIN7,
	GPIOx_PIN8,
	GPIOx_PIN9,
	GPIOx_PIN10,
	GPIOx_PIN11,
	GPIOx_PIN12,
	GPIOx_PIN13,
	GPIOx_PIN14,
	GPIOx_PIN15,
}GPIOxPins_t;


/* allowed pins for PORTA */
#define GPIO_PORTA_PIN0     0
#define GPIO_PORTA_PIN1     1
#define GPIO_PORTA_PIN2     2
#define GPIO_PORTA_PIN3     3
#define GPIO_PORTA_PIN4     4
#define GPIO_PORTA_PIN5     5
#define GPIO_PORTA_PIN6     6
#define GPIO_PORTA_PIN7     7
#define GPIO_PORTA_PIN8     8
#define GPIO_PORTA_PIN9     9
#define GPIO_PORTA_PIN10    10
#define GPIO_PORTA_PIN11    11
#define GPIO_PORTA_PIN12    12
#define GPIO_PORTA_PIN15    15

/* allowed pins for PORTB */
#define GPIO_PORTB_PIN0     0
#define GPIO_PORTB_PIN1     1
#define GPIO_PORTB_PIN2     2
#define GPIO_PORTB_PIN5     5
#define GPIO_PORTB_PIN6     6
#define GPIO_PORTB_PIN7     7
#define GPIO_PORTB_PIN8     8
#define GPIO_PORTB_PIN9     9
#define GPIO_PORTB_PIN10    10
#define GPIO_PORTB_PIN11    11
#define GPIO_PORTB_PIN12    12
#define GPIO_PORTB_PIN13    13
#define GPIO_PORTB_PIN14    14
#define GPIO_PORTB_PIN15    15

/* allowed pins for PORTC */
#define GPIO_PORTC_PIN13    13
#define GPIO_PORTC_PIN14    14
#define GPIO_PORTC_PIN15    15


/***********************************************
 * Name        : GPIO_SetPinValue              *
 * Return type : void                          *
 * Arguments   :                               *
 *			1 --> Copy_u8PortName, u8          *
 *			2 --> Copy_u8PinNumber, u8         *
 *			3 --> Copy_u8Value, u16            *
 *											   *
 * description : Set value for a certain pin   *
 **********************************************/
void GPIO_SetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u16 Copy_u8Value);


/************************************************************
 * Name        : GPIO_SetChannelGroupValue                  *
 * Return type : void                                       *
 * Arguments   :                                            *
 *			1 --> Copy_u8PortName, u8                       *
 *			2 --> Copy_u8PinNumber, u8                      *
 *			3 --> Copy_u8ChannelLength, u8                  *
 *			4 --> Copy_u8Value, u16                         *
 *											                *
 * description : Set value for a certain consecutive pins   *
 ***********************************************************/
void GPIO_SetChannelGroupValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8ChannelLength, u16 Copy_u8Value);


/***********************************************
 * Name        : GPIO_SetPortValue             *
 * Return type : void                          *
 * Arguments   :                               *
 *			1 --> Copy_u8PortName, u8          *
 *			2 --> Copy_u8Value, u16            *
 *											   *
 * description : Set value for a certain port  *
 **********************************************/
void GPIO_SetPortValue(u8 Copy_u8PortName, u16 Copy_u8value);


/***********************************************
 * Name        : GPIO_GetPinValue              *
 * Return type : u8                            *
 * Arguments   :                               *
 *			1 --> Copy_u8PortName, u8          *
 *			2 --> Copy_u8PinNumber, u8         *
 *			3 --> ptr_u16Value, u16*           *
 *											   *
 * description : Get value from a certain pin  *
 **********************************************/
u8 GPIO_GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u16* ptr_u16Value);


/************************************************************
 * Name        : GPIO_GetChannelGroupValue                  *
 * Return type : void                                       *
 * Arguments   :                                            *
 *			1 --> Copy_u8PortName, u8                       *
 *			2 --> Copy_u8PinNumber, u8                      *
 *			3 --> Copy_u8ChannelLength, u8                  *
 *			4 --> ptr_u16Value, u16*                        *
 *											                *
 * description : Get value from a certain consecutive pins  *
 ***********************************************************/
u8 GPIO_GetChannelGroupValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8ChannelLength, u16* ptr_u16Value);


#endif
