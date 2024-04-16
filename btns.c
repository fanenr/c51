#include "btns.h"
#include "timer.h"
#include <mcs51/8052.h>

u8
btns_scan (void)
{
  u8 ret = 1;

  P3 = 0xf0;
  if (P3 == 0xf0)
    return 0;
  else if (P3_5 == 0)
    ret = 2;
  else if (P3_6 == 0)
    ret = 3;
  else if (P3_7 == 0)
    ret = 4;

  delay_msecs (10);

  P3 = 0x0f;
  if (P3 == 0x0f)
    return 0;
  else if (P3_1 == 0)
    ret += 4;
  else if (P3_2 == 0)
    ret += 8;
  else if (P3_3 == 0)
    ret += 12;

  while (P3 != 0x0f)
    ;

  delay_msecs (10);

  return ret;
}
