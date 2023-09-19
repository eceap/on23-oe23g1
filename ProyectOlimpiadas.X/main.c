/*============================================================================
 * Licencia:
 * Autor:
 * Fecha:
 *===========================================================================*/

/*==================[inclusiones]============================================*/
#include <xc.h>         /* Archivo de Encabezados General XC8 */
#include <stdint.h>     /* Para definicines de tipos estandar */

/*==================[definiciones y macros]==================================*/
/* TODO Define system operating frequency */
/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        4000000L
#define _XTAL_FREQ      SYS_FREQ
#define FCY             SYS_FREQ/4

/* Definición de Bits de Configuración */
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
//#pragma config FOSC = INTRC_NOCLKOUT // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3/PGM pin io, low voltage programming disabled)
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// Definición de entradas y salidas
#define PIN_LED1    PORTEbits.RE2
#define TRIS_LED1   TRISEbits.TRISE2

#define PIN_LED2    PORTEbits.RE1
#define TRIS_LED2   TRISEbits.TRISE1

#define PIN_LED3    PORTEbits.RE0
#define TRIS_LED3   TRISEbits.TRISE0

#define PIN_LED4    PORTAbits.RA5
#define TRIS_LED4   TRISAbits.TRISA5

#define PIN_buzzer    PORTCbits.RC0
#define TRIS_buzzer   TRISCbits.TRISC0

#define PIN_display   PORTD
#define TRIS_display  TRISD
 
// TODO: Completar el resto de las salidas

#define PIN_TEC1    PORTBbits.RB0
#define TRIS_TEC1   TRISBbits.TRISB0

#define PIN_TEC2    PORTBbits.RB1
#define TRIS_TEC2   TRISBbits.TRISB1

#define PIN_TEC3    PORTBbits.RB2
#define TRIS_TEC3   TRISBbits.TRISB2

#define PIN_TEC4    PORTBbits.RB3
#define TRIS_TEC4   TRISBbits.TRISB3

#define PIN_POT     PORTAbits.RA0
#define TRIS_POT    TRISAbits.TRISA0

// TODO: Completar el resto de las entradas

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[funcion principal]======================================*/
void main(void) {
    // Configuración de IO
    ANSEL = 0;                  // Configura todos las pines
    ANSELH = 0;                 //   como digitales
    TRIS_TEC1 = 1;              // Configuro la TEC1 como entrada
    TRIS_LED1 = 0;              // Configuro el LED1 como salida
    TRIS_TEC2 = 1;              // Configuro la TEC1 como entrada
    TRIS_LED2 = 0;              // Configuro el LED1 como salida
    TRIS_TEC3 = 1;              // Configuro la TEC1 como entrada
    TRIS_LED3 = 0;              // Configuro el LED1 como salida
    TRIS_TEC4 = 1;              // Configuro la TEC1 como entrada
    TRIS_LED4 = 0;              // Configuro el LED1 como salida
    TRIS_buzzer= 0;
    TRIS_POT = 1 ;
    TRIS_display = 0 ;
    
    PIN_buzzer = 0;
    PIN_display = 0;
    // TODO: Completar el resto de la configuración
    //...
    int i;
    for(i=0;i<1000;i++){
        PIN_buzzer = 1;
        __delay_us(250);
            PIN_buzzer = 0;
        __delay_us(250);
    }
    while(1) {
       
        
        
        
        
        
        
        
        
        }
    }

    // TODO: Completar Super loop
		//...
    


/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/