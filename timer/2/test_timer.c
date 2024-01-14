#include "timer.h"
#include <mcs51/8052.h>

#define LED P1

void
main (void)
{
  for (;;)
    {
      LED = 0xfe;
      delay_secs (1);
      LED = 0xff;
      delay_secs (1);
    }
}
