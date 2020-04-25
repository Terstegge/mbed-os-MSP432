/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
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

#ifndef SYSTEM_MSP432P401R_H
#define SYSTEM_MSP432P401R_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// global clock variables
extern uint32_t SystemCoreClock;      // MCLK in Hz
extern uint32_t SubsystemMasterClock; // SMCLK in Hz

// CMSIS standard methods for system init and master clock update
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
extern uint32_t calculate_DCO_clock(uint32_t dco_base_clock);

#ifdef __cplusplus
}
#endif

#endif // SYSTEM_MSP432P401R_H
