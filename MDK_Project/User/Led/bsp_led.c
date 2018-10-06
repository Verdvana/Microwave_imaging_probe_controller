/**
  ******************************************************************************
  * @file    bsp_LED.c
  * @author  verdvana
  * @version V1.1
  * @date    2018-9-26
  * @brief   LED驱动    
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
		GPIO_InitTypeDef GPIO_InitStructure;

		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE); 
													   

		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;	
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1 ;	
		GPIO_Init(GPIOB, &GPIO_InitStructure);	
															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
				  

		GPIO_ResetBits(GPIOA, GPIO_Pin_3 |GPIO_Pin_4 |GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
	  GPIO_ResetBits(GPIOB, GPIO_Pin_0 |GPIO_Pin_1 );
		GPIO_ResetBits(GPIOC, GPIO_Pin_4 | GPIO_Pin_5);	 
	
}

/*********************************************END OF FILE**********************/
