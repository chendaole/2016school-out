#define uint unsigned int
#define uchar unsigned char
void delay(uint z)   //ÑÓÊ±º¯Êý
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=114;y>0;y--);
}