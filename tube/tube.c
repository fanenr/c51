#include "tube.h"
#include "timer.h"
#include <mcs51/8052.h>

#define DU P2_6
#define WE P2_7
#define TUBE P0

u8 tube[8];

void
show_tube (void)
{
  for (u8 i = 0; i < 8; i++)
    {
      if (tube[i] == 0)
        continue;

      WE = 1;
      DU = 0;
      TUBE = ~(1 << (7 - i));

      DU = 1;
      WE = 0;
      TUBE = tube[i];

      delay_msecs (2);
      TUBE = 0;
    }
}
