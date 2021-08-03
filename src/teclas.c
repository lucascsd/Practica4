/*=============================================================================
 * Ejercicio 4
 * file: teclas.c
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/12
 * Version: 1.0
 *===========================================================================*/
#include "teclas.h"

/*Arreglo del tipo gpioMap_t para teclas */
const gpioMap_t keyArray[] = { TEC1, TEC2, TEC3, TEC4 };

//***** FUNCION QUE INICIALIZA LA MEF DE LAS TECLAS ********************************************
// Recibe: el numero de tecla que se quiere consultar/actualizar
// Devuelve: los parametros de la estructura para inicializarla
// *********************************************************************************************
teclaFSM inicializarKeyFSM ( gpioMap_t key ){

	teclaFSM tecla = {key, TECLA_NO_PRESIONADA, 0};

	return tecla;
}

//***** FUNCION DE ACTUALIZACION PARA LA MEF DE LAS TECLAS **************************************
// Recibe: el numero de tecla que se quiere consultar/actualizar
// Devuelve: TRUE si la tecla fue presionada o FALSE en caso contrario
// *********************************************************************************************
bool_t actualizarKeyFSM ( teclaFSM * tecla ){

	static bool_t keyPressed = FALSE;

	switch ( tecla->estadoTecla ){

	case TECLA_PRESIONADA:
		if ( gpioRead ( tecla->teclaPosicion ) ) {
			tecla->estadoTecla = TECLA_FLANCO_ASCENDENTE;
			delayInit( &tecla->retardoNoBloqueante, DEBOUNCE_TIME );
		}
		else tecla->estadoTecla = TECLA_PRESIONADA;
		keyPressed = FALSE;
		break;

	case TECLA_FLANCO_ASCENDENTE:
		if ( delayRead ( &tecla->retardoNoBloqueante ) ) {
			if ( gpioRead ( tecla->teclaPosicion ) ){
				tecla->estadoTecla = TECLA_NO_PRESIONADA;
				buttonReleased ( tecla->teclaPosicion );
			}
			else {
				tecla->estadoTecla = TECLA_PRESIONADA;
			}
		}
		keyPressed = FALSE;
		break;

	case TECLA_NO_PRESIONADA:
		if ( !gpioRead ( tecla->teclaPosicion ) ){
			tecla->estadoTecla = TECLA_FLANCO_DESCENDENTE;
			delayInit( &tecla->retardoNoBloqueante, DEBOUNCE_TIME );
		}
		else tecla->estadoTecla = TECLA_NO_PRESIONADA;
		keyPressed = FALSE;
		break;

	case TECLA_FLANCO_DESCENDENTE:
		if ( delayRead ( &tecla->retardoNoBloqueante ) ) {
			if ( !gpioRead ( tecla->teclaPosicion ) ){
				tecla->estadoTecla = TECLA_PRESIONADA;
				keyPressed = buttonPressed ( tecla->teclaPosicion );
			}
			else{
				tecla->estadoTecla = TECLA_NO_PRESIONADA;
				keyPressed = FALSE;
			}
		} else keyPressed = FALSE;
		break;

	default:
		tecla->estadoTecla = TECLA_NO_PRESIONADA;
		break;
	}
	return keyPressed;
}

bool_t buttonPressed(gpioMap_t tecla){

	return TRUE;
}

bool_t buttonReleased(gpioMap_t tecla){

	return TRUE;
}

