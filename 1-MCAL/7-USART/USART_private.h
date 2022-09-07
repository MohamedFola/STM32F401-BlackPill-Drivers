/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : USART                     ************/
/*************************************************************/
/*************************************************************/

#ifndef _USART_PRIVATE_H_
#define _USART_PRIVATE_H_

#define USART_NO_PARITY         -1
#define USART_EVEN_PARITY       0
#define USART_ODD_PARITY        1

#define USART_8BIT_MODE         0
#define USART_9BIT_MODE         1

#define USART_1_STOP_BIT        0b00
#define USART_2_STOP_BIT        0b10

/* Baud Rates */
#define USART_9600_16MHZ         0x682
#define USART_9600_25MHZ         0xA2C
#define USART_19200_16MHZ        0x341
#define USART_19200_25MHZ        0x516
#define USART_115200_16MHZ       0x8A
#define USART_115200_25MHZ       0xD8

#define GetBaudRate(Fpclk, Over8, BaudRate) \
	((Fpclk) / ((8 * (2 - Over8)) * (BaudRate)))


/* USART Registers Definition */
#define USART1_BASE_ADDRESS     0x40011000
#define USART2_BASE_ADDRESS     0x40004400
#define USART6_BASE_ADDRESS     0x40011400

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_t;

#define USART1                  ((volatile USART_t*)(USART1_BASE_ADDRESS))
#define USART2                  ((volatile USART_t*)(USART2_BASE_ADDRESS))
#define USART6                  ((volatile USART_t*)(USART6_BASE_ADDRESS))


/* USART Pins of Registers Definition */
typedef enum
{
	PE,                 /* Start of SR */
	FE,
	NF,
	ORE,
	IDLE,
	RXEN,
	TC,
	TXE,
	LBD,
	CTS,                /* End of SR */
	DIV_Fractions = 0,  /* Start of BRR */
	DIV_Mantissa = 4,   /* End of BRR */
	SBK = 0,            /* Start of C1 */
	RWU,
	RE,
	TE,
	IDLEIE,
	RXNEIE,
	TCIE,
	TXEIE,
	PEIE,
	PS,
	PCE,
	WAKE,
	M,
	UE,
	OVER8 = 15,         /* End of C1 */
	ADD = 0,            /* Start of C2 */
	LBDL = 5,
	LBDIE,
	LBCL = 8,
	CHPA,
	CPOL,
	CLKEN,
	STOP,
	LINEN = 14,         /* End of C2 */
	EIE = 0,            /* Start of C3 */
	IREN,
	IRLP,
	HDSEL,
	NACK,
	SCEN,
	DMAR,
	DMAT,
	RTSE,
	CTSE,
	CTSIE,
	ONEBIT,             /* End of C3 */
	PSC = 0,            /* Start of GTPR */
	GT = 8,             /* End od GTPR */
}USART_Reg_Pins_t;


#endif /* _USART_PRIVATE_H_ */
