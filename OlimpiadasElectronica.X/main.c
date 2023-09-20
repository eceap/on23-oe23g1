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

typedef enum {
    E_BuscandoError, E_FallaFusible, E_FallaTrafo, E_FallaCI,
    E_Tension_RegInt, E_TensionAlimGen, E_FallaGeneral, E_Inicial, E_Buzzer
} estadoMEF_t;
/*==================[definiciones de datos internos]=========================*/
estadoMEF_t estadoActual; // Variable de estado (global)
tick_t tInicio;
uint8_t contador;


/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
void InicializarMEF(void);
void ActualizarMEF(void);

/*==================[funcion principal]======================================*/
void main(void) {
    InicializarMEF();
    appInit(); /* Inicializa I/O y Periféricos de la aplicación */
    while (1) {
        ActualizarMEF();
        PIN_LED_FUSIBLE_AB = 0;
        PIN_LED_FALLA_TRAFO = 0;
        PIN_LED_FALLA_CI = 0;
        PIN_LED_TENSION_GEN = 0;
        PIN_LED_TENSION_REG_INT = 0;
        PIN_LED_FUN_GENERAL = 1;
        PIN_BOTON = 0;
        PIN_BUZZER = 0;
    }

}

/*==================[definiciones de funciones internas]=====================*/
void ActualizarMEF(void) {
    switch (estadoActual) {
        case E_BuscandoError:
            if (PIN_FUSIBLE == 0)
                estadoActual = E_FallaFusible;//listo//
            if (PIN_TENSION_ALIM == 0)
                estadoActual = E_TensionAlimGen;//listo//
            if (PIN_TENSION_REG == 0)
                estadoActual = E_Tension_RegInt;////
            if (PIN_CI = 0 && PIN_CI2 = 0)
                estadoActual = E_FallaCI;
            if (PIN_CI = 1 && PIN_CI2 = 1)
                estadoActual = E_FallaCI;
            if (PIN_TRAFO == 0)
                estadoActual = E_FallaTrafo;
            if(PIN_FUSIBLE == 0 && PIN_TENSION_ALIM == 0 && PIN_TENSION_REG == 0
                PIN_CI == 0 && PIN_CI2 == 0 && PIN_TRAFO == 0)
                estadoActual = E_FallaGeneral;
            
            break;


        
        case E_FallaFusible:
                PIN_LED_FUSIBLE_AB = 1;
                PIN_LED_FUN_GENERAL = 0;
                estadoActual = E_Buzzer;
                if (PIN_FUSIBLE == 1)
                estadoActual = E_BuscandoError;
            break;
        
        case E_FallaTrafo:
                PIN_LED_FUN_GENERAL = 0;    
                PIN_LED_FALLA_TRAFO = 1;
                estadoActual = E_Buzzer;
            if (PIN_TRAFO == 1)
                estadoActual = E_BuscandoError;
            break;
        
        case E_Tension_RegInt:   
                PIN_LED_FUN_GENERAL = 0;
                PIN_LED_TENSION_REG_INT = 1;
                estadoActual = E_Buzzer;
 
            if (PIN_TENSION_REG == 1)
                estadoActual = E_BuscandoError;
            break;
        
        case E_FallaCI:   
                PIN_LED_FALLA_CI = 1;
                PIN_LED_FUN_GENERAL = 0;
                estadoActual = E_Buzzer;
            if (PIN_TENSION_REG == 1)
                estadoActual = E_BuscandoError;
            break;
            
        case E_TensionAlimGen:
            PIN_LED_TENSION_GEN = 1;
            PIN_LED_FUN_GENERAL = 0;
            estadoActual = E_Buzzer;
           if(PIN_TENSION_ALIM = 1)
               estadoActual = E_BuscandoError;
            break;
            
        case E_FallaGeneral:
            PIN_LED_FUN_GENERAL = 0;
            estadoActual = E_Buzzer;
            break;
        
        
        
        
        
        
        
        
        
        case E_Buzzer:
            PIN_BUZZER = 1;
            if (PIN_BOTON == 0)
                PIN_BUZZER = 0;
            break;
    }
}

    /*==================[fin del archivo]========================================*/
