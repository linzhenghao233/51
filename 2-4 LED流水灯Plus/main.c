#include <REGX52.h>
#define DELAY_TIME 100

void Delay(unsigned int time_ms);

int main(void){
	while(1){
		P2 = 0xFE;	//1111 1110
		Delay(1000);
		P2 = 0xFD;	//1111 1101
		Delay(1000);
		P2 = 0xFB;	//1111 1011
		Delay(DELAY_TIME);
		P2 = 0xF7;	//1111 0111
		Delay(DELAY_TIME);
		P2 = 0xEF;	//1110 1111
		Delay(DELAY_TIME);
		P2 = 0xDF;	//1101 1111
		Delay(DELAY_TIME);
		P2 = 0xBF;	//1011 1111
		Delay(DELAY_TIME);
		P2 = 0x7F;	//0111 1111
		Delay(DELAY_TIME);
	}
}

void Delay(unsigned int time_ms)		//@12.000MHz
{
	unsigned char i, j;
	
	while(time_ms){
		i = 2;
		j = 239;
		do{
			while (--j);
		} while (--i);
		time_ms--;
	}
}