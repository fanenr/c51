#include "int.h"
#include "type.h"
#include <mcs51/8052.h>

static u8 led_at;

static inline void
poll (void)
{
  if (int_info.flag)
    {
      int_info.flag = 0;
      if (!(int_info.times % 1000))
        {
          P1 = ~led_at;
          led_at++;
        }
    }
}

void
main (void)
{
  int_init (1000);
  int_start ();

  for (;;)
    poll ();
}
