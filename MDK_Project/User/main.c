/**
  ******************************************************************************
  * @file    main.c
  * @author  verdvana
  * @version V1.1
  * @date    2018-9-26
  * @brief   ������     
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

#define CLI()      __set_PRIMASK(1)	   //�ر����ж�	 
#define SEI() __set_PRIMASK(0)	       //�������ж�

uint8_t flag_r,                        //���ұ�־λ
        flag_b,                        //����־λ
				flag_bs,                       //��󲽽���־λ
				flag_f,                        //��ǰ��־λ
				flag_u,                        //���ϱ�־λ
				flag_d;                        //���±�־λ
	
extern uint16_t	 step;                 //������������������ļ�����


void Start(void);                      //�ϵ��Լ캯��




/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	  
	
	Segment_GPIO_Config();               //����ܳ�ʼ��
	LED_GPIO_Config();                   //LED��ʼ��
	Buzzer_GPIO_Config();                //��������ʼ��
	SysTick_Init();                      //ϵͳ�δ�ʱ����ʼ��
	
	CLI();
	SEI();
	EXTI_Config();                       //�жϳ�ʼ��
	
	Start();                             //�ϵ��Լ�
	
 	step=1;                              //������ֵΪ01
	
   ENa_PP_Config();                   
	 ENb_PP_Config();
	 ENc_PP_Config();                    //�������

	

	
	while(1)
	{
		if(flag_r)                         //���Ұ�������
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9))
			{
				Right();                         //���Ҷ���
				Delay_ms(2000);                  //��ʱ2s
				Forward();                       //��ǰ����
				Buzzer(1);                       //��������
				Delay_ms(100);                   //��ʱ100ms
				Buzzer(0);                       //��������
			}
		  flag_r=0;                        //�ָ���־λ
		}
		
		else if(flag_b)                    //��󰴼�����
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8))
			{
				Backward();                      //�����
			}
			flag_b=0;                        //�ָ���־λ
		}
		
		else if(flag_bs)                   //��󲽽���������
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11))
			{
			Backward_Step();                 //��󲽽�����
			}
			flag_bs=0;                       //�ָ���־λ
		}
		
		else if(flag_f)                    //��ǰ��������
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12))
			{
			Forward();                       //��ǰ����
			}
			flag_f=0;                        //�ָ���־λ
		}
		
		else if(flag_u)                    //���ϰ�������
		{ 
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_13))
			{
			Up();                            //���϶���
			}
			flag_u=0;                        //�ָ���־λ
		}
		
		else if(flag_d)                    //���°�������
		{
			Delay_ms(20);
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_10))
			{
			Down();                          //���¶���
			}
			flag_d=0;                        //�ָ���־λ
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
