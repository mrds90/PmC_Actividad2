/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "teclas.h"
#include "sapi.h"


/*=====[Definitions of private global variables]=============================*/
static bool_t flag_tecla[FLAGS_QTY] = {true};

bool leerTecla(gpioMap_t tecla) {
   bool_t tecla_apretada = false;
   if (tecla >= TEC1 && tecla <= TEC4) {
      tecla_apretada = !gpioRead(tecla); 
   }
   return tecla_apretada;
}

gpioMap_t TeclaValida(void) {
	gpioMap_t tecla = 0;
   if (leerTecla(TEC1)) { // Sentido de secuencia 1 (INCREMENTAL)
      if (flag_tecla[CAMBIAR_SECUENCIA]) {
         flag_tecla[CAMBIAR_SECUENCIA] = false;
         tecla = TEC1;
      }
   }
   else if (leerTecla(TEC4)) { // Sentido de secuencia 2 (DECREMENTAL)
      if (flag_tecla[CAMBIAR_SECUENCIA]) {
         flag_tecla[CAMBIAR_SECUENCIA] = false;
         tecla = TEC4;
      }
   }
   else {
      /*habilitar el cambio próximo cuando se suelta la tecla*/
      flag_tecla[CAMBIAR_SECUENCIA] = true;
   }
   return tecla;
}