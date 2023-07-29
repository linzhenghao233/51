void Delay(unsigned int time_ms)		//@11.0592MHz
{
	unsigned char i, j;

	while(time_ms--){
		i = 2;
		j = 199;
		do{
			while (--j);
		} while (--i);
	}
}