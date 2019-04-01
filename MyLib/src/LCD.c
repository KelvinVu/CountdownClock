/**
******************************************************************************
* @file    LCD.c
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 

#include "LCD.h"
#include "iostm8l152c6.h"



//*******************************************************************************************************************
//alphanumeric array
const unsigned int number_mask[] = 
{
  //0
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //1
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //2
  (1<<A_)|(1<<B_)|(0<<C_)|(1<<D_)|(1<<E_)|(0<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),  
  //3
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(0<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //4
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //5
  (1<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //6
  (1<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //7
  (1<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //8
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //9
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL)
};

//array of characters in the Latin alphabet
const unsigned int char_mask[] = 
{
  //A
  (1<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //B
  (1<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //C
  (1<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),  
  //D
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //E
  (1<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //F
  (1<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //G
  (1<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //H
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //I
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //J
  (0<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //K
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //L
  (0<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //M
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //N
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),  
  //O
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //P
  (1<<A_)|(1<<B_)|(0<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Q
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //R
  (1<<A_)|(1<<B_)|(0<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //S
  (1<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //T
  (1<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //U
  (0<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),   
  //V
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //W
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //X
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //Y
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Z  
  (1<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL)
};

//Cyrillic character array
const unsigned int rus_char_mask[] = 
{
  //A
  (1<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Б
  (1<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //В
  (1<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),  
  //Г
  (1<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Д
  (0<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //Е
  (1<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Ж
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //З
  (1<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(0<<E_)|(0<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //И
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //Й
  (1<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //К
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Л
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //М
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Н
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),  
  //О
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //П
  (1<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Р
  (1<<A_)|(1<<B_)|(0<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //С
  (1<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Т
  (1<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //У
  (0<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Ф
  (1<<A_)|(1<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),   
  //Х
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //Ц
  (0<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Ч
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Ш
  (0<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Щ
  (0<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(1<<E_)|(1<<F_)|(0<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //Ъ
  (0<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(1<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //Ы
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(1<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //Ь
  (0<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL), 
  //Э
  (1<<A_)|(1<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL), 
  //Ю  
  (0<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //Я
  (1<<A_)|(1<<B_)|(1<<C_)|(0<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL)
};
//specifying special characters
const unsigned int spec_char_mask[] =
{
  //$
  (1<<A_)|(0<<B_)|(1<<C_)|(1<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //(
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //)
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(0<<G_)|(1<<H_)|(0<<J_)|(0<<K_)|(0<<M_)|(0<<N_)|(0<<P_)|(1<<Q_)|(0<<DP)|(0<<COL),
  //*
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(1<<G_)|(1<<H_)|(1<<J_)|(1<<K_)|(1<<M_)|(1<<N_)|(1<<P_)|(1<<Q_)|(0<<DP)|(0<<COL),
  //+
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(1<<G_)|(0<<H_)|(1<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //-
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(0<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //=
  (0<<A_)|(0<<B_)|(0<<C_)|(1<<D_)|(0<<E_)|(0<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //m
  (0<<A_)|(0<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(0<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(1<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //u
  (0<<A_)|(0<<B_)|(0<<C_)|(0<<D_)|(0<<E_)|(1<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(1<<K_)|(0<<M_)|(1<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL),
  //n
  (0<<A_)|(0<<B_)|(1<<C_)|(0<<D_)|(1<<E_)|(0<<F_)|(1<<G_)|(0<<H_)|(0<<J_)|(0<<K_)|(1<<M_)|(0<<N_)|(0<<P_)|(0<<Q_)|(0<<DP)|(0<<COL)
};

//*******************************************************************************************************************;
void LCD_Init(void)
{
  //Apply clock to LCD, RTC:
  CLK_PCKENR2 |= (1<<3)|(1<<2);
  //Select an external quartz (LSE) for RTC:
  CLK_CRTCR_bit.RTCSEL3 = 1;
  //CLK_CRTCR_bit.RTCSEL2 = 0;
  //CLK_CRTCR_bit.RTCSEL1 = 0;
  //CLK_CRTCR_bit.RTCSEL0 = 0;
  //Waiting for stabilization of external quartz:
  while(CLK_ECKR_bit.LSERDY==0);
  
  /*.............Customize LCD.............*/
  //set the duty ratio:
  LCD_CR1_bit.DUTY1 = 1;/****actually ****/
  LCD_CR1_bit.DUTY0 = 1;/*number of COMs*/
  
  LCD_CR2_bit.PON0 = 1;
  LCD_CR2_bit.PON1 = 1;
  LCD_CR2_bit.PON2 = 1;
  
  //prescaler n = 2 (the fission coefficient will be 2^n, F=(F_RTC/2)/2^n)
  //LCD_FRQ_bit.PS3 = 0;/****After the prescaler (32768/2)/4=4096****/
  //LCD_FRQ_bit.PS2 = 0;/**and then passes through the divisor to 16**/
  LCD_FRQ_bit.PS1 = 1;/******which will result in 256 Hz******/
  //LCD_FRQ_bit.PS0 = 0;/******the frame frequency is equal to 256/4 Hz*****/
  //turn on the LCD:
  LCD_CR3_bit.LCDEN=1;
  
  //turn on 24 legs to control the segments (SEG00 -- SEG23):
  LCD_PM0 = (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
  LCD_PM1 = (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
  LCD_PM2 = (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
}
//*******************************************************************************************************************

void LCD_Contrast(unsigned char cntr)
{
  //contrast setting:
  LCD_CR2 |= ((cntr&0x07)<<1);
}
//*******************************************************************************************************************

static unsigned int LCD_Char_Find(unsigned char* symb)
{
  unsigned int cur_char;
  //if the figure:
  if ( (*symb <= 0x39) && (*symb >= 0x30) )
  {
    cur_char = number_mask[*symb-'0'];
  }
  //if the letter is in the Latin alphabet:
  /* If the character is in uppercase*/
  else{if ((*symb <= 0x5A) && (*symb >= 0x41))
  {
    cur_char = char_mask[*symb-'A'];
  }
  /* If the character is in lowercase*/
  else{if ((*symb <= 0x7A) && ( *symb >= 0x61))    
  {
    cur_char = char_mask[*symb-'a'];
  }
  //if the letter is Cyrillic:
  /* If the character is in uppercase*/
  else{if ((*symb <= 0xDF) && ( *symb >= 0xC0))
  {
    cur_char = rus_char_mask[*symb-'А'];
  }
  /* If the character is in lowercase*/
  else{if (*symb >= 0xE0)
  {
    cur_char = rus_char_mask[*symb-'а'];
  }
  else
  {
    switch (*symb)
    {
      //if the special character:            
    case '$':
      cur_char = spec_char_mask[0];
      break;
      
    case '(':
      cur_char = spec_char_mask[1];
      break;
      
    case ')':
      cur_char = spec_char_mask[2];
      break;
      
    case '*':
      cur_char = spec_char_mask[3];
      break;
      
    case '+':
      cur_char = spec_char_mask[4];
      break;
      
    case '-':
      cur_char = spec_char_mask[5];
      break;
      
    case '=':
      cur_char = spec_char_mask[6];
      break;
      
    default:
      cur_char = 0x00;
      break;
    };
  };
  };
  };
  };
  };
  
  if(*symb=='m') {cur_char = spec_char_mask[7];}
  if(*symb=='u') {cur_char = spec_char_mask[8];}
  if(*symb=='n') {cur_char = spec_char_mask[9];}
  
  return(cur_char);
}
//*******************************************************************************************************************

void LCD_Write_Char(unsigned char* ch, bool point, bool column, unsigned char position)
{
  unsigned int cur_char; /*container for storing the symbol mask*/
  unsigned char temp[2];
  
  /* The definition of the corresponding constant character*/
  cur_char = LCD_Char_Find(ch);
  if(position<5)/* In the fifth, sixth acquaintance of BAR */
  {
    /* Set the state of the decimal point */
    if(point){cur_char |= (1<<DP);};
    /* Setting the Colon State */
    if(column){cur_char |= (1<<COL);};
  };
  
  temp[0]=(unsigned char)cur_char;
  temp[1]=(unsigned char)(cur_char>>8);
  
  /*Record the symbol mask in the LCD_RAM bits corresponding to the current position*/
  switch (position)
  {
    /* Position 1 */
  case 1:
    /*Cleaning 1M, 1E*/            /*Write a new value 1M, 1E*/
    LCD_RAM0 &= ~((1<<1)|(1<<0)); LCD_RAM0 |= temp[0] & ((1<<1)|(1<<0));
    /*Cleaning 1G, 1B*/            /*Write a new value 1G, 1B*/
    LCD_RAM2 &= ~((1<<7)|(1<<6)); LCD_RAM2 |= (temp[0]<<4) & ((1<<7)|(1<<6));
    /*Cleaning 1C, 1D*/            /*Write a new value 1C, 1D*/
    LCD_RAM3 &= ~((1<<5)|(1<<4)); LCD_RAM3 |= temp[0] & ((1<<5)|(1<<4));
    /*Cleaning 1F, 1A*/            /*Write a new value 1F, 1A*/
    LCD_RAM6 &= ~((1<<3)|(1<<2)); LCD_RAM6 |= (temp[0]>>4) & ((1<<3)|(1<<2));
    /*Cleaning 1COL, 1P*/          /*Write a new value 1COL, 1P*/
    LCD_RAM7 &= ~((1<<1)|(1<<0)); LCD_RAM7 |= temp[1] & ((1<<1)|(1<<0));
    /*Cleaning 1Q, 1K*/            /*Write a new value 1Q, 1K*/
    LCD_RAM9 &= ~((1<<7)|(1<<6)); LCD_RAM9 |= (temp[1]<<4) & ((1<<7)|(1<<6));
    /*Cleaning 1DP, 1N*/           /*Write a new value 1DP, 1N*/
    LCD_RAM10 &= ~((1<<5)|(1<<4)); LCD_RAM10 |= temp[1] & ((1<<5)|(1<<4));
    /*Cleaning 1H, 1J*/            /*Write a new value 1H, 1J*/
    LCD_RAM13 &= ~((1<<3)|(1<<2)); LCD_RAM13 |= (temp[1]>>4) & ((1<<3)|(1<<2));
    break;
    
    /* Position 2 */
  case 2:
    /*Cleaning 2M, 2E*/            /*Write a new value 2M, 2E*/
    LCD_RAM0 &= ~((1<<3)|(1<<2)); LCD_RAM0 |= (temp[0]<<2) & ((1<<3)|(1<<2));
    /*Cleaning 2G, 2B*/            /*Write a new value 2G, 2B*/
    LCD_RAM2 &= ~((1<<5)|(1<<4)); LCD_RAM2 |= (temp[0]<<2) & ((1<<5)|(1<<4));
    /*Cleaning 2C, 2D*/            /*Write a new value 2C, 2D*/
    LCD_RAM3 &= ~((1<<7)|(1<<6)); LCD_RAM3 |= (temp[0]<<2) & ((1<<7)|(1<<6));
    /*Cleaning 2F, 2A*/            /*Write a new value 2F, 2A*/
    LCD_RAM6 &= ~((1<<1)|(1<<0)); LCD_RAM6 |= (temp[0]>>6) & ((1<<1)|(1<<0));
    /*Cleaning 2COL, 2P*/          /*Write a new value 2COL, 2P*/
    LCD_RAM7 &= ~((1<<3)|(1<<2)); LCD_RAM7 |= (temp[1]<<2) & ((1<<3)|(1<<2));
    /*Cleaning 2Q, 2K*/            /*Write a new value 2Q, 2K*/
    LCD_RAM9 &= ~((1<<5)|(1<<4)); LCD_RAM9 |= (temp[1]<<2) & ((1<<5)|(1<<4));
    /*Cleaning 2DP, 2N*/           /*Write a new value 2DP, 2N*/
    LCD_RAM10 &= ~((1<<7)|(1<<6)); LCD_RAM10 |= (temp[1]<<2) & ((1<<7)|(1<<6));
    /*Cleaning 2H, 2J*/            /*Write a new value 2H, 2J*/
    LCD_RAM13 &= ~((1<<1)|(1<<0)); LCD_RAM13 |= (temp[1]>>6) & ((1<<1)|(1<<0));
    break;
    
    /* Position 3 */
  case 3:
    /*Cleaning 3M, 3E*/            /*Write a new value 3M, 3E*/
    LCD_RAM0 &= ~((1<<5)|(1<<4)); LCD_RAM0 |= (temp[0]<<4) & ((1<<5)|(1<<4));
    /*Cleaning 3G, 3B*/            /*Write a new value 3G, 3B*/
    LCD_RAM2 &= ~((1<<3)|(1<<2)); LCD_RAM2 |= temp[0] & ((1<<3)|(1<<2));
    /*Cleaning 3C, 3D*/            /*Write a new value 3C, 3D*/
    LCD_RAM4 &= ~((1<<1)|(1<<0)); LCD_RAM4 |= (temp[0]>>4) & ((1<<1)|(1<<0));
    /*Cleaning 3F, 3A*/            /*Write a new value 3F, 3A*/
    LCD_RAM5 &= ~((1<<7)|(1<<6)); LCD_RAM5 |= temp[0] & ((1<<7)|(1<<6));
    /*Cleaning 3COL, 3P*/          /*Write a new value 3COL, 3P*/
    LCD_RAM7 &= ~((1<<5)|(1<<4)); LCD_RAM7 |= (temp[1]<<4) & ((1<<5)|(1<<4));
    /*Cleaning 3Q, 3K*/            /*Write a new value 3Q, 3K*/
    LCD_RAM9 &= ~((1<<3)|(1<<2)); LCD_RAM9 |= temp[1] & ((1<<3)|(1<<2));
    /*Cleaning 3DP, 3N*/           /*Write a new value 3DP, 3N*/
    LCD_RAM11 &= ~((1<<1)|(1<<0)); LCD_RAM11 |= (temp[1]>>4) & ((1<<1)|(1<<0));
    /*Cleaning 3H, 3J*/            /*Write a new value 3H, 3J*/
    LCD_RAM12 &= ~((1<<7)|(1<<6)); LCD_RAM12 |= temp[1] & ((1<<7)|(1<<6));
    break;
    
    /* Позиция 4 */
  case 4:
    /*Cleaning 4M, 4E*/            /*Write a new value 4M, 4E*/
    LCD_RAM0 &= ~((1<<7)|(1<<6)); LCD_RAM0 |= (temp[0]<<6) & ((1<<7)|(1<<6));
    /*Cleaning 4G, 4B*/            /*Write a new value 4G, 4B*/
    LCD_RAM2 &= ~((1<<1)|(1<<0)); LCD_RAM2 |= (temp[0]>>2) & ((1<<1)|(1<<0));
    /*Cleaning 4C, 4D*/            /*Write a new value 4C, 4D*/
    LCD_RAM4 &= ~((1<<3)|(1<<2)); LCD_RAM4 |= (temp[0]>>2) & ((1<<3)|(1<<2));
    /*Cleaning 4F, 4A*/            /*Write a new value 4F, 4A*/
    LCD_RAM5 &= ~((1<<5)|(1<<4)); LCD_RAM5 |= (temp[0]>>2) & ((1<<5)|(1<<4));
    /*Cleaning 4COL, 4P*/          /*Write a new value 4COL, 4P*/
    LCD_RAM7 &= ~((1<<7)|(1<<6)); LCD_RAM7 |= (temp[1]<<6) & ((1<<7)|(1<<6));
    /*Cleaning 4Q, 4K*/            /*Write a new value 4Q, 4K*/
    LCD_RAM9 &= ~((1<<1)|(1<<0)); LCD_RAM9 |= (temp[1]>>2) & ((1<<1)|(1<<0));
    /*Cleaning 4DP, 4N*/           /*Write a new value 4DP, 4N*/
    LCD_RAM11 &= ~((1<<3)|(1<<2)); LCD_RAM11 |= (temp[1]>>2) & ((1<<3)|(1<<2));
    /*Cleaning 4H, 4J*/            /*Write a new value 4H, 4J*/
    LCD_RAM12 &= ~((1<<5)|(1<<4)); LCD_RAM12 |= (temp[1]>>2) & ((1<<5)|(1<<4));
    break;
    
    /* позиция 5 */
  case 5:
    /*Cleaning 5M, 5E*/            /*Write a new value 5M, 5E*/
    LCD_RAM1 &= ~((1<<1)|(1<<0)); LCD_RAM1 |= temp[0] & ((1<<1)|(1<<0));
    /*Cleaning 5G, 5B*/            /*Write a new value 5G, 5B*/
    LCD_RAM1 &= ~((1<<7)|(1<<6)); LCD_RAM1 |= (temp[0]<<4) & ((1<<7)|(1<<6));
    /*Cleaning 5C, 5D*/            /*Write a new value 5C, 5D*/
    LCD_RAM4 &= ~((1<<5)|(1<<4)); LCD_RAM4 |= temp[0] & ((1<<5)|(1<<4));
    /*Cleaning 5F, 5A*/            /*Write a new value 5F, 5A*/
    LCD_RAM5 &= ~((1<<3)|(1<<2)); LCD_RAM5 |= (temp[0]>>4) & ((1<<3)|(1<<2));
    /*Cleaning 5COL, 5P*/          /*Write a new value 5COL, 5P*/
    LCD_RAM8 &= ~((1<<1)|(1<<0)); LCD_RAM8 |= temp[1] & ((1<<1)|(1<<0));
    /*Cleaning 5Q, 5K*/            /*Write a new value 5Q, 5K*/
    LCD_RAM8 &= ~((1<<7)|(1<<6)); LCD_RAM8 |= (temp[1]<<4) & ((1<<7)|(1<<6));
    /*Cleaning 5DP, 5N*/           /*Write a new value 5DP, 5N*/
    LCD_RAM11 &= ~((1<<5)|(1<<4)); LCD_RAM11 |= temp[1] & ((1<<5)|(1<<4));
    /*Cleaning 5H, 5J*/            /*Write a new value 5H, 5J*/
    LCD_RAM12 &= ~((1<<3)|(1<<2)); LCD_RAM12 |= (temp[1]>>4) & ((1<<3)|(1<<2));
    break;
    
    /* Позиция 6 */
  case 6:
    /*Cleaning 6M, 6E*/            /*Write a new value 6M, 6E*/
    LCD_RAM1 &= ~((1<<3)|(1<<2)); LCD_RAM1 |= (temp[0]<<2) & ((1<<3)|(1<<2));
    /*Cleaning 6G, 6B*/            /*Write a new value 6G, 6B*/
    LCD_RAM1 &= ~((1<<5)|(1<<4)); LCD_RAM1 |= (temp[0]<<2) & ((1<<5)|(1<<4));
    /*Cleaning 6C, 6D*/            /*Write a new value 6C, 6D*/
    LCD_RAM4 &= ~((1<<7)|(1<<6)); LCD_RAM4 |= (temp[0]<<2) & ((1<<7)|(1<<6));
    /*Cleaning 6F, 6A*/            /*Write a new value 6F, 6A*/
    LCD_RAM5 &= ~((1<<1)|(1<<0)); LCD_RAM5 |= (temp[0]>>6) & ((1<<1)|(1<<0));
    /*Cleaning 6COL, 6P*/          /*Write a new value 6COL, 6P*/
    LCD_RAM8 &= ~((1<<3)|(1<<2)); LCD_RAM8 |= (temp[1]<<2) & ((1<<3)|(1<<2));
    /*Cleaning 6Q, 6K*/            /*Write a new value 6Q, 6K*/
    LCD_RAM8 &= ~((1<<5)|(1<<4)); LCD_RAM8 |= (temp[1]<<2) & ((1<<5)|(1<<4));
    /*Cleaning 6DP, 6N*/           /*Write a new value 6DP, 6N*/
    LCD_RAM11 &= ~((1<<7)|(1<<6)); LCD_RAM11 |= (temp[1]<<2) & ((1<<7)|(1<<6));
    /*Cleaning 6H, 6J*/            /*Write a new value 6H, 6J*/
    LCD_RAM12 &= ~((1<<1)|(1<<0)); LCD_RAM12 |= (temp[1]>>6) & ((1<<1)|(1<<0));
    break;
    /* we leave in all other cases (incorrect position number)*/
  default:
    break;
  }
}
//*******************************************************************************************************************

void LCD_Write_String(unsigned char* str)
{
  unsigned char i = 1;
  
  /* Until we reached the end of the line
  or did not print 6 characters*/
  while ((*str != 0) && (i < 7))
  {
    /* Display the character in the current familiarity */
    LCD_Write_Char(str, 0, 0, i);
    
    if(*str == '.')
    {
      i--;
      LCD_Write_Char(str-1, 1, 0, i);
    };
    if(*str == ':')
    {
      i--;
      LCD_Write_Char(str-1, 0, 1, i);
    };
    
    /* translation of the pointer to the next. symbol */
    str++;
    
    /* Increment of the familiarity number */
    i++;
  };
}
void LCD_GLASS_Clear()
{
  LCD_Write_String("      ");
}
