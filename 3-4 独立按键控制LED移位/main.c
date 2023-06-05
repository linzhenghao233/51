#include <REGX52.h>

void Delay(unsigned int time_ms);

int main(void){
	unsigned int led_num = 0;
	P2 = ~0x01;
	while(1){
		if(P3_1 == 0){
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			led_num++;
			if(led_num >= 8)
				led_num = 0;
			P2 = ~(0x01<<led_num);
		}
		if(P3_0 == 0){
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			
			if(led_num == 0)
				led_num = 7;
			else
				led_num--;
			P2 = ~(0x01<<led_num);
		}
	}
}

void Delay(unsigned int time_ms){		//@12.000MHz
	unsigned char i, j;
	while(time_ms--){
		i = 2;
		j = 239;
		do{
			while (--j);
		} while (--i);
	}
}