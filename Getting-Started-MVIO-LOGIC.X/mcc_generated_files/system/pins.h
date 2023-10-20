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
� [2023] Microchip Technology Inc. and its subsidiaries.

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
#define MVIO1_TRIS                 TRISBbits.TRISB4
#define MVIO1_LAT                  LATBbits.LATB4
#define MVIO1_PORT                 PORTBbits.RB4
#define MVIO1_WPU                  WPUBbits.WPUB4
#define MVIO1_OD                   ODCONBbits.ODCB4
#define MVIO1_ANS                  ANSELBbits.ANSELB4
#define MVIO1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define MVIO1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define MVIO1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define MVIO1_GetValue()           PORTBbits.RB4
#define MVIO1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define MVIO1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define MVIO1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define MVIO1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define MVIO1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define MVIO1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define MVIO1_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define MVIO1_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC4 aliases
#define MVIO2_TRIS                 TRISCbits.TRISC4
#define MVIO2_LAT                  LATCbits.LATC4
#define MVIO2_PORT                 PORTCbits.RC4
#define MVIO2_WPU                  WPUCbits.WPUC4
#define MVIO2_OD                   ODCONCbits.ODCC4
#define MVIO2_ANS                  ANSELCbits.
#define MVIO2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define MVIO2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define MVIO2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define MVIO2_GetValue()           PORTCbits.RC4
#define MVIO2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define MVIO2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define MVIO2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define MVIO2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define MVIO2_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define MVIO2_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define MVIO2_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define MVIO2_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

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