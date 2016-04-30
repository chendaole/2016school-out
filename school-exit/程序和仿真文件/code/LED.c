#include<reg52.h>
#define uint unsigned int

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
 }

}