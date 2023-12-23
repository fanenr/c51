#include "timer.h"
#include <mcs51/8052.h>

#define LED P1

void
main(void)
{
    for (;;) {
        LED = 0xfe;
        delay(1000000);
        LED = 0xff;
        delay(1000000);
    }
}
