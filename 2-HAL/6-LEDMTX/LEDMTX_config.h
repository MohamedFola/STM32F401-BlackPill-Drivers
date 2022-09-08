/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL                       ************/
/************ Version : 1.00                      ************/
/************ SWC     : LED Matrix                ************/
/*************************************************************/
/*************************************************************/

#ifndef _LEDMTX_CONFIG_H_
#define _LEDMTX_CONFIG_H_

/* Define Number of Rows and Columns */
#define LEDMTX_NO_ROWS        8
#define LEDMTX_NO_COLUMNS     8


/* Set Suitable Time to avoid Flickring and Ghosting --> Set Number to Ticks */
#define LEDMTX_SCAN_TIME      250


/* Configurations of Row and Column Pins */
typedef struct
{
	u8 LEDMTX_PORT;
	u8 LEDMTX_PIN;
}LEDMTX_t;


LEDMTX_t LEDMTX_u8ColumnsArray[LEDMTX_NO_ROWS] = {
		{GPIOx_PORTA, GPIOx_PIN0},
		{GPIOx_PORTA, GPIOx_PIN1},
		{GPIOx_PORTA, GPIOx_PIN2},
		{GPIOx_PORTA, GPIOx_PIN3},
		{GPIOx_PORTA, GPIOx_PIN4},
		{GPIOx_PORTA, GPIOx_PIN5},
		{GPIOx_PORTA, GPIOx_PIN6},
		{GPIOx_PORTA, GPIOx_PIN7},
};

LEDMTX_t LEDMTX_u8RowsArray[LEDMTX_NO_ROWS] = {
		{GPIOx_PORTB, GPIOx_PIN0},
		{GPIOx_PORTB, GPIOx_PIN1},
		{GPIOx_PORTB, GPIOx_PIN5},
		{GPIOx_PORTB, GPIOx_PIN6},
		{GPIOx_PORTB, GPIOx_PIN7},
		{GPIOx_PORTB, GPIOx_PIN8},
		{GPIOx_PORTB, GPIOx_PIN9},
		{GPIOx_PORTB, GPIOx_PIN10},
};

#endif /* _LEDMTX_CONFIG_H_ */
