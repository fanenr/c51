#include "TIMER.h"
#include <mcs51/8052.h>

#define TUBE  P0

__code unsigned char tube_char[]
    = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
       0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

void
main(void)
{
    for (unsigned i = 0; i < 16; i++) {
        TUBE = tube_char[i % 16];
        delay(1.0);
    }
}
