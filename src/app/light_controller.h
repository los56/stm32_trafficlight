/*
 * light_controller.h
 *
 *  Created on: Jun 22, 2024
 *      Author: cream
 */

#ifndef SRC_APP_LIGHT_CONTROLLER_H_
#define SRC_APP_LIGHT_CONTROLLER_H_

#include "app.h"

#define MAX_LIGHT_TARGET 3

#define LIGHT_CAR     ((uint8_t)0)
#define LIGHT_NATURAL ((uint8_t)1)
#define LIGHT_PERSON  ((uint8_t)2)

extern uint32_t STATE_LENGTH[]; // Unit: ms

void      lightInit(void);
void      lightLoop(void);
uint8_t   getLightStatus(void);
uint16_t  getLeftTime(void);

#endif /* SRC_APP_LIGHT_CONTROLLER_H_ */
