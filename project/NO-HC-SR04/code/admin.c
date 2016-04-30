#include"admin.h"
#include"keyboard.h"
#include"1602.h"
extern unsigned char number[];
int admin = 8888;
int admin_key()
{
	int iter;
	int i;
	int temp[4] = {0};
	int key_temp;

	 /* key_temp=key();
	  disp_lcd(0x00,number[key_temp]);
	  disp_lcd(0x01,number[admin]);
	  while(1);*/  //²âÊÔ
	for( iter = 0 ; iter < 4 ; iter++ )
	{
		i = key();
		temp[iter] = i;
		disp_lcd(0x40+iter,number[i]);
			
	}
	key_temp = temp[0]*1000+temp[1]*100+temp[2]*10+temp[0];	  
	if(key_temp == admin)
	{
	 	return 1;
	}
	else
	{
		return 0;
	}
}