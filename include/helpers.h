#ifndef HELPERS_H
#define HELPERS_H

#include "FreeRTOS.h"

void blink_step(int *count, bool *on);

void character_convert( char in );

#endif /* BLINK_HELPER_H */