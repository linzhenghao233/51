#include <REGX52.h>
#include "Delay.h"
#include "Key.h"
#include "nixie.h"
#include "Buzzer.h"

sbit Buzzer = P2^5;

unsigned char KeyNum;

int main(void){
	nixie(1, 0);
	while(1){
		KeyNum = Key();
		if(KeyNum){
			Buzzer_Time(100); 
			nixie(1, KeyNum);
		}
	}
}