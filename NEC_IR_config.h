/*************************************************************************/
/* Author        : Mohamed Mokhtar Abd-Elaziz                            */
/* File          : NEC_IR_CONFIG_H                                       */
/*Description    : An educational driver file for IR reciever based      */
/*                 on NEC standard.                                      */
/* Date          : 22 02 2022                                            */
/* Version       : V1.1-> Raw code. (Algorithm A) Essential tests        */
/* GitHub        : https://github.com/mmokhtar761                        */
/*************************************************************************/
#ifndef NEC_IR_CONFIG_H
#define NEC_IR_CONFIG_H

/*Include timer prototypes here*/
#include "STK_interface.h"

//You have to initialize a timer and define the following functions to use it in the driver
#define NECIRR_START_TIMER_FNC      STK_voidSetSingleShotTimerIR(NECIRR_MAX_FRAME_TME)
#define NECIRR_RESUME_TIMER_FNC      STK_voidResumeSysTick()

#define NECIRR_STOP_TIMER_FNC       STK_voidStopSysTick()
/*Must return atleast unsigned 32 bit value*/
#define NECIRR_GET_ELAPSED_TIME_FNC STK_u32GetElapsedTicks()

//If u want to verify each bit of the frame uncomment the following line
//NOTE: This will make more load on interrupt handlers
//#define NECIRR_EN_BIT_VERIFY


#define GET_INPUT_PIN_VAL_FNC




#endif  /*NEC_IR_CONFIG_H*/
