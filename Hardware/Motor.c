#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	//ºóÂÖ
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	//Ç°ÂÖ
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure1);
	
	PWM_Init();
}

void Motor_SetPWM_zuo_hou(float PWM)
{
	if (PWM >= 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		PWM_SetCompare_zuo_hou(PWM);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		GPIO_SetBits(GPIOB, GPIO_Pin_13);
		PWM_SetCompare_zuo_hou(-PWM);
	}
}

void Motor_SetPWM_you_hou(float PWM)
{
	if (PWM >= 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_14);
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
		PWM_SetCompare_you_hou(PWM);
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		GPIO_SetBits(GPIOB, GPIO_Pin_15);
		PWM_SetCompare_you_hou(-PWM);
	}
}



void Motor_SetPWM_zuo_qian(float PWM)
{
	if (PWM >= 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		PWM_SetCompare_zuo_qian(PWM);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
		GPIO_SetBits(GPIOA, GPIO_Pin_4);
		PWM_SetCompare_zuo_qian(-PWM);
	}
}



void Motor_SetPWM_you_qian(float PWM)
{
	if (PWM >= 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		PWM_SetCompare_you_qian(PWM);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		GPIO_SetBits(GPIOA, GPIO_Pin_6);
		PWM_SetCompare_you_qian(-PWM);
	}
}

