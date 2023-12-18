#include "TIMER.h"
#include <mcs51/8052.h>

#define SER P3_4
#define SCK P3_5
#define RCK P3_6

typedef unsigned char uchar;

void
send_byte(uchar data1)
{
    SCK = 0;
    RCK = 0;
    for (uchar i = 0; i < 8; i++) {
        SER = data1 & (1 << i);
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;
    RCK = 0;
}

void
send_bytes(uchar data1, uchar data2)
{
    SCK = 0;
    RCK = 0;
    for (uchar i = 0; i < 8; i++) {
        SER = data1 & (1 << i);
        SCK = 1;
        SCK = 0;
    }
    for (uchar i = 0; i < 8; i++) {
        SER = data2 & (1 << i);
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;
    RCK = 0;
}

uchar lattice[8];

void
show_lattice(void)
{
    for (uchar i = 0; i < 8; i++) {
        if (lattice[i] == 0)
            continue;
        send_bytes(~(0x80 >> i), lattice[i]);
        delay(100);
    }
}

void
main(void)
{
    for (uchar i = 0; i < 8; i++)
        lattice[i] = 1 << i;

    for (;;)
        show_lattice();
}
