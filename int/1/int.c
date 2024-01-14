#include "types.h"
#include <mcs51/8052.h>

#define LED P1

void
loop_int (u16 cycles)
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

u8 led_bits = 0;

void
int1 (void) __interrupt (3)
{
  /* do something */
  LED = ~(1 << led_bits % 8);
  led_bits++;

  /* restart loop */
  loop_int (0xffff);
}

void
main (void)
{
  loop_int (0xffff);
  for (;;)
    ;
}
