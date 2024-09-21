/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

#include "blink_helper.h"

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
        blink_step(&count, &on);
    }
}

// Main execution task. This task creates the blink_task, after which
// it waits for input from the user, verifies the input is a alphabet
// character, and then converts the character to uppercase if it is
// lower, or lower if it is upper. If the character isn't in the
// alphabet then it will just print that value to the screen
void main_task(__unused void *params) {
    // Create the blinkThread, this thread will execute the blink_task
    // function.
    xTaskCreate(blink_task, "BlinkThread",
                BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
    char c;

    // While loop to wait for input from the user
    while(c = getchar()) {
        // Check if the input is a lower case letter in the alphabet.
        // If the character is lower case then output the uppercase
        // version of that character
        if (c <= 'z' && c >= 'a') putchar(c - 32);
        // Check if the input is uppercase letter in the alphabet.
        // If the character is upper then output the lowercase
        // version of that character
        else if (c >= 'A' && c <= 'Z') putchar(c + 32);
        // If the character is anything else that is not in the
        // alphabet then just output it
        else putchar(c);
    }
}

// Entry point to the program.
int main( void )
{
    // Initialize
    stdio_init_all();

    ;

    // Character pointer that is assigned the name FreeRTOS.
    // It is not used in the code other than at this point.
    const char *rtos_name;
    rtos_name = "FreeRTOS";

    // Create the main execution thread
    TaskHandle_t task;
    xTaskCreate(main_task, "MainThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);

    // Start the scheduler so that our tasks actually execute
    vTaskStartScheduler();
    return 0;
}