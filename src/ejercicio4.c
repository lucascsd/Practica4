/*=============================================================================
 * Ejercicio 4
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/08/03
 * Version: 1.0
 *===========================================================================*/

#include "ejercicio4.h"

/* FUNCION PRINCIPAL */
int main( void )
{
	// INICIALIZAR Y CONFIGURAR PLATAFORMA
    boardInit();

    /* Verificación TICK_RATE rango permitido de tiempo: 1 a 50 ms */
    if ( ( TICK_RATE < TICK_RATE_MIN ) || ( TICK_RATE > TICK_RATE_MAX ) )  blinkError( ERROR_TIME );
    if ( !tickConfig ( TICK_RATE ) )  blinkError( ERROR_TIME );

    inicializarSemaforo(NORMAL);
    teclaDOS 	= inicializarKeyFSM ( TEC2 ); // Se inicializa la MEF de las teclas

   // ----- Repeat for ever -------------------------
    while( true ) {
    	/* Se activa la secuencia correspondiente. En caso de error el programa se bloquea quedando el led rojo parpadeando. */
    	if(!actualizarSemaforo(&teclaDOS)) blinkError ( ERROR_SEQ );
    }
    return 0;
}
