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