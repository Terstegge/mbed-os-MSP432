/* mbed Microcontroller Library
 * MSP432 Blinky example
 * Copyright (c) 2020 A. Terstegge
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef MBED_TEST_MODE
#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE_MS 500
// P2.0/P2.1/P2.2 is the RGB LED
#define RGB_MASK         0x7

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    PortOut    rgb(Port2, RGB_MASK);

    printf("Hello World!\n");
    int i=0;       
    while (true) {
        led = !led;
        printf("Writing %d to Port2\n", i);
        rgb = i++;
        ThisThread::sleep_for(BLINKING_RATE_MS);
    }
}
#endif /* MBED_TEST_MODE */
