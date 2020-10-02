// Header
#include "Measure.h"

// Includes
#include "Board.h"

// Variables
volatile uint16_t ADC1DMABuff[ADC_BUFF_SIZE] = {0};
volatile uint16_t ADC2DMABuff[ADC_BUFF_SIZE] = {0};
volatile bool MEASURE_VoltageDone = false;
volatile bool MEASURE_CurrentDone = false;

// Functions
void MEAS_SetCurrentRange(uint32_t Current);
void MEAS_SetVoltageRange(uint16_t Voltage);
double MEAS_Voltage();
double MEAS_Current();

void MEAS_SetMeasureRange(uint16_t Voltage, uint32_t Current)
{
	MEAS_SetVoltageRange(Voltage);
	MEAS_SetCurrentRange(Current);
}

void MEAS_SetCurrentRange(uint32_t Current)
{
	if(Current <= HW_I_RANGE_L)
	{
		GPIO_SetState(GPIO_I_RANGE_H, false);
		GPIO_SetState(GPIO_I_RANGE_M, false);
		GPIO_SetState(GPIO_I_RANGE_L, true);
	}
	else
	{
		if(Current <= HW_I_RANGE_M)
		{
			GPIO_SetState(GPIO_I_RANGE_H, false);
			GPIO_SetState(GPIO_I_RANGE_M, true);
			GPIO_SetState(GPIO_I_RANGE_L, false);
		}
		else
		{
			GPIO_SetState(GPIO_I_RANGE_H, true);
			GPIO_SetState(GPIO_I_RANGE_M, false);
			GPIO_SetState(GPIO_I_RANGE_L, false);
		}
	}
}

void MEAS_SetVoltageRange(uint16_t Voltage)
{
	if(Voltage <= HW_U_RANGE_L)
	{
		GPIO_SetState(GPIO_U_RANGE, true);
	}
	else
	{
		GPIO_SetState(GPIO_U_RANGE, false);
	}
}

double MEAS_Voltage()
{
	return 0;
}

double MEAS_Current()
{
	return 0;
}
