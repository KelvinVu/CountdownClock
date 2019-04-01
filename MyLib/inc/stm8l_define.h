/**
******************************************************************************
* @file    stm8l_definde.h
* @author  Group 1
* @date    1-jan-2018
******************************************************************************
*/ 
#include <stdint.h>

#define PC_ODR          (*(volatile uint8_t *)0x500A)   /* Port C data output latch register 0x00 */
#define PC_IDR          (*(volatile uint8_t *)0x500B)   /* Port C input pin value register */
#define PC_DDR          (*(volatile uint8_t *)0x500C)   /* Port C data direction register 0x00    */
#define PC_CR1          (*(volatile uint8_t *)0x500D)   /* Port C control register 1 0x00         */
#define PC_CR2          (*(volatile uint8_t *)0x500E)   /* Port C control register 2 0x00         */

#define PE_ODR          (*(volatile uint8_t *)0x5014)   /* Port E data output latch register 0x00 */
#define PE_DDR          (*(volatile uint8_t *)0x5016)   /* Port E data direction register 0x00    */
#define PE_CR1          (*(volatile uint8_t *)0x5017)   /* Port E control register 1 0x00         */
#define PE_CR2          (*(volatile uint8_t *)0x5018)   /* Port E control register 2 0x00         */

#define EXTI_SR1        (*(volatile uint8_t *)0x50A3)   /*External interrupt status register 1*/
#define EXTI_CR1        (*(volatile uint8_t *)0x50A0)   /*External interrupt control register 1*/

#define CLK_DIVR        (*(volatile uint8_t *)0x50c0)   /*Clock master divider register*/
#define CLK_PCKENR2     (*(volatile uint8_t *)0x50c4)   /*Peripheral clock gating register 2*/ // set timer 1 : 0x02
#define CLK_PCKENR1     (*(volatile uint8_t *)0x50c3)   /*Peripheral clock gating register 1*/ // set timer 4 : 0x04

#define TIM1_CR1        (*(volatile uint8_t *)0x52b0)   /*TIM1 control register 1*/
#define TIM1_PCNTRH     (*(volatile uint8_t *)0x52bf)   /*TIM1 counter high*/
#define TIM1_PCNTRL     (*(volatile uint8_t *)0x52c0)   /*TIM1 counter low*/
#define TIM1_PSCRH      (*(volatile uint8_t *)0x52c1)   /*TIM1 prescaler register high*/
#define TIM1_PSCRL      (*(volatile uint8_t *)0x52c2)   /*TIM1 prescaler register low*/
#define TIM1_IER        (*(volatile uint8_t *)0x52B5)   /*TIM1 Interrupt enable register*/
#define TIM1_SR1        (*(volatile uint8_t *)0x52B6)   /*TIM1 status register 1*/
#define TIM1_ARRH       (*(volatile uint8_t *)0x52C3)   /*TIM1 Auto-reload register high*/
#define TIM1_ARRL       (*(volatile uint8_t *)0x52C4)   /*TIM1 Auto-reload register low*/

/* Define Timer 4 register ---------------------------------------------------- */
#define TIM4_CR1 	(*(volatile uint8_t*)0x52E0)    /* define CR1 register*/
#define TIM4_IER	(*(volatile uint8_t*)0x52E4)    /* define address IER register of TIM4*/
#define	TIM4_SR1	(*(volatile uint8_t*)0x52E5)    /* define address SR register of timer 4*/
#define TIM4_CNTR	(*(volatile uint8_t*)0x52E7)    /* define address CNTR register of timer 4*/
#define TIM4_PSCR	(*(volatile uint8_t*)0x52E8)    /* define address prescaler register of timer 4*/
#define TIM4_ARR	(*(volatile uint8_t*)0x52E9)    /* define address auto reload register of timer 4*/

#define CPU_CCR         (*(volatile uint8_t *)0x7F0A)   /* define Condition code register*/

#define ITC_SPR1        (*(volatile uint8_t *)0x7F70)   /*Interrupt Software priority register 1*/
#define ITC_SPR2        (*(volatile uint8_t *)0x7F71)   /*Interrupt Software priority register 2*/
#define ITC_SPR3        (*(volatile uint8_t *)0x7F72)   /*Interrupt Software priority register 3*/
#define ITC_SPR4        (*(volatile uint8_t *)0x7F73)   /*Interrupt Software priority register 4*/
#define ITC_SPR5        (*(volatile uint8_t *)0x7F74)   /*Interrupt Software priority register 5*/
#define ITC_SPR6        (*(volatile uint8_t *)0x7F75)   /*Interrupt Software priority register 6*/
#define ITC_SPR7        (*(volatile uint8_t *)0x7F76)   /*Interrupt Software priority register 7*/
#define ITC_SPR8        (*(volatile uint8_t *)0x7F77)   /*Interrupt Software priority register 8*/