#include "stm32f10x.h"                  // Device header
#define start_press 1
#define up_press 2
#define yes_press 3

uint8_t Key_Num;
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 |GPIO_Pin_6 |GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
uint8_t Key_GetNum(void)
{
	uint8_t Temp;
	//键码标志非0时启动
	if (Key_Num)
	{
		Temp = Key_Num;
		Key_Num = 0;
		return Temp;
	}
	return 0;
}

uint8_t Key_GetState(void)
{
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		return start_press;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == 0)
	{
		return up_press;
	}
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7) == 0)
	{
		return yes_press;
	}
	
	
	return 0;
}


void Key_Tick(void)
{
	static uint8_t Count;
	static uint8_t CurrState, PrevState;
	
	Count ++;
	if (Count >= 20)
	{
		Count = 0;
		
		PrevState = CurrState;
		CurrState = Key_GetState();
		
		if (CurrState == 0 && PrevState != 0)
		{
			Key_Num = PrevState;
		}
	}
}

