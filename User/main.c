#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "sensor.h"
#include "Key.h"
#include "Tim.h"
uint8_t start;
static uint16_t num;
int main(void)
{
	OLED_Init();
	Motor_Init();
	sensor_Init();
	Timer_Init();
	Key_Init();
	
//	OLED_ShowChar(1, 1, 'A');
//	OLED_ShowString(1, 3, "HelloWorld!");
//	OLED_ShowNum(2, 1, 12345, 5);
//	OLED_ShowSignedNum(2, 7, -66, 2);
//	OLED_ShowHexNum(3, 1, 0xAA55, 4);
//	OLED_ShowBinNum(4, 1, 0xAA55, 16);
//	Motor_SetPWM_zuo_qian(100);
//	Motor_SetPWM_you_qian(100);
//	Motor_SetPWM_zuo_hou(100);
//	Motor_SetPWM_you_hou(100);
	
	while (1)
	{
		OLED_ShowNum(1,1,r1,1);
		OLED_ShowNum(1,3,r2,1);
		OLED_ShowNum(1,5,l2,1);
		OLED_ShowNum(1,7,l1,1);
		 OLED_ShowNum(3, 1, start, 1);                    // 按键事件
        OLED_ShowNum(3, 8, Start_GetState(), 1);         // 当前按键状态
        OLED_ShowNum(3, 3, GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11), 1);  // 引脚电平
		OLED_ShowNum(2,1,num,10);
                                          
		start=Start_GetNum();
		OLED_ShowNum(3,1,start,1);
		Motor_SetPWM_you_hou(50);
//		while (!start);
		
		
		sensor_trace();
		
		
	}
}


void TIM4_IRQHandler(void)
{
	
	
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET)
	{
		
		Key_Tick();
		num++;
		
		
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
}
