#include "timer.h"
#include "type.h"
#include <mcs51/8052.h>

#define LED0 P1_0
#define BTN0 P3_0

void
main (void)
{
  for (;;)
    if (BTN0 == 0)
      {
	delay_msecs (10);
	while (BTN0 == 0)
	  ;
	delay_msecs (10);

	LED0 = !LED0;
      }
}
