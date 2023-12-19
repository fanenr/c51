#include "types.h"
#include <mcs51/8052.h>

#define LED0 P1_0
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
    for (;;)
        if (BTN0 == 0) {
            delay();
            while (BTN0 == 0)
                ;
            delay();

            LED0 = !LED0;
        }
}
