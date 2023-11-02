/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../tamagochi/tamagochi.h"
#include "../adc/adc.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

volatile int down=0;
const int freqs_sel[3]={1592,1592,1592};
extern int move;
int flag=0;

void RIT_IRQHandler (void)
{		
	static int i=0;
	ADC_start_conversion();
	
	if(flag==1){
		init_timer(3, 0, 0, 3,freqs_sel[i++]);
		if(i>3){
			disable_timer(3);
			reset_timer(3);
			LPC_DAC->DACR =0;
			flag=0;
			i=0;
		}
			
	}
			
		
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0 && (LPC_GPIO1->FIOPIN & (1<<28)) != 0)
		{
			if(flag==0){
				flag=1;
				disable_timer(3);
				reset_timer(3);
				init_timer(3, 0, 0, 3,freqs_sel[i++]);
				enable_timer(3);
			}
			select_left();
		}
	
	
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0 && (LPC_GPIO1->FIOPIN & (1<<27)) != 0)
		{
			if(flag==0){
				flag=1;
				disable_timer(3);
				reset_timer(3);
				init_timer(3, 0, 0, 3,freqs_sel[i++]);
				enable_timer(3);
			}
			select_right();
	}
	

	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0 ){
			if(flag==0){
				flag=1;
				disable_timer(3);
				reset_timer(3);
				init_timer(3, 0, 0, 3,freqs_sel[i++]);
				enable_timer(3);
			}
			move_tama();
	}
		
	reset_RIT();
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
