/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  20184-12-30
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "adc.h"
#include "../led/led.h"
#include "../timer/timer.h"
#include "../led/led.h"
#include "../tamagochi/tamagochi.h"

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/
extern int move;
unsigned short AD_current;   
unsigned short AD_last = 0xFF;     /* Last converted value               */

/* k=1/f'*f/n  k=f/(f'*n) k=25MHz/(f'*45) */

//const int freqs[8]={4240,3779,3367,3175,2834,2525,2249,2120};
/* 
131Hz		k=4240 C3	
147Hz		k=3779
165Hz		k=3367
175Hz		k=3175
196Hz		k=2834		
220Hz		k=2525
247Hz		k=2249
262Hz		k=2120 C4
*/
//D5 E5 F5 F5 A5 G5 F5
const int freqs[8]={2120,1890,1684,1592,1417,1263,1125,1062};
const int freqs_death[42]={1890,1890,1890,1980,1684,1684,1684,1684,1592,1592,1592,1592,0,
													 1592,1592,1592,1592,1263,1263,1263,1263,1417,1417,1417,1417,1417,1417,1417,1417,1417,0,
													 1592,1592,1592,1592,1592,1592,1592,1592,1592,1592,0};
const int freqs_eat[6]={4540,4540,0,4125,4125,0};


/*
262Hz	k=2120		c4		DO
294Hz	k=1890					RE
330Hz	k=1684					MI
349Hz	k=1592					FA
392Hz	k=1417					SOL
440Hz	k=1263					LA	
494Hz	k=1125					SI
523Hz	k=1062		c5

587Hz k=946
*/
int volume=0;
extern int move;
extern int flag;
void ADC_IRQHandler(void) {
  	
	static int i=0;
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);/* Read Conversion Result             */

			if(get_cuddle()!=0){
			disable_timer(3);
			reset_timer(3);
			init_timer(3, 0, 0, 3,freqs[i++]);
			enable_timer(3);
			if(i>8)
				i=0;
		}

		if(get_life()==0){
				if(i<42){
					if(freqs_death[i++]!=0){
				disable_timer(3);
				reset_timer(3);
				init_timer(3, 0, 0, 3,freqs_death[i]);
				enable_timer(3);
					}
					else 
			{
				disable_timer(3);
				LPC_DAC->DACR =0;
			}
				}
				else{
					disable_timer(3);
					LPC_DAC->DACR =0;
				}

		}
		if(move==1){
			 if(freqs_eat[i++]!=0){
			disable_timer(3);
			reset_timer(3);
			init_timer(3, 0, 0, 3,freqs_eat[i]);
			enable_timer(3);
			 }
			else 
			{
				disable_timer(3);
				LPC_DAC->DACR =0;
			}
		if(i>6)
				i=0;
		}

			
		
		if(get_life()==1 && get_cuddle()==0 && move==0 && flag==0){
			disable_timer(3);
			i=0;
			LPC_DAC->DACR =0;
		}
		if(AD_current!=AD_last){
		volume=(AD_current*4)/4096;
		set_volume(volume);
		}

  
	
}
