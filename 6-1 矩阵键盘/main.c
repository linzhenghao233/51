#include <REGX52.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;

int main(void){
	LCD_Init();
	LCD_ShowString(1, 1, "HelloWorld");
	while(1){
		KeyNum = MatrixKey();
		if(KeyNum){
			LCD_ShowNum(2, 1, KeyNum, 2);
		}
	}
}