/**
******************************************************************************
* @file    timer_delay.c
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
#include "timer_delay.h"
#include "ram.h"
#include "stm8l_define.h"

/* define delay use clock interal */
void DelayMs(uint32_t ms)
{
  ms = ms*50;
  while (ms != 0)
  {
    ms--;
  }
}
/* define delay use interrupt timer 4 */
void DelayMs_t(uint32_t Ms)
{
  //call in timer 4 interrupt
  TimingDelay = Ms;
  while (TimingDelay != 0);
}