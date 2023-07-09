#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__

void MatrixLED_Init();
void _74HC595_WriteByte(unsigned char Byte);
void MatrixLED_ShowColimn(unsigned char Column,Data);

#endif