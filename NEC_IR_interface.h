/*************************************************************************/
/* Author        : Mohamed Mokhtar Abd-Elaziz                            */
/* File          : NEC_IR_INTERFACE_H                                    */
/*Description    : An educational driver file for IR receiver based      */
/*                 on NEC standard.                                      */
/* Date          : 22 02 2022                                            */
/* Version       : V03-> Repeat handling  &  data verification edited    */
/* GitHub        : https://github.com/mmokhtar761                        */
/*************************************************************************/
#ifndef NEC_IR_INTERFACE_H
#define NEC_IR_INTERFACE_H

// --> 1 - You first must set the required actionTaking function
    /*This Func is called after each successful data & addrerss detection*/
void NECIRR_voidSetActionFunc (void (*Local_fnPtr)(u8 Local_u8Address , u8 Local_u8Data));
/*----------------------------------------------------------------------------*/
// --> 2 - THIS FUNC MUST BE CALLED ON EACH FALLING EDGE INTERRUPT OF INPUT PIN
void NECIRR_voidHandlelFaillingEdge (void);
/*----------------------------------------------------------------------------*/

/******************************************************************************/
/***************************** ERROR definition *******************************/
/******************************************************************************/
#define NECIRR_OK              0
#define NECIRR_ERROR_BAD_TIME  2
#define NECIRR_BAD_DATA_BIT    4
#define NECIRR_BAD_ADDRESS_BIT 8
/******************************************************************************/

#endif  /*NEC_IR_INTERFACE_H*/
