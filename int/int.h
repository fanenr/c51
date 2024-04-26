#ifndef INT_H
#define INT_H

#include "type.h"

typedef struct int_info_t int_info_t;
typedef void int_func_t (void);

struct int_info_t
{
  u16 cycs;
  u16 flag : 1;
  u16 times : 15;
  int_func_t *func;
};

extern int_info_t int_info;

extern void int_init (u16 us, int_func_t *fn);
extern void int_event (void) __interrupt (1);
extern void int_start (void);
extern void int_stop (void);

#endif
