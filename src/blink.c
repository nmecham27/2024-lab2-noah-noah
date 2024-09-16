/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

// Global variables that track whether or not the LED is on/off
// also a loop counter.
int count = 0;
bool on = false;

// Setup priorities so that main task is a higher priority than the blink task
#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define BLINK_TASK_PRIORITY     ( tskIDLE_PRIORITY + 2UL )

// Define each functions stack to take the minimum amount of space.
// From the FreeRTOSConfig.h header file it is defined as 128.
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

// blink_task
// This function is executed in its own thread. It accepts a void pointer
// to params, which isn't used in this function. The purpose of this function
// is to alternate the state of the LED every 500mS.
void blink_task(__unused void *params) {
    // Initialize the wireless chip, since our gpio
    // that is used for the LED is controlled by
    // the wireless chip
    hard_assert(cyw43_arch_init() == PICO_OK);

    // Infinite loop
    while (true) {
        // This function writes to the wireless chip GPIO pin 0
        // The value of on is alternated so the led is turned on/off
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);

        // Every 11th iteration of the loop the LED status stays
        // constant. This equates to blinking on 5 times repeatedly.
        if (count++ % 11) on = !on;

        // Sleep for 500mS before executing the loop again
        vTaskDelay(500);
    }
}

void main_task(__unused void *params) {
    xTaskCreate(blink_task, "BlinkThread",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
    char c;
    while(c = getchar()) {
        if (c <= 'z' && c >= 'a') putchar(c - 32);
        else if (c >= 'A' && c <= 'Z') putchar(c + 32);
        else putchar(c);
    }
}

int main( void )
{
    stdio_init_all();
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    TaskHandle_t task;
    xTaskCreate(main_task, "MainThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    return 0;
}