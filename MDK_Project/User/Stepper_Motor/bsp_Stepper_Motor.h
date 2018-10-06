#ifndef __STEPPERMOTOR_H
#define __STEPPERMOTOR_H

#include "stm32f10x.h"


/***************引脚初始化***************/
void ENa_PP_Config(void);
void ENa_OD_Config(void);

void DIRa_PP_Config(void);
void DIRa_OD_Config(void);

void PULa_PP_Config(void);
void PULa_OD_Config(void);

void ENb_PP_Config(void);
void ENb_OD_Config(void);

void DIRb_PP_Config(void);
void DIRb_OD_Config(void);

void PULb_PP_Config(void);
void PULb_OD_Config(void);

void ENc_PP_Config(void);
void ENc_OD_Config(void);

void DIRc_PP_Config(void);
void DIRc_OD_Config(void);

void PULc_PP_Config(void);
void PULc_OD_Config(void);


/*************动作函数****************/
void Forward(void);
void Backward(void);
void Backward_Step(void);
void Right(void);
void Up(void);
void Down(void);


#endif /* __STEPPERMOTOR_H */
					


