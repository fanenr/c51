#include "timer.h"
#include "type.h"
#include <mcs51/8052.h>

#define LED P1
#define BTN0 P3_0

void
main (void)
{
  u8 times = 0;
  for (;;)
    if (BTN0 == 0)
      {
	delay_msecs (10);
	while (BTN0 == 0)
	  ;
	delay_msecs (10);

	LED = ~(1 << (times % 8));
	times++;
      }
}
