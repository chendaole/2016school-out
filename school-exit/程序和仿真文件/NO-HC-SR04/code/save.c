#include "save.h"
#include "1602.h"
#include "keyboard.h"
#include "LED.h"
#define uchar unsigned char 
#define uint unsigned char
extern unsigned char number[10];
extern uint NO1,NO2;
extern unsigned int boxes[12];
int  save2()
 {
 	uint temp;
	uint iter;
 	uint clock_num[4];

	for(iter = 0 ; iter<12 ; iter++)
	{
		if(boxes[iter] == 0)
		{
			clock_num[0] = NO1%10;
			clock_num[1] = NO1%9;
			clock_num[2] = NO2%10;
			clock_num[3] = NO2%9;

 			write_com(0x01);
   			write_lcd(0x00,"key:");

			temp =clock_num[0];
			disp_lcd(0x40,number[temp]);
			temp =clock_num[1];
			disp_lcd(0x41,number[temp]);
			temp =clock_num[2];
			disp_lcd(0x42,number[temp]);
			temp =clock_num[3];
			disp_lcd(0x43,number[temp]);

			boxes[iter] = clock_num[0]*1000+clock_num[1]*100+clock_num[2]*10+clock_num[3];
			select_led(iter);
			goto L;
		}
	}

L:	while(1)
	{
		if(key() == 12)
		{
		return 1;
		}	
	}
 }