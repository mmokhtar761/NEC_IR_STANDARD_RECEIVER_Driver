/*************************************************************************/
/* Author        : Mohamed Mokhtar Abd-Elaziz                            */
/* File          :                                                       */
/*Description    : An educational driver file for IR receiver based      */
/*                 on NEC standard.                                      */
/* Date          : 22 02 2022                                            */
/* Version       : V02-> A better optimized code                         */
/* GitHub        : https://github.com/mmokhtar761                        */
/*************************************************************************/
#include "STD_TYPES.h"
#include "MANIPULATOR.h"
#include "NEC_IR_interface.h"
#include "NEC_IR_config.h"
#include "NEC_IR_private.h"

#if NEC_IR_MODE == NECIR_RECEIVER
void NECIRR_voidSetActionFunc (void (*Local_fnPtr)(u8 Local_u8Address , u8 Local_u8Data))
{
  ActionfnPtr = Local_fnPtr;
}
/*----------------------------------------------------------------------------*/
void NECIRR_voidHandlelFaillingEdge (void)
{
  static u8 i=0,strtBitFlag  = 0;
  static u8 strtEdgeFlag = 1;
  u32 u32TmeHlder=0,data=0, address=0;
  if (strtEdgeFlag)
  {
    /*Announcing the starting edge has come*/
    strtEdgeFlag = 0;
    /*Reinitializing the frame index to 0*/
     i = 0;
     /*Starting the timer to count time*/
    NECIRR_START_TIMER_FNC;
  }
  else
  {
    /*So, This is not the first frame edge */
    /*Stop the timer*/
    NECIRR_STOP_TIMER_FNC;
    /*Read the time elapsed from the last FALLING edge(in MicroSec)*/
    u32TmeHlder = NECIRR_GET_ELAPSED_TIME_FNC;
    /*Polling the value read*/
    if     (u32TmeHlder>NECIRR_MIN_STRT_BIT_TME && u32TmeHlder<NECIRR_MAX_STRT_BIT_TME)
    {
      /*Starting Bit is detected*/
      /*Announcing the starting bit has come*/
      strtBitFlag = 1;
    }
    else if (u32TmeHlder>NECIRR_MIN_HIGH_TME && u32TmeHlder<NECIRR_MAX_HIGH_TME && strtBitFlag)
    {
      /*HIGH logic bit is detected*/
      /*Setting the corresponding bit and incrementing the index*/
      BIT_H(NECIRR_u32Frame,(i++));
    }
    else if (u32TmeHlder>NECIRR_MIN_LOW_TME && u32TmeHlder<NECIRR_MAX_LOW_TME && strtBitFlag)
    {
      /*LOW logic bit is detected*/
      /*Clearing the corresponding bit and incrementing the index*/
      BIT_L(NECIRR_u32Frame,(i++));
    }
    else
    {
      /*Bad time interval is detected*/
      /*Reinitializing the frame index to 0*/
       i = 0;
      /*Setting the strtEdgeFlag to wait for the new one to start handling*/
      strtEdgeFlag  = 1;
      /*Clearing the strtBitFlag to wait for the new one to start handling*/
      strtBitFlag   = 0;
      /*Storing the elapsed time for debugging issues
        NECIRR_u32ArrTME[i] = u32TmeHlder;*/
      //Return here as no need for starting the timer again
      return;
      //return NECIRR_ERROR_BAD_TIME;
    }

    /*Polling i to know the position we are in the frame*/
    if (i == 32)
    {
      /*Setting the strtEdgeFlag to wait for the new one to start handling*/
      strtEdgeFlag  = 1;
      /*Clearing the strtBitFlag to wait for the new one to start handling*/
      strtBitFlag   = 0;
      /*Getting the data byte from the frame*/
      data = GET_BYTE(NECIRR_u32Frame,NECIRR_DATA_START_ARR_POS);
      /*Getting the address byte from the frame*/
      address = GET_BYTE(NECIRR_u32Frame,NECIRR_ADDRESS_START_ARR_POS);
      /*Calling the passed function to take the action */
      ActionfnPtr(data, address);
      /*Return here as no need for starting the timer again*/
      return;
      // return NECIRR_OK;
    }
#ifdef NECIRR_EN_BIT_VERIFY
    else if (i > NECIRR_DATA_END_ARR_POS && i < NECIRR_ADDRESS_START_ARR_POS)
    {
      if (GET_BIT(NECIRR_u32Frame,i) == GET_BIT(NECIRR_u32Frame,(i-NECIRR_DATA_WIDTH)))
      {
        //return NECIRR_BAD_DATA_BIT;
      }
    }
    else if (i > NECIRR_ADDRESS_END_ARR_POS && i < NECIRR_FRAME_WIDTH)
    {
      if (GET_BIT(NECIRR_u32Frame,i) == GET_BIT(NECIRR_u32Frame,(i-NECIRR_ADDRESSE_WIDTH)))
      {
        //return NECIRR_BAD_ADDRESS_BIT;
      }
    }
#endif /*NECIRR_EN_BIT_VERIFY*/
    NECIRR_START_TIMER_FNC;
  }
 // return NECIRR_OK;
}
#elif NEC_IR_MODE == NECIR_TRANSIMETER

 //To be added....

 #endif /*NEC_IR_MODE*/
