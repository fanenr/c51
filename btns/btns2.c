#include "btns.h"
#include "tube.h"
#include "type.h"
#include <mcs51/8052.h>

void
main (void)
{
  for (u8 i = 0; i < 8; i++)
    tube_data[i] = 0;

  u8 key = 0;
  tube_data[0] = tube_char[0];
  tube_data[1] = tube_char[0];

  for (;;)
    {
      key = btns_scan ();
      if (key != 0)
        {
          tube_data[0] = tube_char[key % 10];
          tube_data[1] = tube_char[key / 10];
        }
      tube_show ();
    }
}
