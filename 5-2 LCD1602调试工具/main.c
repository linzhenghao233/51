#include <REGX52.h>
#include "LCD1602.h"
#include "delay.h"

int result = 0;

int main(void){
	LCD_Init();//初始化
	/*
	LCD_ShowChar(1, 1, 'A');//行，列，字符
	LCD_ShowString(1, 3, "Hello");
	LCD_ShowNum(1, 9, 123, 4);//行，列，十进制数字，显示位数(多截取，少0补)
	LCD_ShowSignedNum(1, 14, -66, 2);//有符号的十进制数字，符号没有包括在位数里
	LCD_ShowHexNum(2, 1, 0xA8, 2);//十六进制
	LCD_ShowBinNum(2, 4, 0xAA, 8);//二进制
	*/
	
	/*
	result = 1 + 1;
	LCD_ShowNum(1, 1, result, 3);
	*/
	while(1){
		LCD_ShowNum(1, 1, result++, 3);
		Delay(1000);
	}
}