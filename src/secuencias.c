/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "secuencias.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Fuctions]============================================================*/

void activarSecuencia(control_secuencia_t *ptr_secuencia) {
	ptr_secuencia->ptrLed++;
	if (ptr_secuencia->ptrLed == ptr_secuencia->ptrUltimoLed) {
		ptr_secuencia->ptrLed = ptr_secuencia->ptrPrimerLed;
	}
}

