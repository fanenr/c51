#include <mcs51/8052.h>

#define LED0 P1_0
#define BTN0 P3_0

void
main(void)
{
    for (;;)
        LED0 = BTN0 == 0 ? 0 : 1;
}
