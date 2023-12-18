#include <mcs51/8052.h>

#define LED P1_0

void
main(void)
{
    for (int i = 0;;) {
        LED = 0;
        for (i = 0; i < 30000; i++)
            ;
        LED = 1;
        for (i = 0; i < 30000; i++)
            ;
    }
}