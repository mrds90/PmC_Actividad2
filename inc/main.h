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

#define PERIODO_150MS              150 
#define PERIODO_750MS              750 

/*=====[Public function-like macros]=========================================*/

/**
 * @brief Controla si el tiempo de demora elegido ya se cumplió
 * 
 * @param demora *delay_t
 * @return bool_t (true si la demora se cumplió)
 */
#define demoraCumplida(demora) delayRead(demora)

/*=====[Definitions of public data types]====================================*/

/**
 * @brief Indice de flags que habilitan las teclas
 * 
 */
typedef enum {
   CAMBIAR_SENTIDO,
   CAMBIAR_VELOCIDAD,

   FLAGS_QTY
} flag_tecla_t;

/**
 * @brief Indice del vector que tiene los tiempos de demora.
 * 
 */
typedef enum {
   D150MS,
   D750MS,

   DEMORAS_QTY
} demoras_t;

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __ACTIVIDAD2_H__ */
