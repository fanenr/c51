#include "types.h"
#include <mcs51/8052.h>

#define SER P3_4
#define SCK P3_5
#define RCK P3_6

void
send_byte(u8 data1, u8 data2)
{
    SCK = 0;
    RCK = 0;
    for (u8 i = 0; i < 8; i++) {
        SER = data1 & (1 << i);
        SCK = 1;
        SCK = 0;
    }
    for (u8 i = 0; i < 8; i++) {
        SER = data2 & (1 << i);
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;
    RCK = 0;
}

void
main(void)
{
    send_byte(0x7f, 1);
    for (;;)
        ;
}
