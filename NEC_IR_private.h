/*************************************************************************/
/* Author        : Mohamed Mokhtar Abd-Elaziz                            */
/* File          : NEC_IR_PRIVATE_H                                      */
/*Description    : An educational driver file for IR receiver based      */
/*                 on NEC standard.                                      */
/* Date          : 22 02 2022                                            */
/* Version       : V3.2-> Reduced sysTick time & enabled its interrupt   */
/* GitHub        : https://github.com/mmokhtar761                        */
/*************************************************************************/
#ifndef NEC_IR_PRIVATE_H
#define NEC_IR_PRIVATE_H
/*
<><><><><><>><><><><><>><><><><><>><><><><><>><><><><><>><><><><><>><><><><><><>
 The standard frame is
 [1 StartingBit==> 8 AddressBits==> 8 !AddressBits==> 8 DataBits==> 8 !DataBits]
 <><><><><><>><><><><><>><><><><><>><><><><><>><><><><><>><><><><><>><><><><><><>
*/
#if NEC_IR_MODE == NECIR_RECEIVER
/******************************************************************************/
/***************************** Standard Parameters ****************************/
/******************************************************************************/
#define NECIRR_STARTING_BITS  1
#define NECIRR_ADDRESS_WIDTH 8
#define NECIRR_DATA_WIDTH     8
/*----------------------------------------------------------------------------*/
#define NECIRR_FRAME_WIDTH    (NECIRR_STARTING_BITS+ 2*(NECIRR_DATA_WIDTH+NECIRR_ADDRESS_WIDTH))
/*----------------------------------------------------------------------------*/
#define NECIRR_MIN_STRT_BIT_TME 12500 //MicroSec
#define NECIRR_MAX_STRT_BIT_TME 14000 //MicroSec
/*----------------------------------------------------------------------------*/
#define NECIRR_MIN_HIGH_TME     1900  //MicroSec
#define NECIRR_MAX_HIGH_TME     2700  //MicroSec
/*----------------------------------------------------------------------------*/
#define NECIRR_MIN_LOW_TME      900   //MicroSec
#define NECIRR_MAX_LOW_TME      1500  //MicroSec
/*----------------------------------------------------------------------------*/
#define NECIRR_MSG_2_MSG_TME    41062 //MicroSec
/*----------------------------------------------------------------------------*/
#define NECIRR_REPEAT_MIN_TME   10500 //MicroSec
#define NECIRR_REPEAT_MAX_TME   12000 //MicroSec
/*----------------------------------------------------------------------------*/
#define NECIRR_MAX_FRAME_TME    108000  //MicroSec
/******************************************************************************/
/*Definition of data & address indices in the frame variable (which excludes strtBit)*/
#define NECIRR_ADDRESS_START_ARR_POS    0
#define NECIRR_ADDRESS_END_ARR_POS      (NECIRR_ADDRESS_WIDTH-1)    //7

#define NECIRR_DATA_START_ARR_POS (2*NECIRR_ADDRESS_WIDTH)  //2*8 =16
#define NECIRR_DATA_END_ARR_POS   (NECIRR_DATA_START_ARR_POS + NECIRR_DATA_WIDTH-1)//16+8-1=23
/*----------------------------------------------------------------------------*/
u32  NECIRR_u32Frame = 0;
u32  NECIRR_u32ArrTME[NECIRR_FRAME_WIDTH-NECIRR_STARTING_BITS]  = {0};
/*----------------------------------------------------------------------------*/
void (*ActionfnPtr)(u8 Local_u8Address , u8 Local_u8Data);

#elif NEC_IR_MODE == NECIR_TRANSIMETER

 //Tobe added....

#endif /*NEC_IR_MODE*/
#endif /*NEC_IR_PRIVATE_H*/
