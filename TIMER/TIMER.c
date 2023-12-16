#include <mcs51/8052.h>

#define CLOCK_CYCLE    (1.0 / 11059200)
#define MACHINE_CYCLE  (12 * CLOCK_CYCLE)
#define MACHINE_CYCLE2 (1000 * MACHINE_CYCLE)

static void delay(float secs);

#define LED P1_0

void
main(void)
{
    for (;;) {
        LED = 0;
        delay(3000);
        LED = 1;
        delay(3000);
    }
}

void
delay(float msec)
{
    ET0 = 0;

    unsigned long cycles = msec / MACHINE_CYCLE2;
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
