#ifndef TIMER_H
#define TIMER_H

#include "types.h"

extern void delay_cycles(u32 cycles);

#define US_PER_MCYCLE 1.085

static inline void
delay_msecs(f32 msecs)
{
    delay_cycles(1000 * msecs / US_PER_MCYCLE);
}

static inline void
delay_secs(f32 secs)
{
    delay_msecs(1000 * secs);
}

/* #define delay_msecs(msecs) delay_cycles(1000 * (msecs) / US_PER_MCYCLE) */
/* #define delay_secs(secs)   delay_msecs(1000 * (secs)); */

#endif
