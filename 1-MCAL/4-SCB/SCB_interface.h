/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : MCAL                      ************/
/************ Version : 1.00                      ************/
/************ SWC     : SCB                       ************/
/*************************************************************/
/*************************************************************/

#ifndef _SCB_INTERFACE_H_
#define _SCB_INTERFACE_H_


/***********************************************************
 * Name        : SCB_voidControlInterruptGrouping           *
 * Return type : void                       			    *
 * Arguments   : Copy_u8GroupingMode --> u8                 *
 * description : Sets the Grouping Mode for NVIC            *
 ************************************************************/
void SCB_voidControlInterruptGrouping(u32 Copy_u32GroupingMode);


#endif /* _SCB_INTERFACE_H_ */
