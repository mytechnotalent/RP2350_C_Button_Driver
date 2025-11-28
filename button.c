/**
 * FILE: button.c
 *
 * DESCRIPTION:
 * RP2350 Button Driver Functions.
 * 
 * BRIEF:
 * Provides button initialization and reading functions for GPIO15.
 * Configures the button pin as input with pull-up resistor enabled.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 28, 2025
 * UPDATE DATE: November 28, 2025
 */

#include "button.h"
#include "constants.h"

void Button_Init(void)
{
    volatile uint32_t *pad_reg;
    volatile uint32_t *ctrl_reg;
    uint32_t value;
    
    // Button_Init_Modify_Pad:
    // Get pad register for GPIO15
    pad_reg = &PADS_BANK0->GPIO15;
    
    // read PAD value
    value = *pad_reg;
    
    // clear OD bit (disable output)
    value &= ~(1U << PADS_BANK0_OD_SHIFT);
    
    // set IE bit (enable input)
    value |= (1U << PADS_BANK0_IE_SHIFT);
    
    // set PUE bit (pull-up enable)
    value |= (1U << PADS_BANK0_PUE_SHIFT);
    
    // clear PDE bit (pull-down disable)
    value &= ~(1U << PADS_BANK0_PDE_SHIFT);
    
    // clear ISO bit (isolate)
    value &= ~(1U << PADS_BANK0_ISO_SHIFT);
    
    // store value into PAD
    *pad_reg = value;
    
    // Button_Init_Modify_CTRL:
    // Get control register for GPIO15
    ctrl_reg = &IO_BANK0->GPIO15.CTRL;
    
    // read CTRL value
    value = *ctrl_reg;
    
    // clear FUNCSEL bits
    value &= ~IO_BANK0_CTRL_FUNCSEL_MASK;
    
    // set FUNCSEL to SIO (0x05)
    value |= IO_BANK0_CTRL_FUNCSEL_SIO;
    
    // store value into CTRL
    *ctrl_reg = value;
    
    // Button_Init_Disable_OE:
    // disable output using coprocessor
    // gpioc_bit_oe_put(GPIO15, 0)
    __asm__ volatile (
        "push {r4-r12, lr}\n\t"
        "mov r4, #0\n\t"
        "mov r5, #15\n\t"
        "mcrr p0, #4, r5, r4, c4\n\t"
        "pop {r4-r12, lr}\n\t"
        :
        :
        : "r4", "r5"
    );
}

uint32_t Button_Read(void)
{
    uint32_t result;
    
    // Button_Read_Execute:
    // read all lower 32 GPIO inputs
    // gpioc_lo_in_get
    __asm__ volatile (
        "push {r4-r12, lr}\n\t"
        "mrc p0, #0, r4, c0, c8\n\t"
        "lsr r4, r4, #15\n\t"
        "and %0, r4, #1\n\t"
        "pop {r4-r12, lr}\n\t"
        : "=r" (result)
        :
        : "r4"
    );
    
    return result;
}

uint32_t Button_IsPressed(void)
{
    uint32_t state;
    
    // Button_IsPressed_Read:
    // read button state
    state = Button_Read();
    
    // invert (pressed=1, released=0)
    return state ^ 1U;
}
