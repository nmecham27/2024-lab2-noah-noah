Test setup:
1. Compile project
2. hold down bootsel on pico w and plug into pc
3. Flash program to the pico w

Test Procedure:
1. Enter a string of "HELLO WORLD"
2. Enter a string of "hello world"
3. Enter a string of "!@#$%^&*()"

Expected Behavior:
1. Verify that the LED blinks 5 times and then stays off for about a second.
2. Verify that after entering the string "HELLO WORLD" the connected terminal displays the string "hello world"
2. Verify that after entering the string "hello world" the connected terminal displays the string "HELLO WORLD"
2. Verify that after entering the string "!@#$%^&*()" the connected terminal displays the string "!@#$%^&*()"