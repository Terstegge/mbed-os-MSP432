/* MSP432 port for the mbed Microcontroller Library
 * Copyright (c) 2020 Andreas Terstegge (Andreas.Terstegge@gmail.com)
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PeripheralPins.h"
#include "PeripheralNames.h"
#include "cmsis.h"

const PinMap PinMap_empty[] = {
    { NC, NC, 0 }
};

/*** ADC ***/
const PinMap PinMap_ADC[] = {
    { A0,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  0) },
    { A1,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  1) },
    { A2,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  2) },
    { A3,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  3) },
    { A4,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  4) },
    { A5,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  5) },
    { A6,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  6) },
    { A7,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  7) },
    { A8,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  8) },
    { A9,  ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone,  9) },
    { A10, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 10) },
    { A11, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 11) },
    { A12, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 12) },
    { A13, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 13) },
    { A14, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 14) },
    { A15, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 15) },
    { A16, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 16) },
    { A17, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 17) },
    { A18, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 18) },
    { A19, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 19) },
    { A20, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 20) },
    { A21, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 21) },
    { A22, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 22) },
    { A23, ADC14_BASE, MSP432_PIN_DATA(SEL3, PIN_INPUT, PullNone, 23) },
    { NC, NC, 0 }
};

const PinMap PinMap_ADC_Internal[] = {
    { NC, NC, 0 }
};

//*** I2C ***
const PinMap PinMap_I2C_SDA[] = {
    { SDA_B0,  EUSCI_B0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { SDA_B1,  EUSCI_B1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { SDA_B2,  EUSCI_B2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { SDA_B3,  EUSCI_B3_BASE, MSP432_PIN_DATA(SEL2, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { SDA_B3_2,EUSCI_B3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { NC, NC, 0 }
};

const PinMap PinMap_I2C_SCL[] = {
    { SCL_B0,  EUSCI_B0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { SCL_B1,  EUSCI_B1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { SCL_B2,  EUSCI_B2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { SCL_B3,  EUSCI_B3_BASE, MSP432_PIN_DATA(SEL2, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { SCL_B3_2,EUSCI_B3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, OpenDrainPullUp, 0) },
    { NC, NC, 0 }
};

//*** SERIAL ***
const PinMap PinMap_UART_TX[] = {
    { TX_A0, EUSCI_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 0) },
    { TX_A1, EUSCI_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 1) },
    { TX_A2, EUSCI_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 2) },
    { TX_A3, EUSCI_A3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 3) },
    { NC, NC, 0 }
};

const PinMap PinMap_UART_RX[] = {
    { RX_A0, EUSCI_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 0) },
    { RX_A1, EUSCI_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 1) },
    { RX_A2, EUSCI_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 2) },
    { RX_A3, EUSCI_A3_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 3) },
    { NC, NC, 0 }
};

//*** SPI ***
const PinMap PinMap_SPI_MOSI[] = {
    { MOSI_A0,  EUSCI_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 0) },
    { MOSI_A1,  EUSCI_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 1) },
    { MOSI_A2,  EUSCI_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 2) },
    { MOSI_A3,  EUSCI_A3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 3) },
    { MOSI_B0,  EUSCI_B0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 4) },
    { MOSI_B1,  EUSCI_B1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 5) },
    { MOSI_B2,  EUSCI_B2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 6) },
    { MOSI_B3,  EUSCI_B3_BASE, MSP432_PIN_DATA(SEL2, PIN_OUTPUT, PullNone, 7) },
    { MOSI_B3_2,EUSCI_B3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 7) },
    { NC, NC, 0 }
};

const PinMap PinMap_SPI_MISO[] = {
    { MISO_A0,  EUSCI_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 0) },
    { MISO_A1,  EUSCI_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 1) },
    { MISO_A2,  EUSCI_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 2) },
    { MISO_A3,  EUSCI_A3_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 3) },
    { MISO_B0,  EUSCI_B0_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 4) },
    { MISO_B1,  EUSCI_B1_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 5) },
    { MISO_B2,  EUSCI_B2_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 6) },
    { MISO_B3,  EUSCI_B3_BASE, MSP432_PIN_DATA(SEL2, PIN_INPUT, PullNone, 7) },
    { MISO_B3_2,EUSCI_B3_BASE, MSP432_PIN_DATA(SEL1, PIN_INPUT, PullNone, 7) },
    { NC, NC, 0 }
};

const PinMap PinMap_SPI_SCLK[] = {
    { SCLK_A0,  EUSCI_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 0) },
    { SCLK_A1,  EUSCI_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 1) },
    { SCLK_A2,  EUSCI_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 2) },
    { SCLK_A3,  EUSCI_A3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 3) },
    { SCLK_B0,  EUSCI_B0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 4) },
    { SCLK_B1,  EUSCI_B1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 5) },
    { SCLK_B2,  EUSCI_B2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 6) },
    { SCLK_B3,  EUSCI_B3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 7) },
    { SCLK_B3_2,EUSCI_B3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 7) },
    { NC, NC, 0 }
};

const PinMap PinMap_SPI_SSEL[] = {
    { SSEL_A0,  EUSCI_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 0) },
    { SSEL_A1,  EUSCI_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 1) },
    { SSEL_A2,  EUSCI_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 2) },
    { SSEL_A3,  EUSCI_A3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 3) },
    { SSEL_B0,  EUSCI_B0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 4) },
    { SSEL_B1,  EUSCI_B1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 5) },
    { SSEL_B2,  EUSCI_B2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 6) },
    { SSEL_B3,  EUSCI_B3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 7) },
    { SSEL_B3_2,EUSCI_B3_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 7) },
    { NC, NC, 0 }
};

const PinMap PinMap_PWM[] = {
    { PWM_A01,  TIMER_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 1) },
    { PWM_A02,  TIMER_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 2) },
    { PWM_A03,  TIMER_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 3) },
    { PWM_A04,  TIMER_A0_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 4) },
    { PWM_A11,  TIMER_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 1) },
    { PWM_A12,  TIMER_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 2) },
    { PWM_A13,  TIMER_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 3) },
    { PWM_A14,  TIMER_A1_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 4) },
    { PWM_A21,  TIMER_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 1) },
    { PWM_A22,  TIMER_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 2) },
    { PWM_A23,  TIMER_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 3) },
    { PWM_A24,  TIMER_A2_BASE, MSP432_PIN_DATA(SEL1, PIN_OUTPUT, PullNone, 4) },
    { NC, NC, 0 }
};

