/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h"
#include "../tamagochi/tamagochi.h"
#include "../TouchPanel/TouchPanel.h"
#include <stdio.h>
/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
extern int Xstart, Ystart,d;
extern int volume;
static int h=0, m=0, s=0;

uint16_t SinTable[45] =                                       /*                      */
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};


void TIMER0_IRQHandler (void)
{
	static int time=0;
	static int orientation=0;
	int happiness, satiety;
	char life[9]="";
	if(get_life()==1){
		if (LPC_TIM0->IR & 01 ){
			orientation=!orientation;
			if(s<59)
				s++;
			else{
				if(m<59){
					m++;
					s=0;
				}else {
					h++;
					m=0;
					s=0;
				}
			}
			sprintf(life, "Age: %.2d:%.2d:%.2d", h,m,s);
			GUI_Text(70,10, (uint8_t *)life,0, 0xFFFF);
		}
		time++;
		change_orientation(orientation);
		if(time>=5 && get_cuddle()==0){
			happiness=less_happiness();
			satiety=less_satiety();
			if(happiness<=0 || satiety<=0)
				set_life(0);
			if(happiness<5)
				LCD_DrawRectangle(32+(9*happiness), 69, 8, 16,0xFFFF);
			if(satiety<5)
				LCD_DrawRectangle(164+(9*satiety), 69, 8, 16,0xFFFF);	
			time=0;
		}
	}
	else{
		//GUI_Text(70,10, (uint8_t *)"Age: --:--:--",0, 0xFFFF);
		sprintf(life, "Age: %.2d:%.2d:%.2d", h,m,s);
		GUI_Text(70,10, (uint8_t *)life,0, 0xFFFF);
		clear_tama();
		disable_timer(0);
		LCD_DrawRectangle(0,271,239, 80, 0xFFFF);
		GUI_Text(70, 140, (uint8_t *)"YOUR FRIEND IS", 0, 0xFFFF);
		GUI_Text(90, 160, (uint8_t *) "GONE AWAY!", 0, 0xFFFF);
		
		GUI_Text(99,290, (uint8_t *)"RESET",0, 0xFFFF);
		h=0;
		m=0;
		s=0;
	}
	LPC_TIM0->IR = 1;			/* clear interrupt flag */	
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
	static int orientation=0;
	if ( get_life()==1){
		if(get_cuddle()==0){
		if(getDisplayPoint(&display, Read_Ads7846(), &matrix )){
			if(display.y>=Ystart && display.y<=(Ystart+15*d) && display.x>=(Xstart-2*d) && display.x<=(Xstart+11*d))
				start_cuddle();	
		}		
	}
		else
		{
			orientation=!orientation;
			cuddle_animation(orientation);
		}
	}

  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 2 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER2_IRQHandler (void)
{
	int finish=6;
	static int point=1;
	static int i=0;
	
	if (LPC_TIM2->IR & 01 ){
		
		if(i>2)
			i=0;
		if(point<finish){
			if(point==(finish/2+1)){
				draw_littleTamagochi(point-1, 0xFFFF, 0);
				eat();
				draw_littleTamagochi(point++, 0, 1);
			}
			else{
				draw_littleTamagochi(point-1, 0xFFFF, 1);
				if(point==(finish/2))
					draw_littleTamagochi(point++, 0, 0);
				else
					draw_littleTamagochi(point++, 0, 1);
			}
			
		}else{
			draw_littleTamagochi(point-1, 0xFFFF,1);
			point=1;
			disable_timer(3);
			i=0;
			LPC_DAC->DACR =0;
			finish_eat();
		}
		
	}
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER3_IRQHandler (void)
{
		static int ticks=0;
	/* DAC management */	
	LPC_DAC->DACR = (SinTable[ticks]*volume/3)<<6;
	ticks++;
	if(ticks==45) ticks=0;

  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}




/******************************************************************************
**                            End Of File
******************************************************************************/
