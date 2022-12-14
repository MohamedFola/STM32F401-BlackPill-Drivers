/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL " STM32F401 "         ************/
/************ Version : 1.00                      ************/
/************ SWC     : Buzzer                    ************/
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


#ifndef _BUZZER_INTERFACE_H_
#define _BUZZER_INTERFACE_H_

typedef struct _BUZZER_ BUZZER;

struct _BUZZER_
{
	u8 PORT:2;
	u8 PIN:4;
};

#define BUZZER_ON     1
#define BUZZER_OFF    0

void BUZZER_Status(BUZZER Copy_Buzzer, u8 Copy_u8Status);


#endif /* _BUZZER_INTERFACE_H_ */
