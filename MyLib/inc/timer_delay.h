/**
******************************************************************************
* @file    timer_delay.h
* @author  Group 1
* @date    1/1/2018
* @brief   delay functions header
******************************************************************************
*/
#include "stm8l_define.h"
/***********************************************************************************
*   Function name :   delayMs
*   Returns :         none       
*   Parameters :      ms    
*   Purpose :         not use timer, using an internal 2 MHz clock
************************************************************************************/
void DelayMs(uint32_t ms);
/***********************************************************************************
*   Function name :   delayMs_t
*   Returns :         none       
*   Parameters :      ms   
*   Purpose :         delay using timer interrupt (use timer 4)
************************************************************************************/
void DelayMs_t(uint32_t Ms);