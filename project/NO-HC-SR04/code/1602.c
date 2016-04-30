#include<reg51.h>
#include"timer.h"
#define uchar unsigned char 
#define uint unsigned char
sbit lcden=P3^7;
sbit lcdrw=P3^6;
sbit lcdrs=P3^4;

void write_com(uchar com)   //�����Ӻ���command 
{
	lcdrs=0;//����ָ��
	P0=com; //��P0����ָ����
	delay(5);
	lcden=1; //E��Ϊ�ߵ�ƽ
	delay(5);//�ڴ��ӳ��ڼ䣬��ָ������
	lcden=0; //E��Ϊ�͵�ƽ�����������
}

void write_data(uchar date)  //�����Ӻ���data
{
	lcdrs=1; //��������
	P0=date; //��P0��������
	delay(5);
	lcden=1;  //E��Ϊ�ߵ�ƽ
	delay(5); //�ڴ��ӳ��ڼ䣬����������
	lcden=0; //E��Ϊ�͵�ƽ�����������
}
void init() //��ʼ����
{
	lcdrw=0;
	lcden=0; //E�ĳ�ʼֵΪ�͵�ƽ������ĳ�����ߵ�ƽ�Ӷ�����EΪ������
	write_com(0x38); //д����ʾģʽָ��
	write_com(0x0e); //��ʾ�Ƿ���Լ���������
	write_com(0x06); //��ַָ��ļӼ��������Ƿ��ƶ�
	write_com(0x01); //����ָ��
	write_com(0x80+0x00); //��ʾ�ַ��ĳ�ʼλ��

}
void write_lcd(uint offset,uchar tab[])
{
	uint num;
 	write_com(0x80+offset); //��ʾ�ַ��ĳ�ʼλ��
	for(num=0;num<16;num++)
	{
		write_data(tab[num]);
		delay(20);
	}
}
void disp_lcd(uint offset,uchar c)
{
 	write_com(0x80+offset); //��ʾ�ַ��ĳ�ʼλ��
	write_data(c);//Щ����
}