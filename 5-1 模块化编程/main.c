#include <REGX52.h>
#include "Delay.h"
#include "nixie.h"

int main(void){
	while(1){
		nixie(1,2);
		nixie(2,3);
		nixie(3,3);
		nixie(4,3);
		nixie(5,3);
		nixie(6,3);
	}
}