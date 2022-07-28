/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL "STM32F401"           ************/
/************ Version : 1.00                      ************/
/************ SWC     : LED                       ************/
/*************************************************************/
/*************************************************************/
/*************************************************************

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




/*************************************************************************************************************************/
/** Define The port used in the hardware connection  -->  PORTA or PORTB or PORTC                                       **/
/**																														**/
/**	Define The pin used in the hardware connection   -->  Choose any pin form the above draw except for PB3 and PB4     **/
/**																														**/
/**	Define The connection type                       -->  Source connection or Sink connection                          **/
/**                                                                                                                     **/
/**	1) Source Connection --> Connect the +ve of the led with the Microcontroller Pin and the -ve of the led to ground   **/
/**		to make the led on --> put 5 volt on Microcontroller Pin                                                        **/
/**		to make the led on --> put 0 volt on Microcontroller Pin                                                        **/
/**																														**/
/**	2) Sink Connection   --> Connect the -ve of the led with the Microcontroller Pin and the +ve of the led to 5 volt   **/
/**		to make the led on --> put 0 volt on Microcontroller Pin                                                        **/
/**		to make the led on --> put 5 volt on Microcontroller Pin                                                        **/
/*************************************************************************************************************************/


#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_


typedef struct _LED_ LED;

struct _LED_
{
	u8 PORT:2;
	u8 PIN:4;
	u8 Connection_Type:1;
};

#define LED_OFF                  0
#define LED_ON                   1

#define LED_Source_Connection    0
#define LED_Sink_Connection      1


void LED_Status(LED Copy_led, u8 Copy_u8Status);


#endif
