#include <REGX52.h>
#include "delay.h"

unsigned int nixie_table[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,
0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};

void nixie(unsigned int location, unsigned int number){
	switch(location){
		case 1:P2_4 = 1; P2_3 = 1; P2_2 = 1;break;
		case 2:P2_4 = 1; P2_3 = 1; P2_2 = 0;break;
		case 3:P2_4 = 1; P2_3 = 0; P2_2 = 1;break;
		case 4:P2_4 = 1; P2_3 = 0; P2_2 = 0;break;
		case 5:P2_4 = 0; P2_3 = 1; P2_2 = 1;break;
		case 6:P2_4 = 0; P2_3 = 1; P2_2 = 0;break;
		case 7:P2_4 = 0; P2_3 = 0; P2_2 = 1;break;
		case 8:P2_4 = 0; P2_3 = 0; P2_2 = 0;break;
	}
	P0 = nixie_table[number];
	Delay(0.5);
	P0 = 0X00;
}