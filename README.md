# MSP432 launchpad support for Mbed OS 6 (unreleased)

This project demonstrates how to use the
[MSP432 Launchpad](https://www.ti.com/tool/MSP-EXP432P401R)
with the upcoming version of Mbed OS 6 (unreleased at this time).
It uses the custom board support based on
Mbed OS to compile and run a simple Blinky
application, which will output some text
via the backchannel UART and blink the RGB
LED on the MSP432 launchpad.

### Import Project

```
mbed import https://github.com/Terstegge/mbed-os-MSP432.git
cd mbed-os-MSP432
```

### Compile Project

When using Mbed CLI, you first have to set the path to the ARM compiler:
```
mbed config GCC_ARM_PATH <em>\<path to ARM GCC binary folder\></em>
```
e.g.
```
mbed config GCC_ARM_PATH /usr/local/gcc-arm-none-eabi-9-2019-q4-major/bin
```

Compile the project by typing
```
mbed compile -t GCC_ARM -m MSP432_LAUNCHPAD
```
or simply
```
mbed compile
```
because the TOOLCHAIN and TARGET configurations are already set int
the `.mbed` configuration file.


board for the upcoming version of Mbed OS 6 (unreleased at this time).

It shows how to compile and run a simple Blinky application.
The project uses the custom board support based on Mbed OS.

The main application (main.cpp) is a simple Blinky example.

This project makes uses of the full Mbed OS with RTOS included.
It's possible to make changes in the configuration to support the
Baremetal profile and reduce memory requirements - see
[this](https://os.mbed.com/docs/mbed-os/v5.15/reference/mbed-os-bare-metal.html).

### Import and compile

```
mbed import https://github.com/Terstegge/mbed-os-MSP432.git
cd mbed-os-MSP432
mbed compile -t GCC_ARM -m MSP432_LAUNCHPAD

...

Link: mbed-os-MSP432
Elf2Bin: mbed-os-MSP432
| Module                           |     .text |    .data |     .bss |
|----------------------------------|-----------|----------|----------|
| TARGET_MSP432/PeripheralPins.o   |     0(+0) |    0(+0) |    0(+0) |
| TARGET_MSP432/TARGET_MSP432P401R |  1134(+0) |    8(+0) |    8(+0) |
| TARGET_MSP432/gpio_api.o         |   298(+0) |    0(+0) |    0(+0) |
| TARGET_MSP432/gpio_irq_api.o     |   256(+0) |    0(+0) |  244(+0) |
| TARGET_MSP432/gpio_msp432.o      |     0(+0) |   40(+0) |    0(+0) |
| TARGET_MSP432/i2c_api.o          |   220(+0) |    0(+0) |   16(+0) |
| TARGET_MSP432/pinmap.o           |   408(+0) |    0(+0) |   40(+0) |
| TARGET_MSP432/serial_api.o       |   348(+0) |    0(+0) |   32(+0) |
| TARGET_MSP432/spi_api.o          |   224(+0) |    0(+0) |   32(+0) |
| TARGET_MSP432/us_ticker_api.o    |   252(+0) |    0(+0) |    0(+0) |
| [fill]                           |    48(+0) |    0(+0) |   29(+0) |
| [lib]/c.a                        |  5056(+0) | 2108(+0) |   89(+0) |
| [lib]/gcc.a                      |   760(+0) |    0(+0) |    0(+0) |
| [lib]/misc                       |   180(+0) |    4(+0) |   28(+0) |
| main.o                           |    42(+0) |    0(+0) |    0(+0) |
| mbed-os/drivers                  |    60(+0) |    0(+0) |    0(+0) |
| mbed-os/hal                      |  1422(+0) |    4(+0) |   67(+0) |
| mbed-os/platform                 |  3850(+0) |  260(+0) |  218(+0) |
| mbed-os/rtos                     |  6402(+0) |  168(+0) | 5973(+0) |
| Subtotals                        | 20960(+0) | 2592(+0) | 6776(+0) |
Total Static RAM memory (data + bss): 9368(+0) bytes
Total Flash memory (text + data): 23552(+0) bytes

Image: ./BUILD/MSP432_LAUNCHPAD/GCC_ARM/mbed-os-MSP432.bin
```

### Note

This application has been tested on the MSP432 board!
