/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __ACTIVIDAD2_H__
#define __ACTIVIDAD2_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>
#include "sapi.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/


/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/


/**
 * @brief Indice del vector que tiene los tiempos de demora.
 * 
 */
typedef enum {
   D1S,
   D500MS,
   D2S,
   D3S,

   DEMORAS_QTY
} demoras_t;
/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __ACTIVIDAD2_H__ */
