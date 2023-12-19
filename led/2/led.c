#include "types.h"
#include <mcs51/8052.h>

void
main(void)
{
    u8 cnt = 0;
    for (;;) {
        P1 = ~(1 << cnt++);
        for (u16 i = 0; i < 5000; i++)
            ;
        if (cnt >= 8)
            cnt = 0;
    }
}
