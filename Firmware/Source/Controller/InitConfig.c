// Header
#include "InitConfig.h"

// Include
#include "BCCIxParams.h"
#include "Board.h"
#include "Delay.h"
#include "LowLevel.h"
#include "PWM.h"
#include "SysConfig.h"
#include "ZwDMA.h"

// Variables
extern volatile uint16_t TIM1_DMA_Buffer[SIN_BUFF_SIZE +1 ];

// Functions
Boolean INITCFG_ConfigSystemClock()
{
	return RCC_PLL_HSE_Config(QUARTZ_FREQUENCY, PREDIV_4, PLL_14);
}
//------------------------------------------------

void INITCFG_ConfigIO()
{
	// ��������� ������������ ������
	RCC_GPIO_Clk_EN(PORTA);
	RCC_GPIO_Clk_EN(PORTB);
	RCC_GPIO_Clk_EN(PORTC);
	
	// ������
	GPIO_InitPushPullOutput(GPIO_LED);
	GPIO_InitPushPullOutput(GPIO_LED_EXT);
	GPIO_InitPushPullOutput(GPIO_CTRL_SYNC_1);
	GPIO_InitPushPullOutput(GPIO_CTRL_SYNC_2);
	GPIO_InitPushPullOutput(GPIO_I_RANGE_H);
	GPIO_InitPushPullOutput(GPIO_I_RANGE_M);
	GPIO_InitPushPullOutput(GPIO_I_RANGE_L);
	GPIO_InitPushPullOutput(GPIO_U_RANGE);
	GPIO_InitPushPullOutput(GPIO_CTRL_RELAY_1);
	GPIO_InitPushPullOutput(GPIO_CTRL_RELAY_2);
	GPIO_InitPushPullOutput(GPIO_CTRL_PWMSD_1);
	GPIO_InitPushPullOutput(GPIO_CTRL_PWMSD_2);

	// ����� ����������
	GPIO_InitAnalog(GPIO_MEAS_U);
	GPIO_InitAnalog(GPIO_MEAS_I);

	// �������������� �������
	GPIO_InitAltFunction(GPIO_ALT_CAN_RX, AltFn_9);
	GPIO_InitAltFunction(GPIO_ALT_CAN_TX, AltFn_9);
	GPIO_InitAltFunction(GPIO_ALT_UART_RX, AltFn_7);
	GPIO_InitAltFunction(GPIO_ALT_UART_TX, AltFn_7);
	GPIO_InitAltFunction(GPIO_CTRL_PWM_1, AltFn_6);
	GPIO_InitAltFunction(GPIO_CTRL_PWM_2, AltFn_4);
}
//------------------------------------------------

void INITCFG_ConfigCAN()
{
	RCC_CAN_Clk_EN(CAN_1_ClkEN);
	NCAN_Init(SYSCLK, CAN_BAUDRATE, FALSE);
	NCAN_FIFOInterrupt(TRUE);
	NCAN_FilterInit(0, CAN_SLAVE_FILTER_ID, CAN_SLAVE_NID_MASK);
}
//------------------------------------------------

void INITCFG_ConfigUART()
{
	USART_Init(USART1, SYSCLK, USART_BAUDRATE);
	USART_Recieve_Interupt(USART1, 0, true);
}
//------------------------------------------------

void INITCFG_ConfigTimer7()
{
	TIM_Clock_En(TIM_7);
	TIM_Config(TIM7, SYSCLK, TIMER7_uS);
	TIM_Interupt(TIM7, 0, true);
	TIM_Start(TIM7);
}
//------------------------------------------------

void INITCFG_ConfigWatchDog()
{
	IWDG_Config();
	IWDG_ConfigureFastUpdate();
}
//------------------------------------------------

void INITCFG_PWM()
{
	PWM_ConfigureTIM1_Ch1(SYSCLK, TIMER1_uS);
}
//------------------------------------------------

void INITCFG_DMA()
{
	DMA_Clk_Enable(DMA1_ClkEN);
	DMA_Reset(DMA1_Channel2);
	DMAChannelX_DataConfig(DMA1_Channel2, (uint32_t)TIM1_DMA_Buffer, (uint32_t)(&TIM1->DMAR), SIN_BUFF_SIZE + 1);
	DMAChannelX_Config(DMA1_Channel2, DMA_MEM2MEM_DIS, DMA_LvlPriority_HIGHT,
					   DMA_MSIZE_16BIT, DMA_PSIZE_16BIT, DMA_MINC_EN, DMA_PINC_DIS,
					   DMA_CIRCMODE_DIS, DMA_READ_FROM_MEM);
}
//------------------------------------------------
