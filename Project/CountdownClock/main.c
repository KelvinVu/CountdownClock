/**
******************************************************************************
* @file    stm8l_definde.h
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
#include <stdlib.h>
#include <gpio.h>
#include "LCD.h"
#include "stm8l_define.h"
#include "timer_delay.h"
#include "ram.h"
#include "Func.h"
#include "FUNCTION_TT_nhannut.h"

#define SBit(VAR, Place)        ((VAR) |= ((1<< Place))) //Set Bit
#define CBit(VAR, Place)        ((VAR) &=~ ((1<<Place))) //Clear Bit

void main(void)
{ 
  init_Clock();
  //start LCD
  LCD_Init();
  LCD_Contrast(5);
  //end LCD 
  
  IntGPIO_PC_PE();              // config I/O port C, D //thay cho doanj duoi
  init_Interrupt();
  init_Timer();
  
  asm("rim\n");
  
  /* define variable------------------------------------------------------ */
  int *N_Count = (int*) malloc (sizeof(int)*4);
  unsigned char *CHAR_N_Count= (unsigned char *) malloc( 7 * sizeof(unsigned char ));
  *N_Count = 0;
  *(N_Count + 1) = 0;
  *(N_Count + 2) = 0;
  *(N_Count + 3) = 0;
  
  unsigned char  FLAG = 0x20;  // status of systerm: Space
  int  VT = 1;                 // location of number is being set up
  
  /*----------------------------------------------------------------------*/
  
  while(1)
  {
    TT_NHAN_NUT(&DEM, &BUT);    // return status prees user button
    
    switch(SS){
    case 1:{
      if (BUT==0)
      {
        chuyenmang (N_Count , CHAR_N_Count, FLAG, &VT);
        LCD_Write_String(CHAR_N_Count);
        onLedGreen();
        offLedGreen();
      }
      else if (BUT==1)
      {
        FLAG = 0x53;      // S: Setup;
        tang (VT, N_Count);
        chuyenmang (N_Count , CHAR_N_Count, FLAG, &VT);
        LCD_Write_String(CHAR_N_Count);
        BUT=4;
      }
      else if(BUT==2)
      {
        FLAG = 0x53;      // S: Setup;
        shift(&VT);
        chuyenmang (N_Count , CHAR_N_Count, FLAG, &VT);
        LCD_Write_String(CHAR_N_Count);
        BUT=4;
      }
      else if (BUT ==3)
      {
        SS=2;
      }
      else if(BUT==4) 
      {
        // chuyenmang (N_Count , CHAR_N_Count, FLAG, &VT);
        // LCD_Write_String(CHAR_N_Count);
      }
      break;
      
    }
    case 2:{
      FLAG = 0x20;      // Space
      demxuong (N_Count,CHAR_N_Count,&SS, FLAG, &VT);
      break;
    }
    case 3:{
      FLAG = 0x50; // P: pause
      chuyenmang (N_Count , CHAR_N_Count, FLAG, &VT);
      LCD_Write_String(CHAR_N_Count);
      DelayMs(10);
      break;
    }
    default:{
      
      break;
    }
    
    }
  }
}

