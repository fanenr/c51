#include "timer.h"
#include <mcs51/8052.h>

void
delay_ms (void)
{
  u8 n = 185;
  while (n--)
    ;
}
