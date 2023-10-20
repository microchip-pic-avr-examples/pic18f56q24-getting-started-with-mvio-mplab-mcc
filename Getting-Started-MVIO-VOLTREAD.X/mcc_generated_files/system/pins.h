/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB4 aliases
#define RX_TRIS                 TRISBbits.TRISB4
#define RX_LAT                  LATBbits.LATB4
#define RX_PORT                 PORTBbits.RB4
#define RX_WPU                  WPUBbits.WPUB4
#define RX_OD                   ODCONBbits.ODCB4
#define RX_ANS                  ANSELBbits.ANSELB4
#define RX_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RX_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RX_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RX_GetValue()           PORTBbits.RB4
#define RX_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RX_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define RX_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define RX_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define RX_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define RX_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RX_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define TX_TRIS                 TRISBbits.TRISB5
#define TX_LAT                  LATBbits.LATB5
#define TX_PORT                 PORTBbits.RB5
#define TX_WPU                  WPUBbits.WPUB5
#define TX_OD                   ODCONBbits.ODCB5
#define TX_ANS                  ANSELBbits.ANSELB5
#define TX_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define TX_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define TX_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define TX_GetValue()           PORTBbits.RB5
#define TX_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define TX_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define TX_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define TX_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define TX_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define TX_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define TX_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/