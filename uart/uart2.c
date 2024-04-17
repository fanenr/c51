#include "btns.h"
#include "timer.h"
#include "type.h"
#include <mcs51/8052.h>

void
config_uart (u16 baud)
{
  SCON = 0x50;
  TMOD &= 0x0f;
  TMOD |= 0x20;
  TL1 = TH1 = 256 - 28800 / baud;
  ES = EA = 1;
  ET1 = 0;
  TR1 = 1;
}

void
main (void)
{
  config_uart (4800);

  for (u8 val;;)
    {
      val = btns_scan ();

      if (val == 0)
        continue;

      SBUF = val;
      while (TI == 0)
        ;
      TI = 0;
    }
}
