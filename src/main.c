/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/main.h"
#include "teclas.h"
#include "secuencias.h"
/*=====[Definition macros of private constants]==============================*/

#define PERIODO_1S              1000 
#define PERIODO_500MS           500 
#define PERIODO_2S              2000 
#define PERIODO_3S              3000
/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main(void)
{
	/* Variables de Retardo no bloqueante */
	static uint16_t times[DEMORAS_QTY] = {PERIODO_1S, PERIODO_500MS, PERIODO_2S, PERIODO_3S};
	static gpioMap_t secuencia1[] = {LEDB,LED1,LED2,LED3};
	static gpioMap_t secuencia2[] = {LED3,LED2,LED1,LEDB};
	boardInit();
	configurarSecuencia(secuencia1,times,sizeof(secuencia1)/sizeof(secuencia1[0]));
   // ----- Loop infinito -------------------------
    while(true) {
		static bool_t flag_tecla[FLAGS_QTY] = {true};
		if (leerTecla(TEC1)) { // Sentido de secuencia 1 (INCREMENTAL)
			if (flag_tecla[CAMBIAR_SECUENCIA]) {
				flag_tecla[CAMBIAR_SECUENCIA] = false;
				configurarSecuencia(secuencia1,times,sizeof(secuencia1)/sizeof(secuencia1[0]));
			}
		}
		else if (leerTecla(TEC4)) { // Sentido de secuencia 2 (DECREMENTAL)
			if (flag_tecla[CAMBIAR_SECUENCIA]) {
				flag_tecla[CAMBIAR_SECUENCIA] = false;
				configurarSecuencia(secuencia2,times,sizeof(secuencia2)/sizeof(secuencia2[0]));
   	    	}
	    }
   		else {
      	/*habilitar el cambio próximo cuando se suelta la tecla*/
   	   		flag_tecla[CAMBIAR_SECUENCIA] = true;
	   	}
		
		activarSecuencia();
   }
	// Nunca se alcanza este punto debido al ciclo infinito del while(true)
   return 0;
}

