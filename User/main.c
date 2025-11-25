#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "sensor.h"
#include "Tim.h"
#include "Key.h"
#define run 0
#define stop 1
uint8_t keynum;
uint16_t start_flag=1;
int main(void)
{
	
	Key_Init();
	OLED_Init();
	Motor_Init();
	sensor_Init();
	
	Timer_Init();
		
	

	
	while (1)
	{
		OLED_ShowNum(1,1,r1,1);
		OLED_ShowNum(1,3,r2,1);
		OLED_ShowNum(1,5,l2,1);
		OLED_ShowNum(1,7,l1,1);
		keynum= Key_GetNum();
		
		
		if (keynum==1)
		{
			start_flag=!start_flag;
		}
		
		
		
		


                                          

		
		if (start_flag == run)
		{
			sensor_trace();
		}
		else
		{
			Motor_SetPWM_zuo_qian(0);
			Motor_SetPWM_zuo_hou(0);
			Motor_SetPWM_you_qian(0);
			Motor_SetPWM_you_hou(0);
			OLED_ShowString(2,1,"stop");
		}
		
		
		
		
		
	}
}


void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Key_Tick();
		
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
