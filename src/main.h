/*
 * main.h
 *
 *  Created on: 2 èþë. 2025 ã.
 *      Author:
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_rcc.h"

/* Define */
#define NULL 0

void delay_ms	(uint32_t ms);
void ld_on		(void);
void ld_off		(void);

#endif /* MAIN_H_ */
