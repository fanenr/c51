#include "types.h"
#include <mcs51/8052.h>

#define LED  P1
#define BTN0 P3_0

void
delay(void)
{
    for (u8 i = 0; i < 0xff; i++)
        ;
}

void
main(void)
{
    u8 times = 0;
    for (;;)
        if (BTN0 == 0) {
            delay();
            while (BTN0 == 0)
                ;
            delay();

            LED = ~(1 << (times % 8));
            times++;
        }
}
