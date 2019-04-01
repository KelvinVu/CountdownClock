/**
******************************************************************************
* @file    gpio.c
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
#include "stm8l_define.h"
#include "gpio.h"
#include "timer_delay.h"

#define SBit(VAR, Place)        ((VAR) |= ((1<< Place))) //Set Bit
#define CBit(VAR, Place)        ((VAR) &=~ ((1<<Place))) //Clear Bit

// define GPIO---------------------------------------------
/* Set GPIO -------------------------------------------- */
void IntGPIO_PC_PE()
{
  /*set register direction GPIO */
  SBit(PC_DDR, 7);      // set output PC7
  CBit(PC_DDR, 1);      // set input PC1: user button
  
  /*set register control GPIO */
  SBit(PC_CR1, 7);      // set push-pull
  CBit(PC_CR1, 1);      // set floating input.
  
  SBit(PC_CR2, 7);      // set output speed up to 10 MHz
  SBit(PC_CR2, 1);      // set enable external interrupt: user button
  
  SBit(PE_DDR, 7);      // set output PE7
  SBit(PE_CR1, 7);      // set push-pull
  CBit(PE_CR2, 7);      // set output speed up to 2 MHz
  
}
/*get status of button, bit 1*/
unsigned char Reg(uint8_t reg)
{
  return (reg&0x02)>>1;
}
/*turn on blue led*/
void onLedBlue()
{
  SBit(PC_ODR,7);       // blinking led green
  DelayMs(50);
}
/*turn off blue led*/
void offLedBlue()
{
  CBit(PC_ODR,7);       // blinking led green
  DelayMs(50);
}
/*turn on green led*/
void onLedGreen()
{
  SBit(PE_ODR,7);       // blinking led green
  DelayMs(250);
}
/*turn off green led*/
void offLedGreen()
{
  CBit(PE_ODR,7);       // blinking led green
  DelayMs(250);
}
