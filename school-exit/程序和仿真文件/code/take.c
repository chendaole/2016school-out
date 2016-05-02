#include"keyboard.h"
#include"1602.h"
#include"LED.h"
#include"timer.h"
extern unsigned int boxes[12];
extern unsigned char number[10];
extern int  lock;
void take2()
{
	int err=0;
	int iter = 0;
	int temp[4] = {0};
	int num[4]={0};
	int i;
	write_com(0x01);
 	write_lcd(0x00,"please input key");

	num[0] = key();
	i = num[0];
	disp_lcd(0x40,number[i]);

	num[1] = key();
	i = num[1];
	disp_lcd(0x41,number[i]);

	num[2] = key();
	i = num[2];
	disp_lcd(0x42,number[i]);

	num[3] = key();
	i = num[3];
	disp_lcd(0x43,number[i]); 

	for(iter = 0 ; iter<12 ; iter++)
	{
		temp[0] = boxes[iter]/1000;
		temp[1] = (boxes[iter]%1000)/100;
		temp[2] = (boxes[iter]%100)/10;
		temp[3] = boxes[iter]%10;

		if(temp[0] == num[0] && temp[1] == num[1] && temp[2] == num[2] && temp[3] == num[3] )
		{
		 	open_led(iter);
			boxes[iter]=0;
			lock = 0;
			goto end;
		} 
	} 
	lock++;
end: ;
}