/*=============================================================================
 * Ejercicio 4
 * file: teclas.c
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/12
 * Version: 1.0
 *===========================================================================*/
#include "teclas.h"

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

	bool_t changedState = FALSE;

	switch ( tecla->estadoTecla ){

	case TECLA_PRESIONADA:
		if ( gpioRead ( tecla->teclaPosicion ) ) {
			tecla->estadoTecla = TECLA_FLANCO_ASCENDENTE;
			delayInit( &tecla->retardoNoBloqueante, DEBOUNCE_TIME );
		}
		break;

	case TECLA_FLANCO_ASCENDENTE:
		if ( delayRead ( &tecla->retardoNoBloqueante ) ) {
			if ( gpioRead ( tecla->teclaPosicion ) ){
				tecla->estadoTecla = TECLA_NO_PRESIONADA;
				changedState = TRUE;
			}
			else tecla->estadoTecla = TECLA_PRESIONADA;
		}
		break;

	case TECLA_NO_PRESIONADA:
		if ( !gpioRead ( tecla->teclaPosicion ) ){
			tecla->estadoTecla = TECLA_FLANCO_DESCENDENTE;
			delayInit( &tecla->retardoNoBloqueante, DEBOUNCE_TIME );
		}
		break;

	case TECLA_FLANCO_DESCENDENTE:
		if ( delayRead ( &tecla->retardoNoBloqueante ) ) {
			if ( !gpioRead ( tecla->teclaPosicion ) ){
				tecla->estadoTecla = TECLA_PRESIONADA;
				changedState = TRUE;
			}
			else tecla->estadoTecla = TECLA_NO_PRESIONADA;
		}
		break;

	default:
		tecla->estadoTecla = TECLA_NO_PRESIONADA;
		break;
	}
	return changedState;
}

