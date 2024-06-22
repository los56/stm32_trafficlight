/*
 * gpio.c
 *
 *  Created on: Jun 22, 2024
 *      Author: cream
 */


#include "gpio.h"


static uint16_t channels[] = { GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7,
    GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12 };
static GPIO_TypeDef *gpioxs[] = { GPIOB, GPIOB, GPIOB, GPIOB, GPIOB,
    GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA, GPIOA};

bool gpioInit(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA3 PA4 PA5 PA6
                           PA9 PA10 PA11 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 PB5 PB6
                           PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  return true;
}

void gpioHigh(uint8_t ch) {
  if (ch >= 0 && ch < GPIO_MAX_CH) {
    HAL_GPIO_WritePin(gpioxs[ch], channels[ch], GPIO_PIN_SET);
  }
}

void gpioLow(uint8_t ch) {
  if (ch >= 0 && ch < GPIO_MAX_CH) {
    HAL_GPIO_WritePin(gpioxs[ch], channels[ch], GPIO_PIN_RESET);
  }
}

void gpioToggle(uint8_t ch) {
  if (ch >= 0 && ch < GPIO_MAX_CH) {
    HAL_GPIO_TogglePin(gpioxs[ch], channels[ch]);
  }
}

