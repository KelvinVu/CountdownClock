/**
******************************************************************************
* @file    Interrupt_VectorTable.c
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
#include "ram.h"
#include "stm8l_define.h"
#include "gpio.h"
#include "timer_delay.h"

/* define vector interupt of button */
#pragma vector = 11
__interrupt void ext_interupt2( void )
{
  /*check status of counting*/
  /*SS=1: setup*/
  if (SS==1)
  {
    /*check button's status*/
    if (Reg(PC_IDR) == 0) 
    {
      
      while(Reg(PC_IDR) == 0)
      {
        DEM++;          /*count time of pressing button*/
        DelayMs_t(1);   /*delay using timer 4*/
      }
    }
  }
  /*SS=2 counting down*/
  else if (SS==2)
  {
    SS=3;
  }
  /*SS=3 pause*/
  else if (SS ==3)
  {
    SS=2;
  }
  /*Reset interrupt*/
  EXTI_SR1 |= (0x02); 
  
}
/* define vector interupt of timer 4 */
#pragma vector=27
__interrupt void timer4( void )
{   
  /* TimingDelay is called in DelayMs_t*/
  if (TimingDelay != 0) 
  {
    TimingDelay--;
  }
  /*Reset timer4*/
  TIM4_SR1 = ~0x01; 
}
