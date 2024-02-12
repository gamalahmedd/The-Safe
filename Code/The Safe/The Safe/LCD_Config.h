#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#define eight_bit_mode
#define CLR_SCREEN 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define DISPLAY_ON_CURSOR_ON 0x0C
#define SHIFT_AC_LEFT 0x10
#define SHIFT_AC_RIGHT 0x14
#define SHIFT_DISPLAY_LEFT 0x18
#define SHIFT_DISPLAY_RIGHT 0x1C
#define EIGHT_BITS 0x38
#define FOUR_BITS 0x28
#define EN 0
#define RS 1
#define RW 2
#define LCD_PORT 'A'
#define CONTROL_PORT 'B'
#endif