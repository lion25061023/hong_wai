#ifndef __sensor_H
#define __sensor_H

#define r1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)
#define r2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10)
#define l1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9)
#define l2 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8)



void sensor_Init(void);
void sensor_trace(void);
void zhi_xing(void);
void xiao_zuo(void);
void xiao_you(void);
void da_you(void);
void da_zuo(void);
void stop(void);
void tui(void);
#endif

