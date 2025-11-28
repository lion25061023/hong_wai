#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#define r1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)
#define r2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)
#define l1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)
#define l2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)
#define zuo GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define you GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10)
#define black 1
#define white 0
#include "OLED.h"

uint16_t zhi_speed=60;
uint16_t da_zhu=80;
uint16_t da_cong=80;
uint16_t xiao_zhu=60;
uint16_t xiao_cong=50;
void sensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8| GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_10 ;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure1);
	
	


}


void zhi_xing(void)
{
	Motor_SetPWM_zuo_qian(zhi_speed);
	Motor_SetPWM_zuo_hou(zhi_speed);
	Motor_SetPWM_you_qian(zhi_speed);
	Motor_SetPWM_you_hou(zhi_speed);
	//OLED_ShowString(2,1,"zhi_xing");
}

void xiao_zuo(void)
{
	Motor_SetPWM_zuo_qian(-xiao_cong);
	Motor_SetPWM_zuo_hou(-xiao_cong);
	Motor_SetPWM_you_qian(xiao_zhu);
	Motor_SetPWM_you_hou(xiao_zhu);
	//OLED_ShowString(2,1,"xiao_zuo");
}

void xiao_you(void)
{
	Motor_SetPWM_zuo_qian(xiao_zhu);
	Motor_SetPWM_zuo_hou(xiao_zhu);
	Motor_SetPWM_you_qian(-xiao_cong);
	Motor_SetPWM_you_hou(-xiao_cong);
	//OLED_ShowString(2,1,"xiao_you");
	
}


void da_you(void)
{
	Motor_SetPWM_zuo_qian(da_zhu);
	Motor_SetPWM_zuo_hou(da_zhu);
	Motor_SetPWM_you_qian(-da_cong);
	Motor_SetPWM_you_hou(-da_cong);
	//OLED_ShowString(2,1,"da_you");
}

void da_zuo(void)
{
	Motor_SetPWM_zuo_qian(-da_cong);
	Motor_SetPWM_zuo_hou(-da_cong);
	Motor_SetPWM_you_qian(da_zhu);
	Motor_SetPWM_you_hou(da_zhu);
	//OLED_ShowString(2,1,"da_zuo");
}

void stop(void)
{
	Motor_SetPWM_zuo_qian(0);
	Motor_SetPWM_zuo_hou(0);
	Motor_SetPWM_you_qian(0);
	Motor_SetPWM_you_hou(0);
	//OLED_ShowString(2,1,"stop");
	
}

void tui(void)
{
	Motor_SetPWM_zuo_qian(30);
	Motor_SetPWM_zuo_hou(30);
	Motor_SetPWM_you_qian(30);
	Motor_SetPWM_you_hou(30);
	//OLED_ShowString(2,1,"tui");
}

//�׵���0���ڵ���1
void sensor_trace(void)
{
	OLED_ShowString(4,1,"               ");
	if(l1==white &&l2==black && r2==black && r1==white)
	{
		zhi_xing();
	
	}
	else if(l1==white &&l2==black && r2==white && r1==white)
	{
		xiao_zuo();
	}
	else if(l1==white &&l2==white && r2==black && r1==white)
	{
		xiao_you();
	}
	else if(l1==black &&l2==black && r2==black && r1==white)
	{
		da_zuo();
	}
	
	else if(l1==white &&l2==black && r2==black && r1==black)
	{
		da_you();
	}

	else if(l1==white &&l2==black && r2==white && r1==white)
	{
		da_zuo();
	}
	else if(l1==white &&l2==white && r2==black && r1==black)
	{
		da_you();
	}
	else if(l1==white &&l2==white && r2==white && r1==white)
	{
		tui();
	}
	
	else if(l1==black &&l2==black && r2==black && r1==black)
	{
		zhi_xing();
	}
	
	else if(l1==black &&l2==white && r2==white && r1==white)
	{
		da_zuo();
	}
	
	else if(l1==white &&l2==white && r2==white && r1==black)
	{
		da_you();
	}
	
}


