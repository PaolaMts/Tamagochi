#include "../GLCD/GLCD.h"
#include "../timer/timer.h"
#include "../adc/adc.h"

void draw_tamagochi(void);																	//disegna l'aspetto base del tamagochi
void background_tama(void);																	//disegna lo sfondo del gioco
void change_orientation(int orientation);										//modifica l'aspetto del tamagochi in base al valore di orientation 
int less_satiety(void);																			//diminuisce la sazietà
int less_happiness(void);																		//diminuisce la felicità
void finish_eat(void);																			//termina l'azione (mangia lo snack o il cibo) del tamagochi 
void draw_littleTamagochi(int point, int color, int pos);		//disegna la versione piccola del tamagochi per l'animazione in cui mangia
void select_left(void);																			//viene selezionata l'azione del riquadro a sinistra
void select_right(void);																		//viene selezionata l'azione del riquadro a destra
void move_tama(void);																			  //dà il via all'azione (mangia lo snack o il cibo) del tamagochi se life è 1 o chiama start se 0
int get_life(void);																					//restituisce il valore di life
void set_life(int l);																				//setta il valore di life
void eat(void);																							//il tamagochi mangia e sparisce il cibo
void clear_tama(void);																			//cancella la versione base del tamagochi
void start(void);																						//imposta i valori per permettere di ricominciare il gioco
void draw_heart(int x,int y,int color);
void start_cuddle(void);
void cuddle_animation(int orientation);
int get_cuddle(void);
void set_volume(int newVolume);
