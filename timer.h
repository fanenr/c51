#ifndef TIMER_H
#define TIMER_H

#include "type.h"

#define US_PER_MCYCLE 1.085

extern void delay_cycles (u32 cycles);

static inline void
delay_msecs (f32 msecs)
{
  delay_cycles (1000 * msecs / US_PER_MCYCLE);
}

static inline void
delay_secs (f32 secs)
{
  delay_msecs (1000 * secs);
}

#endif
