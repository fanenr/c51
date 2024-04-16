#include "lattice.h"
#include "timer.h"
#include <mcs51/8052.h>

#define SER P3_4
#define SCK P3_5
#define RCK P3_6

u8 lattice_data[8];

static void
send_bytes (u8 hbs, u8 lbs)
{
  SCK = 0;
  RCK = 1;
  RCK = 0;
  for (u8 i = 0; i < 8; i++)
    {
      SER = hbs & (1 << i);
      SCK = 1;
      SCK = 0;
    }
  for (u8 i = 0; i < 8; i++)
    {
      SER = lbs & (1 << i);
      SCK = 1;
      SCK = 0;
    }
  RCK = 1;
  RCK = 0;
}

void
lattice_show (void)
{
  for (u8 i = 0; i < 8; i++)
    {
      if (lattice_data[i] == 0)
        continue;
      send_bytes (~(0x80 >> i), lattice_data[i]);
      delay_msecs (1);
    }
}
