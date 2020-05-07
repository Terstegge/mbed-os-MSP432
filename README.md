# MSP-EXP432P401R Launchpad support for Mbed OS 6 (unreleased)

This project demonstrates how to use the
[MSP-EXP432P401R Launchpad](https://www.ti.com/tool/MSP-EXP432P401R)
with the upcoming version of Mbed OS 6 (unreleased at this time).
It uses the custom board support based on Mbed OS to compile and run a
simple Blinky application, which will output some text via the backchannel
UART and blink the RGB LED on the MSP432 Launchpad. The default toolchain
for this board is GNU ARM since this is the only free toolchain available.
The ARM and IAR C compilers are also supported, but checked less frequently.
The latest version of [Mbed Studio](https://os.mbed.com/studio/) (0.9.1)
using the ARM Compiler 6 should work without problems. Follow the steps
described below to compile and run the Blinky program!

### Import Project

```
mbed import https://github.com/Terstegge/mbed-os-MSP432.git
cd mbed-os-MSP432
```

### Compile Project

When using Mbed CLI, you might have to set the path to the
GNU ARM compiler first:
```
mbed config GCC_ARM_PATH <path to ARM GCC binary folder>
```
e.g.
```
mbed config GCC_ARM_PATH /usr/local/gcc-arm-none-eabi-9-2019-q4-major/bin
```

Now compile the project by typing
```
mbed compile -t GCC_ARM -m MSP432_LAUNCHPAD
```
or simply
```
mbed compile
```
because the default TOOLCHAIN (GCC_ARM) and TARGET (MSP432_LAUNCHPAD)
configurations are already set int the `.mbed` configuration file.
The end of the compile output should look like this:
```
...
Link: mbed-os-msp432
Elf2Bin: mbed-os-msp432
| Module                           |         .text |     .data |      .bss |
|----------------------------------|---------------|-----------|-----------|
| TARGET_MSP432/PeripheralPins.o   |         0(+0) |     0(+0) |     0(+0) |
| TARGET_MSP432/TARGET_MSP432P401R |   1134(+1134) |     8(+8) |     8(+8) |
| TARGET_MSP432/gpio_api.o         |     298(+298) |     0(+0) |     0(+0) |
| TARGET_MSP432/gpio_irq_api.o     |     256(+256) |     0(+0) | 244(+244) |
| TARGET_MSP432/gpio_msp432.o      |         0(+0) |   40(+40) |     0(+0) |
| TARGET_MSP432/i2c_api.o          |     220(+220) |     0(+0) |   16(+16) |
| TARGET_MSP432/pinmap.o           |     408(+408) |     0(+0) |   40(+40) |
| TARGET_MSP432/serial_api.o       |     348(+348) |     0(+0) |   32(+32) |
| TARGET_MSP432/spi_api.o          |     224(+224) |     0(+0) |   32(+32) |
| TARGET_MSP432/us_ticker_api.o    |     252(+252) |     0(+0) |     0(+0) |
| [fill]                           |       30(+30) |     0(+0) |   14(+14) |
| [lib]/c_nano.a                   |   2622(+2622) | 100(+100) |   21(+21) |
| [lib]/gcc.a                      |     760(+760) |     0(+0) |     0(+0) |
| [lib]/misc                       |     180(+180) |     4(+4) |   28(+28) |
| main.o                           |       50(+50) |     0(+0) |     0(+0) |
| mbed-os/drivers                  |     160(+160) |     0(+0) |     0(+0) |
| mbed-os/hal                      |   1596(+1596) |     4(+4) |   67(+67) |
| mbed-os/platform                 |   4474(+4474) | 260(+260) | 294(+294) |
| mbed-os/rtos                     |         4(+4) |     0(+0) |     0(+0) |
| Subtotals                        | 13016(+13016) | 416(+416) | 796(+796) |
Total Static RAM memory (data + bss): 1212(+1212) bytes
Total Flash memory (text + data): 13432(+13432) bytes

Image: ./BUILD/MSP432_LAUNCHPAD/GCC_ARM/mbed-os-msp432.bin
```
### Download and run the executable

This repository contains the
[TICloudAgent](https://processors.wiki.ti.com/index.php/TI_Cloud_Agent),
a small application that facilitates flashing and debugging hardware
devices from Texas Instruments. The `bin` folder contains a small
script which will call the TICloundAgent with the correct parameters.
The (one and only) command line argument is the `*.elf` executable
(**not** the `*.bin` file!). So the executable can be downloaded and run by
typing:
```
bin/upload BUILD/MSP432_LAUNCHPAD/GCC_ARM/mbed-os-msp432.elf

DSLite version 10.1.0.1986
Configuring Debugger (may take a few minutes on first launch)...
	Initializing Register Database...
	Initializing: CS_DAP_0
	Executing Startup Scripts: CS_DAP_0
	Initializing: CORTEX_M4_0
	Executing Startup Scripts: CORTEX_M4_0
Connecting...
GEL: CORTEX_M4_0: GEL Output: Memory Map Initialization Complete
GEL: CORTEX_M4_0: GEL Output: Halting Watchdog Timer
GEL: CORTEX_M4_0: WARNING   : On MSP432P401R hitting a breakpoint cannot be detected by the debugger when the device is in low power mode.
                         Click the pause button during debug to check if the device is held at the breakpoint.
Loading Program: BUILD/MSP432_LAUNCHPAD/GCC_ARM/mbed-os-msp432.elf
	Preparing ... 
	.text: 0 of 15144 at 0x0
	.data: 0 of 424 at 0x3b28: 97%
	Finished: 97%
	Setting PC to entry point.: 97%
Running...
Success
```

### Build configuration

The project contains the file `mbed_app.json`, which can be used to
configure the build process.
```
{
    "requires": ["bare-metal"],
    "target_overrides": {
        "*": {
            "target.lfxt_hz"      :  null,
            "target.c_lib"        : "small",
            "target.dco_rsel"     : "DCO_3MHz",
            "target.dco_tune"     :  0,
            "target.mclk_select"  : "HFXT",
            "target.mclk_div"     : "DIV1",
            "target.smclk_select" : "HFXT",
            "target.smclk_div"    : "DIV2",
            "target.adc_auto_scan": 1
        }
    }
}
```
As default, the
[bare-metal](https://os.mbed.com/docs/mbed-os/v5.15/reference/mbed-os-bare-metal.html)
profile is selected, which does not contain the RTOS parts.
Simply delete this line if you wish to have the full Mbed OS
functionality. The master CPU clock (MCLK) is configured to use the
48MHz crystal, the subsystem master clock (SMCLK) is also using the
48MHz crystal but with a divider of 2. More information on all
compile-time configuration parameters can be shown with
```
mbed compile --config -v
```

### Serial output

When connected to a Linux PC, the MSP432 Launchpad will show up as
two virtual serial ports: `/dev/ttyACM0` and `/dev/ttyACM1`.
The first one is connected to the backchannel UART, the second one
serves as the debug interface.
To see the serial output just connect a serial terminal program
(e.g. gtkterm) of your choice to `/dev/ttyACM0` using the UART
protocol 8N1 and baudrate 9600.

### Mbed OS updates

The project has a fixed link to the latest Mbed OS version, which is
known to work with this board (see file `mbed-os.lib`). If you wish
to upgrade to the latest version, just use git in the subfolder
`mbed-os`, or simply type
```
cd mbed-os
mbed update <mbed-os hash / tag >
```

### Board pinout

![MSP-EXP432P401R Launchpad pinout](img/MSP-EXP432P401_Launchpad_Pins.png)

  