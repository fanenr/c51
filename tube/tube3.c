#include "tube.h"
#include <mcs51/8052.h>

void
main (void)
{
  for (u8 i = 0; i < 8; i++)
    tube_data[i] = tube_char[i];

  for (;;)
    tube_show ();
}
