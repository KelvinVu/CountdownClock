/**
******************************************************************************
* @file    FUNCTION_TT_nhannut.c
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
#include "FUNCTION_TT_nhannut.h"

/*status of button*/
void TT_NHAN_NUT(int* DEM, int *TT_nut)
{
  if(*DEM > 2500)
  {
    *TT_nut =3;
    *DEM =0;
    //Printf_LCD(TT_nut);
  }
  if ((1000 < *DEM)&&(*DEM <= 2500))
  {
    *TT_nut =2;
    *DEM =0;
    //Printf_LCD(TT_nut);
  }
  if ((1000>=*DEM) && (*DEM>0))
  {
    *TT_nut =1;
    *DEM =0;
    //Printf_LCD(TT_nut);
  }
}
