/*=============================================================================
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/08/03
 * Version: 1.0
 *===========================================================================*/

#ifndef EJERCICIOPROPUESTO_PRACTICA4_INC_SECUENCIAS_H_
#define EJERCICIOPROPUESTO_PRACTICA4_INC_SECUENCIAS_H_

#include "led.h"
#include "teclas.h"
#include "sapi.h"

// Tiempos de destello en ms
#define DISCONECTED_BLINK_TIME		500
#define ALARM_BLINK_TIME			1000
#define NORMAL_ON_TIME_RED			3000
#define NORMAL_ON_TIME_RED_YELLOW	500
#define NORMAL_ON_TIME_YELLOW		500
#define NORMAL_ON_TIME_GREEN		1000

#define RED_LED						LED1
#define GREEN_LED					LED3
#define YELLOW_LED					LED2
#define LEDS_SEMAFORO				3

// Estados de la MEF de los modos del semaforo
typedef enum
{
	NORMAL,
	DESCONECTADO,
	ALARMA,
}modeSt_t;

// Estados del modo Normal
typedef enum
{
	NORMAL_INICIAL,
	ROJO,
	ROJO_AMARILLO,
	VERDE,
	AMARILLO,
}normalSt_t;

// FUNCIONES PARA CONTROLAR EL SEMAFORO
bool_t actualizarSemaforo (teclaFSM* tecla);
void inicializarSemaforo(modeSt_t _mode);

#endif /* EJERCICIOPROPUESTO_PRACTICA4_INC_SECUENCIAS_H_ */
