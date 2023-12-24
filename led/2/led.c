#include "timer.h"
#include "types.h"
#include <mcs51/8052.h>

void
main(void)
{
    u8 cnt = 0;
    for (;;) {
        P1 = ~(1 << (cnt % 8));
        cnt++;
        delay_secs(1);
    }
}
