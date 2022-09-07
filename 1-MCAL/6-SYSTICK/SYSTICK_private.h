/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : SYSTICK                   ************/
/*************************************************************/
/*************************************************************/

#ifndef _SYSTICK_PRIVATE_H_
#define _SYSTICK_PRIVATE_H_

/*******************************************************/
/******************** Useful Macros ********************/
/*******************************************************/

#define SYSTICK_SINGLE_INTERVAL         0
#define SYSTICK_PERIODIC_INTERVAL       1



/***********************************************************/
/******************** SYSTICK Registers ********************/
/***********************************************************/

#define SYSTICK_BASE_ADDRESS     0xE000E010

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SYSTICK_t;

#define SYSTICK                  ((volatile SYSTICK_t*)(SYSTICK_BASE_ADDRESS))



/******************************************************/
/******************** SYSTICK Pins ********************/
/******************************************************/

typedef enum
{
	ENABLE,
	TICKINT,
	CLKSOURCE,
	COUNTFLAG = 16,
}SYSTICK_CTRL_t;


typedef enum
{
	TENMS,
	SKEW = 30,
	NOREF,
}SYSTICK_CALIB_t;


#endif /* _SYSTICK_PRIVATE_H_ */
