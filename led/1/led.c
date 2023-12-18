#include "types.h"
#include <mcs51/8052.h>

#define LED P1_0

void
main(void)
{
    for (u16 i;;) {
        LED = 0;
        for (i = 0; i < 30000; i++)
            ;
        LED = 1;
        for (i = 0; i < 30000; i++)
            ;
    }
}
