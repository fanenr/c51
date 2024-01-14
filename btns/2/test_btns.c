#include "btns.h"
#include "tube.h"
#include "types.h"
#include <mcs51/8052.h>

/*
 * 0 - 9: 0 1 2 3 4 5 6 7 8 9
 * 10-18: A B C d E F H L -
 */
__code u8 tube_char[] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
  0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x40,
};

void
main (void)
{
  for (u8 i = 0; i < 8; i++)
    tube[i] = 0;

  u8 key = 0;
  tube[0] = tube_char[0];
  tube[1] = tube_char[0];

  for (;;)
    {
      key = scan_btns ();
      if (key != 0)
        {
          tube[0] = tube_char[key % 10];
          tube[1] = tube_char[key / 10];
        }
      show_tube ();
    }
}
