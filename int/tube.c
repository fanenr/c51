#include "tube.h"
#include <mcs51/8052.h>

#define DU P2_6
#define WE P2_7
#define TUBE P0

void
show_tube (u8 val, u8 pos)
{
  TUBE = 0;

  WE = 1;
  DU = 0;
  TUBE = ~pos;

  DU = 1;
  WE = 0;
  TUBE = val;
}
