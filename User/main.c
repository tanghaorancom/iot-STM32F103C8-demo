#include "delay.h"
#include "stm32f10x.h"

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    // ---------- ??? LED (PA0) ----------
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET); // ????

    // ---------- ??? ??? (PB12) ----------
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET); // ????

    while (1)
    {
        // =================================
        // ???:??,??????
        // =================================
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);  // ??
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_RESET);  // ????
        Delay_ms(1000); // ????1?

        // =================================
        // ???:??,?????
        // =================================
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);    // ??
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET);  // ????
        Delay_ms(1000); // ????1?

        // =================================
        // ???:??,??????
        // ??:?200ms -> ?200ms -> ?200ms
        // =================================
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);  // ??
        // ???
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_RESET);
        Delay_ms(200);
        // ??
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET);
        Delay_ms(200);
        // ???
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_RESET);
        Delay_ms(200);
        // ?????????,?????
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET);

        // =================================
        // ???:??,?????
        // =================================
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);    // ??
        GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET);  // ????
        Delay_ms(1000); // ????1?
    }
}


/**
int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	while(1)
	{
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
		Delay_ms(500);
	}
}


int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	while(1)
	{
		//GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOB, GPIO_Pin_12, Bit_SET);
		Delay_ms(100);
	}
}
*/