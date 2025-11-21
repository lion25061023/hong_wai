#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);
//设置tim3的3通道pwm波
void PWM_SetCompare3(uint16_t Compare);
//设置tim3的4通道pwm波
void PWM_SetCompare4(uint16_t Compare);

#endif
