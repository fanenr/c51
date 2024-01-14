#include "timer.h"
#include <mcs51/8052.h>

void
delay (u32 cycles)
{
  TMOD &= 0xf0;
  TMOD |= 0x01;

  u16 residue = 0xffff - (u16)cycles;
  TL0 = residue;
  TH0 = residue >> 8;

  TF0 = 0;
  TR0 = 1;
  while (TF0 != 1)
    ;

  u16 times = cycles >> 16;
  for (; times > 0; times--)
    {
      TL0 = 0;
      TH0 = 0;
      TF0 = 0;
      while (TF0 != 1)
        ;
    }
}
