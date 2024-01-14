#include "lattice.h"
#include <mcs51/8052.h>

#define SER P3_4
#define SCK P3_5
#define RCK P3_6

void
send_byte (u8 low)
{
  SCK = 0;
  RCK = 0;
  for (u8 i = 0; i < 8; i++)
    {
      SER = low & (1 << i);
      SCK = 1;
      SCK = 0;
    }
  RCK = 1;
  RCK = 0;
}

void
send_bytes (u8 low, u8 high)
{
  SCK = 0;
  RCK = 1;
  RCK = 0;
  for (u8 i = 0; i < 8; i++)
    {
      SER = high & (1 << i);
      SCK = 1;
      SCK = 0;
    }
  for (u8 i = 0; i < 8; i++)
    {
      SER = low & (1 << i);
      SCK = 1;
      SCK = 0;
    }
  RCK = 1;
  RCK = 0;
}

void
show_lattice (u8 val, u8 pos)
{
  if (val == 0)
    return;

  send_bytes (val, ~pos);
}
