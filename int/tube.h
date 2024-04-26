#ifndef TUBE_H
#define TUBE_H

#include "type.h"

/*
 * 0 - 9: 0 1 2 3 4 5 6 7 8 9
 * 10-18: A B C d E F H L -
 */
extern __code u8 tube_char[];

extern void tube_show (u8 val, u8 pos);

#endif
