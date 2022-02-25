/*************************************************************************/
/* Author        : Mohamed Mokhtar Abd-Elaziz                            */
/* File          : NEC_IR_CONFIG_H                                       */
/*Description    : An educational driver file for IR receiver based      */
/*                 on NEC standard.                                      */
/* Date          : 22 02 2022                                            */
/* Version       : V03-> Repeat handling  &  data verification edited    */
/* GitHub        : https://github.com/mmokhtar761                        */
/*************************************************************************/
#ifndef NEC_IR_CONFIG_H
#define NEC_IR_CONFIG_H

/*
Options:
   NECIR_RECEIVER
   NECIR_TRANSIMETER //Tobe added....
*/
#define NEC_IR_MODE  NECIR_RECEIVER

/*Include timer prototypes here*/
#include "STK_interface.h"

/*You have to initialize a timer and define the following functions to use it in the driver*/
#define NECIRR_START_TIMER_FNC       STK_voidSetSingleShotTimerIR(NECIRR_MAX_FRAME_TME)
#define NECIRR_RESUME_TIMER_FNC      STK_voidResumeSysTick()

#define NECIRR_STOP_TIMER_FNC       STK_voidStopSysTick()
/*Must returns MicroSec. Atleast can count tome upto 108000Micro*/
#define NECIRR_GET_ELAPSED_TIME_FNC STK_u32GetElapsedTicks()

//If u want to verify each bit of the frame define this as 0
//NOTE: This will make more load on interrupt handlers
#define NECIRR_EN_BIT_VERIFY 0

#endif  /*NEC_IR_CONFIG_H*/
