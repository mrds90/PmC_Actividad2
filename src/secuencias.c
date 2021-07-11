/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/secuencias.h"
#include "led.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

static delay_t delayLeds;
static control_secuencia_t secuencia;
/*=====[Fuctions]============================================================*/

static void incrementarSecuencia(void) {
	secuencia.ptrLed++;
   secuencia.ptrTiempo++;
	if (secuencia.ptrLed == secuencia.ptrUltimoLed) {
		secuencia.ptrLed = secuencia.ptrPrimerLed;
      secuencia.ptrTiempo = secuencia.ptrPrimerTiempo;
	}
}

void configurarSecuencia(gpioMap_t psecuencia[], uint16_t tiempo_destello[], uint8_t tamanio_secuencia) {
   secuencia.ptrLed = &psecuencia[0];
   secuencia.ptrTiempo = &tiempo_destello[0];
   secuencia.ptrPrimerLed = &psecuencia[0];
   secuencia.ptrPrimerTiempo = &tiempo_destello[0];
   // uint8_t i;
   // for (i = 0; i<tamanio_secuencia ; i++) {
   //    psecuencia++;
   //    tiempo_destello++;
   // }
   secuencia.ptrUltimoLed = &psecuencia[tamanio_secuencia];
   secuencia.ptrUltimoTiempo = &tiempo_destello[tamanio_secuencia];

   delayConfig(&delayLeds, *secuencia.ptrTiempo);
}

void activarSecuencia(void) {
   if(delayRead(&delayLeds)) {
      encenderLedUnico(*secuencia.ptrLed);
      delayConfig(&delayLeds, *secuencia.ptrTiempo);
      incrementarSecuencia();
   }
}

