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
typedef enum{E_00, E_10, E_11, E_01, E_RESET, E_Inicial} estadoMEF_t;

/*==================[definiciones de datos internos]=========================*/
estadoMEF_t  estadoActual; // Variable de estado (global)
tick_t tInicio; 
uint8_t contador;
/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
void InicializarMEF(void);
void ActualizarMEF(void);

/*==================[funcion principal]======================================*/
void main(void) {
    /* TODO: Agregar el Cod1iogo de la Aplicación aquí */
    PIN_LED_V = 0;
    PIN_LED_R = 0;
    PIN_LED_AM = 0;
    PIN_LED_AZ = 0;
    displayWrite(0);
    appInit(); /* Inicializa I/O y Periféricos de la aplicación */
    InicializarMEF();
    while (1) {
        ActualizarMEF();
    }
}

/*==================[definiciones de funciones internas]=====================*/
// Función Inicializa MEF
void InicializarMEF(void) {
    estadoActual = E_11; // Establece estado inicial 
    tInicio = tickRead(); // También inicia temporizacion    
}

// Función Actualizar MEF


void ActualizarMEF(void) {
    switch (estadoActual) {
        case E_Inicial:
            PIN_LED_V = 0;
            PIN_LED_AM = 0;
            PIN_LED_R = 0;
            if(PIN_TEC1 == 0 && PIN_TEC2 == 0)
                estadoActual = E_00;
            if(PIN_TEC1 == 1 && PIN_TEC2 == 0)
                estadoActual = E_10;
            if(PIN_TEC1 == 0 && PIN_TEC2 == 1)
                estadoActual = E_01;
            if(PIN_TEC1 == 1 && PIN_TEC2 == 1)
                estadoActual = E_11;  
        break;                         
        case E_11:
            PIN_LED_R = 0;
            if (PIN_TEC1 == 0 && PIN_TEC2 == 0) {// Chequear condiciones de transición de estado
                estadoActual = E_RESET;
            }
            if (PIN_TEC1 == 0)
                estadoActual = E_01;
            else
                if (PIN_TEC2 == 0)
                estadoActual = E_10;
            break;

        case E_01:
            if (PIN_TEC1 == 1 && PIN_TEC2 == 0) {// Chequear condiciones de transición de estado
                estadoActual = E_RESET; // Cambiar a otro estado
            } else
                if (PIN_TEC1 == 0 && PIN_TEC2 == 0) {
                estadoActual = E_00;
            } else
                if (PIN_TEC1 == 1)
                estadoActual = E_11;
            break;

        case E_00:
            if (PIN_TEC1 == 1 && PIN_TEC2 == 1) {
                estadoActual = E_RESET;
            } else
                if (PIN_TEC1 == 1 && PIN_TEC2 == 0) {

                PIN_LED_V = 1;
                PIN_LED_AM = 0;
                estadoActual = E_10;
                contador++;
                if (contador == 10)
                    contador = 0;
                displayWrite(contador);
            } else
                if (PIN_TEC1 == 0 && PIN_TEC2 == 1) {
                estadoActual = E_01;

            }


            break;

        case E_10:
            if (PIN_TEC1 == 0 && PIN_TEC2 == 1) {// Chequear condiciones de transición de estado
                estadoActual = E_RESET; // Cambiar a otro estado   
            } else
                if (PIN_TEC1 == 0 && PIN_TEC2 == 0) {
                PIN_LED_V = 0;
                PIN_LED_AM = 1;
                estadoActual = E_00;
                if (contador == 0)
                    contador = 10;
                contador--;
                displayWrite(contador);
            } else
                if (PIN_TEC1 == 1 && PIN_TEC2 == 1) {
                estadoActual = E_11;
            }
            break;
        case E_RESET:
            PIN_LED_R = 1; // Chequear condiciones de transición de estado
            PIN_LED_V = 0;
            PIN_LED_AM = 0;
            if(PIN_TEC4 == 0)
                estadoActual = E_Inicial;
            break;

        default:
            //Si algo modificó la variable estadoActual 
            // a un estado no válido llevo la MEF a un 
            // lugar seguro, por ejemplo, la reinicio:
            InicializarMEF();
    }
}


/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
