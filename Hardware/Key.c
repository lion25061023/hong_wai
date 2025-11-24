#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
//#define up GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
//#define yes GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)
//#define start GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
uint8_t Start_Num;
void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


uint8_t Start_GetState(void)
{
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0)
	{
		return 1;
	}
	
	return 0;
}

uint8_t Start_GetNum(void)
{
	uint8_t Temp;
	
	if (Start_Num==1)
	{
		Temp = Start_Num;
		Start_Num= 0;
		
		return Temp;
	}
	return 0;
}


void Key_Tick(void)
{
	static uint8_t Count;
	static uint8_t CurrState, PrevState;
	
	Count ++;
	if (Count >= 200)
	{
		Count = 0;
		
		PrevState = CurrState;
		CurrState = Start_GetState();
		
		
		
		if (CurrState == 0 && PrevState != 0)
		{
			Start_Num=1;
			
		}
	}
}
