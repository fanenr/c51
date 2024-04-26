#include "int.h"
#include <mcs51/8052.h>

int_info_t int_info;

void
int_init (u16 us, int_func_t *fn)
{
  TR0 = 0;
  TMOD &= 0xf0;
  TMOD |= 0x01;
  ET0 = EA = 1;

  int_info.func = fn;
  int_info.cycs = 0xffff - us;
  int_info.times = int_info.flag = 0;
}

void
int_start (void)
{
  TH0 = int_info.cycs >> 8;
  TL0 = int_info.cycs;
  TR0 = 1;
}

void
int_stop (void)
{
  TR0 = 0;
}

void
int_event (void) __interrupt (1)
{
  TL0 = int_info.cycs;  
  TH0 = int_info.cycs >> 8;

  int_info.times++;
  int_info.flag = 1;
  if (int_info.func)
    int_info.func ();
}
