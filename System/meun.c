#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "OLED.h"

//取行(1-3)
uint8_t flag=1;
int menu1(void)
{
   OLED_ShowString(1, 2, "zhi_xing");
   OLED_ShowString(2, 2, "xiao");
   OLED_ShowString(3, 2, "da");
   OLED_ShowString(flag, 1, ">");
   

//    if (flag==up_press)
//    {
    //    flag--;
    //    if (flag==0)
    //    {
        //    flag=3;
    //    }
//    }

   return flag;



}

int menu2_zhi_xing(void)
{
    OLED_Clear();
     OLED_ShowString(1,1,"<-           ");
    OLED_ShowString(2,1,"zhi_xing");
    return 0;
}
int menu2_xiao(void)
{
    OLED_Clear();
    OLED_ShowString(1,1,"<-           ");
    OLED_ShowString(2,1,"xiao");
    return 0;
}
int menu2_da(void)
{
    OLED_Clear();
    OLED_ShowString(1,1,"<-           ");
    OLED_ShowString(2,1,"da");
    return 0;
}


