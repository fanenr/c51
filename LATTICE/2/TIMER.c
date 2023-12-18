#include "TIMER.h"
#include <mcs51/8052.h>

void
delay(unsigned long cycles)
{
    ET0 = 0;

    unsigned residue = 0xffff - cycles % 0xffff;
    unsigned times = cycles / 0xffff;

    TMOD = 1;

    TL0 = residue;
    TH0 = residue >> 8;

    TF0 = 0;
    TR0 = 1;
    for (;;) {
        if (TF0 == 1) {
            break;
        }
    }

    for (; times > 0; times--) {
        TL0 = 0;
        TH0 = 0;
        TF0 = 0;
        while (TF0 != 1)
            ;
    }

    ET0 = 1;
}
