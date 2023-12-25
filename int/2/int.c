#include "int.h"
#include <mcs51/8052.h>

void
loop_int_cycles(u16 cycles)
{
    EA = 1;
    ET1 = 1;

    TMOD &= 0x0f;
    TMOD |= 0x10;

    cycles = 0xffff - cycles;
    TL1 = cycles;
    TH1 = cycles >> 8;

    TR1 = 1;
}
