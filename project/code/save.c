#include<reg52.h>
#include "1602.h"
#include "keyboard.h"
#include "LED.h"
#include "SR04.h"
#define uchar unsigned char 
#define uint unsigned char
extern unsigned char number[10];
extern uint NO1,NO2;
extern unsigned int boxes[];
int  save2()
 {
 	uint temp;
	uint iter;
	uint userkey_temp;
 	uint clock_num[4];
	int i;

	for(iter = 0 ; iter<BNUM ; iter++)
	{
		if(boxes[iter] == 0)
		{
	restart:clock_num[0] = NO1%10;
			clock_num[1] = NO1%9;
			clock_num[2] = NO2%10;
			clock_num[3] = NO2%9;

 			write_com(0x01);
   			write_lcd(0x00,"key:            ");

			temp =clock_num[0];
			disp_lcd(0x40,number[temp]);
			temp =clock_num[1];
			disp_lcd(0x41,number[temp]);
			temp =clock_num[2];
			disp_lcd(0x42,number[temp]);
			temp =clock_num[3];
			disp_lcd(0x43,number[temp]);

			userkey_temp = clock_num[0]*1000+clock_num[1]*100+clock_num[2]*10+clock_num[3];
			for(i = 0 ; i<BNUM ; i++)  //查询密码是否有相同的柜子
			{
				if(boxes[i] == userkey_temp)
				{
					NO1 = TH0;
					NO2 = TL0;
					goto restart;
				}
			}
			boxes[iter] = userkey_temp;
			select_led(iter);
			goto L;
		}
	}

L:	while(1)
	{
		if(location()>80)	  //返回
		{
		return 1;
		}	
	}
 }