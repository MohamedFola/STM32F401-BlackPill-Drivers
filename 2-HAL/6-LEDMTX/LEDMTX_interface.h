/*************************************************************/
/*************************************************************/
/************ Author  : Mohamed Hassan Hassan     ************/
/************ Layer   : HAL                       ************/
/************ Version : 1.00                      ************/
/************ SWC     : LED Matrix                ************/
/*************************************************************/
/*************************************************************/

#ifndef _LEDMTX_INTERFACE_H_
#define _LEDMTX_INTERFACE_H_


#define LEDMTX_WORKFOREVER       0


/***********************************************
 * Name        : LEDMTX_voidInit               *
 * Return type : void                          *
 * Arguments   : void                          *
 * Description : Initiate the LED Matrix       *
 **********************************************/
void LEDMTX_voidInit(void);


/*****************************************************
 * Name        : LEDMTX_voidDisplayFrame             *
 * Return type : void                                *
 * Arguments   : Copy_u8Frame    --> array of u8     *
 *               Copy_FrameDelay --> u32             *
 * Description : Displays a Frame on the LED Matrix  *
 *****************************************************/
void LEDMTX_voidDisplayFrame(u8 Copy_u8Frame[], u32 Copy_FrameDelay);


#endif /* _LEDMTX_INTERFACE_H_ */
