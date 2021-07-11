/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "teclas.h"
#include "sapi.h"
#include "secuencias.h"

/**
 * @brief leo el estado de la tecla
 * 
 * @param tecla gpioMap_t
 * @return bool_t (true si tecla apretada)
 */
static bool leerTecla(gpioMap_t tecla);
/**
 * @brief Devuleve la tecla recien presionada (solo por flanco)
 * 
 * @return gpioMap_t 
 */
static gpioMap_t teclaValida(void);
/**
 * @brief Interpretar Tecla evalua cual es la tecla presionada y configura la secuencia.
 * 
 */

/*=====[Definition macros of private constants]==============================*/
#define PERIODO_1S              1000 
#define PERIODO_500MS           500 
#define PERIODO_2S              2000 
#define PERIODO_3S              3000


/*=====[Definitions of private global variables]=============================*/

static uint16_t times[DEMORAS_QTY] = {PERIODO_1S, PERIODO_500MS, PERIODO_2S, PERIODO_3S};
static gpioMap_t secuencia1[] = {LEDB,LED1,LED2,LED3};
static gpioMap_t secuencia2[] = {LED3,LED2,LED1,LEDB};



static bool leerTecla(gpioMap_t tecla) {
   bool_t tecla_apretada = false;
   if (tecla >= TEC1 && tecla <= TEC4) {
      tecla_apretada = !gpioRead(tecla); 
   }
   return tecla_apretada;
}

static gpioMap_t teclaValida(void) {
   static bool_t flag_tecla[FLAGS_QTY] = {true};
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

void interpretarTecla(void) {
   gpioMap_t tecla = teclaValida();
   if (tecla == TEC1) {
      configurarSecuencia(secuencia1,times,sizeof(secuencia1)/sizeof(secuencia1[0]));
   }
   else if (tecla == TEC4) {
      configurarSecuencia(secuencia2,times,sizeof(secuencia2)/sizeof(secuencia2[0]));
   }
   activarSecuencia();
}

void condicionInicial(void) {
   configurarSecuencia(secuencia1,times,sizeof(secuencia1)/sizeof(secuencia1[0]));
}