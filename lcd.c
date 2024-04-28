#include "lcd.h"
#include <mcs51/8052.h>

#define LCD_DB P0
#define LCD_RS P3_5
#define LCD_RW P3_6
#define LCD_EN P3_4

static inline void
wait (void)
{
  LCD_DB = 0xff;
  LCD_RS = 0;
  LCD_RW = 1;
  u8 sts;

  do
    {
      LCD_EN = 1;
      sts = LCD_DB;
      LCD_EN = 0;
    }
  while (sts & 0x80);
}

static inline void
write_cmd (u8 cmd)
{
  wait ();
  LCD_RS = 0;
  LCD_RW = 0;
  LCD_DB = cmd;
  LCD_EN = 1;
  LCD_EN = 0;
}

static inline void
write_data (u8 data)
{
  wait ();
  LCD_RS = 1;
  LCD_RW = 0;
  LCD_DB = data;
  LCD_EN = 1;
  LCD_EN = 0;
}

void
lcd_init (void)
{
  write_cmd (0x38);
  write_cmd (0x0C);
  write_cmd (0x06);
  write_cmd (0x01);
}

void
lcd_show (u8 x, u8 y, const char *str)
{
  /* set cursor */
  if (y != 0)
    x += 0x40;
  write_cmd (x | 0x80);

  /* send data */
  while (*str != 0)
    write_data (*str++);
}
