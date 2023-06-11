#include <REGX52.h>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char second = 0, min = 0, hour = 0;

int main(void){
	LCD_Init();
	Timer0Init();
	
	LCD_ShowString(1, 1, "Clock:");
	LCD_ShowString(2, 1, "  :  :");
	while(1){
		LCD_ShowNum(2, 1, hour, 2);
		LCD_ShowNum(2, 4, min, 2);
		LCD_ShowNum(2, 7, second, 2);
	}
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0Count = 0;
	TH0 = 0xFC;
	TL0 = 0x66;
	T0Count++;
	if(T0Count >= 1000){
		T0Count = 0;
		second++;
		if(second == 60){
			second = 0;
			min++;
			if(min == 60){
				min = 0;
				hour++;
				if(hour == 24)
					hour = 0;
			}
		}	
	}
}