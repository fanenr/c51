#include <mcs51/8052.h>

#define CLOCK_CYCLE   (1.0 / 11059200)
#define MACHINE_CYCLE (12 * CLOCK_CYCLE)

void delay(float secs);

#define LED P1_0

void
main(void)
{
    for (;;) {
        LED = 0;
        delay(2);
        LED = 1;
        delay(2);
    }
}

void
delay(float secs)
{
    unsigned long cycles = secs / MACHINE_CYCLE;
    unsigned residue = 0x10000 - cycles % 0xffff;
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

    for (unsigned i = 0; i < times; i++) {
        TL0 = 0;
        TH0 = 0;
        TF0 = 0;
        while (TF0 != 1)
            ;
    }
}
