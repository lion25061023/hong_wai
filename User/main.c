#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "sensor.h"

int main(void)
{
	OLED_Init();
	Motor_Init();
	sensor_Init();
	
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
		OLED_ShowNum(1,1,GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6),1);
		OLED_ShowNum(2,1,x3,1);
		OLED_ShowNum(3,1,GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5),1);
		OLED_ShowNum(4,1,x4,1);
	}
}
