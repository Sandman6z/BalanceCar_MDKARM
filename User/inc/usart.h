/**********************************************************************
��Ȩ���У�	���ش��¿Ƽ���2017.
��		����	http://www.miaowlabs.com
��		����	https://shop275516297.taobao.com/
�� �� ��: 	.h
��    ��:   ����ʵ����
��		��:   3.00
�������:   2017.03.01
��		Ҫ: 	




***********************************************************************/

#ifndef __USART_H
#define __USART_H



#define Uart1BufferSize 128 //KKDD 3->1

extern char Uart1Buffer[];			//����ͨ�Ŵ��ڽ��ջ����� KKDD 3->1
extern unsigned char Uart1Index; //KKDD 3->1

void USART1Init(unsigned int baudrate);
void USART3Init(char baudrate);


void Uart1SendByte(char byte) ;
void Uart1SendBuff(char *buf, unsigned short len);
void Uart1SendStr(char * str);
	
void Uart3SendByte(char byte)  ;
void Uart3SendBuff(char *buf, unsigned short len);
void Uart3SendStr(char *str);

#define BluetoothOut(str) Uart1SendStr(str) //KKDD 3->1



#endif /* __USART1_H */
