#include <REGX52.h>
#include "Delay.h"

sbit RCK = P3^5;	//RCLK
sbit SCK = P3^6;	//SRCLK
sbit SER = P3^4;	//SER

#define MATRIX_LED_PORT P0

void _74HC595_WriteByte(unsigned char Byte);
void MatrixLED_ShowColimn(unsigned char Column,Data);

int main(void){
	SCK = 0;
	RCK = 0;
	
	while(1){
		MatrixLED_ShowColimn(0, 0x3C);
		MatrixLED_ShowColimn(1, 0x42);
		MatrixLED_ShowColimn(2, 0xA9);
		MatrixLED_ShowColimn(3, 0x85);
		MatrixLED_ShowColimn(4, 0x85);
		MatrixLED_ShowColimn(5, 0xA9);
		MatrixLED_ShowColimn(6, 0x42);
		MatrixLED_ShowColimn(7, 0x3C);
	}
}

/**
  * @brief 74HC595写入一个字节
  * @param 要写入的字节
  * @retval 无
  */

void _74HC595_WriteByte(unsigned char Byte){
	unsigned char i;
	for(i = 0; i < 8; i++){
		SER = Byte & (0x80 >> i);
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

/**
  * @brief LED点阵屏显示一列数据
  * @param Column要选择的列，范围：0~7，0在最左边
	* @param Data选择列显示的数据，高位在上，1为亮，0为灭
  * @retval 无
  */

void MatrixLED_ShowColimn(unsigned char Column,Data){
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT = ~(0x80 >> Column);
	Delay(1);
	MATRIX_LED_PORT = 0xFF;
}