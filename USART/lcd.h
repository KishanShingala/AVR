#include <util/delay.h>
#include <string.h>
#include <avr/io.h>
void lcd_cmd(char cmd);

void lcd_data(char data);

void lcd_init();

void gotoxy(unsigned char x, unsigned char y);

void lcd_string(unsigned char str[]);