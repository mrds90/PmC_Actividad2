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

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/
/**
 * @brief leo el estado de la tecla
 * 
 * @param tecla gpioMap_t
 * @return bool_t (true si tecla apretada)
 */
 bool leerTecla(gpioMap_t tecla);
/**
 * @brief Devuleve la tecla recien presionada (solo por flanco)
 * 
 * @return gpioMap_t 
 */
gpioMap_t TeclaValida(void);
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
/*=====[Prototypes (declarations) of public functions]=======================*/

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __ACTIVIDAD2_H__ */
