/**
******************************************************************************
* @file    Func.c
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
#include <stdlib.h>
#include "Func.h"
#include "stm8l_define.h"
#include "ram.h"
#include "LCD.h"
#include "gpio.h"
#include "timer_delay.h"

#define SBit(VAR, Place)        ((VAR) |= ((1<< Place))) //Set Bit
#define CBit(VAR, Place)        ((VAR) &=~ ((1<<Place))) //Clear Bit

/*initialize interrupt*/
void init_Interrupt()
{
  SBit(ITC_SPR3,2);             //Vector 9 bit 7 and 6 : 01 level 1   Priority Register  Low Level 
  CBit(ITC_SPR3,3);             //Vector 9 bit 7 and 6 : 01 level 1   Priority Register  Low Level
  
  CBit(EXTI_CR1,2);     
  CBit(EXTI_CR1,3);
  
  /* Config priority interrupt */
  CBit(ITC_SPR7,3);             //Vector 25 bit 2 and 3 : 00 level 2  Priority Register  High Level 
  CBit(ITC_SPR7,2);             //Vector 25 bit 2 and 3 : 00 level 2  Priority Register  High Level
  
  /* Enable interupt  */
  EXTI_CR1 |= 0x08;
}
/*initialize clock*/
void init_Clock()
{
  CLK_DIVR = 0x03;             // Set the frequency to 2 MHz
  CLK_PCKENR1 |= 0x04;        // Enable clock to timer4
}
/*initialize timer*/
void init_Timer()
{
  // config prescaler timer 4
  TIM4_PSCR = 0x03;             // NOTE: prescaler = 2^3
  TIM4_ARR =  250-1;            //Auto reload value            
  
  // Enable interrupt
  TIM4_IER = 0x01;              // set bit 0      
  TIM4_CR1 = 0x01;              // enable counter
}
/*convert int to unsigned char*/
unsigned char chuyen (int a)
{
  unsigned char b;
  switch(a)
  {
  case 0:
    b = 0x30;   //symbol '0'
    break;
  case 1:
    b = 0x31;   //symbol '1'
    break;
  case 2:
    b = 0x32;   //symbol '2'
    break;
  case 3:
    b = 0x33;   //symbol '3'
    break;
  case 4:
    b = 0x34;   //symbol '4'
    break;
  case 5:
    b = 0x35;   //symbol '5'
    break;
  case 6:
    b = 0x36;   //symbol '6'
    break;
  case 7:
    b = 0x37;   //symbol '7'
    break;
  case 8:
    b = 0x38;   //symbol '8'
    break;
  case 9:
    b = 0x39;   //symbol '9'
    break;
  default: b = 0x30; break;
  }
  return b;
}
/*convert int to char*/
unsigned char* chuyenmang (int *clock, unsigned char *a, unsigned char status, int *vt)
{
  *a = status;         // symbol space
  *(a+1) = chuyen(clock[0]);
  *(a+2) = chuyen(clock[1]);
  *(a+3) = 0x3A;       //symbol colon
  *(a+4) = chuyen(clock[2]);
  *(a+5) = chuyen(clock[3]);
  if (*a == 0x53)
  {
    *(a+6) = chuyen(*vt); //location need to set up
  }
  else
  {
    *(a+6) = 0x20;     // symbol space
  }
  
  return a;
}
/*Countdown*/
int* CountDown(int *clock)
{
  if (clock[3] != 0)
  {
    clock[3] -= 1;
  }
  else if(clock[3] == 0)
  {
    if (clock[2] != 0)
    {
      clock[2] -= 1;
    }
    else if (clock[2] == 0)
    {
      if (clock[1] != 0)
      {
        clock[1] -= 1;
      }
      else if (clock[1] == 0)
      {
        if (clock[0] != 0)
        {
          clock[0] -= 1;
        }
        else if (clock[0] == 0)
        {
          return clock;
        }
        clock[1] = 9;         //reset led 2 by 9
      }
      clock[2] = 5;           //reset led 3 by 5
    }
    clock[3] = 9;             //reset led 4 by 9
  }
  return clock;
}
/*show countdow value on LCD*/
void demxuong (int *clock, unsigned char *a, int *SS, unsigned char flag, int *vt)
{
  //while(!((clock[0] == 0) && (clock[1] == 0) && (clock[2] == 0) && (clock[3] == 0)))
  while(((clock[0] != 0) || (clock[1] != 0) || (clock[2] != 0) || (clock[3] != 0)))
  {
    chuyenmang(clock,a, flag, vt);
    LCD_Write_String(a);
    CountDown(clock);
    SBit(PE_ODR,7);            // blinking led green
    DelayMs_t(250);
    CBit(PE_ODR,7);            // blinking led green
    DelayMs_t(250);
    SBit(PE_ODR,7);            // blinking led green
    DelayMs_t(250);
    CBit(PE_ODR,7);            // blinking led green
    DelayMs_t(250);
    if(*SS == 3) {break;}
  }; 
  if (*SS != 3)
  {
    chuyenmang(clock,a, flag, vt);
    LCD_Write_String(a);
    
    while(tt_led)
    {
      onLedBlue();
      offLedBlue();
      tt_led--;
    }
    DelayMs_t(1000);
    free(a);
    free(clock);
    
  }
  
}
/*increase value at vt*/
void tang (int vt, int *b)
{
  // vt: location of number want to set up: 1,2;4
  if (vt == 1 || vt == 2 || vt == 4)    
  {
    if (b[vt-1] < 9)
    {
      b[vt-1]++;
    }
    else
    {
      b[vt-1] = 0;
    }
  }
  else
  {
    if(b[vt-1] < 5)
    {
      b[vt-1]++;
    }
    else
    {
      b[vt-1] = 0;
    }
  }
}
/*shift pointer on LCD*/
void shift (int *vt)
{
  if((*vt) == 4)
  {
    *vt = 1;
  }
  else
  {
    (*vt)++;
  }
}