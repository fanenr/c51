#include "lattice.h"
#include <mcs51/8052.h>

#define SER P3_4
#define SCK P3_5
#define RCK P3_6

void
lattice_show (u8 val, u8 pos)
{
  pos = ~pos;

  SCK = 0;
  RCK = 1;
  RCK = 0;

  for (u8 i = 0; i < 8; i++)
    {
      SER = pos & (1 << i);
      SCK = 1;
      SCK = 0;
    }

  for (u8 i = 0; i < 8; i++)
    {
      SER = val & (1 << i);
      SCK = 1;
      SCK = 0;
    }

  RCK = 1;
  RCK = 0;
}
