/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/
/** @file
 * @brief	Contiene macros y definiciones de user
 * 
 * Aquí se definen macros, tipos de datos y se declaran las funciones y datos 
 * externos de user
 */
#ifndef USER_H
#define USER_H
/*==================[inclusiones]============================================*/
#include <stdint.h>     /* para las definiciones de uint8_t por ej.*/

/*==================[macros]=================================================*/
/* User Level #define Macros                                                 */
/* TODO: Los parámetros de user.c pueden ponerse aquí */
    
//Teclas
#define	TRIS_FUSIBLE                    TRISAbits.TRISA0
#define	PIN_FUSIBLE                     PORTAbits.RA0
#define	TRIS_TRAFO                      TRISAbits.TRISA1
#define	PIN_TRAFO                       PORTAbits.RA1
#define	TRIS_TENSION_ALIM               TRISAbits.TRISA2
#define	PIN_TENSION_ALIM                PORTAbits.RA2
#define	TRIS_CI                         TRISAbits.TRISA3
#define	PIN_CI                          PORTAbits.RA3
#define	TRIS_CI2                        TRISAbits.TRISA4
#define	PIN_CI2                         PORTAbits.RA4
#define	TRIS_TENSION_REG                TRISAbits.TRISA5
#define	PIN_TENSION_REG                 PORTAbits.RA5



//Leds
#define	TRIS_LED_FUSIBLE_AB             TRISCbits.TRISC0
#define	PIN_LED_FUSIBLE_AB              PORTCbits.RC0
#define	TRIS_LED_FALLA_TRAFO            TRISCbits.TRISC1
#define	PIN_LED_FALLA_TRAFO             PORTCbits.RC1
#define	TRIS_LED_FALLA_CI               TRISCbits.TRISC2
#define	PIN_LED_FALLA_CI                PORTCbits.RC2
#define	TRIS_LED_TENSION_GEN            TRISCbits.TRISC3
#define	PIN_LED_TENSION_GEN             PORTCbits.RC3
#define	TRIS_LED_TENSION_REG_INT        TRISCbits.TRISC4
#define	PIN_LED_TENSION_REG_INT         PORTCbits.RC4 
#define	TRIS_BOTON                      TRISCbits.TRISC5
#define	PIN_BOTON                       PORTCbits.RC5
#define	TRIS_LED_FUN_GENERAL            TRISCbits.TRISC7
#define	PIN_LED_FUN_GENERAL             PORTCbits.RC7
//Buzzer
#define	TRIS_BUZZER                     TRISCbits.TRISC6
#define	PIN_BUZZER                       PORTCbits.RC6



/*==================[tipos de datos declarados por el usuario]===============*/

/*==================[declaraciones de datos externos]========================*/
//extern char datoUser; //Ejemplo

/*==================[declaraciones de funciones externas]====================*/
/* TODO: Los prototipos de User level (ej. InitApp) van aquí */
void appInit(void);     /* Inicializa las I/O y los periféricos */
void delayTMR0mSeg(uint16_t tmsegs); /* Demora una cantidad de mSegs basado en desbordes de TMR0 */

/*==================[fin del archivo]========================================*/
#endif// USER_H
