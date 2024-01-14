#include "int.h"
#include "lattice.h"
#include "led.h"
#include "tube.h"
#include "types.h"
#include <mcs51/8052.h>

/* led */
u8 led_at;

/* tube */
u8 tube[8], tube_at;

/* lattice */
u8 lattice[8], lattice_at;

/*
 * 0 - 9: 0 1 2 3 4 5 6 7 8 9
 * 10-18: A B C d E F H L -
 */
__code u8 tube_char[] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
  0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x40,
};

void
int_t1 (void) __interrupt (3)
{
  static u32 msecs;

  if (msecs % 800 == 0)
    {
      show_led (1 << (led_at % 8));
      led_at++;
    }

  show_tube (tube[tube_at % 8], 1 << (tube_at % 8));
  tube_at++;

  show_lattice (lattice[lattice_at % 8], 1 << (lattice_at % 8));
  lattice_at++;

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
