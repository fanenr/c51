#include "types.h"
#include "timer.h"
#include <mcs51/8052.h>

void
config_uart(u16 baud)
{
    SCON = 0x50;
    TMOD &= 0x0f;
    TMOD |= 0x20;
    TL1 = TH1 = 256 - 28800 / baud;
    ES = EA = 1;
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
