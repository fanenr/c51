#include "lcd.h"
#include "timer.h"
#include <mcs51/8052.h>

#define LCD_DB P0
#define LCD_RS P3_5
#define LCD_RW P3_6
#define LCD_EN P3_4

char str1[32] = "hello world, hello 51, hello c.";
char str2[32] = "hello c, hello 51, hello world.";

void
main (void)
{
  lcd_init ();

  for (u8 i = 0; i < 31;)
    {
      lcd_show (0, 0, str1 + i);
      lcd_show (0, 1, str2 + i);
      i = i >= 15 ? 0 : i + 1;
      delay_msecs (1000);
    }
}
