#include "TUBE.h"
#include "TIMER.h"
#include <mcs51/8052.h>

#define DU   P2_6
#define WE   P2_7
#define TUBE P0

char tube[8];

void
display(void)
{
    for (char i = 0; i < 8; i++) {
        if (tube[i] == 0)
            continue;
        WE = 1;
        DU = 0;
        TUBE = ~(1 << (7 - i));
        DU = 1;
        WE = 0;
        TUBE = tube[i];
        delay(0.1);
        TUBE = 0;
    }
}
