#ifndef TIMER_H
#define TIMER_H

#define CLOCK_CYCLE   (1.0 / 11059200)
#define MACHINE_CYCLE (12 * CLOCK_CYCLE)

extern void delay(float secs);

#endif