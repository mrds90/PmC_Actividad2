/*=============================================================================
 * Author: Marcos Dominguez <mrds0690@gmail.com>
 * Date: 2021/07/07
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "teclas.h"
#include "sapi.h"
#include "secuencias.h"

/*=====[Definitions of private functions]====================================*/
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
 * @brief semaforo func gestiona el modo semáforo
 * 
 */
static void semaforoFunc(void);
/**
 * @brief inicializa los delay de la secuencia original
 * 
 */
static void initSecuencia (void);
/*=====[Definition macros of private constants]==============================*/
#define PERIODO_1S              1000 
#define PERIODO_500MS           500 
#define PERIODO_2S              2000 
#define PERIODO_3S              3000
#define LED_OFF                 0


/*=====[Definitions of private global variables]=============================*/
static const uint8_t LED_VERDE     = LED3;
static const uint8_t LED_ROJO      = LED2;
static const uint8_t LED_AMARILLO  = LED1;
static uint16_t times[DEMORAS_QTY] = {PERIODO_1S, PERIODO_500MS, PERIODO_2S, PERIODO_3S};
static gpioMap_t secuencia1[] = {LEDB,LED1,LED2,LED3};
static gpioMap_t secuencia2[] = {LED3,LED2,LED1,LEDB};
static gpioMap_t secuencia3[] = {LED_ROJO,LED_AMARILLO,LED_VERDE};
static gpioMap_t secuencia4[] = {LED_AMARILLO,LED_OFF};
static gpioMap_t secuencia5[] = {LED_ROJO,LED_OFF};


/*=====[Implematation of private functions]==================================*/
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
   bool tecla_presionada = false;

   for (tecla = TEC1 ; tecla <= TEC4 ; tecla++) {
      if (leerTecla(tecla)) { 
         tecla_presionada = true;
         if (flag_tecla[CAMBIAR_SECUENCIA]) {
            flag_tecla[CAMBIAR_SECUENCIA] = false;
            break;
         }
      }

   }
   if (tecla > TEC4) {
      tecla = 0;
      if(!tecla_presionada) {
         flag_tecla[CAMBIAR_SECUENCIA] = true;
      }
   }
   return tecla;
}

static void semaforoFunc(void) {
   static modos_t modo = 0;

   switch (modo) {
      case NORMAL:
         times[0] =  PERIODO_3S;    
         times[1] =  PERIODO_500MS;
         times[2] =  PERIODO_1S;
         configurarSecuencia(secuencia3,times,sizeof(secuencia3)/sizeof(secuencia3[0]));
         break;
      case DESCONECTADO:
         times[0] =  PERIODO_500MS;    
         times[1] =  PERIODO_500MS;
         configurarSecuencia(secuencia4,times,sizeof(secuencia4)/sizeof(secuencia4[0]));
         break;
      case ALARMA:
         times[0] =  PERIODO_1S;    
         times[1] =  PERIODO_1S;
         configurarSecuencia(secuencia5,times,sizeof(secuencia5)/sizeof(secuencia5[0]));
         break;
      default:
         break;
   }
   modo++;
   if (modo == MODOS_QTY) {
      modo = 0;
   }
}

static void initSecuencia (void) {
   times[0] = PERIODO_1S;
   times[1] =  PERIODO_500MS;
   times[2] =  PERIODO_2S;
   times[3] =  PERIODO_3S;

}
/*=====[Implemetation of public functions]====================================*/

void interpretarTecla(void) {
   gpioMap_t tecla = teclaValida();
   switch (tecla) {
   case TEC1:
      initSecuencia();
      configurarSecuencia(secuencia1,times,sizeof(secuencia1)/sizeof(secuencia1[0]));
      break;
   case TEC2:
      semaforoFunc();
      break;
   case TEC3:
      break;      
   case TEC4:
      initSecuencia();
      configurarSecuencia(secuencia2,times,sizeof(secuencia2)/sizeof(secuencia2[0]));
      break;
   default:
      break;
   }
   
   activarSecuencia();
}

void condicionInicial(void) {
   configurarSecuencia(secuencia1,times,sizeof(secuencia1)/sizeof(secuencia1[0]));
}
