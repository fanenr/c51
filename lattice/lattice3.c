#include "lattice.h"
#include "type.h"
#include <mcs51/8052.h>

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

  for (;;)
    lattice_show ();
}
