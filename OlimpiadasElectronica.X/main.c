/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene la función principal
 * 
 * Aquí se encuentra la implementación de la función principal
 */
/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* Para las definiciones de uint8_t por ej.*/
#include "system.h"     /* Funciones/Parametros System, como osc/peripheral config */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "uart.h"       /* Funciones/Parametros Uart */
#include "display.h"    /* Funciones/Parametros Display */
#include "tick.h"       /* Funciones/Parametros Tick */
#include <stdio.h>      /* Archivo de Encabezados StdIO */

/*==================[definiciones y macros]==================================*/
// Nuevo tipo de datos enumerado llamado estadoMEF_t



/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
void InicializarMEF(void);
void ActualizarMEF(void);

/*==================[funcion principal]======================================*/
void main(void) {
    /*leds*/
    PIN_FUSIBLE_AB  = 0;
    PIN_FALLA_TRAFO = 0;
    PIN_FALLA_CI = 0;
    PIN_TENSION_GEN = 0;
    PIN_TENSION_REG_INT = 0;
    PIN_BOTON = 0;        
    appInit(); /* Inicializa I/O y Periféricos de la aplicación */
    while (1) {
 if(PIN_FUSIBLE = 0){
  PIN_FUSIBLE_AB  = 1;
 }
  else if(PIN_TRAFO = 0){
   PIN_FALLA_TRAFO = 1;
  }
  
 else if(PIN_TENSION_ALIM = 0){
  PIN_TENSION_GEN = 1; 
  PIN_BUZZER = 1;  
 }
 
  else if(PIN_CI = 0){
 PIN_FALLA_CI = 1;
 }
 
  else if(PIN_CI2 = 0){
 PIN_FALLA_CI = 1;
 }
 
  else if(PIN_TENSION_REG = 0){
 PIN_TENSION_REG_INT = 1;
 }
 if(PIN_BOTON = 0)
     PIN_BUZZER = 0; 
 }  

}


 
    




/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
