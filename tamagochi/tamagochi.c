#include "../tamagochi/tamagochi.h"

int happiness=5, satiety=5, move=0, action=0,life=1, cuddle=0;
int Xstart=90, Ystart=150, d=7;

void background_tama(void){
	
	int i;
	LCD_DrawRectangle(10,15,4,4, Black);
	LCD_DrawRectangle(14,13,2,8,Black);
	LCD_DrawRectangle(16,11,2,12,Black);
	LCD_DrawRectangle(18,9,2,16,Black);
	GUI_Text(70,10, (uint8_t *)"Age: 00:00:00",0, 0xFFFF);
	GUI_Text(20,40, (uint8_t *)"Happiness",0, 0xFFFF);
	GUI_Text(160, 40, (uint8_t *)"Satiety",0, 0xFFFF);
	//batterie
	LCD_DrawRectangle(28, 65, 52, 24, 0);
	LCD_DrawRectangle(81, 72, 3, 6, 0);
	LCD_DrawRectangle(160, 65, 52, 24, 0);
	LCD_DrawRectangle(213, 72,3,6,6);
	LCD_DrawRectangle(31, 68, 46, 18, 0xFFFF);
	LCD_DrawRectangle(163, 68, 46, 18, 0xFFFF);
	for (i=0; i<5;i++)
		LCD_DrawRectangle(32+(9*i), 69, 8,16, 0);

	for (i=0; i<5;i++)
		LCD_DrawRectangle(164 +(9*i), 69, 8,16, 0);
	
	LCD_DrawLine(0,270,250,270,0);
	GUI_Text(45,290, (uint8_t *)"SNACK",0, 0xFFFF);
	LCD_DrawLine(115, 271, 115, 350,0);
	GUI_Text(160,290, (uint8_t *)"MEAL",0, 0xFFFF);
}
void draw_tamagochi(void){
	
	int i, j=0;
		for(i=0; i<2;i++){
			LCD_DrawRectangle(Xstart+(i*d), Ystart, d, d, 0);
			LCD_DrawRectangle(Xstart+((7+i)*d), Ystart, d, d, 0);
		}
		j++;
		for(i=0; i<4;i++){
			LCD_DrawRectangle(Xstart-d+(i*d), Ystart+(j*d), d, d, 0);
			LCD_DrawRectangle(Xstart+((6+i)*d), Ystart+(j*d), d, d, 0);
		}
			j++;
		for(i=0; i<11;i++)
			LCD_DrawRectangle(Xstart-d+(i*d), Ystart+(j*d), d, d, 0);
		j++;
		for(i=0; i<2;i++){
			LCD_DrawRectangle(Xstart-d+(i*d), Ystart+(j*d), d, d, 0);
			LCD_DrawRectangle(Xstart+((8+i)*d), Ystart+(j*d), d, d, 0);
		}
		j++;
		LCD_DrawRectangle(Xstart-d, Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(9*d), Ystart+(d*(j++)), d, d, 0);
		LCD_DrawRectangle(Xstart-(2*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(10*d), Ystart+(d*(j++)), d, d, 0);
		for(i=0; i<3;i++)
			LCD_DrawRectangle(Xstart+((3+i)*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart-(2*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(10*d), Ystart+(d*(j++)), d, d, 0);
		LCD_DrawRectangle(Xstart-d, Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(9*d), Ystart+(d*(j++)), d, d, 0);
		LCD_DrawRectangle(Xstart-d, Ystart+(j*d), d, d, 0); //1
		LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(7*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(10*d), Ystart+(d*(j++)), d, d, 0); //2
		LCD_DrawRectangle(Xstart-d, Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart, Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0); //3
		LCD_DrawRectangle(Xstart+(8*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(9*d), Ystart+(d*(j++)), d, d, 0);
		LCD_DrawRectangle(Xstart-d, Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(9*d), Ystart+(d*(j++)), d, d, 0);
		LCD_DrawRectangle(Xstart, Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(8*d), Ystart+(d*(j++)), d, d, 0); 
		LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0); 
		LCD_DrawRectangle(Xstart+(3*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(4*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(5*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(7*d), Ystart+(d*(j++)), d, d, 0); 
		LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0); //4
		LCD_DrawRectangle(Xstart+(5*d), Ystart+(j*d), d, d, 0); //5
		LCD_DrawRectangle(Xstart+(7*d), Ystart+(d*(j++)), d, d, 0);//6
		LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d, 0); //7	
}

void change_orientation(int orientation){
	
	int j=8; //riga da cui cominciano i pixel da modificare
	if(move==0 && cuddle==0){
	if (orientation==1 ){
			LCD_DrawRectangle(Xstart-d, Ystart+(j*d), d, d, 0xFFFF); //disattivo 1
			LCD_DrawRectangle(Xstart-(2*d), Ystart+(j*d), d, d, 0); //attivo 1
			LCD_DrawRectangle(Xstart+(10*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 2
			LCD_DrawRectangle(Xstart+(9*d), Ystart+(d*(j++)), d, d, 0); //attivo 2
			LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0xFFFF); //disattivo 3
			LCD_DrawRectangle(Xstart+(7*d), Ystart+(j*d), d, d, 0); //attivo 3
			j=j+4;
			LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 4
			LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0); //attivo 4
			LCD_DrawRectangle(Xstart+(3*d), Ystart+(j*d), d, d, 0); //attivo 4
		  LCD_DrawRectangle(Xstart+(7*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 5
			LCD_DrawRectangle(Xstart+(5*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 5
			LCD_DrawRectangle(Xstart+(6*d), Ystart+(d*(j++)), d, d, 0); //attivo 5
			LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 6
			LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0); //attivo 6	
		}else{
			LCD_DrawRectangle(Xstart-(2*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 1
			LCD_DrawRectangle(Xstart-d, Ystart+(j*d), d, d, 0); //attivo 1
			LCD_DrawRectangle(Xstart+(9*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 2
			LCD_DrawRectangle(Xstart+(10*d), Ystart+(d*(j++)), d, d, 0); //attivo 2
			LCD_DrawRectangle(Xstart+(7*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 3
			LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0); //attivo 3
			j=j+4;
			LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0xFFFF); //disattivo 4
			LCD_DrawRectangle(Xstart+(3*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 4
			LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0); //attivo 4
			LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 5
			LCD_DrawRectangle(Xstart+(5*d), Ystart+(j*d), d, d, 0); //attivo 5
			LCD_DrawRectangle(Xstart+(7*d), Ystart+(d*(j++)), d, d, 0); //attivo 5
			LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 6
			LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d, 0); //attivo 6
		}
	}
}


int less_satiety(void){
	if(move==0)
		satiety--;	
	return satiety;
}

int less_happiness(void){
	if(move==0)
		happiness--;
	return happiness;
}

void select_left(void){
	if(move==0 && happiness>0) {
		if(action==1){
		//cancello la selezione di destra
		LCD_DrawRectangle(116,271,123,2,0xFFFF);
		LCD_DrawRectangle(116,271,2,48,0xFFFF);
		LCD_DrawRectangle(116,318,123,2,0xFFFF);
		LCD_DrawRectangle(238,271,2,48,0xFFFF);
		}
		//inserisco la selezione a sinistra
		LCD_DrawRectangle(0,271,114,2,0xF800);
		LCD_DrawRectangle(0,271,2,48,0xF800);
		LCD_DrawRectangle(0,318,114,2,0xF800);
		LCD_DrawRectangle(113,271,2,48,0xF800);
		action=2;
	}
}
	
void select_right(void){
	if(move==0 && satiety>0){
		if(action==2){
		//cancello la selezione di sinistra
		LCD_DrawRectangle(0,271,114,2,0xFFFF);
		LCD_DrawRectangle(0,271,2,48,0xFFFF);
		LCD_DrawRectangle(0,318,114,2,0xFFFF);
		LCD_DrawRectangle(113,271,2,48,0xFFFF);
		}
		//inserisco la selezione di destra
		LCD_DrawRectangle(116,271,123,2,0xF800);
		LCD_DrawRectangle(116,271,2,48,0xF800);
		LCD_DrawRectangle(116,318,123,2,0xF800);
		LCD_DrawRectangle(238,271,2,48,0xF800);
		action=1;
	}
}

void move_tama(){
	if(action!=0 && life==1 && move==0){
		clear_tama();
		draw_littleTamagochi(0,0,1);
		move=1;
		if(action==1){
			LCD_DrawRectangle(34,232,16,5,0xFFE0);
			LCD_DrawRectangle(30,237,24,5,0xFFE0);
			LCD_DrawRectangle(30,242,24,4,0xF800);
			LCD_DrawRectangle(30,246,24,4,0x07E0);
			LCD_DrawRectangle(30,250,24,5,0xFFE0);
		}
		else if(action==2){
			LCD_DrawRectangle(30,231,7,7,0xF800);
			LCD_DrawRectangle(30,231,3,3,0xFFFF);
			LCD_DrawRectangle(37,238,10,10,0xF800);
			LCD_DrawRectangle(47,248,7,7,0xF800);
			LCD_DrawRectangle(51,252,3,3,0xFFFF);
		}
		reset_timer(2);
		enable_timer(2);
	}
	else if (life==0){
		LCD_DrawRectangle(0,271, 239,2,0xF800);
		LCD_DrawRectangle(0, 271, 2, 48, 0xF800);
		LCD_DrawRectangle(0,318, 239, 2, 0xF800);
		LCD_DrawRectangle(238,271,2,48,0xF800);
		start();	
	}
}

void draw_littleTamagochi(int point, int color, int pose){
	int x= 210,y=215,start;
	int d=5;
	int i,k=1;
	
		start=x-(d*8*point);
		for(i=0;i<4;i++)
			LCD_DrawRectangle(start-(d*k), y+(d*(2+i)),d,d,color);
		LCD_DrawRectangle(start-(d*(++k)),y+d,d,d,color);
		LCD_DrawRectangle(start-(d*(k++)), y+(d*6),d,d,color);
		for(i=0;i<4;i++){
			LCD_DrawRectangle(start-(d*(k+i)), y,d,d,color);
			LCD_DrawRectangle(start-(d*(k+i)), y+(d*7),d,d,color);
		}
	if(pose==1){
		k++;
		LCD_DrawRectangle(start-(d*k), y+(d*2),d,d,color);
		for(i=0;i<3;i++)
			LCD_DrawRectangle(start-(d*(++k)), y+(4*d),d,d,color);
	
		LCD_DrawRectangle(start-(d*k),y+d,d,d,color);
		LCD_DrawRectangle(start-(d*k++), y+(d*6),d,d,color);
		for(i=0;i<4;i++)
			LCD_DrawRectangle(start-(d*k), y+(d*(2+i)),d,d,color);
	}else{
		LCD_DrawRectangle(start-(d*(k++)), y+(d*3),d,d,color);
		LCD_DrawRectangle(start-(d*(++k)), y+(d*3),d,d,color);
		for(i=0;i<4;i++)
			LCD_DrawRectangle(start-(d*(k+i)), y+(4*d),d,d,color);
		LCD_DrawRectangle(start-(d*(++k)), y+(d*2),d,d,color);
		LCD_DrawRectangle(start-(d*k),y+d,d,d,color);
		LCD_DrawRectangle(start-(d*k++), y+(d*6),d,d,color);
		LCD_DrawRectangle(start-(d*k),y+(d*5),d,d,color);	
	}

}

void eat(void){
	if(action==1){
		LCD_DrawRectangle(34,232,16,5,0xFFFF);
			LCD_DrawRectangle(30,237,24,5,0xFFFF);
			LCD_DrawRectangle(30,242,24,4,0xFFFF);
			LCD_DrawRectangle(30,246,24,4,0xFFFF);
			LCD_DrawRectangle(30,250,24,5,0xFFFF);
	}
	else if(action==2){
			LCD_DrawRectangle(30,231,7,7,0xFFFF);
			LCD_DrawRectangle(37,238,10,10,0xFFFF);
			LCD_DrawRectangle(47,248,7,7,0xFFFF);	
	}
}

void finish_eat(void){
	if(action==1){
		if(satiety<5){
			LCD_DrawRectangle(164+(9*satiety), 69, 8, 16,0);
			satiety++;
		}
		LCD_DrawRectangle(116,271,123,2,0xFFFF);
		LCD_DrawRectangle(116,271,2,48,0xFFFF);
		LCD_DrawRectangle(116,318,123,2,0xFFFF);
		LCD_DrawRectangle(238,271,2,48,0xFFFF);
	}
	else if(action==2){
		if(happiness<5){
			LCD_DrawRectangle(32+(9*happiness), 69, 8, 16,0);
			happiness++;
		}
		LCD_DrawRectangle(0,271,114,2,0xFFFF);
		LCD_DrawRectangle(0,271,2,48,0xFFFF);
		LCD_DrawRectangle(0,318,114,2,0xFFFF);
		LCD_DrawRectangle(113,271,2,48,0xFFFF);
	}		
	action=0;
	draw_tamagochi();
	move=0;
	disable_timer(2);
}


void clear_tama(void){
	LCD_DrawRectangle(Xstart-(2*d), Ystart,13*d, 15*d, 0xFFFF);
}

void start(void){
	LCD_Clear(0xFFFF);
	satiety=5;
	happiness=5;
	action=0;
	move=0;
	life=1;
	background_tama();
	draw_tamagochi();	
	enable_timer(0);
}

int get_life(void){
	return life;
}

void set_life(int l){
	life=l;
}

void start_cuddle(){
	int j=4;
	disable_timer(1);
	cuddle=1;
	
	//occhi
	LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d/3, 0XFFFF);
	LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d+ d/3), d, d/3, 0xFFFF);
	LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d/3, 0XFFFF);
	LCD_DrawRectangle(Xstart+(6*d), Ystart+((j++)*d+ d/3), d, d/3, 0xFFFF);
	//bocca
	LCD_DrawRectangle(Xstart+3*d, Ystart+((++j)*d), 3*d, d, 0XFFFF);
	LCD_DrawRectangle(Xstart+3*d, Ystart+(j*d), 3, 2, 0);
	LCD_DrawRectangle(Xstart+3*d+2*d+2, Ystart+(j*d), 3, 2, 0);
	LCD_DrawRectangle(Xstart+(3*d)+3, Ystart+(j*d+2), 3*d-8, 3, 0);
	LCD_DrawRectangle(Xstart+(3*d+d), Ystart+(d*(j++)+5), d, 2, 0);
	//corpo
	LCD_DrawRectangle(Xstart-(2*d), Ystart+(++j*d), d, d, 0xFFFF); //disattivo 1
	LCD_DrawRectangle(Xstart-d, Ystart+(j*d), d, d, 0); //attivo 1
	LCD_DrawRectangle(Xstart+(10*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 2
	LCD_DrawRectangle(Xstart+(9*d), Ystart+(d*(j++)), d, d, 0); //attivo 2
	LCD_DrawRectangle(Xstart+(7*d), Ystart+(j*d), d, d, 0); //attivo 3
	LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0); //attivo 3
	j=j+4;
	LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 4
	LCD_DrawRectangle(Xstart+d, Ystart+(j*d), d, d, 0); //attivo 4
	LCD_DrawRectangle(Xstart+(3*d), Ystart+(j*d), d, d, 0); //attivo 4
	LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d, 0xFFFF); //disattivo 5
	LCD_DrawRectangle(Xstart+(5*d), Ystart+(j*d), d, d, 0); //attivo 5
	LCD_DrawRectangle(Xstart+(7*d), Ystart+(d*(j++)), d, d, 0); //attivo 5
	LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0); //attivo 6
	LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d, 0);
	
	draw_heart(Xstart+2.5*d, Ystart+7.5*d,Red);
	reset_timer(1);
	init_timer(1, 0, 0, 3,0x5F5E10);
	enable_timer(1);
	
}

void draw_heart(int x,int y,int color){
	int d1=4, j=0, start_y=y+2*d1;
	
	LCD_DrawRectangle(x, start_y, d1, 2*d1, color);
	LCD_DrawRectangle(x+d1*(++j), start_y-d1, d1, 4*d1, color);
	LCD_DrawRectangle(x+d1*(++j), start_y-d1, d1, 5*d1, color);
	LCD_DrawRectangle(x+d1*(++j), start_y, d1, 5*d1, color);
	LCD_DrawRectangle(x+d1*(++j), start_y-d1, d1, 5*d1, color);
	LCD_DrawRectangle(x+d1*(++j), start_y-d1, d1, 4*d1, color);
	LCD_DrawRectangle(x+d1*(++j), start_y, d1, 2*d1, color);

}

void cuddle_animation(int orientation){
	static int point=0;
	int dim=28, j=4, x=Xstart+2.5*d, y=Ystart+7.5*d;
	//8d, 2d
	if(point-1>=0){
		draw_heart(x+(point-1)*dim, y-(point-1)*dim, White);	
		if(point==2){
		LCD_DrawRectangle(Xstart+3*d, Ystart+(6*d), 3, 2, 0);
		LCD_DrawRectangle(Xstart+3*d+2*d+2, Ystart+(6*d), 3, 2, 0);
		LCD_DrawRectangle(Xstart+(3*d)+3, Ystart+(6*d+2), 3*d-8, 3, 0);
		LCD_DrawRectangle(Xstart+10*d, Ystart+(5*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(9*d), Ystart+(4*d), d, d, 0);
		LCD_DrawRectangle(Xstart-d+(10*d), Ystart+(2*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(8*d), Ystart+d, d, d, 0);
		LCD_DrawRectangle(Xstart+(9*d), Ystart+d, d, d, 0);
		LCD_DrawRectangle(Xstart+(8*d), Ystart, d, d, 0);
		}
		
	}
	point++;
	draw_heart(x+point*dim, y-point*dim,Red);
	if(point>=5){

			disable_timer(1);
			orientation=1;
			if(happiness<5){
			LCD_DrawRectangle(32+(9*happiness), 69, 8, 16,0);
			happiness++;
			}
			LCD_DrawRectangle(Xstart+3*d, Ystart+(6*d), 3*d, d, 0);
			cuddle=0;
			reset_timer(1);
			init_timer(1, 0, 0, 3,0xC8);					//timer per controllo touch
			enable_timer(1);
		draw_heart(x+(point-1)*dim, y-(point-1)*dim,White);
		point=0;
			
	}
	
	if(orientation==0){
		LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d/3, 0XFFFF);
		LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d+ d/3), d, d/3, 0xFFFF);
		LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d/3, 0XFFFF);
		LCD_DrawRectangle(Xstart+(6*d), Ystart+((j++)*d+ d/3), d, d/3, 0xFFFF);
	}
	else{
		LCD_DrawRectangle(Xstart+(2*d), Ystart+(j*d), d, d, 0);
		LCD_DrawRectangle(Xstart+(6*d), Ystart+(j*d), d, d, 0);
	}
}

void set_volume(int newVolume){
	if(newVolume==3){
				LCD_DrawRectangle(22,13,2,2,Black);
				LCD_DrawRectangle(24,15,2,4,Black);
				LCD_DrawRectangle(22,19,2,2,Black);
		
				LCD_DrawRectangle(24,9,2,2,Black);
				LCD_DrawRectangle(26,11,2,2,Black);
				LCD_DrawRectangle(28,13,2,8,Black);
				LCD_DrawRectangle(26,21,2,2,Black);
				LCD_DrawRectangle(24,23,2,2,Black);
		
				LCD_DrawRectangle(28,7,2,2,Black);
				LCD_DrawRectangle(30,9,2,2,Black);
				LCD_DrawRectangle(32,11,2,12,Black);
				LCD_DrawRectangle(30,23,2,2,Black);
				LCD_DrawRectangle(28,25,2,2,Black);
	}
	if(newVolume==2){
				LCD_DrawRectangle(22,13,2,2,Black);
				LCD_DrawRectangle(24,15,2,4,Black);
				LCD_DrawRectangle(22,19,2,2,Black);
		
				LCD_DrawRectangle(24,9,2,2,Black);
				LCD_DrawRectangle(26,11,2,2,Black);
				LCD_DrawRectangle(28,13,2,8,Black);
				LCD_DrawRectangle(26,21,2,2,Black);
				LCD_DrawRectangle(24,23,2,2,Black);
		
				LCD_DrawRectangle(28,7,2,2,White);
				LCD_DrawRectangle(30,9,2,2,White);
				LCD_DrawRectangle(32,11,2,12,White);
				LCD_DrawRectangle(30,23,2,2,White);
				LCD_DrawRectangle(28,25,2,2,White);
		
	}
	if(newVolume==1){
				LCD_DrawRectangle(22,13,2,2,Black);
				LCD_DrawRectangle(24,15,2,4,Black);
				LCD_DrawRectangle(22,19,2,2,Black);
		
				LCD_DrawRectangle(24,9,2,2,White);
				LCD_DrawRectangle(26,11,2,2,White);
				LCD_DrawRectangle(28,13,2,8,White);
				LCD_DrawRectangle(26,21,2,2,White);
				LCD_DrawRectangle(24,23,2,2,White);
		
				LCD_DrawRectangle(28,7,2,2,White);
				LCD_DrawRectangle(30,9,2,2,White);
				LCD_DrawRectangle(32,11,2,12,White);
				LCD_DrawRectangle(30,23,2,2,White);
				LCD_DrawRectangle(28,25,2,2,White);
		
	}
	if(newVolume==0){
				LCD_DrawRectangle(22,13,2,2,White);
				LCD_DrawRectangle(24,15,2,4,White);
				LCD_DrawRectangle(22,19,2,2,White);
		
				LCD_DrawRectangle(24,9,2,2,White);
				LCD_DrawRectangle(26,11,2,2,White);
				LCD_DrawRectangle(28,13,2,8,White);
				LCD_DrawRectangle(26,21,2,2,White);
				LCD_DrawRectangle(24,23,2,2,White);
		
				LCD_DrawRectangle(28,7,2,2,White);
				LCD_DrawRectangle(30,9,2,2,White);
				LCD_DrawRectangle(32,11,2,12,White);
				LCD_DrawRectangle(30,23,2,2,White);
				LCD_DrawRectangle(28,25,2,2,White);
		
	}
	
}

int get_cuddle(void){
	return cuddle;
}

