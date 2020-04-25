/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef MBED_TEST_MODE
#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE_MS     500

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE_MS);
    }
}
#endif /* MBED_TEST_MODE */
