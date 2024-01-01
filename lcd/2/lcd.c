#include "timer.h"
#include "types.h"
#include <mcs51/8052.h>

#define LCD_DB P0
#define LCD_RS P3_5
#define LCD_RW P3_6
#define LCD_EN P3_4

void init_lcd(void);
void show_lcd(u8 x, u8 y, const u8 *str, u8 len);

char str1[32] = "hello world, hello 51, hello c.";
char str2[32] = "hello c, hello 51, hello world.";

void
main(void)
{
    init_lcd();

    for (u8 i = 0; i < 31;) {
        show_lcd(0, 0, str1 + i, 16);
        show_lcd(0, 1, str2 + i, 16);
        i = i >= 15 ? 0 : i + 1;
        delay_msecs(1000);
    }
}

static void
wait(void)
{
    LCD_DB = 0xFF;
    LCD_RS = 0;
    LCD_RW = 1;

    u8 sts;
    do {
        LCD_EN = 1;
        sts = LCD_DB;
        LCD_EN = 0;
    } while (sts & 0x80);
}

static void
write_cmd(u8 cmd)
{
    wait();
    LCD_RS = 0;
    LCD_RW = 0;
    LCD_DB = cmd;
    LCD_EN = 1;
    LCD_EN = 0;
}

static void
write_data(u8 data)
{
    wait();
    LCD_RS = 1;
    LCD_RW = 0;
    LCD_DB = data;
    LCD_EN = 1;
    LCD_EN = 0;
}

void
show_lcd(u8 x, u8 y, const u8 *str, u8 len)
{
    /* set cursor */
    if (y != 0)
        x += 0x40;
    write_cmd(x | 0x80);

    /* send data */
    for (u8 i = 0; i < len && str[i]; i++)
        write_data(str[i]);
}

void
init_lcd(void)
{
    write_cmd(0x38);
    write_cmd(0x0C);
    write_cmd(0x06);
    write_cmd(0x01);
}
