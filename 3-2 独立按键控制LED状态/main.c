#include <REGX52.h>

void Delay(unsigned int time_ms);

int main(void){
	while(1){
		if(P3_1 == 0){
			Delay(20);
			while(P3_1 == 0);
			
			P2_0 = ~P2_0;
		}
	}
}

void Delay(unsigned time_ms)		//@12.000MHz
{
	unsigned char i, j;

	while(time_ms){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		time_ms--;
	}
}
