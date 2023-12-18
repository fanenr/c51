#include <mcs51/8052.h>

#define SER P3_4
#define SCK P3_5
#define RCK P3_6

typedef unsigned char uchar;

void
send_byte(uchar data1, uchar data2)
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

void
main(void)
{
    send_byte(0x7f, 1);
    for (;;)
        ;
}
