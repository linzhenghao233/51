#include <REGX51.h>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"

unsigned char Second;

int main(void){
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1, 1, "hello");
	DS1302_WriteByte(0x8E, 0x00);
	DS1302_WriteByte(0x80, 0x03);

	while(1){
		Second = DS1302_ReadByte(0x81);
		LCD_ShowNum(2, 1, Second, 3);
		Delay(1000);
	}
}