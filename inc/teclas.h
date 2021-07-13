/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Author: Mario Aguilar <fernandoaguilar731010.com>
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

/**
 * @brief Configura las seuecnias segun la tecla presionada
 * 
 */
void interpretarTecla(void);
/**
 * @brief Configura la secuencia inicial con sus delays
 * 
 */
void condicionInicial(void);
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

/**
 * @brief Modos del semáforo.
 * 
 */
typedef enum {
   NORMAL,
   DESCONECTADO,
   ALARMA,

   MODOS_QTY
} modos_t;
/*=====[Prototypes (declarations) of public functions]=======================*/

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __ACTIVIDAD2_H__ */
