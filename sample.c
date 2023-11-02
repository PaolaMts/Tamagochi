/*----------------------------------------------------------------------------
 * Name:    sample.c
 * Purpose: to control led through debounced buttons and Joystick
 *        	- key1 switches on the led at the left of the current led on, 
 *					- it implements a circular led effect,
 * 					- joystick select function returns to initial configuration (led11 on) .
 * Note(s): this version supports the LANDTIGER Emulator
 * Author: 	Paolo BERNARDI - PoliTO - last modified 15/12/2020
 *----------------------------------------------------------------------------
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2017 Politecnico di Torino. All rights reserved.
 *----------------------------------------------------------------------------*/
                  
#include <stdio.h>
#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "tamagochi/tamagochi.h"
#include "TouchPanel/TouchPanel.h"
#include "adc/adc.h"

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif
/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
    int main (void) {
  	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
  LCD_Initialization();
	TP_Init();
	TouchPanel_Calibrate();
	LCD_Clear(0xFFFF);
	ADC_init();
  background_tama();
	draw_tamagochi();												
	joystick_init();											/* Joystick Initialization            */
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec       	*/
	enable_RIT();													/* RIT enabled												*/
	
	//init_timer(0, 0, 0, 3,0x98968 );			/*25 ms*/
	init_timer(0, 0, 0, 3,0x17D7840 );  /*un secondo*/
	enable_timer(0);
	init_timer(1, 0, 0, 3,0xC8);					//timer per controllo touch
	enable_timer(1);
	LPC_SC->PCONP |=(1<<22);
	LPC_SC->PCONP |=(1<<23);	 
	//init_timer(2, 0, 0, 3,0x4C4B4);				/*12.5 ms*/
	init_timer(2, 0, 0, 3,0xBEBC20);	 	/*mezzo secondo*/
	
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);	

	LPC_PINCON->PINSEL1 |= (1<<21);
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	LPC_GPIO0->FIODIR |= (1<<26);
		
  while (1) {                           /* Loop forever                       */	
		__ASM("wfi");
  }

}
