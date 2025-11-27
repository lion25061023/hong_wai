#ifndef __Key_H
#define __Key_H
void Key_Init(void);
uint8_t Key_GetNum(void);
uint8_t Key_GetState(void);
void Key_Tick(void);

#define start_press
#define up_press 2
#define yes_press 3


#endif

