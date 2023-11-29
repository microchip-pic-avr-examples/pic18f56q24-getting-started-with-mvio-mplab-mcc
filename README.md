<!-- Please do not change this html logo with link -->

<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Multi-Voltage I/O (MVIO) in Three Different Examples Using PIC18F56Q24 Microcontroller Generated with MCC Melody

<br>The repository contains three MPLAB® X projects:

[1. MVIO Logic](#1-mvio-1-logic) This use case shows how to configure two output pins that provide different output voltage levels: 3.3V for a non-MVIO pin and 5V for an MVIO pin.

[2. MVIO Interrupt](#2-mvio-interrupt) This use case shows how to configure the MVIO interrupts and turn on the on-board LED when the voltage drops below the acceptable thresholds for each interrupt.

[3. MVIO Read Voltage](#3-mvio-read-voltage) This use case shows how to measure the voltage on V<sub>DDIO2</sub> with the Analog-to-Digital Converter (ADC), and then print it using the Universal Asynchronous Receiver Transceiver (UART) module.

## Related Documentation

More details and code examples on the PIC18F56Q24 can be found at the following links:

- [PIC18F56Q24 Product Page](https://www.microchip.com/wwwproducts/en/PIC18F56Q24)
- [PIC18F56Q24 Code Examples on GitHub](https://github.com/microchip-pic-PIC-examples?q=PIC18F56Q24)


## Software Used

- [MPLAB® X IDE](http://www.microchip.com/mplab/mplab-x-ide) v6.15 or newer
- [MPLAB® XC8](http://www.microchip.com/mplab/compilers) v2.45 or newer
- [PIC18F-Q_DFP Series Device Pack](https://packs.download.microchip.com) v1.23.425 or newer
- [MPLAB® Code Configurator](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator) 5.3.7 or newer
- [MPLAB® Code Configurator Melody](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator/melody) core 2.6.2 or newer


## Hardware Used

- The PIC18F56Q24 Curiosity Nano Development Board was used as the test platform for this example.

<img src="images/56Q24-Board.png" width = "600"><br>

## Prerequisites

For MVIO to work together with the Curiosity Nano board, disconnect the R201 resistor connecting V<sub>DDIO2</sub> to VCC_TARGET.

<img src="images/56Q24-MVIO-BOARD.png" width = "300"><br>

A power supply must be connected to the V<sub>DDIO2</sub> pin. There are two possible use cases:
<br />
**a.** Connecting an external DC power supply to the V<sub>DDIO2</sub> pin and GND.
<br />
**b.** Using Curiosity Nano, use V<sub>BUS</sub> as power supply, simply by connecting a wire between V<sub>BUS</sub> and V<sub>DDIO2</sub>.

## Initial Setup

The following configurations are used for each lab in this example.

<br><img src="images/CLOCK-CONFIG.png">

  - Clock Source: HFINTOSC
  - Internal Clock: 4 MHz
  - Clock Divider: 1

<br><img src="images/CONFIG1.png">

  - External Oscillator: Disabled
  - Reset Oscillator: 4 MHz

## Operation

To program the Curiosity Nano board with this MPLAB X project, follow the steps provided in the [How to Program the Curiosity Nano board](#how-to-program-the-curiosity-nano-board) section of this code example.


## 1. MVIO Logic Level Demonstration

This lab demonstrates the functionality of the Multi-Voltage I/O (MVIO) pins on the PIC18-Q24 device family. In this example two pins are configured as outputs; one using an MVIO pin on the  V<sub>DDIO2</sub> voltage domain and the other on a standard non-MVIO pin on the V<sub>DD</sub> domain. Both pins are driven high to a logic `1` in order to demonstrate how the output levels differ between the two voltage domains.

**Note**: For this example, V<sub>DDIO2</sub> is connected to V<sub>BUS</sub> on the PIC Curiosity Nano board.

When using a voltmeter, it can be observed in this lab that the microcontroller is generating 3.3V on the non-MVIO pin and 5V on the MVIO pin. The voltage values that represent a logic `1` differ between the MVIO and non-MVIO pins in this example, since each voltage domain is being supplied with 5V and 3.3V respectively. The MVIO module offers increased flexibility on the PIC18-Q24 Device family, allowing for communication with sensors/MPUs/SoCs and other components that operate a different voltage levels, without needing external components such as level shifters or translators.

### 1.1 Setup

|Pin                       | Configuration      |
|   ---------------------  |   ---------------- |
| RB4 - non-MVIO           | Digital Output     |
| RC4 - MVIO               | Digital Output     |

### 1.2 Demo

<br><img src="images/LOGIC.gif">

The animation above demonstrates how the output voltage levels on the MVIO and non-MVIO pins differ, and are scaled according to the voltage provided to each of the supply pins. Since in his example 3.3V is applied to the V<sub>DD</sub> pin and 5V is applied to the V<sub>DDIO2</sub> pin, the pins on each respective voltage domain generate an output that corresponds with the voltage supplied to V<sub>DD</sub> and V<sub>DDIO2</sub>.

For this demonstration to work properly the user must:

- Have a voltage source plugged into V<sub>DDIO2</sub>.
- Have outputs set, for a pin on V<sub>DD</sub>, and one on V<sub>DDIO2</sub>.


### 1.3 Summary

This example demonstrates the differences and key new feature of MVIO module. By configuring two pins on different voltage domains (V<sub>DD</sub>, and V<sub>DDIO2</sub>) we are able to operate sets of pins based on two different voltage sources on the same device. The V<sub>DD</sub> voltage supplied was 3.3V and the V<sub>DDIO2</sub>) voltage supplied in this example was 5.0V. Once these voltages were applied, the logic levels for each of the voltage domains correlated with the voltage supplied to each respective source.<br><br>

[Back to top](#multi-voltage-input--output-mvio-in-three-different-examples-using-PIC18F56Q24-microcontroller-generated-with-mcc-melody)<br>

## 2. MVIO Interrupt

This lab demonstrates the functionality of the **MVIO VDDIOx Ready Interrupt Flag** (`VDDIOxnRDYIF`) and the **VDDIOx Low-Voltage Detect Interrupt Flag** (`VDDIOxLVDIF`)

**Note**:
- The **VDDIOx Ready Interrupt Flag** (`VDDIOxnRDYIF`) is active low on the PIC18-Q24 device family. This interrupt flag will be set in hardware when the respective V<sub>DDIOx</sub> voltage domain is NOT ready, and it will be cleared in hardware when the voltage domain is ready to use. The **VDDIOx Low Voltage Detect Interrupt Flag** (`VDDIOxLVDIF`) has normal polarity, and this interrupt flag will be set in hardware when the respective V<sub>DDIOx</sub> supply voltage drops below the configured LVD threshold, and it will be cleared in hardware when the supply voltage is rises above the selected LVD threshold.
- V<sub>DDIO2</sub> is connected to an external and adjustable power supply in the portion of this lab demonstrating the `VDDIOxLVDIF`, but is connected to V<sub>BUS</sub> in the part of this lab demonstrating the functionality of `VDDIOxnRDYIF`.

The MVIO module interrupts on the PIC18-Q24 device family are level triggered, rather than the typical edge triggered interrupts. It should be noted that these interrupt flags will continuously be set as long as the event causing the interrupt continues to occur. To avoid an ISR loop it is recommended to disable the interrupts after the interrupt flag initially gets set, and then monitor the corresponding status bits to determine when the MVIO supply has been restored. The status bits are `VDDIO2CONbits.RDY` and `VDDIO2CONbits.LVDSTAT`.

### 2.1 Setup

|Pin                       | Configuration      |
| :---------------------:  | :----------------: |
| RF2 (LED pin)            | Digital output     |


This example requires the interrupts to be enabled, which can be done in user firmware.

### Code
To implement this example in firmware, an Interrupt Service Routine (ISR) and Interrupt manager were added. The following code examples are used to demonstrate the **VDDIOx Ready Interrupt flag**, but can be be modified to demonstrate the **VDDIOx Low-Voltage Detect Interrupt Flag** as well. Refer to the MPLABX project for the specific implementation for each lab in this example.

```
static void MVIO_ISR(void)
{                  
  /* Turn on LED0 to indicate VDDIO2 is below voltage */
  LATFbits.LATF2 = 0;   
}
```

```
  void __interrupt() INTERRUPT_InterruptManager (void)
  {
    /* Check if MVIO_RDY interrupt is enabled and if the interrupt flag is set */
    if(PIE11bits.VDDIO2nRDYIE == 1 && PIR11bits.VDDIO2nRDYIF == 1)

    {
        PIR11bits.VDDIO2nRDYIF = 0;
        MVIO_ISR();
    }
  }
```

### 2.2 Demo

## VDDIOx Ready Interrupt

| Interrupt Demo | Expected Plot|
|----------|-----------|
|<br><img src="images/INTERRUPT.gif" width = "600">|<br><img src="images/RDY PLOT.png" width = "600">|

<br> This animation demonstrates how `VDDIO2nRDYIF` works on the PIC18-Q24 device family by applying the V<sub>BUS</sub> voltage to the V<sub>DDIO2</sub> supply pin. Upon initial programming of the device for this example, the `VDDIO2nRDYIF` interrupt flag will be set high to signify the MVIO is not ready since V<sub>BUS</sub> has not yet been connected to the V<sub>DDIO2</sub> supply pin. Once V<sub>BUS</sub> gets connected to the V<sub>DDIO2</sub> supply pin using a jumper wire, the `VDDIO2nRDYIF` interrupt flag will be cleared in hardware indicating that V<sub>DDIO2</sub> has met or exceeded the minimum required operating voltage for MVIO to function. Refer to the electrical specifications of the device datasheet for more information about the minimum voltage requirements of the MVIO module.  

<br> In this demonstration the interrupt service routine turns the on board LED on until the V<sub>DDIO2</sub> voltage domain is ready.

## VDDIOx Low-Voltage Detect Interrupt

| Interrupt Demo | Expected Plot|
|----------|-----------|
|<br><img src="images/LVD INT.gif" width = "600">|<br><img src="images/LVD PLOT.png" width = "600">|

<br> This annimation demonstrates how the `VDDIO2LVDIF` works on the PIC18-Q24 device family by manipulating the voltage applied to the V<sub>DDIO2</sub> supply pin in order to trigger a Low-Voltage detect interrupt. On the PIC18-Q24 device family, in order to use the `VDDIO2LVDIF` Interrupt Flag, the respective interrupt enable bit must be set and the `LVD` bits of the  `VDDIO2CON` register must be configured to select from the available Low-Voltage Detect trip points. If the `LVD` selection bist are left in their default state of `0b0000`, the LVD detection circuitry of the MVIO module will be disabled and the respective interrupt flag will not work. For this example, `LVD` bits of the  `VDDIO2CON` register were programmed to select an LVD trip point of 2.2V. Once V<sub>DDIO2</sub> supply voltage drops below 2.2V, the `VDDIO2LVDIF` interrupt flag will be set.

<br> The interrupt service routine in this demonstration turns the LED off when the `VDDIO2LVDIF` interrupt flag gets set.

### 2.3 Summary

This lab demonstrates the demonstrates the functionality of the V<sub>DDIOx</sub> Low-Voltage Detect interrupt, and turns on an LED using an ISR when the respective V<sub>DDIOx</sub> supply voltage drops below the configured LVD trip point of 2.2V. Refer to the electrical specifications of the device datasheet to see all of the available LVD trip points. <br><br>
[Back to top](#multi-voltage-input--output-mvio-in-three-different-examples-using-PIC18F56Q24-microcontroller-generated-with-mcc-melody)<br>

## 3. MVIO Voltage Measurement

This lab demonstrates how to measure the V<sub>DDIO2</sub> supply voltage on the PIC18-Q24 device family using a dedicated internal ADC channel. It is entirely possible that there are applications where the available ADC reference voltages are lower than the MVIO supply voltage being measured, and in order to handle such cases the ADC channel provided for the MVIO module is divided down by 10 (V<sub>DDIO2</sub>/10).

**Note**: A power supply must be connected to the V<sub>DDIO2</sub> pin. There are two possible use cases:
- Connecting an external DC power supply to the V<sub>DDIO2</sub> pin and GND.
- Using Curiosity Nano, use V<sub>BUS</sub> as power supply, simply by connecting a jumper wire between V<sub>BUS</sub> and V<sub>DDIO2</sub>.

In this example, a DC power supply was used to provide power to the V<sub>DDIO2</sub> supply pin. The program will measure the voltage from the DC power supply using the dedicated V<sub>DDIO2</sub>/10 ADC input channel, and then convert and display it using the UART module every 500ms.

## 3.1 Setup

<br><img src="images/ADC-CONFIG.png">

  - Basic Mode
  - Right Alignment
  - Positive Input Channel: VDDIO2_by_10
  - Clock Source: ADCRC



<br><img src="images/uart2_plib_config.png">

 - UART dependency: UART 2

<br><img src="images/uart2_config.png">

  - Enable Redirect to Printf is enabled for only one UART driver.


|Pin                       | Configuration      |
| :---------------------:  | :----------------: |
| RB5 (UART2 TX)          | Digital Output     |


### 3.2 Demo

<br><img src="images/ADC-READ.png" width = "800">

The figure above shows the messages received from the board during normal operation.

### 3.3 Summary

This example shows how to measure the V<sub>DDIO2</sub> supply voltage, and then sends the results to a PC via UART for display. <br><br>
[Back to top](#multi-voltage-input--output-mvio-in-three-different-examples-using-PIC18F56Q24-microcontroller-generated-with-mcc-melody)<br>

## How to Program the Curiosity Nano board

This chapter shows how to use the MPLAB® X IDE to program an PIC® device with an Example_Project.X. This can be applied for any other projects.

- Connect the board to the PC.

- Open the Example_Project.X project in MPLAB X IDE.

- Set the Example_Project.X project as main project.

  - Right click on the project in the **Projects** tab and click **Set as Main Project**.
    <br><img src="images/SET-AS-MAIN.png" width="300">

- Clean and build the Example_Project.X project.

  - Right click on the **Example_Project.X** project and select **Clean and Build**.
    <br><img src="images/CLEAN-AND-BUILD.png" width="300">

- Select the **PICxxxxx Curiosity Nano** in the Connected Hardware Tool section of the project settings:

  - Right click on the project and click **Properties**
  - Click on the arrow under the Connected Hardware Tool
  - Select the **PICxxxxx Curiosity Nano** (click on the **SN**), click **Apply** and then click **OK**:
    <br><img src="images/TOOL-AND-COMPILER.png" width="600">

- Program the project to the board.
  - Right click on the project and click **Make and Program Device**.
    <br><img src="images/MAKE AND PROGRAM.png" width="600">

- - -

- [Back to 1. MVIO 1 Logic](#1-mvio-1-logic)
- [Back to 2. MVIO Interrupt](#2-mvio-interrupt)
- [Back to 3. MVIO Read Voltage](#3-mvio-read-voltage)
- [Back to top](#multi-voltage-input--output-mvio-in-three-different-examples-using-PIC18F56Q24-microcontroller-generated-with-mcc-melody)

- - -
