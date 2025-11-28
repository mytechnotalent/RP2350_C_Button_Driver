/**
 * FILE: main.c
 *
 * DESCRIPTION:
 * RP2350 Bare-Metal Button-Controlled LED Application.
 * 
 * BRIEF:
 * Main application entry point for RP2350 button driver. Contains the
 * main loop that toggles GPIO16 LED when the button on GPIO15 is pressed.
 *
 * AUTHOR: Kevin Thomas
 * CREATION DATE: November 27, 2025
 * UPDATE DATE: November 28, 2025
 */

#include "constants.h"
#include "gpio.h"
#include "delay.h"
#include "button.h"

/**
 * @brief   Main application entry point.
 *
 * @details Implements the infinite loop that reads button state and
 *          controls LED accordingly.
 *
 * @param   None
 * @retval  None
 */
int main(void)
{
    // GPIO16_Config:
    // Configure GPIO16 for output
    GPIO_Config(GPIO16_NUM);
    
    // Button_Init:
    // Initialize button on GPIO15
    Button_Init();
    
    // Loop:
    while (1) {
        // Check if button is pressed
        if (Button_IsPressed()) {
            // Set GPIO16 high
            GPIO_Set(GPIO16_NUM);
        } else {
            // Set GPIO16 low
            GPIO_Clear(GPIO16_NUM);
        }
        
        // Small delay for debouncing
        Delay_MS(10);
    }
    
    // should never reach here
    return 0;
}
