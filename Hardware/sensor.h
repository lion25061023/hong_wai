#ifndef __sensor_H
#define __sensor_H

#define r1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)
#define r2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)
#define l1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)
#define l2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)
#define zuo GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define you GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10)



void sensor_Init(void);
void read_sensors(void);
void quan(void);
void pid_control(void);
void motor_control(void);
void sensor_trace(void);
#endif

