#include "types.h"
#include "timer.h"
#include <mcs51/8052.h>

void
config_uart(u16 baud)
{
    SCON = 0x50;
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TL1 = TH1 = 256 - (11059200 / 12 / 32) / baud;
    ET1 = 0;
    TR1 = 1;
}

void
int_uart(void) __interrupt(4)
{
    if (RI == 1) {
        RI = 0;
    }

    if (TI == 1) {
        TI = 0;
    }
}

void
main(void)
{
    EA = 1;

    config_uart(4800);

    for (u8 i = 0;; i++) {
        SBUF = i;
        delay_secs(1);
    }
}
