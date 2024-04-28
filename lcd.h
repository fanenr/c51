#ifndef LCD_H
#define LCD_H

#include "type.h"

extern void lcd_init (void);
extern void lcd_show (u8 x, u8 y, const char *str);

#endif
