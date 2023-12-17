#include <mcs51/8052.h>

#define LED   P0_0
#define ADDR0 P1_0
#define ADDR1 P1_1
#define ADDR2 P1_2
#define ADDR3 P1_3
#define ENLED P1_4

void
main(void)
{
    ENLED = 0;
    ADDR3 = 0;
    ADDR2 = 0;
    ADDR1 = 0;
    ADDR0 = 0;
    LED = 0;
    while (1)
        ;
}
