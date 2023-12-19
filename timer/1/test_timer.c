#include "timer.h"
#include <mcs51/8052.h>

#define LED P1

void
main(void)
{
    for (;;) {
        LED = 0xfe;
        delay(0xffff);
        LED = 0xff;
        delay(0xffff);
    }
}
