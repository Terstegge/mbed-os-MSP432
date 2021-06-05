/******************************************************
 * GCC linker script for Texas Instruments MSP432P401R
 ******************************************************/

/* Device specific values */

#define ROM_START   0x00000000
#define ROM_SIZE    0x00040000
#define RAM_START   0x20000000
#define RAM_SIZE    0x00010000
#define INFO_START  0x00200000
#define INFO_SIZE   0x00004000

/* Common - Do not change */

#if !defined(MBED_APP_START)
  #define MBED_APP_START ROM_START
#endif

#if !defined(MBED_APP_SIZE)
  #define MBED_APP_SIZE ROM_SIZE
#endif

#if !defined(MBED_BOOT_STACK_SIZE)
    #define  MBED_BOOT_STACK_SIZE 0x400
#endif

STACK_SIZE = MBED_BOOT_STACK_SIZE;

/* Linker script to configure memory regions. */
/* 0x1AC resevered for vectors; 8-byte aligned = 0x1B0 (0x1AC + 0x4)*/
MEMORY
{
    FLASH (rx)   : ORIGIN = MBED_APP_START, LENGTH = MBED_APP_SIZE
    RAM   (rwx)  : ORIGIN = RAM_START,      LENGTH = RAM_SIZE
}

ENTRY(Reset_Handler)

SECTIONS
{
    /********/
    /* Code */
    /********/
    .text : {
        KEEP (*(.isr_vector))
        *(.text.*)

        *(SORT(.ctors.*))
        *(.ctors)
        *(SORT(.dtors.*))
        *(.dtors)

        KEEP (*(.init))
        KEEP (*(.fini))

        __preinit_array_start = .;
        KEEP (*(.preinit_array*))
        __preinit_array_end = .;

        __init_array_start = .;
        KEEP (*(.init_array*))
        __init_array_end = .;

        __fini_array_start = .;
        KEEP (*(.fini_array*))
        __fini_array_end = .;

    } > FLASH
 
    /******************/
    /* Read-only data */
    /******************/
    .rodata : {
        *(.rodata)
        *(.rodata.*)
    } > FLASH

    /*************************/
    /* Exception information */
    /*************************/

    .ARM.extab : {
        KEEP (*(.ARM.extab* .gnu.linkonce.armextab.*))
    } > FLASH

    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > FLASH

    /***********************************/
    /* .copy.table used by cmsis_gcc.h */
    /***********************************/
    .copy.table : {
      . = ALIGN(8);
      __copy_table_start__ = .;
      LONG (__data_load__)
      LONG (__data_start__)
      LONG (__data_end__ - __data_start__)
      __copy_table_end__ = .;
    } > FLASH

    /***********************************/
    /* .zero.table used by cmsis_gcc.h */
    /***********************************/
    .copy.table : {
      . = ALIGN(8);
      __zero_table_start__ = .;
      LONG (__bss_start__)
      LONG (__bss_end__ - __bss_start__)
      __zero_table_end__ = .;
    } > FLASH

    etext = .;
    __etext = .;

    /****************************************/
    /* Data which needs to be copied to RAM */
    /****************************************/
    .data : {
        . = ALIGN (4);
        __data_load__  = LOADADDR(.data);
        __data_start__ = .;
        *(.vtable)
        *(.data*)
        . = ALIGN (4);
        __data_end__ = .;
    } > RAM AT> FLASH

    /*******/
    /* bss */
    /*******/
    .bss : {
        . = ALIGN (4);
	__bss_start__ = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN (4);
	__bss_end__ = .;
    } > RAM

    __end__ = .;

    /********/
    /* heap */
    /********/
    .heap (NOLOAD): {
        __heap_start__ = .;
        *(.heap*)
	. = ORIGIN(RAM) + LENGTH(RAM) - STACK_SIZE;
        __heap_end__ = .;
        __HeapLimit = .;
    } > RAM

    /*********/
    /* stack */
    /*********/
    .stack (NOLOAD): {
        *(.stack*)
    } > RAM

    __StackTop   = ORIGIN(RAM) + LENGTH(RAM);
    __StackLimit = __StackTop  - STACK_SIZE;
    __stack = __StackTop;

}

