/*************************************************************************/
/* Author        : Mohamed Mokhtar Abd-Elaziz                            */
/* File          : NEC_IR_INTERFACE_H                                    */
/*Description    : An educational driver file for IR reciever based      */
/*                 on NEC standard.                                      */
/* Date          : 22 02 2022                                            */
/* Version       : V1.0-> Raw code. (Algorithm A)                        */
/* GitHub        : https://github.com/mmokhtar761                        */
/*************************************************************************/
#ifndef NEC_IR_INTERFACE_H
#define NEC_IR_INTERFACE_H

// --> 1 - You first must set the required actionTaking function
void NECIRR_voidSetActionFunc (void (*Local_fnPtr)(u8 Local_u8Address , u8 Local_u8Data));
/*----------------------------------------------------------------------------*/
// --> 2 - THIS FUNC MUST BE CALLED ON EACH FALLING EDGE INTERRUPT OF INPUT PIN
u8   NECIRR_u8HandlelFaillingEdge (void);
/*----------------------------------------------------------------------------*/


#endif  /*NEC_IR_INTERFACE_H*/
