#include <REGX52.h>
#include "Delay.h"
#include "UART.h"

unsigned char Sec = 0;

int main(void){
	UART_Init();
	
	while(1){
		UART_SendByte(Sec++);
		Delay(1000);	//输出过快有时会出错，所以延迟下
	}
}

