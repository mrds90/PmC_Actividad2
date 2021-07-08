/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "teclas.h"
#include "sapi.h"

bool leerTecla(gpioMap_t tecla) {
   bool_t tecla_apretada = false;
   if (tecla >= TEC1 && tecla <= TEC4) {
      tecla_apretada = !gpioRead(tecla); 
   }
   return tecla;
}
