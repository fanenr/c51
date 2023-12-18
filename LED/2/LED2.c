#include <mcs51/8052.h>

void
main(void)
{
    char cnt = 0;
    for (;;) {
        P1 = ~(1 << cnt++);
        for (int i = 0; i < 5000; i++)
            ;
        if (cnt >= 8)
            cnt = 0;
    }
}