/*************************************************************************/
/* Author        : Mohamed Mokhtar Abd-Elaziz                            */
/* File          :                                                       */
/*Description    : An educational driver file for IR reciever based      */
/*                 on NEC standard.                                      */
/* Date          : 22 02 2022                                            */
/* Version       : V1.0-> Raw code. (Algorithm A)                        */
/* GitHub        : https://github.com/mmokhtar761                        */
/*************************************************************************/
#include "STD_TYPES.h"
#include "MANIPULATOR.h"
#include "NEC_IR_interface.h"
#include "NEC_IR_config.h"
#include "NEC_IR_private.h"

u32  NECIRR_u32ArrToDecimel (u8 Local_u8TargetStrtBit , u8 *Local_u8ArrPtr)
{
  u8 i =0;
  u32 decVal=0;
  if (Local_u8TargetStrtBit == NECIRR_DATA_START_ARR_POS)
  {
    for (i= 0;i<8;i++)
    {
      MAN_BIT(decVal,i,Local_u8ArrPtr[i+NECIRR_DATA_START_ARR_POS]);
    }
  }
  else
  {
    for (i= 0;i<8;i++)
    {
      MAN_BIT(decVal,i,Local_u8ArrPtr[i+NECIRR_ADDRESS_START_ARR_POS]);
    }
  }
}

void NECIRR_voidSetActionFunc (void (*Local_fnPtr)(u8 Local_u8Address , u8 Local_u8Data))
{
  ActionfnPtr = Local_fnPtr;
}
u8   NECIRR_u8HandlelFaillingEdge (void)
{
  static u8 i = 0;
  static u8 strtEdgeFlag = 1;
  u32 u32TmeHlder,data, address = 0;
  if (strtEdgeFlag)
  {
    strtEdgeFlag = 0;
    i =0;
    NECIRR_START_TIMER_FNC;
  }
  else
  {
    /*So, This is not the first frame edge */
    /*Stop the timer*/
    NECIRR_STOP_TIMER_FNC;
    /*Read the time elapsed from the last FALLING edge*/
    u32TmeHlder = NECIRR_GET_ELAPSED_TIME_FNC;

    /*Polling the value read*/
    if     (u32TmeHlder>NECIRR_MIN_STRT_BIT_TME && u32TmeHlder>NECIRR_MAX_STRT_BIT_TME)
    {
      /*StartingBit is detected*/
      i = 0;
    }
    else if (u32TmeHlder>NECIRR_MIN_HIGH_TME && u32TmeHlder>NECIRR_MAX_HIGH_TME)
    {
      /*HIGH logic bit is detected*/
      NECIRR_u8ArrFrame[++i] = HIGH;
    }
    else if (u32TmeHlder>NECIRR_MIN_LOW_TME && u32TmeHlder>NECIRR_MAX_LOW_TME)
    {
      /*LOW logic bit is detected*/
      NECIRR_u8ArrFrame[++i] = LOW;
    }
    else
    {
      strtEdgeFlag = 1;
      return NECIRR_ERROR_BAD_TIME
    }

    /*Polling i to know the position we are in the frame*/
    if (i == 32)
    {
      strtEdgeFlag  = 1;
      data = NECIRR_u32ArrToDecimel (NECIRR_DATA_START_ARR_POS , NECIRR_u8ArrFrame);
      address = NECIRR_u32ArrToDecimel (NECIRR_ADDRESS_START_ARR_POS , NECIRR_u8ArrFrame);
      ActionfnPtr(data, address);
    }
#ifdef NECIRR_EN_BIT_VERIFY
    else if (i > NECIRR_DATA_END_ARR_POS && i < NECIRR_ADDRESS_START_ARR_POS)
    {
      if (NECIRR_u8ArrFrame[i] == NECIRR_u8ArrFrame[i-NECIRR_DATA_WIDTH])
      {
        return NECIRR_BAD_DATA_BIT;
      }
    }
    else if (i > NECIRR_ADDRESS_END_ARR_POS && i < NECIRR_FRAME_WIDTH)
    {
      if (NECIRR_u8ArrFrame[i] == NECIRR_u8ArrFrame[i-NECIRR_ADDRESSE_WIDTH])
      {
        return NECIRR_BAD_ADDRESS_BIT;
      }
    }
#endif /*NECIRR_EN_BIT_VERIFY*/
    NECIRR_START_TIMER_FNC;
  }
  return NECIRR_OK;
}
