#include<avr/io.h>
#include <util/delay.h>

#define LCD_port PORTA
#define LCD_ctrl PORTB
#define LCD_port_ddr DDRA
#define LCD_ctrl_ddr DDRB
#define LCD_RS 0
#define LCD_RW 1
#define LCD_E 2
#define SETB(x,y) x |= (1<<y)
#define CLRB(x,y) x &= ~(1<<y)
#define COMB(x,y) x ^= (1<<y)

void lcd_cmd(char cmd){
	LCD_port = cmd;
	CLRB(LCD_ctrl,LCD_RS);
	CLRB(LCD_ctrl,LCD_RW);
	SETB(LCD_ctrl,LCD_E);
	_delay_ms(100);
	CLRB(LCD_ctrl,LCD_E);
}

void lcd_data(char data){
	LCD_port = data;
	SETB(LCD_ctrl,LCD_RS);
	CLRB(LCD_ctrl,LCD_RW);
	SETB(LCD_ctrl,LCD_E);
	_delay_ms(1);
	CLRB(LCD_ctrl,LCD_E);
}

void lcd_init(){
	LCD_port_ddr = 0xFF;
	LCD_ctrl_ddr = 0xFF;
	lcd_cmd(0x38);
	lcd_cmd(0x0E);
	lcd_cmd(0x01);
	lcd_cmd(0x06);
}

void gotoxy(unsigned char x, unsigned char y){
	unsigned char f[] = {0x80,0xC0,0x94,0xD4};
	lcd_cmd(f[y-1]+x-1);
	_delay_ms(1);
}

void lcd_string(unsigned char str[]){
	unsigned int i =0,count = 0;
	while(str[i]!='\0'){
		lcd_data(str[i++]);
	}
}
