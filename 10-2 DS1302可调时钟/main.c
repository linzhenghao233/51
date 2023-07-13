#include <REGX51.h>
#include "LCD1602.h"
#include "DS1302.h"
#include "Key.h"
#include "Timer0.h"

unsigned char KeyNumber, Mode, TimeSetSelect, TimeSetFlashFlag;

void TimeShow(void);
void TimeSet(void);

int main(void){
	LCD_Init();
	DS1302_Init();
	Timer0Init();
	LCD_ShowString(1, 1, "  -  -  ");
	LCD_ShowString(2, 1, "  :  :  ");
	
	DS1302_SetTime();

	while(1){
		KeyNumber = Key();
		if(KeyNumber == 1){
			Mode = Mode > 0 ? 0 : 1;
			if(!Mode)
				DS1302_SetTime();
			if(Mode)
				TimeSetSelect = 0;
		}
		
		switch(Mode){
			case 0: TimeShow();break;
			case 1: TimeSet();break;
		}
	}
}

void TimeShow(void){
	DS1302_ReadTime();
	LCD_ShowNum(1, 1, DS1302_Time[0], 2);
	LCD_ShowNum(1, 4, DS1302_Time[1], 2);
	LCD_ShowNum(1, 7, DS1302_Time[2], 2);
	LCD_ShowNum(2, 1, DS1302_Time[3], 2);
	LCD_ShowNum(2, 4, DS1302_Time[4], 2);
	LCD_ShowNum(2, 7, DS1302_Time[5], 2);
}

void TimeSet(void){
	if(KeyNumber == 2){
		TimeSetSelect++;
		TimeSetSelect %= 6;	//越界清零
	}
	if(KeyNumber == 3){
		DS1302_Time[TimeSetSelect]++;
		if(DS1302_Time[0] > 99)DS1302_Time[0] = 0;
		if(DS1302_Time[1] > 12)DS1302_Time[1] = 1;
		if(DS1302_Time[1] == 1 || DS1302_Time[1] == 3 || DS1302_Time[1] == 5 || 
			 DS1302_Time[1] == 7 || DS1302_Time[1] == 8 || DS1302_Time[1] == 10 || 
			 DS1302_Time[1] == 12){
				if(DS1302_Time[2] > 31)DS1302_Time[2] = 1;
			 }
		else if(DS1302_Time[1] == 4 || DS1302_Time[1] == 6 || DS1302_Time[1] == 9 || 
						DS1302_Time[1] == 11){
							if(DS1302_Time[2] > 30)DS1302_Time[2] = 1;
						}
		else if(DS1302_Time[1] == 2){
			if(DS1302_Time[0] % 4 == 0){
				if(DS1302_Time[2] > 29)DS1302_Time[2] = 1;
			}
			else{
				if(DS1302_Time[2] > 28)DS1302_Time[2] = 1;
			}
		}
		if(DS1302_Time[3] > 23)DS1302_Time[3] = 0;
		if(DS1302_Time[4] > 59)DS1302_Time[4] = 0;
		if(DS1302_Time[5] > 59)DS1302_Time[5] = 0;
	}
	if(KeyNumber == 4){
		DS1302_Time[TimeSetSelect]--;
		if(DS1302_Time[0] < 0)DS1302_Time[0] = 99;
		if(DS1302_Time[1] < 1)DS1302_Time[1] = 12;
		if(DS1302_Time[1] == 1 || DS1302_Time[1] == 3 || DS1302_Time[1] == 5 || 
			 DS1302_Time[1] == 7 || DS1302_Time[1] == 8 || DS1302_Time[1] == 10 || 
			 DS1302_Time[1] == 12){
				if(DS1302_Time[2] < 1)DS1302_Time[2] = 31;
				if(DS1302_Time[2] > 31)DS1302_Time[2] = 1;
			 }
		else if(DS1302_Time[1] == 4 || DS1302_Time[1] == 6 || DS1302_Time[1] == 9 || 
						DS1302_Time[1] == 11){
							if(DS1302_Time[2] < 1)DS1302_Time[2] = 30;
							if(DS1302_Time[2] > 30)DS1302_Time[2] = 1;
						}
		else if(DS1302_Time[1] == 2){
			if(DS1302_Time[0] % 4 == 0){
				if(DS1302_Time[2] < 1)DS1302_Time[2] = 29;
				if(DS1302_Time[2] > 29)DS1302_Time[2] = 1;
			}
			else{
				if(DS1302_Time[2] < 1)DS1302_Time[2] = 28;
				if(DS1302_Time[2] > 28)DS1302_Time[2] = 1;
			}
		}
		if(DS1302_Time[3] < 0)DS1302_Time[3] = 23;
		if(DS1302_Time[4] < 0)DS1302_Time[4] = 59;
		if(DS1302_Time[5] < 0)DS1302_Time[5] = 59;
	}
	if(TimeSetSelect == 0 && TimeSetFlashFlag == 1)
		LCD_ShowString(1, 1, "  ");
	else
		LCD_ShowNum(1, 1, DS1302_Time[0], 2);
	if(TimeSetSelect == 1 && TimeSetFlashFlag == 1)
		LCD_ShowString(1, 4, "  ");
	else
		LCD_ShowNum(1, 4, DS1302_Time[1], 2);
	if(TimeSetSelect == 2 && TimeSetFlashFlag == 1)
		LCD_ShowString(1, 7, "  ");
	else
		LCD_ShowNum(1, 7, DS1302_Time[2], 2);
	if(TimeSetSelect == 3 && TimeSetFlashFlag == 1)
		LCD_ShowString(2, 1, "  ");
	else
		LCD_ShowNum(2, 1, DS1302_Time[3], 2);
	if(TimeSetSelect == 4 && TimeSetFlashFlag == 1)
		LCD_ShowString(2, 4, "  ");
	else
		LCD_ShowNum(2, 4, DS1302_Time[4], 2);
	if(TimeSetSelect == 5 && TimeSetFlashFlag == 1)
		LCD_ShowString(2, 7, "  ");
	else
		LCD_ShowNum(2, 7, DS1302_Time[5], 2);
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0Count = 0;
	TH0 = 0xFC;
	TL0 = 0x66;
	T0Count++;
	if(T0Count >= 500){
		T0Count = 0;
		TimeSetFlashFlag = !TimeSetFlashFlag;
	}
}