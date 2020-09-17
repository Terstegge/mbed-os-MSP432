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

#ifndef MBED_CMSIS_H
#define MBED_CMSIS_H

// Undef DIR_H because of name clash:
// DIR_H is defined in the MSP432 header file
// as well as in Dir.cpp
#undef DIR_H

#include "msp.h"

// Undef CS because of name clash:
// CS is defined in the MSP432 header file
// as well as in NanostackRfPhyAT86RF215.cpp
#undef CS

#endif
