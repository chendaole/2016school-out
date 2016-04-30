#include<reg51.h>
#include"LED.h"
#define uint unsigned int
sbit led0 = P2^0;
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;
sbit led4 = P2^4;
sbit led5 = P2^5;
sbit led6 = P2^6;
sbit led7 = P2^7;
sbit led8 = P3^0;
sbit led9 = P3^1;
sbit led10 = P3^2;
sbit led11 = P3^3;

void select_led(uint i)
{
 switch(i)
 {
 	case 0: led0 = 0;break;
	case 1: led1 = 0;break;
	case 2: led2 = 0;break;
	case 3: led3 = 0;break;
	case 4: led4 = 0;break;
	case 5: led5 = 0;break;
	case 6: led6 = 0;break;
	case 7: led7 = 0;break;
	case 8: led8 = 0;break;
	case 9: led9 = 0;break;
	case 10: led10 = 0;break;
	case 11: led11 = 0;break;
 }

}
void open_led(uint i)
{
 switch(i)
 {
 	case 0: led0 = 1;break;
	case 1: led1 = 1;break;
	case 2: led2 = 1;break;
	case 3: led3 = 1;break;
	case 4: led4 = 1;break;
	case 5: led5 = 1;break;
	case 6: led6 = 1;break;
	case 7: led7 = 1;break;
	case 8: led8 = 1;break;
	case 9: led9 = 1;break;
	case 10: led10 = 1;break;
	case 11: led11 = 1;break;
 }

}