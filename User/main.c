#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "sensor.h"
#include "Tim.h"
#include "Key.h"
#include "menu.h"
#include "encoder.h"
#define run 0
#define stop 1
uint8_t keynum;
uint16_t start_flag=1;



//调参数
extern uint16_t zhi_speed;
extern uint16_t da_zhu;
extern uint16_t da_cong;
extern uint16_t xiao_zhu;
extern uint16_t xiao_cong;

int main(void)
{
	
	Key_Init();
	Encoder_Init();
	OLED_Init();
	Motor_Init();
	sensor_Init();
	
	Timer_Init();
		
	

	
	while (1)
	{
		OLED_ShowNum(4,1,you,1);
		OLED_ShowNum(4,3,r1,1);
		OLED_ShowNum(4,5,r2,1);
		OLED_ShowNum(4,7,l2,1);
		OLED_ShowNum(4,9,l1,1);
		OLED_ShowNum(4,11,zuo,1);
		keynum= Key_GetNum();
		
		
		// start键发车
		if (keynum==1)
		{
			OLED_Clear();
			start_flag=!start_flag;
		}	
																                        
		//控制发车  循迹
		if (start_flag == run)
		{
			sensor_trace();
		}
		//标志位非run 不动
		else
		{
			Motor_SetPWM_zuo_qian(0);
			Motor_SetPWM_zuo_hou(0);
			Motor_SetPWM_you_qian(0);
			Motor_SetPWM_you_hou(0);
			//OLED_ShowString(2,1,"stop");
		}
    
		
		
 	}
	
}

//定时器检测按键
void TIM1_UP_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_Update) == SET)
	{
		Key_Tick();
		
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
}
