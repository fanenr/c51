#ifndef LATTICE_H
#define LATTICE_H

#include "types.h"

extern void send_byte(u8 low);
extern void send_bytes(u8 low, u8 high);
extern void show_lattice(u8 val, u8 pos);

#endif
