/**********************************************************************
Author:     1+1>2 Team
技术论坛：
购买链接：
File:  	infrare.c
@Copyright：by 1+1>2
Version：V1.0
Date：2020
@brief：2020 	


***********************************************************************/

#include "stm32f10x_gpio.h"
#include "infrare.h"


#define La GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
//#define Lb GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
#define Lc GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3)
#define Ra GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
//#define Rb GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12)
#define Rc GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)

void InfraredIOInit(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //使能GPIOB时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);  //使能GPIOB时钟
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //PB0 ??  
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_15; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);


	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3 | GPIO_Pin_5; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/*
	四通道红外模块
	result从高位到低位分别标识通道Lb、La、Ra、Rb
	检测到黑线的通道相应的位置1
*/
char InfraredDetect(void)
{
	char resut = 0;
	
	if(Lc)
		resut |= infrared_channel_Lc;
//	else if(Lb)
//		resut |= infrared_channel_Lb;
	else if(La)
		resut |= infrared_channel_La;
	else if(Ra)
		resut |= infrared_channel_Ra;
//	else if(Rb)
//		resut |= infrared_channel_Rb;
	else if(Rc)
		resut |= infrared_channel_Rc;

	return resut;
}

static char InfrareError = 0;//0:Ok; 1:error
void InfrareSelfCheck(void)
{
		char cnt = 0;
		if(La==1)cnt++;
//		if(Lb==1)cnt++;
		if(Lc==1)cnt++;
		if(Ra==1)cnt++;
//		if(Rb==1)cnt++;
		if(Rc==1)cnt++;
		
		if(cnt == 4)// 如果每个通道都是高电平，则判断为红外模块没有接上
			InfrareError = 1;
}

int IsInfrareOK(void)
{
	return !InfrareError;
}

