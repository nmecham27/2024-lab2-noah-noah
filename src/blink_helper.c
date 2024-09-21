#include "pico/cyw43_arch.h"
#include "blink_helper.h"

void blink_step(int *count, bool *on) {
    // This function writes to the wireless chip GPIO pin 0
    // The value of on is alternated so the led is turned on/off
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, *on);

    // Every 11th iteration of the loop the LED status stays
    // constant. This equates to blinking on 5 times repeatedly.
    if ((*count)++ % 11) (*on) = !(*on);

    // Sleep for 500mS before executing the loop again
    vTaskDelay(500);
}
