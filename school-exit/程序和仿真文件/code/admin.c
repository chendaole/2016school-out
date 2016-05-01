#include"keyboard.h"
#include"1602.h"
#include"LED.h"
extern unsigned char number[];
extern unsigned int boxes[];//声明外部变量
extern int admin;
int admin_key()	//管理员密码校验程序
{
	int iter;
	int i;
	int temp[4];
	int key_temp;

	 /* key_temp=key();
	  disp_lcd(0x00,number[key_temp]);
	  disp_lcd(0x01,number[admin]);
	  while(1);*/  //测试
 lp3:write_lcd(0x40,"                 ");
	for( iter = 0 ; iter < 4 ; iter++ )
	{
		i = key();
		if(i == 12)
		{
			return 0;
		} else if(i > 9)
		{
			goto lp3;
		}
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
void admin_control()//管理员控制
{	int num,x,i;
lp2:
	num = 0;
	write_lcd(0x00,"please input num");
	for(i=0 ; i<2 ; i++)
	{
	   x = key();
	   if(x > 9)
	   {
	   	 goto lp2;
	   }
	   if(x== 12)
	   {
	   	goto end;
	   }
	   disp_lcd(0x40+i,number[x]);
	   if(i == 0)
	   {
	   num += x*10;
	   }
	   else
	   {
	   	num += x;
	   }
	   if(num>12)
	   {
	   	write_lcd(0x40,"               ");
		num =0;
		i = -1;
	   }
	}
	open_led(num);
	boxes[num]=0;
end: write_com(0x01);
}
void admin_resetkey()//管理员密码重置
{
	int iter;
	int i;
	int temp[4];
	write_lcd(0x00,"reset_adminkey:  ");
 lp3:write_lcd(0x40,"                 ");
	for( iter = 0 ; iter < 4 ; iter++ )
	{
		i = key();
		if(i > 9)
		{
			goto lp3;
		}else if(i == 12)
		{
			goto over;
		}
		temp[iter] = i;
		disp_lcd(0x40+iter,number[i]);
			
	}
	admin = temp[0]*1000+temp[1]*100+temp[2]*10+temp[0];
over:;	  
}