#include <REGX52.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password = 0, Count = 0;

int main(void){
	LCD_Init();
	LCD_ShowString(1, 1, "Password:");
	while(1){
		KeyNum = MatrixKey();
		if(KeyNum){
			if(KeyNum <= 10 && Count++ < 4){	//如果按下S1~S10按键：输入密码;只能输入4位密码
				Password *= 10;	//密码左移一位
				Password += KeyNum % 10;	//获取一位密码
			}
			LCD_ShowNum(2, 1, Password, 4);	//显示密码
			
			if(KeyNum == 11){	//确认密码
				if(Password == 2345){
					LCD_ShowString(1, 14, "OK!");
					Password = 0;
					Count = 0;
					LCD_ShowNum(2, 1, Password, 4);
				}
				else{
					LCD_ShowString(1, 14, "ERR");
					Password = 0;
					Count = 0;
					LCD_ShowNum(2, 1, Password, 4);
				}
			}
			
			if(KeyNum == 12){	//重输密码
				LCD_Init();
				LCD_ShowString(1, 1, "Password:");
				Password = 0;
				Count = 0;
				LCD_ShowNum(2, 1, Password, 4);
			}
		}
	}
}