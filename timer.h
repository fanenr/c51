#ifndef TIMER_H
#define TIMER_H

#include "type.h"

extern void delay_ms (void);

#define delay_msecs(ms)                                                       \
  do                                                                          \
    {                                                                         \
      u32 n = (ms);                                                           \
      while (n--)                                                             \
	delay_ms ();                                                          \
    }                                                                         \
  while (0)

#define delay_secs(ss)                                                        \
  do                                                                          \
    {                                                                         \
      u32 n = 1000 * (ss);                                                    \
      while (n--)                                                             \
	delay_ms ();                                                          \
    }                                                                         \
  while (0)

#endif
