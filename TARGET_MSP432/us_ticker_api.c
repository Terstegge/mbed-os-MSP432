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

/* Low-level implementation of the us ticker for MSP432. The Timer32
 * modules can not be used for this purpose, because they do not
 * generate irqs in free-running mode. So the only remaing choice
 * are the Timer A modules, which are only 16 bit, but support irqs
 * when operated in continuous mode. Timer A3 is choosen here, which
 * could be made configurable in the future.
 */

#if DEVICE_USTICKER

#include <stdint.h>
#include "us_ticker_api.h"
#include "mbed_assert.h"

/** The wrapper for ticker_irq_handler, to pass us ticker's data
 *
 */
extern void us_ticker_irq_handler(void);

/* HAL us ticker */

/** Initialize the ticker
 *
 * Initialize or re-initialize the ticker. This resets all the
 * clocking and prescaler registers, along with disabling
 * the compare interrupt.
 *
 * @note Initialization properties tested by ::ticker_init_test
 *
 * Pseudo Code:
 * @code
 * void us_ticker_init()
 * {
 *     // Enable clock gate so processor can read TIMER registers
 *     POWER_CTRL |= POWER_CTRL_TIMER_Msk;
 *
 *     // Disable the timer and ensure it is powered down
 *     TIMER_CTRL &= ~(TIMER_CTRL_ENABLE_Msk | TIMER_CTRL_COMPARE_ENABLE_Msk);
 *
 *     // Configure divisors
 *     uint32_t prescale = SystemCoreClock / 1000000;
 *     TIMER_PRESCALE = prescale - 1;
 *     TIMER_CTRL |= TIMER_CTRL_ENABLE_Msk;
 *
 *     // Install the interrupt handler
 *     NVIC_SetVector(TIMER_IRQn, (uint32_t)us_ticker_irq_handler);
 *     NVIC_EnableIRQ(TIMER_IRQn);
 * }
 * @endcode
 */
void us_ticker_init(void)
{
    // Calculate the Timer A divisors (shift and remainder)
    uint32_t prescale = SubsystemMasterClock / 1000000;
    int  shifts = 0;
    for (shifts = 0; shifts < 3; shifts++) {
        if (prescale & 0x1) {
            break;
        } else {
            prescale >>= 1;
        }
    }

    // Check that we have at least a 1MHz clock
    MBED_ASSERT(prescale && (prescale < 9));

    // initialize the registers and set prescalers
    TIMER_A3->CTL     = (shifts << TIMER_A_CTL_ID_OFS) |
                        TIMER_A_CTL_SSEL__SMCLK |
                        TIMER_A_CTL_MC__CONTINUOUS;
    TIMER_A3->CCTL[0] = 0;
    TIMER_A3->EX0     = prescale - 1;

    // enable IRQ in NVIC
    NVIC_EnableIRQ(TA3_0_IRQn);
}

/** Deinitialize the us ticker
 *
 * Powerdown the us ticker in preparation for sleep, powerdown, or reset.
 *
 * After this function is called, no other ticker functions should be called
 * except us_ticker_init(), calling any function other than init is undefined.
 *
 * @note This function stops the ticker from counting.
 *
 * Pseudo Code:
 * @code
 * uint32_t us_ticker_free()
 * {
 *     // Disable timer
 *     TIMER_CTRL &= ~TIMER_CTRL_ENABLE_Msk;
 *
 *     // Disable the compare interrupt
 *     TIMER_CTRL &= ~TIMER_CTRL_COMPARE_ENABLE_Msk;
 *
 *     // Disable timer interrupt
 *     NVIC_DisableIRQ(TIMER_IRQn);
 *
 *     // Disable clock gate so processor cannot read TIMER registers
 *     POWER_CTRL &= ~POWER_CTRL_TIMER_Msk;
 * }
 * @endcode
 *
 */
void us_ticker_free(void)
{
    // Reset the ctrl registers to default value
    TIMER_A3->CTL     = 0;
    TIMER_A3->CCTL[0] = 0;

    // Disable timer interrupt
    NVIC_DisableIRQ(TA3_0_IRQn);
}

/** Read the current counter
 *
 * Read the current counter value without performing frequency conversions.
 * If no rollover has occurred, the seconds passed since us_ticker_init()
 * was called can be found by dividing the ticks returned by this function
 * by the frequency returned by ::us_ticker_get_info.
 *
 * @return The current timer's counter value in ticks
 *
 * Pseudo Code:
 * @code
 * uint32_t us_ticker_read()
 * {
 *     return TIMER_COUNT;
 * }
 * @endcode
 */
uint32_t us_ticker_read(void)
{
    return TIMER_A3->R;
}

/** Set interrupt for specified timestamp
 *
 * @param timestamp The time in ticks to be set
 *
 * @note no special handling needs to be done for times in the past
 * as the common timer code will detect this and call
 * us_ticker_fire_interrupt() if this is the case
 *
 * @note calling this function with timestamp of more than the supported
 * number of bits returned by ::us_ticker_get_info results in undefined
 * behavior.
 *
 * Pseudo Code:
 * @code
 * void us_ticker_set_interrupt(timestamp_t timestamp)
 * {
 *     TIMER_COMPARE = timestamp;
 *     TIMER_CTRL |= TIMER_CTRL_COMPARE_ENABLE_Msk;
 * }
 * @endcode
 */
void us_ticker_set_interrupt(timestamp_t timestamp)
{
    TIMER_A3->CCR [0] = timestamp;
    TIMER_A3->CCTL[0] = TIMER_A_CCTLN_CCIE;
}

/** Disable us ticker interrupt
 *
 * Pseudo Code:
 * @code
 * void us_ticker_disable_interrupt(void)
 * {
 *     // Disable the compare interrupt
 *     TIMER_CTRL &= ~TIMER_CTRL_COMPARE_ENABLE_Msk;
 * }
 * @endcode
 */
void us_ticker_disable_interrupt(void)
{
    TIMER_A3->CCTL[0] &= ~TIMER_A_CCTLN_CCIE;
}

/** Clear us ticker interrupt
 *
 * Pseudo Code:
 * @code
 * void us_ticker_clear_interrupt(void)
 * {
 *     // Write to the ICR (interrupt clear register) of the TIMER
 *     TIMER_ICR = TIMER_ICR_COMPARE_Msk;
 * }
 * @endcode
 */
void us_ticker_clear_interrupt(void)
{
    TIMER_A3->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG;
}

/** Set pending interrupt that should be fired right away.
 *
 * The ticker should be initialized prior calling this function.
 *
 * Pseudo Code:
 * @code
 * void us_ticker_fire_interrupt(void)
 * {
 *     NVIC_SetPendingIRQ(TIMER_IRQn);
 * }
 * @endcode
 */
void us_ticker_fire_interrupt(void)
{
    NVIC_SetPendingIRQ(TA3_0_IRQn);
}

/** Get frequency and counter bits of this ticker.
 *
 * Pseudo Code:
 * @code
 * const ticker_info_t* us_ticker_get_info()
 * {
 *     static const ticker_info_t info = {
 *         1000000,    // 1 MHz
 *         32          // 32 bit counter
 *     };
 *     return &info;
 * }
 * @endcode
 */
const ticker_info_t *us_ticker_get_info(void)
{
    static const ticker_info_t info = {
        1000000,    // 1 MHz
        16          // 16 bit counter
    };
    return &info;
}

/* Timer_A3 interrupt handler */
void TA3_0_IRQHandler()
{
    us_ticker_irq_handler();
}

#endif /* DEVICE_USTICKER */
