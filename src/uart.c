/*============================================================================
 * Ejercicio 4
 * file: teclas.c
 * Authors: Martin Rios <jrios@fi.uba.ar> - Lucas Zalazar <lucas.zalazar6@gmail.com>
 * Date: 2021/07/12
 * Version: 1.0
 *===========================================================================*/

#include "uart.h"

void inicializarUART() {
	
	bool_t printOk = FALSE;
	uartInit ( UART_USB, 115200 );
	uartWriteString	(UART_USB, "UART_USB configurada.\n\r" );

}

void infoUART(){
	
	uartWriteString( UART_USB, menu );

}

void printStateDebounce( stateKey_t estadoTecla ){

	char *estadoAntirebote[] = {
			"\t\tTECLA PRESIONADA \n\r",
			"\t\tTECLA EN FLANCO ASCENDENTE \n\r",
			"\t\tTECLA NO PRESIONADA \n\r",
			"\t\tTECLA EN FLANCO DESCENDENTE \n\r"};

	uartWriteString( UART_USB, "MEF antirrebote:\n\r");
	uartWriteString( UART_USB, estadoAntirebote[estadoTecla] );
}
//bool_t printStateKey( teclaFSM teclaPresionada ){
//
//	return TRUE;
//}
	
void printModeSeq( modeSt_t mode ){

	char *_estadoSecuencia[] = {
			"\t\tNORMAL \n\r",
			"\t\tDESCONECTADO \n\r",
			"\t\tALARMA \n\r"
	};
	uartWriteString( UART_USB, "MEF Controlador semaforo:\n\r");
	uartWriteString( UART_USB, _estadoSecuencia[mode] );

}
