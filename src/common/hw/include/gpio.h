/*
 * gpio.h
 *
 *  Created on: Jun 22, 2024
 *      Author: cream
 */

#ifndef SRC_HW_GPIO_GPIO_H_
#define SRC_HW_GPIO_GPIO_H_

#include "hw_def.h"

#ifdef _USE_HW_GPIO

#define GPIO_MAX_CH HW_GPIO_MAX_CH

bool gpioInit(void);
void gpioHigh(uint8_t ch);
void gpioLow(uint8_t ch);
void gpioToggle(uint8_t ch);

#endif

#endif /* SRC_HW_GPIO_GPIO_H_ */
