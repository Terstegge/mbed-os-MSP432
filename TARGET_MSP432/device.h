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

// Defines for compile-time optimization of us_ticker code.
#define US_TICKER_PERIOD_NUM 1
#define US_TICKER_PERIOD_DEN 1
#define US_TICKER_MASK 0xffff

#include "objects.h"
#include "PeripheralPins.h"

