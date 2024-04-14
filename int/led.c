#include "led.h"
#include <mcs51/8052.h>

#define LED P1

void
show_led (u8 val)
{
  LED = ~val;
}
