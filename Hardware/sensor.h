#ifndef __sensor_H
#define __sensor_H



#define x1 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)
#define x2 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)
#define x3 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4)
#define x4 GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3)


void sensor_Init(void);
void sensor_trace(void);

#endif

