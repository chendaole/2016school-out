#ifndef _1602_H_
#define _1602_H_
void delay(unsigned int);   //延时函数
void write_com(unsigned char);   //命令子函数command 
void write_data(unsigned char);  //数据子函数data
void init(); //初始函数
void write_lcd(unsigned int offset,unsigned char tab[]); //1602显示函数
void disp_lcd(unsigned int offfset,unsigned char c);
#endif