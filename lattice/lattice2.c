#include "type.h"
#include "timer.h"
#include <mcs51/8052.h>

#define SER P3_4
#define SCK P3_5
#define RCK P3_6

void
send_byte (u8 lbs)
{
  SCK = 0;
  RCK = 0;
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

u8 lattice[8];

void
show_lattice (void)
{
  for (u8 i = 0; i < 8; i++)
    {
      if (lattice[i] == 0)
	continue;
      send_bytes (~(0x80 >> i), lattice[i]);
      delay_msecs (1);
    }
}

void
main (void)
{
  for (u8 i = 0; i < 8; i++)
    lattice[i] = 1 << i;

  for (;;)
    show_lattice ();
}
