#include "TIMER.h"
#include <mcs51/8052.h>

#define TUBE P0

/*
 * 0 - 9: 0 1 2 3 4 5 6 7 8 9
 * 10-19: A B C d E F H L -
 */
__code unsigned char tube_char[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
    0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x40, 0x00,
};

void
main(void)
{
    for (unsigned i = 0;; i++) {
        TUBE = tube_char[i % 20];
        delay(1.0);
    }
}
