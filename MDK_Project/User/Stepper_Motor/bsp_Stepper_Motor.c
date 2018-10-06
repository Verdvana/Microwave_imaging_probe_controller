/**
  ******************************************************************************
  * @file    bsp_Stepper_Motor.c
  * @author  verdvana
  * @version V1.1
  * @date    2018-9-26
  * @brief   步进电机驱动    
  ******************************************************************************
  * @attention
  *					3200个脉冲使步进电机移动1cm
  *					总长度8cm，即25600个脉冲
	*					步进区间0.2cm，即640个脉冲
	*
	*         引脚开漏输出高阻态时，端子为逻辑0
	*					引脚推挽输出低电平时，端子为逻辑1
  ******************************************************************************
  */

#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "bsp_led.h"
#include "bsp_Stepper_Motor.h"
#include "bsp_Segment_Display.h"

uint16_t 		count_pulse;               //脉冲计数
uint16_t    step;                      //电机2步数
uint8_t unit,ten;                      //步数个位与十位
											  
void ENa_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_10);	 
}


void ENa_OD_Config(void)               //开漏输出高阻态初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_10);	
}



void DIRa_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_11);	 
}


void DIRa_OD_Config(void)               //开漏输出高阻态初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_11);	
}

void PULa_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_12);	 
}


void PULa_OD_Config(void)               //开漏输出高阻态初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_12);	
}

void ENb_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_13);	 
}


void ENb_OD_Config(void)               //开漏输出高阻态初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_13);	
}



void DIRb_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_14);	 
}


void DIRb_OD_Config(void)               //开漏输出高阻态初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_14);	
}

void PULb_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOB, GPIO_Pin_15);	 
}


void PULb_OD_Config(void)               //开漏输出高阻态初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOB, GPIO_Pin_15);	
}


void ENc_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOC, GPIO_Pin_6);	 
}


void ENc_OD_Config(void)               //开漏输出高阻态初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOC, GPIO_Pin_6);	
}



void DIRc_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOC, GPIO_Pin_7);	 
}


void DIRc_OD_Config(void)               //开漏输出高阻态初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;     
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_SetBits(GPIOC, GPIO_Pin_7);	
}

void PULc_PP_Config(void)               //推挽输出低电平初始化
{
    GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE); 
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
																   
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_ResetBits(GPIOC, GPIO_Pin_8);	 
}


void PULc_OD_Config(void)               //开漏输出高阻态初始化
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
		ENb_OD_Config();                                   //电机使能
		DIRb_PP_Config();                                  //方向向前
	
		for(count_pulse=0;count_pulse<640;count_pulse++)   //640个脉冲
		  {
		  	 PULb_PP_Config();
	       Delay_us(70); 
         PULb_OD_Config();	
         Delay_us(210);				
		  }
				
			
		ENb_PP_Config();                                   //电机失能
			
		YL1(1);Delay_ms(100);YL2(1);Delay_ms(100);YL1(0);YL3(1);Delay_ms(100);YL2(0);Delay_ms(100);YL3(0);  //LED指示灯
			
		step++;	                                           //步数加1
			
		unit = step/1 %10;                                 //计算步数个位
		ten  = step/10%10;                                 //计算步数十位
		
		Segment2(unit);
		Segment1(ten);                                     //数码管显示步数
}

	
	
void Backward(void)
{
		ENb_OD_Config();                                    //电机使能
		DIRb_OD_Config();                                   //方向向后
	  for(;step>1;step--)
	  {
			for(count_pulse=0;count_pulse<640;count_pulse++)  //640个脉冲
				{
					PULb_PP_Config();
					Delay_us(70); 
					PULb_OD_Config();	
					Delay_us(210);				
				}
		}		
		ENb_PP_Config();
		
		YL3(1);Delay_ms(100);YL2(1);Delay_ms(100);YL3(0);YL1(1);Delay_ms(100);YL2(0);Delay_ms(100);YL1(0);
		
		unit = step/1 %10;                 //计算步数个位
		ten  = step/10%10;                 //计算步数十位
		
		Segment2(unit);
		Segment1(ten);                     //数码管显示步数
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
			
		unit = step/1 %10;                 //计算步数个位
		ten  = step/10%10;                 //计算步数十位
		
		Segment2(unit);
		Segment1(ten);                     //数码管显示步数
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

