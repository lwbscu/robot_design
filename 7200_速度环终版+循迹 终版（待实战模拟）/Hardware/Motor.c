#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	PWM_Init();
}


void Motor_L_SetSpeed(int16_t Speed)		//左轮
{

	int limit=3000;
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		if(Speed<limit)
		PWM_SetCompareL(Speed);
		else
			PWM_SetCompareL(limit);
		Delay_ms(1);
		
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		GPIO_SetBits(GPIOB, GPIO_Pin_13);
		
		if(-Speed<limit)
		PWM_SetCompareL(-Speed);
		else
		PWM_SetCompareL(limit);
		Delay_ms(1);
	}
}

void Motor_R_SetSpeed(int16_t Speed)		//左轮
{

	int limit=7000;
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_14);
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
		if(Speed<limit)
		PWM_SetCompareR(Speed);
		else
			PWM_SetCompareR(limit);
		Delay_ms(1);
		
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		GPIO_SetBits(GPIOB, GPIO_Pin_15);
		
		if(-Speed<limit)
		PWM_SetCompareR(-Speed);
		else
		PWM_SetCompareR(limit);
		Delay_ms(1);
	}
}
