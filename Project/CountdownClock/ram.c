/**
******************************************************************************
* @file    ram.c
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
volatile int    SS =1;            // star stop counting
volatile int    BUT = 0;          // status of button, select shift, increasing and start countdown
volatile int    DEM;               // variable to count time press button
volatile int    tt_led=100;        // counting time of blinking blue led
volatile int    TimingDelay = 0;   // sub variable to count time delay