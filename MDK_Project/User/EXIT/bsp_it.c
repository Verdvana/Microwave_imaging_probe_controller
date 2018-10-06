/**
  ******************************************************************************
  * @file    bsp_it.c
  * @author  verdvana
  * @version V1.1
  * @date    2018-9-26
  * @brief   �ж������ļ�    
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

#include "stm32f10x.h"
#include "bsp_it.h"

/********************************Ƕ�������жϳ�ʼ��**********************************************/
void NVIC_Configuration(void)
{
   NVIC_InitTypeDef NVIC_InitStructure;
  
   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                         //�ж���������
	
   /* ���� �����ж� */
	 NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;                      //9��
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //��ռ���ȼ�2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //��Ӧ���ȼ�0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //ʹ��
   NVIC_Init(&NVIC_InitStructure);                                       	 //д��Ĵ���
	
	 /* ��� �����ж� */
	 NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;                      //8��
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //��ռ���ȼ�2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //��Ӧ���ȼ�0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //ʹ��
   NVIC_Init(&NVIC_InitStructure);
	
	 /* ��󲽽� �����ж� */
   NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;                    //11��
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //��ռ���ȼ�2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //��Ӧ���ȼ�0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //ʹ��
   NVIC_Init(&NVIC_InitStructure);                                         //д��Ĵ���
	
	 /* ��ǰ �����ж� */
   NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;                    //12��
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //��ռ���ȼ�2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //��Ӧ���ȼ�0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //ʹ��
   NVIC_Init(&NVIC_InitStructure);                                         //д��Ĵ���
	 
	 /* ���� �����ж� */
   NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;                    //13��
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //��ռ���ȼ�2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //��Ӧ���ȼ�0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //ʹ��
   NVIC_Init(&NVIC_InitStructure);                                         //д��Ĵ���
	 
	 /* ���� �����ж� */
   NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;                    //10��
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;               //��ռ���ȼ�2
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;                      //��Ӧ���ȼ�0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                         //ʹ��
   NVIC_Init(&NVIC_InitStructure);                                         //д��Ĵ���
}
/***********************************�ⲿ�жϳ�ʼ��********************************************/

void EXTI_Config(void)
{
	 GPIO_InitTypeDef GPIO_InitStructure; 
	 EXTI_InitTypeDef EXTI_InitStructure;

	 RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO,ENABLE);                        //��AFIOʱ��
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOA ,ENABLE); //��PA PB ����ʱ��	
	
   NVIC_Configuration();                                                       //�������жϳ�ʼ�����������
	
	 /* ���� */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                              // ��������
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
   GPIO_Init(GPIOC, &GPIO_InitStructure);	                                     //ѡ����PC9

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource9);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line9;                                  //ѡ��9
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                         //�ж�ģʽ
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                     //�½����ж�
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                   //���ж�
   EXTI_Init(&EXTI_InitStructure);                                             //д��Ĵ���
	
	 /* ��� */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                              // ��������
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);	                                     //ѡ����PA8

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line8;                                  //ѡ��8
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                         //�ж�ģʽ
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                     //�½����ж�
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                   //���ж�
   EXTI_Init(&EXTI_InitStructure);                                             //д��Ĵ���
	
	 /* ��󲽽� */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                              // ��������
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);	                                     //ѡ����PA11

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource11);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line11;                                 //ѡ��11
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                         //�ж�ģʽ
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                     //�½����ж�
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                   //���ж�
   EXTI_Init(&EXTI_InitStructure);                                             //д��Ĵ���
	
	 /* ��ǰ */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                                // ��������
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);	                                     //ѡ����PA12

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource12);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line12;                                  //ѡ��12
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                          //�ж�ģʽ
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                      //�½����ж�
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                    //���ж�
   EXTI_Init(&EXTI_InitStructure);
	 
	 /* ���� */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                                // ��������
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; 
   GPIO_Init(GPIOA, &GPIO_InitStructure);	                                     //ѡ����PA13

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource13);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line13;                                  //ѡ��13
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                          //�ж�ģʽ
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                      //�½����ж�
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                    //���ж�
   EXTI_Init(&EXTI_InitStructure);
	 
	 /* ���� */
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	                                // ��������
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
   GPIO_Init(GPIOC, &GPIO_InitStructure);	                                     //ѡ����PC10

   GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource10);                 
   EXTI_InitStructure.EXTI_Line = EXTI_Line10;                                  //ѡ��10
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;                          //�ж�ģʽ
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;                      //�½����ж�
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;                                    //���ж�
   EXTI_Init(&EXTI_InitStructure);
}
