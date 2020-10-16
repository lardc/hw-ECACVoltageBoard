﻿#ifndef __GLOBAL_H
#define __GLOBAL_H

// Параметры интерфейса
#define	SCCI_TIMEOUT_TICKS		1000	// Таймаут интерфейса SCCI (в мс)
#define EP_WRITE_COUNT			0		// Количество массивов для записи
#define EP_COUNT				7		// Количество массивов для чтения
#define ENABLE_LOCKING			FALSE	// Защита NV регистров паролем
#define VALUES_x_SIZE			1000	// Размер буфера Endpoint

// Временные параметры
#define TIME_LED_BLINK			500		// Мигание светодиодом (в мс)

// Параметры оцифровки
#define ADC_REF_VOLTAGE			3300.0f	// Опорное напряжение (в В)
#define ADC_RESOLUTION			4095	// Разрешение АЦП
#define ADC_DMA_BUFF_SIZE 		4		// Размер буфера ДМА для АЦП

// Параметры регулятора
#define REGULATOR_I_ERR_SAT		100.0f	// Величина насыщения интегральной ошибки

#endif //  __GLOBAL_H
