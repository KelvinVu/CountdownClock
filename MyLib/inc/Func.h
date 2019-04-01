/**
******************************************************************************
* @file    Func.h
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
/***********************************************************************************
*   Function name :   init_Interrupt
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         initialize interrupt
************************************************************************************/
void init_Interrupt();
/***********************************************************************************
*   Function name :   init_Timer
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         initialize timer
************************************************************************************/
void init_Timer();
/***********************************************************************************
*   Function name :   init_Clock
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         initialize clock
************************************************************************************/
void init_Clock();
/***********************************************************************************
*   Function name :   chuyenmang
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         convert int to char
************************************************************************************/
unsigned char* chuyenmang (int *clock, unsigned char *a, unsigned char status, int *vt);
/***********************************************************************************
*   Function name :   chuyen
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         convert int to unsigned char
************************************************************************************/
unsigned char chuyen (int a);
/***********************************************************************************
*   Function name :   demxuong
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         show countdow value on LCD
************************************************************************************/
void demxuong (int *clock, unsigned char *a, int *SS, unsigned char flag, int *vt);
/***********************************************************************************
*   Function name :   CountDown
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         countdowwn
************************************************************************************/
int* CountDown(int *clock);
/***********************************************************************************
*   Function name :   shift
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         shift pointer on LCD
************************************************************************************/
void shift (int *vt);
/***********************************************************************************
*   Function name :   tang
*   Returns :         none       
*   Parameters :      none    
*   Purpose :         increase value
************************************************************************************/
void tang (int vt, int *b);