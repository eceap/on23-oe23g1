/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene las definiciones de user
 * 
 * Aquí se encuentra la implementación de users, los defines, macros, 
 * datos internos y externos, declaraciones y definiciones de funciones
 * internas y definiciones de funciones externas.
 */

/*==================[inlcusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

#include "system.h"     /* Funciones/Parametros System, como conf de osc/perif */
#include "user.h"       /* Funciones/Parametros User, como InitApp */
#include "uart.h"       /* Funciones/Parametros Uart */
#include "display.h"    /* Funciones/Parametros Display */
#include "tick.h"       /* Funciones/Parametros Tick */

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/
//char datoUser; //Ejemplo

/*==================[declaraciones de funciones internas]====================*/
//static void funcUser(void); //Ejemplo

/*==================[definiciones de funciones internas]=====================*/
//static void funcUser(void){ //Ejemplo
//}; 

/*==================[definiciones de funciones externas]=====================*/
/**
 * @brief	Inicializa Ports, Periféricos e Interrupciones
 * @return	Nada
 */
void appInit(void) {
    /* TODO: Inicializar Ports/Periféricos/Interrupciones */

    /* Configura funciones analógicas y dirección de los Ports de I/O */
    ANSEL = 0;
    ANSELH = 0;
    TRIS_FUSIBLE = 1;
    TRIS_TRAFO = 1;
    TRIS_TENSION_ALIM = 1;
    TRIS_CI = 1; 
    TRIS_CI2 = 1;
    TRIS_TENSION_REG = 1;
    
    TRIS_LED_FUSIBLE_AB = 0;
    TRIS_LED_FALLA_TRAFO = 0;
    TRIS_LED_FALLA_CI = 0;
    TRIS_LED_TENSION_GEN = 0;
    TRIS_LED_TENSION_REG_INT = 0;
    TRIS_BOTON = 0;
    TRIS_LED_FUN_GENERAL = 0;
    TRIS_BUZZER = 0;
    
    __delay_ms(100); //Espera que se estabilice la fuente
    
    /* TODO: Habilita Interrupciones si es necesario*/
    TMR0IE = 1;     //Habilita interrupcion para tick
    //PEIE = 1;
    GIE = 1;
}

/*==================[fin del archivo]========================================*/
