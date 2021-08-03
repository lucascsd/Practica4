/*=============================================================================
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/08/03
 * Version: 1.0
 *===========================================================================*/

#ifndef EJERCICIOPROPUESTO_PRACTICA4_INC_TECLAS_H_
#define EJERCICIOPROPUESTO_PRACTICA4_INC_TECLAS_H_

#include "sapi.h"

// TIEMPOS DE REBOTE (ms)
#define DEBOUNCE_TIME	40

// TECLAS
#define KEY1			0
#define KEY2			1
#define KEY3			2
#define KEY4			3

#define LAST_KEY		4

// DEFINICION DE TIPOS DATOS ENUM
typedef enum
{
	TECLA_PRESIONADA,
	TECLA_FLANCO_ASCENDENTE,
	TECLA_NO_PRESIONADA,
	TECLA_FLANCO_DESCENDENTE,
}stateKey_t;

typedef struct
{
	gpioMap_t 	teclaPosicion;
	stateKey_t 	estadoTecla;
	delay_t 	retardoNoBloqueante;
}teclaFSM ;

teclaFSM teclaUNO, teclaDOS, teclaTRES, teclaCUATRO;

// FUNCIONES DE ACCION PARA FLANCO ASCENDENTE
// Y DESCENDENTE
bool_t buttonPressed(gpioMap_t tecla);
bool_t buttonReleased(gpioMap_t tecla);

//FUNCIONES PARA LA MAQUINA DE ESTADO FINITO
//DE LAS TECLAS
teclaFSM inicializarKeyFSM ( gpioMap_t key );
bool_t actualizarKeyFSM ( teclaFSM * teclaX );

#endif /* EJERCICIOPROPUESTO_PRACTICA4_INC_TECLAS_H_ */
