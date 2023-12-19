#include "timer.h"
#include <mcs51/8052.h>

#define CLOCK_CYCLE    (1.0 / 11059200)
#define MACHINE_CYCLE  (12 * CLOCK_CYCLE)
#define MACHINE_CYCLE2 (1000 * MACHINE_CYCLE)

void
delay(f32 msec)
{
    ET0 = 0;

    u32 cycles = msec / MACHINE_CYCLE2;
    u16 residue = 0xffff - cycles % 0xffff;
    u16 times = cycles / 0xffff;

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
