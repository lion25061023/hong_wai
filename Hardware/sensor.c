#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "OLED.h"

//宏定义传感器状态
#define r1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)
#define r2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)
#define l1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)
#define l2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)
#define zuo GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define you GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10)
#define black 1
#define white 0

//权重参数
int16_t weight[6] = { -7, -4, -1, 1, 4, 7 }; 


//pid参数
float Kp = 15.0;
float Ki = 0.0;
float Kd = 8.0;

//电机速度参数（初始值）
int baseSpeed = 50;  

//pid变量
int error = 0;          // 当前偏差
int last_error = 0;      // 上次偏差
int output = 0;         // PID输出值


//传感器状态存储 脱线变量
unsigned long last_time = 0;     // 上次计算时间
int sensor_value[6];            // 传感器数值存储
int lost_count = 0;        // 脱线计数器






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

//从左往右的传感器读取
void read_sensors(void)
{
	sensor_value[0] = zuo;
	sensor_value[1] = l1;
	sensor_value[2] = l2;
	sensor_value[3] = r2;
	sensor_value[4] = r1;
	sensor_value[5] = you;
}

//计算权重（error）
void quan(void)
{
	int weight_sum = 0; //权重和
  	int sensor_sum = 0; //传感器黑色计数
	{
		for (int i = 0; i < 6; i++)
		{
			if (sensor_value[i] == black)
			{
				weight_sum += weight[i];
				sensor_sum++;
			}
		}
		//正常巡线
		if (sensor_sum > 0)
		{
			error = weight_sum / sensor_sum;
			//丢线不计数
			lost_count = 0;  
		}
		
		//丢线lost
		else
		{
			lost_count++;
			
			//短暂丢线，沿上次方向修正 （时间需要调）
			if (lost_count <= 5)
			{
				error = last_error;  
			}
			
			//长时间丢线，大幅修正
			else
			{
				if (last_error > 0)
				{
					error = 10;  
				}
				else
				{
					error = -10; 
				}
			}
		}
		
		//存权重（error）
		last_error = error;
	}
}

//计算最后的output
void pid_control(void)
{
	int P, I, D;
	//积分项，先放着，不打算用
	I += error;
	//计算PID输出
	output = (int)(Kp * error + Ki * I + Kd * (error - last_error));
	
	//限幅
	if (output > 100) output = 100;
	if (output < -100) output = -100;
}

// 调电机的速度 核心调速函数
void motor_control(void)
{
	
	//计算左右电机速度（out负的 ，就要往左偏）
	int leftSpeed = baseSpeed + output;
	int rightSpeed = baseSpeed - output;
	
	//限幅
	if (leftSpeed > 100) leftSpeed = 100;
	if (leftSpeed < -100) leftSpeed = -100;
	if (rightSpeed > 100) rightSpeed = 100;
	if (rightSpeed < -100) rightSpeed = -100;
	
	Motor_SetPWM_zuo_qian(leftSpeed);
	Motor_SetPWM_you_qian(rightSpeed);
	Motor_SetPWM_zuo_hou(leftSpeed);
	Motor_SetPWM_you_hou(rightSpeed);
}

//封装最后的循迹函数
void sensor_trace(void)
{
	//读取传感器
	read_sensors();
	
	//计算权重error
	quan();
	
	//计算pid输出output
	pid_control();
	
	//调电机速度
	motor_control();
}