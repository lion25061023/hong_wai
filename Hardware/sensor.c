#include "stm32f10x.h"                  // Device header
#define x4 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)
#define x3 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define x2 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
#define x1 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3)
void sensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4 |GPIO_Pin_5 |GPIO_Pin_6 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	


}

void sensor_trace(void)
{
	
}

