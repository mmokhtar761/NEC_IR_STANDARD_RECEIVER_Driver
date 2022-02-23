/*************************************************************************/
/* Author        : Mohamed Mokhtar Abd-Elaziz                            */
/* File          : NEC_IR_PRIVATE_H                                      */
/*Description    : An educational driver file for IR reciever based      */
/*                 on NEC standard.                                      */
/* Date          : 22 02 2022                                            */
/* Version       : V1.0-> Raw code. (Algorithm A)                        */
/* GitHub        : https://github.com/mmokhtar761                        */
/*************************************************************************/
#ifndef NEC_IR_PRIVATE_H
#define NEC_IR_PRIVATE_H
/*
 The sytandard frame is
 [1 StartingBit == 8 AddressBits== 8 !AddressBits == 8 DataBits == 8 !DataBits]
*/
/******************************************************************************/
/***************************** Standard Parameters ****************************/
/******************************************************************************/
#define NECIRR_STARTING_BITS  1
#define NECIRR_DATA_WIDTH     8
#define NECIRR_ADDRESSE_WIDTH 8

#define NECIRR_FRAME_WIDTH    (NECIRR_STARTING_BITS+ 2*(NECIRR_DATA_WIDTH+NECIRR_ADDRESSE_WIDTH))

#define NECIRR_MIN_STRT_BIT_TME 10000 //MicroSec
#define NECIRR_MAX_STRT_BIT_TME 14500 //MicroSec

#define NECIRR_MIN_HIGH_TME     2000  //MicroSec
#define NECIRR_MAX_HIGH_TME     2500  //MicroSec

#define NECIRR_MIN_LOW_TME      1000  //MicroSec
#define NECIRR_MAX_LOW_TME      1400  //MicroSec



#define NECIRR_MAX_FRAME_TME    108000  //MicroSec
/******************************************************************************/

#define NECIRR_DATA_START_ARR_POS    NECIRR_STARTING_BITS //1
#define NECIRR_DATA_END_ARR_POS      NECIRR_DATA_WIDTH    //8

#define NECIRR_ADDRESS_START_ARR_POS (NECIRR_STARTING_BITS + 2*NECIRR_DATA_WIDTH)  //1 + 2*8 =17
#define NECIRR_ADDRESS_END_ARR_POS   (2*NECIRR_DATA_WIDTH + NECIRR_ADDRESSE_WIDTH)//2*8 + 8 =24

u8   NECIRR_u8ArrFrame [NECIRR_FRAME_WIDTH] = {0};
void (*ActionfnPtr)(u8 Local_u8Address , u8 Local_u8Data);
u32  NECIRR_u32ArrToDecimel (u8 Local_u8TargetStrtBit , u8 *Local_u8ArrPtr);

#endif /*NEC_IR_PRIVATE_H*/
