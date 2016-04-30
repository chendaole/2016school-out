#include  "reg52.h"
#include "SR04.h"
#include "timer.h"

short int checkkey(void)
{	
	unsigned char n;
 	P2=0xf0;
	n=P2;
	if(n!=0xf0)
		return 1;
	else
		return 0;
}
int key()
{
	int NO=0;
	int sign=1;
	unsigned char i,j;
   while(sign)
	{  
		if(sr04() == 1)//距离在6厘米内
		{
		  return 100; // 返回标志信号
		}
		 
		if(checkkey()==1)
	  {	
	 	 delay(1);
		  if(checkkey()==1)
			P2=0xf0;
			i=P2;
			P2=0x0f;
			j=P2;
			i=i|j;
			switch(i)
			{   
				case 0x7e:NO=0,sign=0;break;
			  	case 0xbe:NO=1,sign=0;break;
				case 0xde:NO=2,sign=0;break;
				case 0xee:NO=3,sign=0;break;
				case 0x7d:NO=4,sign=0;break;
				case 0xbd:NO=5,sign=0;break;
				case 0xdd:NO=6,sign=0;break;
				case 0xed:NO=7,sign=0;break;
				case 0x7b:NO=8,sign=0;break;
				case 0xbb:NO=9,sign=0;break;
				case 0xdb:NO=10,sign=0;break;
				case 0xeb:NO=11,sign=0;break;
			  	case 0x77:NO=12,sign=0;break;
				case 0xb7:NO=13,sign=0;break;
				case 0xd7:NO=14,sign=0;break;
				case 0xe7:NO=15,sign=0;break;
        	}
			 while(checkkey()==1); //等待按键弹起
     	}
	
		}
	return NO;
}