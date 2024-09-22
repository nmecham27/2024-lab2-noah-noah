#include "helpers.h"
#include <stdio.h>

void blink_step(int *count, bool *on)
{
    // Every 11th iteration of the loop the LED status stays
    // constant. This equates to blinking on 5 times repeatedly.
    if ((*count)++ % 11) (*on) = !(*on);
}

void character_convert( char in )
{
    // Check if the input is a lower case letter in the alphabet.
    // If the character is lower case then output the uppercase
    // version of that character
    if (in <= 'z' && in >= 'a') putchar(in - 32);
    // Check if the input is uppercase letter in the alphabet.
    // If the character is upper then output the lowercase
    // version of that character
    else if (in >= 'A' && in <= 'Z') putchar(in + 32);
    // If the character is anything else that is not in the
    // alphabet then just output it
    else putchar(in);
}