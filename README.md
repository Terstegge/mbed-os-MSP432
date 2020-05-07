# MSP-EXP432P401R Launchpad support for Mbed OS 6 (unreleased)

![MSP432 Launchpad](img/MSP_Launchpad_small.png)

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
| TARGET_MSP432/TARGET_MSP432P401R |   1194(+1194) |     8(+8) |     8(+8) |
| TARGET_MSP432/gpio_api.o         |     298(+298) |     0(+0) |     0(+0) |
| TARGET_MSP432/gpio_irq_api.o     |     256(+256) |     0(+0) | 244(+244) |
| TARGET_MSP432/gpio_msp432.o      |         0(+0) |   80(+80) |     0(+0) |
| TARGET_MSP432/i2c_api.o          |     220(+220) |     0(+0) |   16(+16) |
| TARGET_MSP432/pinmap.o           |     408(+408) |     0(+0) |   40(+40) |
| TARGET_MSP432/port_api.o         |       84(+84) |     0(+0) |     0(+0) |
| TARGET_MSP432/serial_api.o       |     348(+348) |     0(+0) |   32(+32) |
| TARGET_MSP432/spi_api.o          |     224(+224) |     0(+0) |   32(+32) |
| TARGET_MSP432/us_ticker_api.o    |     252(+252) |     0(+0) |     0(+0) |
| [fill]                           |       34(+34) |     0(+0) |   14(+14) |
| [lib]/c_nano.a                   |   2842(+2842) | 100(+100) |   21(+21) |
| [lib]/gcc.a                      |     760(+760) |     0(+0) |     0(+0) |
| [lib]/misc                       |     180(+180) |     4(+4) |   28(+28) |
| main.o                           |       92(+92) |     0(+0) |     0(+0) |
| mbed-os/drivers                  |     188(+188) |     0(+0) |     0(+0) |
| mbed-os/hal                      |   1596(+1596) |     4(+4) |   67(+67) |
| mbed-os/platform                 |   4776(+4776) | 260(+260) | 422(+422) |
| mbed-os/rtos                     |         4(+4) |     0(+0) |     0(+0) |
| Subtotals                        | 13756(+13756) | 456(+456) | 924(+924) |
Total Static RAM memory (data + bss): 1380(+1380) bytes
Total Flash memory (text + data): 14212(+14212) bytes

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
configure Mbed OS and the board configuration.
```
{
    "requires": ["bare-metal"],
    "target_overrides": {
        "*": {
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
48MHz crystal but with a divider of 2. The default clock configuration
(see file `custom_targets.json`) is the DCO with 3MHz for both, MCLK
and SMCLK. More information on all compile-time configuration parameters
can be shown with
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

### Testing

The board can be tested with all available automatic Mbed OS tests.
To do this, first edit the file `mbed_app.json` to use the full Mbed OS
functionality and the standard runtime c library. The file should look
like this:
```
{
    "target_overrides": {
        "*": {
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
Then run
```
mbed test --compile
```
to compile all available tests for this board. After that, generate
a list of the test with the command
```
mbed test --compile-list > tests.list
```
Now you can use a little program (written in C++) to automatically
run all available test. Currently only a linux 64 bit binary is
provided in the `bin` folder. There will be better support for
other platforms in the future (and the source code).
Start the tests by typing
```
bin/mbed_manual_testing tests.list GCC_ARM | tee tests.log
```
Running all tests will take a while (approx. 20-30 minutes). When there
are lines like `Binary not found. Test skipped!!` this means that the
respective test is not available for this board (e.g. there is no
flash filesystem). The output during testing should look like:
```
**************************************************************
* mbed-os-features-device_key-tests-device_key-functionality *
**************************************************************

Binary not found. Test skipped!!

*****************************************************************
* mbed-os-features-frameworks-utest-tests-unit_tests-basic_test *
*****************************************************************

Download binary ...
Run test ...
[1588888394.29][HTST][INF] host test executor ver. 0.0.12
[1588888394.29][HTST][INF] copy image onto target... SKIPPED!
[1588888394.29][HTST][INF] starting host test process...
[1588888394.29][CONN][INF] starting connection process...
[1588888394.29][CONN][INF] notify event queue about extra 60 sec timeout for serial port pooling
[1588888394.29][CONN][INF] initializing serial port listener... 
[1588888394.29][HTST][INF] setting timeout to: 60 sec
[1588888394.29][SERI][INF] serial(port=/dev/ttyACM0, baudrate=9600, read_timeout=0.01, write_timeout=5)
[1588888394.29][SERI][TXD] mbedmbedmbedmbedmbedmbedmbedmbedmbedmbed
[1588888394.29][CONN][INF] sending up to 2 __sync packets (specified with --sync=2)
[1588888394.29][CONN][INF] sending preamble 'b29d6fae-7543-4d47-9147-48421e4b87fc'
[1588888394.29][SERI][TXD] {{__sync;b29d6fae-7543-4d47-9147-48421e4b87fc}}
[1588888394.43][CONN][RXD] mbedmbedmbedmbedmbedmbedmbedmbed
[1588888394.48][CONN][INF] found SYNC in stream: {{__sync;b29d6fae-7543-4d47-9147-48421e4b87fc}} it is #0 sent, queued...
[1588888394.48][HTST][INF] sync KV found, uuid=b29d6fae-7543-4d47-9147-48421e4b87fc, timestamp=1588888394.481540
[1588888394.50][CONN][INF] found KV pair in stream: {{__version;1.3.0}}, queued...
[1588888394.50][HTST][INF] DUT greentea-client version: 1.3.0
[1588888394.53][CONN][INF] found KV pair in stream: {{__timeout;20}}, queued...
[1588888394.53][HTST][INF] setting timeout to: 20 sec
[1588888394.56][CONN][INF] found KV pair in stream: {{__host_test_name;default_auto}}, queued...
[1588888394.56][HTST][INF] host test class: '<class 'mbed_os_tools.test.host_tests.default_auto.DefaultAuto'>'
[1588888394.56][HTST][INF] host test setup() call...
[1588888394.56][HTST][INF] CALLBACKs updated
[1588888394.56][HTST][INF] host test detected: default_auto
[1588888394.58][CONN][INF] found KV pair in stream: {{__testcase_count;2}}, queued...
[1588888394.61][CONN][RXD] >>> Running 2 test cases...
[1588888394.65][CONN][INF] found KV pair in stream: {{__testcase_name;Simple Test}}, queued...
[1588888394.69][CONN][RXD] 
[1588888394.69][CONN][INF] found KV pair in stream: {{__testcase_name;Repeating Test}}, queued...
[1588888394.72][CONN][RXD] >>> Running case #1: 'Simple Test'...
[1588888394.75][CONN][INF] found KV pair in stream: {{__testcase_start;Simple Test}}, queued...
[1588888394.80][CONN][INF] found KV pair in stream: {{__testcase_finish;Simple Test;1;0}}, queued...
[1588888394.84][CONN][RXD] >>> 'Simple Test': 1 passed, 0 failed
[1588888394.84][CONN][RXD] 
[1588888394.88][CONN][RXD] >>> Running case #2: 'Repeating Test'...
[1588888394.92][CONN][INF] found KV pair in stream: {{__testcase_start;Repeating Test}}, queued...
[1588888394.96][CONN][RXD] Setting up for 'Repeating Test'
[1588888395.00][CONN][INF] found KV pair in stream: {{__testcase_finish;Repeating Test;1;0}}, queued...
[1588888395.04][CONN][RXD] >>> 'Repeating Test': 1 passed, 0 failed
[1588888395.04][CONN][RXD] 
[1588888395.08][CONN][RXD] >>> Running case #2: 'Repeating Test'...
[1588888395.13][CONN][INF] found KV pair in stream: {{__testcase_start;Repeating Test}}, queued...
[1588888395.16][CONN][RXD] Setting up for 'Repeating Test'
[1588888395.20][CONN][INF] found KV pair in stream: {{__testcase_finish;Repeating Test;2;0}}, queued...
[1588888395.24][CONN][RXD] >>> 'Repeating Test': 2 passed, 0 failed
[1588888395.25][CONN][RXD] 
[1588888395.29][CONN][RXD] >>> Test cases: 2 passed, 0 failed
[1588888395.31][CONN][INF] found KV pair in stream: {{__testcase_summary;2;0}}, queued...
[1588888395.33][CONN][INF] found KV pair in stream: {{end;success}}, queued...
[1588888395.33][HTST][INF] __notify_complete(True)
[1588888395.33][HTST][INF] __exit_event_queue received
[1588888395.33][HTST][INF] test suite run finished after 0.81 sec...
[1588888395.34][CONN][INF] found KV pair in stream: {{__exit;0}}, queued...
[1588888395.34][CONN][INF] received special event '__host_test_finished' value='True', finishing
[1588888395.35][HTST][INF] CONN exited with code: 0
[1588888395.35][HTST][INF] Some events in queue
[1588888395.35][HTST][INF] stopped consuming events
[1588888395.35][HTST][INF] host test result() call skipped, received: True
[1588888395.35][HTST][WRN] missing __exit event from DUT
[1588888395.35][HTST][INF] calling blocking teardown()
[1588888395.35][HTST][INF] teardown() finished
[1588888395.35][HTST][INF] {{result;success}}


*************************************************************************
* mbed-os-features-frameworks-utest-tests-unit_tests-basic_test_default *
*************************************************************************

Download binary ...
Run test ...
[1588888399.84][HTST][INF] host test executor ver. 0.0.12
[1588888399.84][HTST][INF] copy image onto target... SKIPPED!
[1588888399.84][HTST][INF] starting host test process...
[1588888399.85][CONN][INF] starting connection process...
[1588888399.85][CONN][INF] notify event queue about extra 60 sec timeout for serial port pooling
[1588888399.85][CONN][INF] initializing serial port listener... 
[1588888399.85][SERI][INF] serial(port=/dev/ttyACM0, baudrate=9600, read_timeout=0.01, write_timeout=5)
[1588888399.85][HTST][INF] setting timeout to: 60 sec
[1588888399.85][SERI][TXD] mbedmbedmbedmbedmbedmbedmbedmbedmbedmbed
[1588888399.85][CONN][INF] sending up to 2 __sync packets (specified with --sync=2)
[1588888399.85][CONN][INF] sending preamble 'e7a5e8c3-e945-4f19-b96c-b42000df3502'
[1588888399.85][SERI][TXD] {{__sync;e7a5e8c3-e945-4f19-b96c-b42000df3502}}
[1588888399.98][CONN][RXD] mbedmbedmbedmbedmbedmbedmbedmbed
[1588888400.04][CONN][INF] found SYNC in stream: {{__sync;e7a5e8c3-e945-4f19-b96c-b42000df3502}} it is #0 sent, queued...
[1588888400.04][HTST][INF] sync KV found, uuid=e7a5e8c3-e945-4f19-b96c-b42000df3502, timestamp=1588888400.037524
[1588888400.06][CONN][INF] found KV pair in stream: {{__version;1.3.0}}, queued...
[1588888400.06][HTST][INF] DUT greentea-client version: 1.3.0
[1588888400.08][CONN][INF] found KV pair in stream: {{__timeout;10}}, queued...
[1588888400.08][HTST][INF] setting timeout to: 10 sec
[1588888400.11][CONN][INF] found KV pair in stream: {{__host_test_name;default_auto}}, queued...
[1588888400.11][HTST][INF] host test class: '<class 'mbed_os_tools.test.host_tests.default_auto.DefaultAuto'>'
[1588888400.11][HTST][INF] host test setup() call...
[1588888400.11][HTST][INF] CALLBACKs updated
[1588888400.11][HTST][INF] host test detected: default_auto
[1588888400.13][CONN][INF] found KV pair in stream: {{__testcase_count;2}}, queued...
[1588888400.17][CONN][RXD] >>> Running 2 test cases...
[1588888400.21][CONN][INF] found KV pair in stream: {{__testcase_name;Simple Test}}, queued...
[1588888400.24][CONN][RXD] 
[1588888400.24][CONN][INF] found KV pair in stream: {{__testcase_name;Repeating Test}}, queued...
[1588888400.27][CONN][RXD] >>> Running case #1: 'Simple Test'...
[1588888400.32][CONN][INF] found KV pair in stream: {{__testcase_start;Simple Test}}, queued...
[1588888400.35][CONN][INF] found KV pair in stream: {{__testcase_finish;Simple Test;1;0}}, queued...
[1588888400.39][CONN][RXD] >>> 'Simple Test': 1 passed, 0 failed
[1588888400.39][CONN][RXD] 
[1588888400.44][CONN][RXD] >>> Running case #2: 'Repeating Test'...
[1588888400.48][CONN][INF] found KV pair in stream: {{__testcase_start;Repeating Test}}, queued...
[1588888400.51][CONN][RXD] Setting up for 'Repeating Test'
[1588888400.55][CONN][INF] found KV pair in stream: {{__testcase_finish;Repeating Test;1;0}}, queued...
[1588888400.60][CONN][RXD] >>> 'Repeating Test': 1 passed, 0 failed
[1588888400.60][CONN][RXD] 
[1588888400.64][CONN][RXD] >>> Running case #2: 'Repeating Test'...
[1588888400.68][CONN][INF] found KV pair in stream: {{__testcase_start;Repeating Test}}, queued...
[1588888400.71][CONN][RXD] Setting up for 'Repeating Test'
[1588888400.76][CONN][INF] found KV pair in stream: {{__testcase_finish;Repeating Test;2;0}}, queued...
[1588888400.80][CONN][RXD] >>> 'Repeating Test': 2 passed, 0 failed
[1588888400.81][CONN][RXD] 
[1588888400.84][CONN][RXD] >>> Test cases: 2 passed, 0 failed
[1588888400.86][CONN][INF] found KV pair in stream: {{__testcase_summary;2;0}}, queued...
[1588888400.88][CONN][INF] found KV pair in stream: {{end;success}}, queued...
[1588888400.89][HTST][INF] __notify_complete(True)
[1588888400.89][HTST][INF] __exit_event_queue received
[1588888400.89][HTST][INF] test suite run finished after 0.81 sec...
[1588888400.89][CONN][INF] found KV pair in stream: {{__exit;0}}, queued...
[1588888400.90][CONN][INF] received special event '__host_test_finished' value='True', finishing
[1588888400.90][HTST][INF] CONN exited with code: 0
[1588888400.90][HTST][INF] Some events in queue
[1588888400.90][HTST][INF] stopped consuming events
[1588888400.90][HTST][INF] host test result() call skipped, received: True
[1588888400.90][HTST][WRN] missing __exit event from DUT
[1588888400.90][HTST][INF] calling blocking teardown()
[1588888400.90][HTST][INF] teardown() finished
[1588888400.90][HTST][INF] {{result;success}}


**************************************************************************
* mbed-os-features-frameworks-utest-tests-unit_tests-case_async_validate *
**************************************************************************

Download binary ...
Run test ...
[1588888405.38][HTST][INF] host test executor ver. 0.0.12
[1588888405.38][HTST][INF] copy image onto target... SKIPPED!
[1588888405.38][HTST][INF] starting host test process...
[1588888405.38][CONN][INF] starting connection process...
[1588888405.38][CONN][INF] notify event queue about extra 60 sec timeout for serial port pooling
[1588888405.38][CONN][INF] initializing serial port listener... 
[1588888405.38][SERI][INF] serial(port=/dev/ttyACM0, baudrate=9600, read_timeout=0.01, write_timeout=5)
[1588888405.38][HTST][INF] setting timeout to: 60 sec
[1588888405.38][SERI][TXD] mbedmbedmbedmbedmbedmbedmbedmbedmbedmbed
[1588888405.38][CONN][INF] sending up to 2 __sync packets (specified with --sync=2)
[1588888405.38][CONN][INF] sending preamble 'eed6739d-1e5f-4c4f-8488-ed71e0e5a53e'
[1588888405.38][SERI][TXD] {{__sync;eed6739d-1e5f-4c4f-8488-ed71e0e5a53e}}
[1588888405.52][CONN][RXD] mbedmbedmbedmbedmbedmbedmbedmbed
[1588888405.57][CONN][INF] found SYNC in stream: {{__sync;eed6739d-1e5f-4c4f-8488-ed71e0e5a53e}} it is #0 sent, queued...
[1588888405.57][HTST][INF] sync KV found, uuid=eed6739d-1e5f-4c4f-8488-ed71e0e5a53e, timestamp=1588888405.570134
[1588888405.59][CONN][INF] found KV pair in stream: {{__version;1.3.0}}, queued...
[1588888405.59][HTST][INF] DUT greentea-client version: 1.3.0
[1588888405.61][CONN][INF] found KV pair in stream: {{__timeout;15}}, queued...
[1588888405.61][HTST][INF] setting timeout to: 15 sec
[1588888405.65][CONN][INF] found KV pair in stream: {{__host_test_name;default_auto}}, queued...
[1588888405.65][HTST][INF] host test class: '<class 'mbed_os_tools.test.host_tests.default_auto.DefaultAuto'>'
[1588888405.65][HTST][INF] host test setup() call...
[1588888405.65][HTST][INF] CALLBACKs updated
[1588888405.65][HTST][INF] host test detected: default_auto
[1588888405.67][CONN][INF] found KV pair in stream: {{__testcase_count;6}}, queued...
[1588888405.70][CONN][RXD] >>> Running 6 test cases...
[1588888405.76][CONN][INF] found KV pair in stream: {{__testcase_name;Validate: Simple Validation}}, queued...
[1588888405.80][CONN][INF] found KV pair in stream: {{__testcase_name;Validate: Multiple Validation}}, queued...
[1588888405.87][CONN][INF] found KV pair in stream: {{__testcase_name;Validate: Premature Validation}}, queued...
[1588888405.92][CONN][INF] found KV pair in stream: {{__testcase_name;Validate: Multiple Premature Validation}}, queued...
[1588888405.99][CONN][INF] found KV pair in stream: {{__testcase_name;Validate: Attributed Validation: Cancel Repeat}}, queued...
[1588888406.08][CONN][RXD] 
[1588888406.08][CONN][INF] found KV pair in stream: {{__testcase_name;Validate: Attributed Validation: Enable Repeat Handler}}, queued...
[1588888406.13][CONN][RXD] >>> Running case #1: 'Validate: Simple Validation'...
[1588888406.18][CONN][INF] found KV pair in stream: {{__testcase_start;Validate: Simple Validation}}, queued...
[1588888406.23][CONN][INF] found KV pair in stream: {{__testcase_finish;Validate: Simple Validation;1;0}}, queued...
[1588888406.30][CONN][RXD] >>> 'Validate: Simple Validation': 1 passed, 0 failed
[1588888406.30][CONN][RXD] 
[1588888406.35][CONN][RXD] >>> Running case #2: 'Validate: Multiple Validation'...
[1588888406.41][CONN][INF] found KV pair in stream: {{__testcase_start;Validate: Multiple Validation}}, queued...
[1588888406.57][CONN][INF] found KV pair in stream: {{__testcase_finish;Validate: Multiple Validation;1;0}}, queued...
[1588888406.63][CONN][RXD] >>> 'Validate: Multiple Validation': 1 passed, 0 failed
[1588888406.63][CONN][RXD] 
[1588888406.68][CONN][RXD] >>> Running case #3: 'Validate: Premature Validation'...
[1588888406.74][CONN][INF] found KV pair in stream: {{__testcase_start;Validate: Premature Validation}}, queued...
[1588888406.80][CONN][INF] found KV pair in stream: {{__testcase_finish;Validate: Premature Validation;1;0}}, queued...
[1588888406.86][CONN][RXD] >>> 'Validate: Premature Validation': 1 passed, 0 failed
[1588888406.86][CONN][RXD] 
[1588888406.93][CONN][RXD] >>> Running case #4: 'Validate: Multiple Premature Validation'...
[1588888406.99][CONN][INF] found KV pair in stream: {{__testcase_start;Validate: Multiple Premature Validation}}, queued...
[1588888407.06][CONN][INF] found KV pair in stream: {{__testcase_finish;Validate: Multiple Premature Validation;1;0}}, queued...
[1588888407.14][CONN][RXD] >>> 'Validate: Multiple Premature Validation': 1 passed, 0 failed
[1588888407.14][CONN][RXD] 
[1588888407.22][CONN][RXD] >>> Running case #5: 'Validate: Attributed Validation: Cancel Repeat'...
[1588888407.28][CONN][INF] found KV pair in stream: {{__testcase_start;Validate: Attributed Validation: Cancel Repeat}}, queued...
[1588888407.46][CONN][INF] found KV pair in stream: {{__testcase_finish;Validate: Attributed Validation: Cancel Repeat;1;0}}, queued...
[1588888407.54][CONN][RXD] >>> 'Validate: Attributed Validation: Cancel Repeat': 1 passed, 0 failed
[1588888407.54][CONN][RXD] 
[1588888407.62][CONN][RXD] >>> Running case #6: 'Validate: Attributed Validation: Enable Repeat Handler'...
[1588888407.70][CONN][INF] found KV pair in stream: {{__testcase_start;Validate: Attributed Validation: Enable Repeat Handler}}, queued...
[1588888407.88][CONN][INF] found KV pair in stream: {{__testcase_finish;Validate: Attributed Validation: Enable Repeat Handler;2;0}}, queued...
[1588888407.97][CONN][RXD] >>> 'Validate: Attributed Validation: Enable Repeat Handler': 2 passed, 0 failed
[1588888407.97][CONN][RXD] 
[1588888408.01][CONN][RXD] >>> Test cases: 6 passed, 0 failed
[1588888408.04][CONN][INF] found KV pair in stream: {{__testcase_summary;6;0}}, queued...
[1588888408.05][CONN][INF] found KV pair in stream: {{end;success}}, queued...
[1588888408.05][HTST][INF] __notify_complete(True)
[1588888408.05][HTST][INF] __exit_event_queue received
[1588888408.05][HTST][INF] test suite run finished after 2.44 sec...
[1588888408.06][CONN][INF] found KV pair in stream: {{__exit;0}}, queued...
[1588888408.06][CONN][INF] received special event '__host_test_finished' value='True', finishing
[1588888408.07][HTST][INF] CONN exited with code: 0
[1588888408.07][HTST][INF] Some events in queue
[1588888408.07][HTST][INF] stopped consuming events
[1588888408.07][HTST][INF] host test result() call skipped, received: True
[1588888408.07][HTST][WRN] missing __exit event from DUT
[1588888408.07][HTST][INF] calling blocking teardown()
[1588888408.07][HTST][INF] teardown() finished
[1588888408.07][HTST][INF] {{result;success}}
...
...
```
After running all the tests, the file `tests.log` can be grepped for all
lines containing `result;`. Hopefully all tests succeeded.

