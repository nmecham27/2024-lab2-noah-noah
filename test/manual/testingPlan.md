Test setup:
1. Compile project
2. hold down bootsel on pico w and plug into pc
3. Flash program to the pico w
4. Open "SERIAL MONITOR" tab in vs code. This can be accessed by opening a new terminal.

Test Procedure:
1. Enter a string of "HELLO WORLD"
2. Enter a string of "hello world"
3. Enter a string of "!@#$%^&*()"
4. Enter a string of "He!!0 W0r!d"

Expected Behavior:
1. Verify that the LED blinks 5 times and then stays off for about a second.
2. Verify that after entering the string "HELLO WORLD" the connected terminal displays the string "hello world"
3. Verify that after entering the string "hello world" the connected terminal displays the string "HELLO WORLD"
4. Verify that after entering the string "!@#$%^&*()" the connected terminal displays the string "!@#$%^&*()"
5. Verify that after entering the string "He!!0 W0r!d" the connected terminal displays the string "He!!0 W0r!d"