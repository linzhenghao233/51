#include <REGX52.h>
#include "Delay.h"
#include "MatrixLED.h"





int main(void){
	MatrixLED_Init()
	while(1){
		MatrixLED_ShowColimn(0, 0x3C);
		MatrixLED_ShowColimn(1, 0x42);
		MatrixLED_ShowColimn(2, 0xA9);
		MatrixLED_ShowColimn(3, 0x85);
		MatrixLED_ShowColimn(4, 0x85);
		MatrixLED_ShowColimn(5, 0xA9);
		MatrixLED_ShowColimn(6, 0x42);
		MatrixLED_ShowColimn(7, 0x3C);
	}
}

