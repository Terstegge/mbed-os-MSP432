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

#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Macros to extract port/pin index from the PinName
 * MSP432_PORT returns values 0...9, corresponing to P1...P10
 * MSP432_PIN  returns values 0...7, corresponing to pin index
 */
#define MSP432_PORT_IDX(pin) (((uint32_t)pin & 0xF0) >> 4)
#define MSP432_PIN_IDX(pin)   ((uint32_t)pin & 0x0F)

/*
 * The following defines are used by user applications.
 * Since PinDirection and PinMode are not part of the
 * mbed-os interface for GPIOs, care must be taken that
 * the standard names (e.g. PIN_INPUT) are used so that
 * cross-platform compatibility of source code is kept!
 */

typedef enum {
    PIN_INPUT  = 0,
    PIN_OUTPUT = 1
} PinDirection;

typedef enum {
    PullNone,
    PullUp,
    PullDown,
    OpenDrain,
    OpenDrainPullUp,
    OpenSource,
    OpenSourcePullDown,
    // Alias names
    PullDefault      = PullNone,
    OpenDrainNoPull  = OpenDrain,
    OpenSourceNoPull = OpenSource
} PinMode;

typedef enum {
    P1_0  = 0x00,
    P1_1  = 0x01,
    P1_2  = 0x02,
    P1_3  = 0x03,
    P1_4  = 0x04,
    P1_5  = 0x05,
    P1_6  = 0x06,
    P1_7  = 0x07,
    P2_0  = 0x10,
    P2_1  = 0x11,
    P2_2  = 0x12,
    P2_3  = 0x13,
    P2_4  = 0x14,
    P2_5  = 0x15,
    P2_6  = 0x16,
    P2_7  = 0x17,
    P3_0  = 0x20,
    P3_1  = 0x21,
    P3_2  = 0x22,
    P3_3  = 0x23,
    P3_4  = 0x24,
    P3_5  = 0x25,
    P3_6  = 0x26,
    P3_7  = 0x27,
    P4_0  = 0x30,
    P4_1  = 0x31,
    P4_2  = 0x32,
    P4_3  = 0x33,
    P4_4  = 0x34,
    P4_5  = 0x35,
    P4_6  = 0x36,
    P4_7  = 0x37,
    P5_0  = 0x40,
    P5_1  = 0x41,
    P5_2  = 0x42,
    P5_3  = 0x43,
    P5_4  = 0x44,
    P5_5  = 0x45,
    P5_6  = 0x46,
    P5_7  = 0x47,
    P6_0  = 0x50,
    P6_1  = 0x51,
    P6_2  = 0x52,
    P6_3  = 0x53,
    P6_4  = 0x54,
    P6_5  = 0x55,
    P6_6  = 0x56,
    P6_7  = 0x57,
    P7_0  = 0x60,
    P7_1  = 0x61,
    P7_2  = 0x62,
    P7_3  = 0x63,
    P7_4  = 0x64,
    P7_5  = 0x65,
    P7_6  = 0x66,
    P7_7  = 0x67,
    P8_0  = 0x70,
    P8_1  = 0x71,
    P8_2  = 0x72,
    P8_3  = 0x73,
    P8_4  = 0x74,
    P8_5  = 0x75,
    P8_6  = 0x76,
    P8_7  = 0x77,
    P9_0  = 0x80,
    P9_1  = 0x81,
    P9_2  = 0x82,
    P9_3  = 0x83,
    P9_4  = 0x84,
    P9_5  = 0x85,
    P9_6  = 0x86,
    P9_7  = 0x87,
    P10_0 = 0x90,
    P10_1 = 0x91,
    P10_2 = 0x92,
    P10_3 = 0x93,
    P10_4 = 0x94,
    P10_5 = 0x95,

    /*** ADC ***/
    A0  = P5_5,
    A1  = P5_4,
    A2  = P5_3,
    A3  = P5_2,
    A4  = P5_1,
    A5  = P5_0,
    A6  = P4_7,
    A7  = P4_6,
    A8  = P4_5,
    A9  = P4_4,
    A10 = P4_3,
    A11 = P4_2,
    A12 = P4_1,
    A13 = P4_0,
    A14 = P6_1,
    A15 = P6_0,
    A16 = P9_1,
    A17 = P9_0,
    A18 = P8_7,
    A19 = P8_6,
    A20 = P8_5,
    A21 = P8_4,
    A22 = P8_3,
    A23 = P8_2,

    /*** I2C ***/
    SDA_B0 = P1_6,
    SDA_B1 = P6_4,
    SDA_B2 = P3_6,
    SDA_B3 = P6_6,
    SDA_B3_2 = P10_2,

    SCL_B0 = P1_7,
    SCL_B1 = P6_5,
    SCL_B2 = P3_7,
    SCL_B3 = P6_7,
    SCL_B3_2 = P10_3,

    /*** SERIAL ***/
    TX_A0 = P1_3,
    TX_A1 = P2_3,
    TX_A2 = P3_3,
    TX_A3 = P9_7,

    RX_A0 = P1_2,
    RX_A1 = P2_2,
    RX_A2 = P3_2,
    RX_A3 = P9_6,

    /*** SPI ***/
    MOSI_A0 = P1_3,
    MOSI_A1 = P2_3,
    MOSI_A2 = P3_3,
    MOSI_A3 = P9_7,
    MOSI_B0 = P1_6,
    MOSI_B1 = P6_4,
    MOSI_B2 = P3_6,
    MOSI_B3 = P6_6,
    MOSI_B3_2 = P10_2,

    MISO_A0 = P1_2,
    MISO_A1 = P2_2,
    MISO_A2 = P3_2,
    MISO_A3 = P9_6,
    MISO_B0 = P1_7,
    MISO_B1 = P6_5,
    MISO_B2 = P3_7,
    MISO_B3 = P6_7,
    MISO_B3_2 = P10_3,

    SCLK_A0 = P1_1,
    SCLK_A1 = P2_1,
    SCLK_A2 = P3_1,
    SCLK_A3 = P9_5,
    SCLK_B0 = P1_5,
    SCLK_B1 = P6_3,
    SCLK_B2 = P3_5,
    SCLK_B3 = P8_1,
    SCLK_B3_2 = P10_1,

    SSEL_A0 = P1_0,
    SSEL_A1 = P2_0,
    SSEL_A2 = P3_0,
    SSEL_A3 = P9_4,
    SSEL_B0 = P1_4,
    SSEL_B1 = P6_2,
    SSEL_B2 = P3_4,
    SSEL_B3 = P8_0,
    SSEL_B3_2 = P10_0,

    PWM_A01 = P2_4,
    PWM_A02 = P2_5,
    PWM_A03 = P2_6,
    PWM_A04 = P2_7,
    PWM_A11 = P7_7,
    PWM_A12 = P7_6,
    PWM_A13 = P7_5,
    PWM_A14 = P7_4,
    PWM_A21 = P5_6,
    PWM_A22 = P5_7,
    PWM_A23 = P6_6,
    PWM_A24 = P6_7,

    // Not connected
    NC = (int)0xFFFFFFFF,

#include "BoardPinNames.h"

} PinName;

#ifdef __cplusplus
}
#endif

#endif
