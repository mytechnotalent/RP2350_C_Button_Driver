/**
 * FILE: button.h
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

#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

/**
 * @brief   Initialize button on GPIO15.
 *
 * @details Configures GPIO15 as input with pull-up resistor enabled.
 *          Button is active-low (pressed = 0, released = 1).
 *
 * @param   None
 * @retval  None
 */
void Button_Init(void);

/**
 * @brief   Read button state.
 *
 * @details Reads the current state of the button on GPIO15.
 *          Returns 0 if button is pressed, 1 if released.
 *
 * @param   None
 * @retval  Button state (0 = pressed, 1 = released)
 */
uint32_t Button_Read(void);

/**
 * @brief   Check if button is pressed.
 *
 * @details Returns 1 if button is currently pressed, 0 otherwise.
 *
 * @param   None
 * @retval  1 if pressed, 0 if not pressed
 */
uint32_t Button_IsPressed(void);

#endif /* BUTTON_H */
