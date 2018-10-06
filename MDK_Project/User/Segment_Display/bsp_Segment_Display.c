/**
  ******************************************************************************
  * @file    bsp_Segment_Display.c
  * @author  verdvana
  * @version V1.1
  * @date    2018-9-26
  * @brief   共阴极数码管驱动    
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

#include "bsp_Segment_Display.h"

void Segment_GPIO_Config(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
	
///////////////////////////////////将JTAG引脚作为普通IO//////////////////////////////////
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);  //开复用时钟

		//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);  //即能用PB3，PB4，PA15做普通IO，PA13&14用于SWD调试
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);      //改变指定管脚的映射 GPIO_Remap_SWJ_Disable SWJ 完全禁用（JTAG+SW-DP）
		//GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST, ENABLE);      //PB4可为普通IO口，JTAG&SWD正常使用，但JTAG没有复位
//////////////////////////////////////////////////////////////////////////////////////////	
	
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE); 
													   

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |  GPIO_Pin_1 ;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
												   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5 |  GPIO_Pin_6 |GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 ;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |  GPIO_Pin_1 |GPIO_Pin_2 |  GPIO_Pin_3 | GPIO_Pin_11 | GPIO_Pin_12 ;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 ;
		GPIO_Init(GPIOD, &GPIO_InitStructure);
		
	


		GPIO_ResetBits(GPIOA, GPIO_Pin_0 |  GPIO_Pin_1 );
		GPIO_ResetBits(GPIOB, GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 |GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);	 
		GPIO_ResetBits(GPIOC, GPIO_Pin_0 |  GPIO_Pin_1 |GPIO_Pin_2 |  GPIO_Pin_3 | GPIO_Pin_11 | GPIO_Pin_12 );	 
		GPIO_ResetBits(GPIOD, GPIO_Pin_2 );	 
}

void Segment1(uint8_t s)
{
	switch (s)
	{
		case 0: GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 );
		        GPIO_SetBits(GPIOB, GPIO_Pin_8);
						GPIO_SetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3);
		
						GPIO_ResetBits(GPIOC, GPIO_Pin_2);
		        break;
		
		
		case 1: GPIO_SetBits(GPIOA, GPIO_Pin_0  );
						GPIO_SetBits(GPIOC, GPIO_Pin_1 );
		
						GPIO_ResetBits(GPIOA, GPIO_Pin_1);
						GPIO_ResetBits(GPIOB, GPIO_Pin_8);
						GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3);
						break;
		
		
		case 2: GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 );
		        GPIO_SetBits(GPIOB, GPIO_Pin_8);
						GPIO_SetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_2);
		
						GPIO_ResetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_3);
						break;
						
						
		case 3: GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 );
		        GPIO_SetBits(GPIOB, GPIO_Pin_8);
						GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2);
		
						GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_3);
						break;
						
						
		case 4: GPIO_SetBits(GPIOA, GPIO_Pin_0 );
						GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		
						GPIO_ResetBits(GPIOA, GPIO_Pin_1);
						GPIO_ResetBits(GPIOB, GPIO_Pin_8);
						GPIO_ResetBits(GPIOC, GPIO_Pin_0);
						break;
		
		
		case 5: GPIO_SetBits(GPIOA, GPIO_Pin_1 );
		        GPIO_SetBits(GPIOB, GPIO_Pin_8);
						GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		
						GPIO_ResetBits(GPIOA, GPIO_Pin_0);
						GPIO_ResetBits(GPIOC, GPIO_Pin_0);
						break;
		
		
		case 6: GPIO_SetBits(GPIOA, GPIO_Pin_1 );
		        GPIO_SetBits(GPIOB, GPIO_Pin_8);
						GPIO_SetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		
						GPIO_ResetBits(GPIOA, GPIO_Pin_0);
						break;
		
		
		case 7: GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 );
						GPIO_SetBits(GPIOC, GPIO_Pin_1);
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_8);
						GPIO_ResetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3);
						break;
		
		
		case 8: GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 );
		        GPIO_SetBits(GPIOB, GPIO_Pin_8);
						GPIO_SetBits(GPIOC, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
						break;
		
		
		case 9: GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 );
		        GPIO_SetBits(GPIOB, GPIO_Pin_8);
						GPIO_SetBits(GPIOC, GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
		
						GPIO_ResetBits(GPIOC, GPIO_Pin_0);
						break;
		
	}			
}




void Segment2(uint8_t s)
{
	switch (s)
	{
		case 0: GPIO_SetBits(GPIOB, GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7);
		        GPIO_SetBits(GPIOC, GPIO_Pin_11 | GPIO_Pin_12);
						GPIO_SetBits(GPIOD, GPIO_Pin_2);
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_4);
		        break;
		
		
		case 1: GPIO_SetBits(GPIOB, GPIO_Pin_3  );
						GPIO_SetBits(GPIOD, GPIO_Pin_2 );
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_7);
						GPIO_ResetBits(GPIOC, GPIO_Pin_11 | GPIO_Pin_12);
						break;
		
		
		case 2: GPIO_SetBits(GPIOB, GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_7 );
		        GPIO_SetBits(GPIOC, GPIO_Pin_11);
						GPIO_SetBits(GPIOD, GPIO_Pin_2);
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_3);
						GPIO_ResetBits(GPIOC, GPIO_Pin_12);
						break;
						
						
		case 3: GPIO_SetBits(GPIOB, GPIO_Pin_4 | GPIO_Pin_3 | GPIO_Pin_7 );
		        GPIO_SetBits(GPIOC, GPIO_Pin_11);
						GPIO_SetBits(GPIOD, GPIO_Pin_2);
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_6);
						GPIO_ResetBits(GPIOC, GPIO_Pin_12);
						break;
						
						
		case 4: GPIO_SetBits(GPIOB, GPIO_Pin_3 | GPIO_Pin_4 );
		        GPIO_SetBits(GPIOC, GPIO_Pin_12);
						GPIO_SetBits(GPIOD, GPIO_Pin_2);
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_6 | GPIO_Pin_7 );
						GPIO_ResetBits(GPIOC, GPIO_Pin_11);
						break;
		
		
		case 5: GPIO_SetBits(GPIOB, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_7 );
		        GPIO_SetBits(GPIOC, GPIO_Pin_11 | GPIO_Pin_12);
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_6 );
						GPIO_ResetBits(GPIOD, GPIO_Pin_2);
						break;
		
		
		case 6: GPIO_SetBits(GPIOB, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_7);
						GPIO_SetBits(GPIOC, GPIO_Pin_11| GPIO_Pin_12);
		
						GPIO_ResetBits(GPIOD, GPIO_Pin_2);
						break;
		
		
		case 7: GPIO_SetBits(GPIOB, GPIO_Pin_3);
						GPIO_SetBits(GPIOC, GPIO_Pin_11);
						GPIO_SetBits(GPIOD, GPIO_Pin_2);
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_7);
						GPIO_ResetBits(GPIOC, GPIO_Pin_12);
						break;
		
		
		case 8: GPIO_SetBits(GPIOB, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6 | GPIO_Pin_7);
						GPIO_SetBits(GPIOC, GPIO_Pin_11| GPIO_Pin_12);
						GPIO_SetBits(GPIOD, GPIO_Pin_2);
						break;
		
		
		case 9: GPIO_SetBits(GPIOB, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_7 );
		        GPIO_SetBits(GPIOC, GPIO_Pin_11 | GPIO_Pin_12);
						GPIO_SetBits(GPIOD, GPIO_Pin_2);
		
						GPIO_ResetBits(GPIOB, GPIO_Pin_6);
						break;
		
	}			
}

void Segment_Reset(void)
{
		GPIO_ResetBits(GPIOA, GPIO_Pin_0 |  GPIO_Pin_1 );
		GPIO_ResetBits(GPIOB, GPIO_Pin_3 |GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 |GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9);	 
		GPIO_ResetBits(GPIOC, GPIO_Pin_0 |  GPIO_Pin_1 |GPIO_Pin_2 |  GPIO_Pin_3 | GPIO_Pin_11 | GPIO_Pin_12 );	 
		GPIO_ResetBits(GPIOD, GPIO_Pin_2 );	
}