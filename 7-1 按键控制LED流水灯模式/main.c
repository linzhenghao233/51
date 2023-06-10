#include <REGX52.h>

void Timer0_Init();

int main(void){
	Timer0_Init();
	while(1){
		
	}
}

void Timer0Init(void)		//1毫秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xCD;		//设置定时初值
	TH0 = 0xD4;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}

void Timer0_Init(){
	//TMOD = 0x01;	//0000 0001，十六位
	TMOD &= 0xF0;	//把TMOD的低四位清零，高四位保持不变
	TMOD |= 0x01;	//把TMOD的最低位置一，高四位保持不变
	TF0 = 0;	//溢出中断标志
	TR0 = 1;	//开始工作
	/*一个寄存器存8位（2的8次方等于256），要存65535即需16位，此时就把
	两个寄存器拼起来，从而达到存16位的目的。
	TL0存256以下的数，TH0存以上的*/
	TH0 = 64535 / 256;
	TL0 = 64535 % 256;
	
	//中断器启动
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

unsigned int T0Count = 0;
void Timer0_Routine() interrupt 1{
	TH0 = 64535 / 256;
	TL0 = 64535 % 256;
	T0Count++;
	if(T0Count >= 1000){
		T0Count = 0;
		P2_0 = ~P2_0;
	}
}