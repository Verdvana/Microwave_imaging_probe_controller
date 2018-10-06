/**
  ******************************************************************************
  * @file    bsp_it.c
  * @author  verdvana
  * @version V1.1
  * @date    2018-9-26
  * @brief   中断配置文件    
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

#include "stm32f10x.h"
#include "bsp_it.h"

/********************************嵌套向量中断初始化**********************************************/
void NVIC_Configuration(void)
{
   NVIC_InitTypeDef NVIC_InitStructure;
  
   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                         //中断向量分组
	
   /* 向右 按键中断 */
	 NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;                      //9线
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //抢占优先级2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //响应优先级0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //使能
   NVIC_Init(&NVIC_InitStructure);                                       	 //写入寄存器
	
	 /* 向后 按键中断 */
	 NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;                      //8线
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //抢占优先级2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //响应优先级0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //使能
   NVIC_Init(&NVIC_InitStructure);
	
	 /* 向后步进 按键中断 */
   NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;                    //11线
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //抢占优先级2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //响应优先级0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //使能
   NVIC_Init(&NVIC_InitStructure);                                         //写入寄存器
	
	 /* 向前 按键中断 */
   NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;                    //12线
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //抢占优先级2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //响应优先级0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //使能
   NVIC_Init(&NVIC_InitStructure);                                         //写入寄存器
	 
	 /* 向上 按键中断 */
   NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;                    //13线
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //抢占优先级2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //响应优先级0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //使能
   NVIC_Init(&NVIC_InitStructure);                                         //写入寄存器
	 
	 /* 向下 按键中断 */
   NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;                    //10线
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //抢占优先级2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //响应优先级0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //使能
   NVIC_Init(&NVIC_InitStructure);                                         //写入寄存器
}
/***********************************外部中断初始化********************************************/

void EXTI_Config(void)
{
	 GPIO_InitTypeDef GPIO_InitStructure; 
	 EXTI_InitTypeDef EXTI_InitStructure;

	 RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO,ENABLE);                        //开AFIO时钟
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOA ,ENABLE); //开PA PB 引脚时钟	
	
   NVIC_Configuration();                                                       //必须在中断初始化函数里调用
	
	 /* 向右 */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                              // 上拉输入
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
   GPIO_Init(GPIOC, &GPIO_InitStructure);	                                     //选引脚PC9

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource9);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line9;                                  //选线9
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                         //中断模式
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                     //下降沿中断
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                   //开中断
   EXTI_Init(&EXTI_InitStructure);                                             //写入寄存器
	
	 /* 向后 */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                              // 上拉输入
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);	                                     //选引脚PA8

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line8;                                  //选线8
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                         //中断模式
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                     //下降沿中断
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                   //开中断
   EXTI_Init(&EXTI_InitStructure);                                             //写入寄存器
	
	 /* 向后步进 */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                              // 上拉输入
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);	                                     //选引脚PA11

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line11;                                 //选线11
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                         //中断模式
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                     //下降沿中断
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                   //开中断
   EXTI_Init(&EXTI_InitStructure);                                             //写入寄存器
	
	 /* 向前 */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                                // 上拉输入
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);	                                     //选引脚PA12

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource12);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line12;                                  //选线12
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                          //中断模式
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                      //下降沿中断
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                    //开中断
   EXTI_Init(&EXTI_InitStructure);
	 
	 /* 向上 */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                                // 上拉输入
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);	                                     //选引脚PA13

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource13);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line13;                                  //选线13
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                          //中断模式
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                      //下降沿中断
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                    //开中断
   EXTI_Init(&EXTI_InitStructure);
	 
	 /* 向下 */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                                // 上拉输入
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
   GPIO_Init(GPIOC, &GPIO_InitStructure);	                                     //选引脚PC10

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource10);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line10;                                  //选线10
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                          //中断模式
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                      //下降沿中断
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                    //开中断
   EXTI_Init(&EXTI_InitStructure);
}
