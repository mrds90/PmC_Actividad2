/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __TECLAS_H__
#define __TECLAS_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>
#include "sapi.h"


/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif


void interpretarTecla(void);
/**
 * @brief Configura la secuencia inicial con sus delays
 * 
 */
void condicionInicial(void);
/*=====[Definitions of public data types]====================================*/
/**
 * @brief Indice de flags que habilitan las teclas
 * 
 */
typedef enum {
   CAMBIAR_SECUENCIA,
   CAMBIAR_VELOCIDAD,

   FLAGS_QTY
} flag_tecla_t;

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
/*=====[Prototypes (declarations) of public functions]=======================*/

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __ACTIVIDAD2_H__ */
