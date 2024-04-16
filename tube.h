#ifndef TUBE_H
#define TUBE_H

#include "type.h"

/* tube_data holds 8 chars: right to left */
extern u8 tube_data[];

/*
 * 0 - 9: 0 1 2 3 4 5 6 7 8 9
 * 10-18: A B C d E F H L -
 */
extern __code u8 tube_char[];

/* show tube_data */
extern void tube_show (void);

#endif