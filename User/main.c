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
uint16_t tiao_flag=0;
uint16_t xiao_flag=0;
uint16_t da_flag=0;



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
		
		OLED_ShowNum(4,1,r1,1);
		OLED_ShowNum(4,3,r2,1);
		OLED_ShowNum(4,5,l2,1);
		OLED_ShowNum(4,7,l1,1);
		keynum= Key_GetNum();
		
		
		
		if (keynum==1)
		{
			OLED_Clear();
			start_flag=!start_flag;
		}

		else if (keynum==2)
		{
			if (!tiao_flag)
			{
				OLED_Clear();
				OLED_ShowString(flag, 1, " ");
				flag--;
			
				if (flag==0)
				{
					flag=3;
				}
			}
			else
			{
				if (flag==1)
				{
					
					OLED_ShowString(1,10,">");
					zhi_speed+=Encoder_Get();
				}
				else if (flag==2)
				{
					xiao_flag=!xiao_flag;
					if (xiao_flag)
					{
						OLED_ShowString(2,10," ");
						OLED_ShowString(2,6,">");
						xiao_zhu+=Encoder_Get();
						
					}
					else
					{
						OLED_ShowString(2,6," ");
						OLED_ShowString(2,10,">");
						xiao_cong+=Encoder_Get();
					}
				}
				else if(flag==3)
				{
					da_flag=!da_flag;
					if (da_flag)
					{
						OLED_ShowString(3,10," ");
						OLED_ShowString(3,6,">");
						da_zhu+=Encoder_Get();
					}
					else
					{
						OLED_ShowString(3,6," ");
						OLED_ShowString(3,10,">");
						da_cong+=Encoder_Get();
					}
				}

			}
			
			
			
			
			
			
			
		}
		else if (keynum==3)
		{
			tiao_flag=!tiao_flag;
			

			
			
			if (tiao_flag)
			{
				
				if (flag==1)
				{
					OLED_Clear();
					OLED_ShowNum(1,11,zhi_speed,3);

				}
				else if (flag==2)
				{
					OLED_Clear();
					OLED_ShowNum(2,7,xiao_zhu,3);
					OLED_ShowNum(2,11,xiao_cong,3);
				}
				else if (flag==3)
				{
					OLED_Clear();
					OLED_ShowNum(3,7,da_zhu,3);
					OLED_ShowNum(3,11,da_cong,3);

				}
				OLED_ShowString(4,10, "tiao");

				

			}
			else
			{
				OLED_Clear();
				OLED_ShowString(4,10, "normal");
			}
		}



		int menu2 = menu1();																						                                          
		
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
			//OLED_ShowString(2,1,"stop");
		}
		// //调试问题
		// int16_t encoder_value = Encoder_Get();
		// OLED_ShowNum(3, 5, encoder_value, 5);
		// int8_t pa12_state = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
		// uint8_t pb5_state = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5);
    
		// OLED_ShowString(3, 14, "PA12");
		// OLED_ShowNum(3, 10, pa12_state, 1);
		// OLED_ShowString(4, 14, "PB5");  
		// OLED_ShowNum(4, 10, pb5_state, 1);
		// if (encoder_value != 0) {
		// OLED_ShowNum(3, 5, encoder_value, 5);  // 显示编码器原始值
		// OLED_ShowNum(3, 7, zhi_speed, 5);      // 显示当前速度值
			
		// }
		
		
		
		
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
