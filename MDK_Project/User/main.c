/**
  ******************************************************************************
  * @file    main.c
  * @author  verdvana
  * @version V1.1
  * @date    2018-9-26
  * @brief   主函数     
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "bsp_led.h"
#include "bsp_Stepper_Motor.h"
#include "bsp_Segment_Display.h"
#include "bsp_Buzzer.h"
#include "bsp_it.h"

#define CLI()      __set_PRIMASK(1)	   //关闭总中断	 
#define SEI() __set_PRIMASK(0)	       //开启总中断

uint8_t flag_r,                        //向右标志位
        flag_b,                        //向后标志位
				flag_bs,                       //向后步进标志位
				flag_f,                        //向前标志位
				flag_u,                        //向上标志位
				flag_d;                        //向下标志位
	
extern uint16_t	 step;                 //步进电机驱动器配置文件定义


void Start(void);                      //上电自检函数




/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	  
	
	Segment_GPIO_Config();               //数码管初始化
	LED_GPIO_Config();                   //LED初始化
	Buzzer_GPIO_Config();                //蜂鸣器初始化
	SysTick_Init();                      //系统滴答定时器初始化
	
	CLI();
	SEI();
	EXTI_Config();                       //中断初始化
	
	Start();                             //上电自检
	
 	step=1;                              //步数初值为01
	
   ENa_PP_Config();                   
	 ENb_PP_Config();
	 ENc_PP_Config();                    //锁定电机

	

	
	while(1)
	{
		if(flag_r)                         //向右按键按下
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9))
			{
				Right();                         //向右动作
				Delay_ms(2000);                  //延时2s
				Forward();                       //向前动作
				Buzzer(1);                       //蜂鸣器响
				Delay_ms(100);                   //延时100ms
				Buzzer(0);                       //蜂鸣器关
			}
		  flag_r=0;                        //恢复标志位
		}
		
		else if(flag_b)                    //向后按键按下
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8))
			{
				Backward();                      //向后动作
			}
			flag_b=0;                        //恢复标志位
		}
		
		else if(flag_bs)                   //向后步进按键按下
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11))
			{
			Backward_Step();                 //向后步进动作
			}
			flag_bs=0;                       //恢复标志位
		}
		
		else if(flag_f)                    //向前按键按下
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12))
			{
			Forward();                       //向前动作
			}
			flag_f=0;                        //恢复标志位
		}
		
		else if(flag_u)                    //向上按键按下
		{ 
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_13))
			{
			Up();                            //向上动作
			}
			flag_u=0;                        //恢复标志位
		}
		
		else if(flag_d)                    //向下按键按下
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_10))
			{
			Down();                          //向下动作
			}
			flag_d=0;                        //恢复标志位
		}
		
		

	}   


		
}

void Start(void)
{
	uint8_t i;
	for(i=0;i<3;i++)
	{
		XL1(1);YL1(1);ZL1(1);
		Delay_ms(100);
		XL1(0);YL1(0);ZL1(0);
		XL2(1);YL2(1);ZL2(1);
		Delay_ms(100);
		XL2(0);YL2(0);ZL2(0);
		XL3(1);YL3(1);ZL3(1);
		Delay_ms(100);
		XL3(0);YL3(0);ZL3(0);
	}
	
	for(i=0;i<10;i++)
	{
		Segment1(i);
		Segment2(i);
		Delay_ms(100);
	}
	
	Segment_Reset();
	
	Buzzer(1);
	Delay_ms(200);
	Buzzer(0);
}
/*********************************************END OF FILE**********************/
