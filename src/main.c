/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "../inc/main.h"
#include "teclas.h"
/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main(void)
{
	/* Variables de Retardo no bloqueante */

	boardInit();

	condicionInicial();
   // ----- Loop infinito -------------------------
    while(true) {
		interpretarTecla();
   }
	// Nunca se alcanza este punto debido al ciclo infinito del while(true)
   return 0;
}

