/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : USART                     ************/
/*************************************************************/
/*************************************************************/


#ifndef _USART_CONFIG_H_
#define _USART_CONFIG_H_

/************************************
 * Word Length                      *
 * Options:                         *
 * 		1 --> USART_8BIT_MODE       *
 * 		2 --> USART_9BIT_MODE       *
 ************************************/
#define USART1_WORD_LENGTH     USART_8BIT_MODE
#define USART2_WORD_LENGTH     USART_8BIT_MODE
#define USART6_WORD_LENGTH     USART_8BIT_MODE


/************************************
 * Stop Bit                         *
 * Options:                         *
 * 		1 --> USART_1_STOP_BIT      *
 * 		2 --> USART_2_STOP_BIT      *
 ************************************/
#define USART1_STOP_BIT        USART_1_STOP_BIT
#define USART2_STOP_BIT        USART_1_STOP_BIT
#define USART6_STOP_BIT        USART_1_STOP_BIT


/************************************
 * Parity Bit Enable                *
 * Options:                         *
 * 		1 --> USART_NO_PARITY       *
 * 		2 --> USART_EVEN_PARITY     *
 * 		3 --> USART_ODD_PARITY      *
 ************************************/
#define USART1_PARITY_ON       USART_NO_PARITY
#define USART2_PARITY_ON       USART_NO_PARITY
#define USART6_PARITY_ON       USART_NO_PARITY



/************************************
 * Baud Rate                        *
 * Options:                         *
 * 		1 -->  USART_9600_16MHZ     *
 * 		2 -->  USART_9600_25MHZ     *
 * 		3 -->  USART_19200_16MHZ    *
 * 		4 -->  USART_19200_25MHZ    *
 * 		5 -->  USART_115200_16MHZ   *
 * 		6 -->  USART_115200_25MHZ   *
 ************************************/
#define USART1_BAUD_RATE       USART_9600_16MHZ
#define USART2_BAUD_RATE       USART_9600_16MHZ
#define USART6_BAUD_RATE       USART_9600_16MHZ





#endif /* _USART_CONFIG_H_ */
