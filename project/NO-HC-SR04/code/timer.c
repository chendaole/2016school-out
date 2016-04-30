#include "timer.h"
#define uint unsigned int
#define uchar unsigned char
void delay(uint z)   //ÑÓÊ±º¯Êý
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void key_delay(void) 
{
   unsigned int i;   
	for(i=0;i<200;i++);
}