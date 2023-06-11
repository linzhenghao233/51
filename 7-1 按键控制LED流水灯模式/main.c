#include <REGX52.h>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.h>

//void Timer0_Init();
unsigned char KeyNum, LEDMode = 0;

int main(void){
	P2 = 0xFE;
	Timer0Init();
	while(1){
		KeyNum = Key();
		if(KeyNum){
			if(KeyNum == 1){
				LEDMode++;
				if(LEDMode >= 2)LEDMode = 0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0Count = 0;
	TH0 = 0xFC;
	TL0 = 0x66;
	T0Count++;
	if(T0Count >= 500){
		T0Count = 0;
		if(LEDMode == 0)
			P2 = _crol_(P2,1);
		if(LEDMode == 1)
			P2 = _cror_(P2,1);
	}
}

//void Timer0_Init(){
//	//TMOD = 0x01;	//0000 0001，十六位
//	TMOD &= 0xF0;	//把TMOD的低四位清零，高四位保持不变
//	TMOD |= 0x01;	//把TMOD的最低位置一，高四位保持不变
//	TF0 = 0;	//溢出中断标志
//	TR0 = 1;	//开始工作
//	/*一个寄存器存8位（2的8次方等于256），要存65535即需16位，此时就把
//	两个寄存器拼起来，从而达到存16位的目的。
//	TL0存256以下的数，TH0存以上的*/
//	TH0 = 64535 / 256;
//	TL0 = 64535 % 256;
//	
//	//中断器启动
//	ET0 = 1;
//	EA = 1;
//	PT0 = 0;
//}