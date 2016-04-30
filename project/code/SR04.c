#include"reg52.h"
#include"timer.h"
#include<intrins.h>
bit cuowu;
sbit trig=P3^2;
sbit echo=P3^3;
unsigned int s;
unsigned long sj;
void init_sr04()
{
	trig=0;
	EA=1;
	ET1=1;
	ET0=1;
	TMOD=0x10;
	TH1=0;
	TL1=0;
	s=0;
	TR1=0;
	delay(1000);
	
}
unsigned int location()
{
	init_sr04();
	trig=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	trig=0;
	while(!echo);
	TR1=1;
	while(echo);
	TR1=0;
	
	sj=TH1*256+TL1;
	s=sj*340/2/1000;
	return s;	
}

int sr04()
{
	int k; 
	k=location();
	if(k<60)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void time1() interrupt 3
{  

}
