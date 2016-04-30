#include<reg52.h>
#include"1602.h"
#include"keyboard.h"
#include"save.h"
#include"take.h"
#include"admin.h"
#define uchar unsigned char 
#define uint unsigned char
int admin = 8888;
uchar number[] ="0123456789";
uint NO1,NO2;
unsigned int boxes[BNUM]={0,0};
int lock;
int main()
{
	int num;
	int count = 0;

	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;    //开中断
	TR0=1;
		
	init();
	P0=0xff;
st:	lock=0;
	while(1)
	{	
		write_com(0x01);
		write_lcd(0x40,"save        take");
		num = key();
		if(num == 100)	//存放模式
		{
			NO1 = TH0;
			NO2 = TL0;
			save2();
		}
		if(num == 11) //取出模式
		{
			take2();
		}
		if(num ==13) //管理员制定打开柜子
		{
			write_com(0x01);
			write_lcd(0x00,"admin:          ");

			if(admin_key() == 1)
			{
				write_com(0x01);
				admin_control();
			}
		}
		if(num == 14)//重置管理员密码
		{
		   write_com(0x01);
		   write_lcd(0x00,"admin:          ");
		   if(admin_key() == 1)
		  	{
				write_com(0x01);
		   		admin_resetkey();
			}
		  
		}
	 if(lock>4)
	 {	 
	 lk:write_com(0x01);
	 	write_lcd(0x00,"    lock on!    ");
		while(1)
		{
			if(key() == 13)
			{
				write_lcd(0x00,"admin:          ");
				if(admin_key() == 1)
				{
					lock = 0;
					 goto st;
				}
				goto lk;
			}
		}
	 }
	}
 	return 0;

}
void timer0() interrupt 1   //中断函数
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
}