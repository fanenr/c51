#include "timer.h"
#include "tube.h"
#include "type.h"
#include <mcs51/8052.h>

u8
btns_scan (void)
{
  P3 = 0xf0;
  u8 ret = 0;

  if (P3 == 0xf0)
    return 0;

  delay_msecs (10);
  switch (P3)
    {
    case 0xe0:
      ret = 1;
      break;
    case 0xd0:
      ret = 2;
      break;
    case 0xb0:
      ret = 3;
      break;
    case 0x70:
      ret = 4;
      break;
    default:
      return 0;
    }

  P3 = 0x0f;
  switch (P3)
    {
    case 0x0e:
      break;
    case 0x0d:
      ret += 4;
      break;
    case 0x0b:
      ret += 8;
      break;
    case 0x07:
      ret += 12;
      break;
    default:
      return 0;
    }

  while (P3 != 0x0f)
    ;

  delay_msecs (10);
  return ret;
}

void
main (void)
{
  for (u8 i = 0; i < 8; i++)
    tube_data[i] = 0;

  u8 key = 0;
  tube_data[0] = tube_char[0];
  tube_data[1] = tube_char[0];

  for (;;)
    {
      key = btns_scan ();
      if (key != 0)
	{
	  tube_data[0] = tube_char[key % 10];
	  tube_data[1] = tube_char[key / 10];
	}
      tube_show ();
    }
}
