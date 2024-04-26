#include "int.h"
#include "lattice.h"
#include "tube.h"
#include "type.h"
#include <mcs51/8052.h>

#define LED P1
static u8 led_at;

static u8 tube_at;
static u8 tube_data[8];

static u8 lattice_at;
static u8 lattice_data[8];

void
poll (void)
{
  if (!(int_info.times % 1000))
    {
      LED = ~(1 << led_at);
      led_at = (led_at + 1) % 8;
    }

  lattice_show (lattice_data[lattice_at], 1 << lattice_at);
  lattice_at = (lattice_at + 1) % 8;

  tube_show (tube_data[tube_at], 1 << tube_at);
  tube_at = (tube_at + 1) % 8;
}

void
main (void)
{
  lattice_data[0] = 0x80; /* 0b10000000 */
  lattice_data[1] = 0x40; /* 0b01000000 */
  lattice_data[2] = 0x3f; /* 0b00111111 */
  lattice_data[3] = 0x09; /* 0b00001001 */
  lattice_data[4] = 0x11; /* 0b00010001 */
  lattice_data[5] = 0xff; /* 0b11111111 */
  lattice_data[6] = 0x80; /* 0b10000000 */
  lattice_data[7] = 0xe0; /* 0b11100000 */

  for (u8 i = 0; i < 8; i++)
    tube_data[i] = tube_char[i];

  int_init (1000, poll);
  int_start ();

  for (;;)
    ;
}
