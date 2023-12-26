#ifndef INT_H
#define INT_H

#include "types.h"

extern void loop_int_cycles(u16 cycles);

#define US_PER_MCYCLE   1.085
/* #define MAX_LOOP_INT_MS 71.0 */

static inline void
loop_int_msecs(float msecs)
{
    loop_int_cycles(1000 * msecs / US_PER_MCYCLE);
}

#endif
