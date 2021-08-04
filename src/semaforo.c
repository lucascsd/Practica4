/*=============================================================================
 * Ejercicio 4
 * file: secuencias.c
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/12
 * Version: 1.0
 *===========================================================================*/

#include "../inc/semaforo.h"
#include "uart.h"

static modeSt_t mode;
static normalSt_t normalState;
static const gpioMap_t leds[] = {RED_LED, GREEN_LED, YELLOW_LED};
static delay_t ledDelay; /* Variable del tipo tick para retardos */

void inicializarSemaforo(modeSt_t _mode)
{
	mode = _mode;
	printModeSeq( mode );

	switch(mode){
	case NORMAL:
		normalState = NORMAL_INICIAL;
		break;
	case DESCONECTADO:
		delayInit ( &ledDelay, DISCONECTED_BLINK_TIME);
		break;
	case ALARMA:
		delayInit ( &ledDelay, ALARM_BLINK_TIME);
		break;
	}
}

// ********************* FUNCIÓN QUE ACTUALIZA LA MEF DEL SEMAFORO *****************************
// Recibe: un puntero a la estructura de la tecla para cambiar el modo de funcionamiento.
// Devuelve: TRUE en caso de actualizarse correctamente o FALSE en caso contrario.
// *********************************************************************************************
bool_t actualizarSemaforo(teclaFSM* tecla)
{
	/* Se cambia el modo de la secuencia */
	if ( actualizarKeyFSM ( tecla ) ){
		if(tecla->estadoTecla == TECLA_NO_PRESIONADA){
			mode += 1;
			if(mode > ALARMA) mode = NORMAL;
			printModeSeq( mode );
			printStateDebounce( tecla->estadoTecla );
			if ( !ledsOff(leds, LEDS_SEMAFORO) ) return FALSE; /* Se apagan todos los LEDs del semaforo*/

			switch(mode){
			case NORMAL:
				normalState = NORMAL_INICIAL;
				break;
			case DESCONECTADO:
				delayInit ( &ledDelay, DISCONECTED_BLINK_TIME);
				break;
			case ALARMA:
				delayInit ( &ledDelay, ALARM_BLINK_TIME);
				break;
			}
		}
	}

	switch(mode){

	case NORMAL:

		switch(normalState){
		case NORMAL_INICIAL:
			if(!ledsOff(leds, LEDS_SEMAFORO)) return FALSE;
			if(!ledOn(RED_LED)) return FALSE;
			normalState = ROJO;
			delayInit ( &ledDelay, NORMAL_ON_TIME_RED );
			break;

		case ROJO:
			if(delayRead(&ledDelay)){
				if(!ledsOff(leds, LEDS_SEMAFORO)) return FALSE;
				if(!ledOn(RED_LED)) return FALSE;
				if(!ledOn(YELLOW_LED)) return FALSE;
				normalState = ROJO_AMARILLO;
				delayInit ( &ledDelay, NORMAL_ON_TIME_RED_YELLOW );
			}
			break;

		case ROJO_AMARILLO:
			if(delayRead(&ledDelay)){
				if(!ledsOff(leds, LEDS_SEMAFORO)) return FALSE;
				if(!ledOn(GREEN_LED)) return FALSE;
				normalState = VERDE;
				delayInit ( &ledDelay, NORMAL_ON_TIME_GREEN );
			}
			break;

		case VERDE:
			if(delayRead(&ledDelay)){
				if(!ledsOff(leds, LEDS_SEMAFORO)) return FALSE;
				if(!ledOn(YELLOW_LED)) return FALSE;
				normalState = AMARILLO;
				delayInit ( &ledDelay, NORMAL_ON_TIME_YELLOW );
			}
			break;

		case AMARILLO:
			if(delayRead(&ledDelay)){
				if(!ledsOff(leds, LEDS_SEMAFORO)) return FALSE;
				if(!ledOn(RED_LED)) return FALSE;
				normalState = ROJO;
				delayInit ( &ledDelay, NORMAL_ON_TIME_RED );
			}
			break;
		}

		break;

	case DESCONECTADO:
		if(delayRead(&ledDelay)){
			if(!ledToggle(YELLOW_LED)) return FALSE;
		}
		break;

	case ALARMA:
		if(delayRead(&ledDelay)){
			if(!ledToggle(RED_LED)) return FALSE;
		}
		break;

	}

	return TRUE;
}
