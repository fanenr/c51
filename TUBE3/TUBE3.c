#include "TUBE.h"
#include <mcs51/8052.h>

/*
 * 0 - 9: 0 1 2 3 4 5 6 7 8 9
 * 10-18: A B C d E F H L -
 */
__code unsigned char tube_char[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
    0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x40,
};

void
int_c0(void) __interrupt(1)
{
}

void
main(void)
{
    tube[0] = tube_char[0];
    tube[1] = tube_char[1];
    tube[2] = tube_char[2];
    tube[3] = tube_char[3];
    tube[4] = tube_char[4];
    tube[5] = tube_char[5];
    tube[6] = tube_char[6];
    tube[7] = tube_char[7];
    for (;;)
        display();
}
