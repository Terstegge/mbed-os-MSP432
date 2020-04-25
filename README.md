# MSP432 launchpad support for Mbed OS 6 (unreleased)

This is an initial configuration for the [MSP432 Launchpad](https://www.ti.com/tool/MSP-EXP432P401R) board for the upcoming version of Mbed OS 6 (unreleased at this time).

It shows how to create a custom board support based on Mbed OS and how to compile a simple Blinky application.

Note this project makes uses of the full Mbed OS with RTOS included. It's possible to make changes in the configuration to support the Baremetal profile and reduce memory requirements - see [this](https://os.mbed.com/docs/mbed-os/v5.15/reference/mbed-os-bare-metal.html).

### Import and compile

```
mbed import https://github.com/Terstegge/mbed-os-MSP432.git
cd mbed-os-MSP432
mbed compile -t GCC_ARM -m MSP432

...

Link: bluepill
Elf2Bin: bluepill
| Module                           |         .text |       .data |        .bss |
|----------------------------------|---------------|-------------|-------------|
| TARGET_BLUEPILL/PeripheralPins.o |         0(+0) |       0(+0) |       0(+0) |
| TARGET_BLUEPILL/device           |     572(+572) |       0(+0) |       0(+0) |
| [fill]                           |       50(+50) |       4(+4) |     16(+16) |
| [lib]/c.a                        |   4792(+4792) | 2108(+2108) |     89(+89) |
| [lib]/gcc.a                      |     760(+760) |       0(+0) |       0(+0) |
| [lib]/misc                       |     180(+180) |       4(+4) |     28(+28) |
| main.o                           |       48(+48) |       0(+0) |       0(+0) |
| mbed-os/drivers                  |       60(+60) |       0(+0) |       0(+0) |
| mbed-os/hal                      |   1356(+1356) |       4(+4) |     66(+66) |
| mbed-os/platform                 |   4002(+4002) |   260(+260) |   220(+220) |
| mbed-os/rtos                     |   6386(+6386) |   168(+168) | 5973(+5973) |
| mbed-os/targets                  |   5438(+5438) |       4(+4) |   368(+368) |
| Subtotals                        | 23644(+23644) | 2552(+2552) | 6760(+6760) |
Total Static RAM memory (data + bss): 9312(+9312) bytes
Total Flash memory (text + data): 26196(+26196) bytes

Image: ./BUILD/BLUEPILL/GCC_ARM/bluepill.bin
```

### Note

This application has not (yet) been tested on the Bluepill board.
