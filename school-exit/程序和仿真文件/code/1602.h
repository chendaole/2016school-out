#ifndef _1602_H_
#define _1602_H_
void delay(unsigned int);   //��ʱ����
void write_com(unsigned char);   //�����Ӻ���command 
void write_data(unsigned char);  //�����Ӻ���data
void init(); //��ʼ����
void write_lcd(unsigned int offset,unsigned char tab[]); //1602��ʾ����
void disp_lcd(unsigned int offfset,unsigned char c);
#endif