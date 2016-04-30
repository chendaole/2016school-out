#include<reg51.h>
#include"timer.h"
#define uchar unsigned char 
#define uint unsigned char
sbit lcden=P3^7;
sbit lcdrw=P3^6;
sbit lcdrs=P3^4;

void write_com(uchar com)   //命令子函数command 
{
	lcdrs=0;//接受指令
	P0=com; //给P0口送指令码
	delay(5);
	lcden=1; //E变为高电平
	delay(5);//在此延迟期间，将指令送入
	lcden=0; //E变为低电平，高脉冲结束
}

void write_data(uchar date)  //数据子函数data
{
	lcdrs=1; //接受数据
	P0=date; //给P0口送数据
	delay(5);
	lcden=1;  //E变为高电平
	delay(5); //在此延迟期间，将数据送入
	lcden=0; //E变为低电平，高脉冲结束
}
void init() //初始函数
{
	lcdrw=0;
	lcden=0; //E的初始值为低电平，后面的程序给高电平从而满足E为高脉冲
	write_com(0x38); //写入显示模式指令
	write_com(0x0e); //显示是否打开以及光标的设置
	write_com(0x06); //地址指针的加减和整屏是否移动
	write_com(0x01); //清屏指令
	write_com(0x80+0x00); //显示字符的初始位置

}
void write_lcd(uint offset,uchar tab[])
{
	uint num;
 	write_com(0x80+offset); //显示字符的初始位置
	for(num=0;num<16;num++)
	{
		write_data(tab[num]);
		delay(20);
	}
}
void disp_lcd(uint offset,uchar c)
{
 	write_com(0x80+offset); //显示字符的初始位置
	write_data(c);//些数据
}