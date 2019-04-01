/**
******************************************************************************
* @file    LCD.h
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 

#ifndef LCD_H
#define LCD_H

#include "stdbool.h"
//Xac d?nh trinh t? c?a cac bit trong h?ng ky t?
#define A_ 6
#define B_ 2
#define C_ 5
#define D_ 4
#define E_ 0
#define F_ 7
#define G_ 3
#define H_ 15
#define J_ 14
#define K_ 10
#define M_ 1
#define N_ 12
#define P_ 8
#define Q_ 11
#define DP 13
#define COL 9


/***********************************************************************************
*   Function name :   LCD_Init
*   Returns :         khong       
*   Parameters :      khong    
*   Purpose :         kh?i t?o b? di?u khi?n LCD
************************************************************************************/
void LCD_Init(void);
/***********************************************************************************
*   Function name :   LCD_Contrast
*   Returns :         khong       
*   Parameters :      cntr - gia tr? tuong ph?n 0-7   
*   Purpose :         Thi?t l?p tuong ph?n LCD
************************************************************************************/
void LCD_Contrast(unsigned char cntr);

/***********************************************************************************
*   Function name :   LCD_Char_Find
*   Returns :         cur_char - character mask
*   Parameters :      *ñ - ASCII character code, 
*   Purpose :         defines the mask corresponding to the character
***********************************************************************************/
static unsigned int LCD_Char_Find(unsigned char* symb);

/***********************************************************************************
*   Function name :   LCD_Write_Char
*   Returns :         khong       
*   Parameters :      *ch - character code, point - des. dot, column - colon,
position - serial number of familiarity
*   Purpose :         Outputs a symbol to the indicator in the corresponding sign
***********************************************************************************/
void LCD_Write_Char(unsigned char* ch, bool point, bool column, unsigned char position);

/***********************************************************************************
*   Function name :   LCD_Write_String
*   Returns :         khong       
*   Parameters :      * str - pointer to the beginning of the character string
*   Purpose :         Displays a string
***********************************************************************************/
void LCD_Write_String(unsigned char* str);


void LCD_Scroll(unsigned char* str);
void LCD_GLASS_Clear();

#endif //LCD_H