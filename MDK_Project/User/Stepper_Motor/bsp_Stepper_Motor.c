/**
  ******************************************************************************
  * @file    bsp_Stepper_Motor.c
  * @author  verdvana
  * @version V1.1
  * @date    2018-9-26
  * @brief   �����������    
  ******************************************************************************
  * @attention
  *					3200������ʹ��������ƶ�1cm
  *					�ܳ���8cm����25600������
	*					��������0.2cm����640������
	*
	*         ���ſ�©�������̬ʱ������Ϊ�߼�0
	*					������������͵�ƽʱ������Ϊ�߼�1
  ******************************************************************************
  */

#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "bsp_led.h"
#include "bsp_Stepper_Motor.h"
#include "bsp_Segment_Display.h"

uint16_t 		count_pulse;               //�������
uint16_t    step;                      //���2����
uint8_t unit,ten;                      //������λ��ʮλ
											  
void ENa_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_10);	 
}


void ENa_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_10);	
}



void DIRa_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_11);	 
}


void DIRa_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_11);	
}

void PULa_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_12);	 
}


void PULa_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_12);	
}

void ENb_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_13);	 
}


void ENb_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_13);	
}



void DIRb_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_14);	 
}


void DIRb_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_14);	
}

void PULb_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_15);	 
}


void PULb_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_15);	
}


void ENc_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOC, GPIO_Pin_6);	 
}


void ENc_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOC, GPIO_Pin_6);	
}



void DIRc_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOC, GPIO_Pin_7);	 
}


void DIRc_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOC, GPIO_Pin_7);	
}

void PULc_PP_Config(void)               //��������͵�ƽ��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOC, GPIO_Pin_8);	 
}


void PULc_OD_Config(void)               //��©�������̬��ʼ��
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOC, GPIO_Pin_8);	
}



////////////////////////////////////////////////////////////////////////////////////


void Forward(void)
{
		ENb_OD_Config();                                   //���ʹ��
		DIRb_PP_Config();                                  //������ǰ
	
		for(count_pulse=0;count_pulse<640;count_pulse++)   //640������
		  {
		  	 PULb_PP_Config();
	       Delay_us(70); 
         PULb_OD_Config();	
         Delay_us(210);				
		  }
				
			
		ENb_PP_Config();                                   //���ʧ��
			
		YL1(1);Delay_ms(100);YL2(1);Delay_ms(100);YL1(0);YL3(1);Delay_ms(100);YL2(0);Delay_ms(100);YL3(0);  //LEDָʾ��
			
		step++;	                                           //������1
			
		unit = step/1 %10;                                 //���㲽����λ
		ten  = step/10%10;                                 //���㲽��ʮλ
		
		Segment2(unit);
		Segment1(ten);                                     //�������ʾ����
}

	
	
void Backward(void)
{
		ENb_OD_Config();                                    //���ʹ��
		DIRb_OD_Config();                                   //�������
	  for(;step>1;step--)
	  {
			for(count_pulse=0;count_pulse<640;count_pulse++)  //640������
				{
					PULb_PP_Config();
					Delay_us(70); 
					PULb_OD_Config();	
					Delay_us(210);				
				}
		}		
		ENb_PP_Config();
		
		YL3(1);Delay_ms(100);YL2(1);Delay_ms(100);YL3(0);YL1(1);Delay_ms(100);YL2(0);Delay_ms(100);YL1(0);
		
		unit = step/1 %10;                 //���㲽����λ
		ten  = step/10%10;                 //���㲽��ʮλ
		
		Segment2(unit);
		Segment1(ten);                     //�������ʾ����
}
	
	
void Backward_Step(void)
{
	ENb_OD_Config();
	DIRb_OD_Config();
	
	for(count_pulse=0;count_pulse<640;count_pulse++)
		  {
		  	 PULb_PP_Config();
	       Delay_us(70); 
         PULb_OD_Config();	
         Delay_us(210);				
		  }
		ENb_PP_Config();
			
		YL3(1);Delay_ms(100);YL2(1);Delay_ms(100);YL3(0);YL1(1);Delay_ms(100);YL2(0);Delay_ms(100);YL1(0);
			
			step--;
			
		unit = step/1 %10;                 //���㲽����λ
		ten  = step/10%10;                 //���㲽��ʮλ
		
		Segment2(unit);
		Segment1(ten);                     //�������ʾ����
}
	
void Right(void)
{
	ENa_OD_Config();
	DIRa_OD_Config();
	
	for(count_pulse=0;count_pulse<25600;count_pulse++)
		  {
		  	 PULa_PP_Config();
	       Delay_us(200); 
         PULa_OD_Config();	
         Delay_us(600);				
		  }
	ENa_PP_Config();
	XL1(1);Delay_ms(100);XL2(1);Delay_ms(100);XL1(0);XL3(1);Delay_ms(100);XL2(0);Delay_ms(100);XL3(0);
			
	Delay_ms(3000);
			
	ENa_OD_Config();
	DIRa_PP_Config();
	
	for(count_pulse=0;count_pulse<25600;count_pulse++)
		  {
		  	 PULa_PP_Config();
	       Delay_us(70); 
         PULa_OD_Config();	
         Delay_us(210);				
		  }
	ENa_PP_Config();		
	XL3(1);Delay_ms(100);XL2(1);Delay_ms(100);XL3(0);YL1(1);Delay_ms(100);XL2(0);Delay_ms(100);XL1(0);
}



void Up(void)
{

}



void Down(void)
{
		ENa_OD_Config();
	  DIRa_PP_Config();
	   for(count_pulse=0;count_pulse<640;count_pulse++)
		  {
		  	 PULa_PP_Config();
	       Delay_us(70); 
         PULa_OD_Config();	
         Delay_us(210);				
		  }
		ENa_PP_Config();
		XL3(1);Delay_ms(100);XL2(1);Delay_ms(100);XL3(0);YL1(1);Delay_ms(100);XL2(0);Delay_ms(100);XL1(0);
	
	
}

