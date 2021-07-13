/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Author: Mario Aguilar <fernandoaguilar731010.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/secuencias.h"
#include "led.h"

/*=====[Definitions of private functions]====================================*/
static void incrementarSecuencia(void);

/*=====[Definitions of private global variables]=============================*/

static delay_t delayLeds;
static control_secuencia_t secuencia;

/*=====[Implementation of private functions]====================================*/

static void incrementarSecuencia(void) {
	secuencia.ptrLed++;
   secuencia.ptrTiempo++;
	if (secuencia.ptrLed >= secuencia.ptrUltimoLed) {
		secuencia.ptrLed = secuencia.ptrPrimerLed;
      secuencia.ptrTiempo = secuencia.ptrPrimerTiempo;
	}
}
/*=====[Implementation of public functions]==================================*/
void configurarSecuencia(gpioMap_t psecuencia[], uint16_t tiempo_destello[], uint8_t tamanio_secuencia) {
   uint8_t i;
   for (i = 0;i < tamanio_secuencia; i++) {
      if (*secuencia.ptrLed == psecuencia[i]) {
         break;
      }
   } 
   if (i < tamanio_secuencia) {
      secuencia.ptrLed = &psecuencia[i];
      secuencia.ptrTiempo = &tiempo_destello[i];
   }
   else {
      secuencia.ptrLed = &psecuencia[0];
      secuencia.ptrTiempo = &tiempo_destello[0];
      delayConfig(&delayLeds, *secuencia.ptrTiempo);
   }
   
   secuencia.ptrPrimerLed = &psecuencia[0];
   secuencia.ptrPrimerTiempo = &tiempo_destello[0];

   secuencia.ptrUltimoLed = &psecuencia[tamanio_secuencia];
   secuencia.ptrUltimoTiempo = &tiempo_destello[tamanio_secuencia];

   incrementarSecuencia();
   encenderLedUnico(*secuencia.ptrLed);
}

void activarSecuencia(void) {
   if(delayRead(&delayLeds)) {
      incrementarSecuencia();
      encenderLedUnico(*secuencia.ptrLed);
      delayConfig(&delayLeds, *secuencia.ptrTiempo);
   }
}

