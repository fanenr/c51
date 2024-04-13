#include "../timer.h"
#include <mcs51/8052.h>

#define LED P1_0

void
main (void)
{
  for (;;)
    {
      LED = 0;
      delay_secs (1);
      LED = 1;
      delay_secs (1);
    }
}
