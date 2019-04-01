/**
******************************************************************************
* @file    gpio.h
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 

#include "stm8l_define.h"

/***********************************************************************************
*   Function name :   onLED
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         turn on led
************************************************************************************/
void onLedBlue();
/***********************************************************************************
*   Function name :   offLED
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         turn off led
************************************************************************************/
void offLedBlue();

/***********************************************************************************
*   Function name :   config port C, D
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         set input, output port C, D
************************************************************************************/
void IntGPIO_PC_PE();
/***********************************************************************************
*   Function name :   Reg
*   Returns :         register of button     
*   Parameters :      register of button    
*   Purpose :         get status of button
************************************************************************************/
unsigned char Reg(uint8_t reg);
/***********************************************************************************
*   Function name :   onLedGreen
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         turn on green led
************************************************************************************/
void onLedGreen();
/***********************************************************************************
*   Function name :   offLedGreen
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         turn off green led
************************************************************************************/
void offLedGreen();