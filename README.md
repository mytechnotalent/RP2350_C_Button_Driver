<img src="https://github.com/mytechnotalent/RP2350_C_Button_Driver/blob/main/RP2350_C_Button_Driver.png?raw=true">

## FREE Reverse Engineering Self-Study Course [HERE](https://github.com/mytechnotalent/Reverse-Engineering-Tutorial)
### VIDEO PROMO [HERE](https://www.youtube.com/watch?v=aD7X9sXirF8)

<br>

# RP2350 C Button Driver
An RP2350 C Button driver written entirely in bare-metal C.

<br>

# Install ARM Toolchain
## NOTE: Be SURE to select `Add path to environment variable` on setup.
[HERE](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)

<br>

# Hardware
## Raspberry Pi Pico 2 w/ Header [BUY](https://www.pishop.us/product/raspberry-pi-pico-2-with-header)
## USB A-Male to USB Micro-B Cable [BUY](https://www.pishop.us/product/usb-a-male-to-usb-micro-b-cable-6-inches)
## Raspberry Pi Pico Debug Probe [BUY](https://www.pishop.us/product/raspberry-pi-debug-probe)
## Complete Component Kit for Raspberry Pi [BUY](https://www.pishop.us/product/complete-component-kit-for-raspberry-pi)
## 10pc 25v 1000uF Capacitor [BUY](https://www.amazon.com/Cionyce-Capacitor-Electrolytic-CapacitorsMicrowave/dp/B0B63CCQ2N?th=1)
### 10% PiShop DISCOUNT CODE - KVPE_HS320548_10PC

<br>

# Build
```
.\build.bat
```

<br>

# Clean
```
.\clean.bat
```

<br>

# main.c Code
```c
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
```

<br>

# License
[Apache License 2.0](https://github.com/mytechnotalent/RP2350_C_Button_Driver/blob/main/LICENSE)
