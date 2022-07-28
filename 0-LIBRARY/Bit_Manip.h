/*
--> Atmega16/Atmega32 Driver for Bit Manipulation but depeneds on the DIO Registers  
--> Author: Mohamed Hassan Fola

		   -----
1	PB0	 -|		|-	PA0	 40
2	PB1	 -|		|-	PA1	 39
3	PB2	 -|		|-	PA2	 38
4	PB3	 -|		|-	PA3	 37
5   PB4	 -|		|-	PA4	 36
6 	PB5  -|		|-	PA5	 35
7   PB6  -|		|-	PA6	 34
8 	PB7  -|		|-	PA7	 33
9		 -|		|-		 32
10		 -|		|-		 31
11		 -|		|-	     30
12		 -|		|-	PC7	 29
13		 -|		|-	PC6	 28
14	PD0	 -|		|-	PC5	 27
15	PD1	 -|		|-	PC4	 26
16	PD2	 -|		|-	PC3	 25
17	PD3	 -|		|-	PC2	 24
18	PD4	 -|		|-	PC1	 23
19	PD5	 -|		|-	PC0	 22
20	PD6	 -|		|-  PD7  21
		   -----	       
*/

#ifndef _BIT_MANIP_H_
#define _BIT_MANIP_H_

#include "DIO_Registers"


#define GPIO_PORT(PORT_NAME)                             (PORT##PORT_NAME)
#define GPIO_DIRECTION(PORT_NAME)                        (DDR##PORT_NAME)
#define GPIO_STATE(PORT_NAME)                            (PIN##PORT_NAME)


#define PIN_MODE(PORT_NAME, Bit, Mode)                   (GPIO_DIRECTION(PORT_NAME)) = ((GPIO_DIRECTION(PORT_NAME)) | MASK(Bit)) & ~(((Mode)  == 0)<<(Bit))
#define DIGITAL_WRITE(PORT_NAME, Bit, Value)             (GPIO_PORT(PORT_NAME))      = ((GPIO_PORT(PORT_NAME))      | MASK(Bit)) & ~(((Value) == 0)<<(Bit))


#define SET_BIT_HIGH(PORT_NAME, Bit)                     ((GPIO_PORT(PORT_NAME)) |= MASK(Bit))
#define SET_BIT_LOW(PORT_NAME, Bit)                      ((GPIO_PORT(PORT_NAME)) &= ~MASK(Bit))
#define TOGGLE_BIT_PORT(PORT_NAME, Bit)                  ((GPIO_PORT(PORT_NAME)) ^= MASK(Bit))


#define SET_BIT_OUTPUT(PORT_NAME, Bit)                   ((GPIO_DIRECTION(PORT_NAME)) |= MASK(Bit))
#define SET_BIT_INPUT(PORT_NAME, Bit)                    ((GPIO_DIRECTION(PORT_NAME)) &= ~MASK(Bit))


#define READ_BIT_PIN(PORT_NAME, Bit)                     (((GPIO_STATE(PORT_NAME))>>(Bit)) & 0x01)
#define IS_BIT_HIGH(PORT_NAME, Bit)                      (((GPIO_STATE(PORT_NAME))>>(Bit)) & 0x01)
#define IS_BIT_LOW(PORT_NAME, Bit)                      ~(((GPIO_STATE(PORT_NAME))>>(Bit)) & 0x01)


#endif  /* _BIT_MANIP_H_ */