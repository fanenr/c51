#include "int.h"
#include "types.h"
#include <mcs51/8052.h>

#define DU P2_6
#define WE P2_7
#define TUBE P0

u8 tube[8];
u8 tube_at = 0;

/*
 * 0 - 9: 0 1 2 3 4 5 6 7 8 9
 * 10-18: A B C d E F H L -
 */
__code u8 tube_char[] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
  0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x40,
};

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
u8 lattice_at = 0;

#define LED P1
u8 led_at = 0;

void
int_t1 (void) __interrupt (3)
{
  static u32 msecs = 0;

  if (msecs % 800 == 0)
    {
      LED = ~(1 << (led_at % 8));
      led_at++;
    }

  if (lattice[lattice_at] != 0)
    {
      send_bytes (~(0x80 >> lattice_at), lattice[lattice_at]);
      if (++lattice_at >= 8)
        lattice_at = 0;
    }

  if (tube[tube_at] != 0)
    {
      TUBE = 0;

      WE = 1;
      DU = 0;
      TUBE = ~(1 << (7 - tube_at));

      DU = 1;
      WE = 0;
      TUBE = tube[tube_at];

      if (++tube_at >= 8)
        tube_at = 0;
    }

  msecs++;
  loop_int_msecs (0.8);
}

void
main (void)
{
  for (u8 i = 0; i < 8; i++)
    tube[i] = tube_char[i];

  for (u8 i = 0; i < 8; i++)
    lattice[i] = 1 << i;

  loop_int_msecs (0.8);

  for (;;)
    ;
}
