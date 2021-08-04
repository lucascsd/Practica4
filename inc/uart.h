/*=============================================================================
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/08/03
 * Version: 1.0
 *===========================================================================*/
#ifndef EJERCICIOPROPUESTO_PRACTICA4_INC_UART_H_
#define EJERCICIOPROPUESTO_PRACTICA4_INC_UART_H_

#include "sapi.h"
#include "semaforo.h"
//VARIABLES

static char menu[] =
		"\n\r"
		"********************* Practica 4 - Prog. de uP ********************\n\r"
		"\n\r"
		"Alumnos: Rios - Zalazar											\n\r"
		"Secuencias: 														\n\r"
		"Normal:		Led rojo parpadeante cada 3 seg						\n\r"
		"       		Led rojo-amarillo parpadeante cada  500 mseg		\n\r"
		"       		Led verde parpadeante cada 1 seg					\n\r"
		"       		Led amarillo parpadeante cada 1 seg					\n\r"
		"Desconectado:	Led amarillo parpadeante cada 500 mseg				\n\r"
		"Alarma:      	Led rojo parpadeante cada 1 seg 					\n\r"
		"*******************************************************************\n\r"
		"Se informarán cada cambios en la MEF antirrebote					\n\r"
		"Se informarán cada cambios en la MEF del controlador de semáforos	\n\r"
		"*******************************************************************\n\r"
		;

//FUNCIONES PARA LA UART
void inicializarUART();
void infoUART();
void printStateDebounce( stateKey_t estadoTecla );
//bool_t printStateKey( teclaFSM teclaPresionada );
void printModeSeq( modeSt_t mode );

#endif /* EJERCICIOPROPUESTO_PRACTICA4_INC_UART_H_ */
