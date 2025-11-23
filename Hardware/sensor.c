#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#define r1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)
#define r2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)
#define l1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)
#define l2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)
void sensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8| GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	


}
//白的是0，黑的是1
void sensor_trace(void)
{
	if(l2==1&&r2==1)
	{
		Motor_SetPWM_zuo_qian(100);
		Motor_SetPWM_zuo_hou(100);
		Motor_SetPWM_you_qian(100);
		Motor_SetPWM_you_hou(100);
	
	}
	if (l2==1&&r2==0)
	{
		Motor_SetPWM_zuo_qian(10);
		Motor_SetPWM_zuo_hou(-50);
		Motor_SetPWM_you_qian(10);
		Motor_SetPWM_you_hou(80);
	}
	
	if (l2==0&&r2==1)
	{
		Motor_SetPWM_zuo_qian(10);
		Motor_SetPWM_zuo_hou(80);
		Motor_SetPWM_you_qian(10);
		Motor_SetPWM_you_hou(-50);
	}
}

