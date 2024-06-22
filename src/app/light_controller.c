/*
 * light_controller.c
 *
 *  Created on: Jun 22, 2024
 *      Author: cream
 */



#include "light_controller.h"

uint32_t STATE_LENGTH[] = { 30000, 5000, 20000 };

static uint8_t state;
static uint16_t channels[3][2] = { {2, 3}, {1, 3}, {0, 4} }; // order by NEGATIVE state, POSITIVE state

static uint8_t nextStates[] = { LIGHT_NATURAL, LIGHT_PERSON, LIGHT_CAR };
static uint32_t befTick, timeCounterForPersonGreen;

void changeState(void);
void blinkPersonGreen(void);
void onLight(uint8_t ch);
void offLight(uint8_t ch);

void lightInit(void) {
  state = LIGHT_PERSON;
  changeState();
}

void lightLoop(void) {
  if (state == LIGHT_PERSON) {
    //blinkPersonGreen();
  }

  if ((millis() - befTick) >= STATE_LENGTH[state]) {
    changeState();
  }
}

uint8_t getLightStatus(void) {
  return state;
}

uint16_t getLeftTime(void) {
  return STATE_LENGTH[state] - (millis() - befTick);
}

void changeState() {
  int i;

  state = nextStates[state];
  befTick = millis();

  for (i = 0;i < MAX_LIGHT_TARGET;i++) {
    offLight(channels[i][0]);
    offLight(channels[i][1]);
  }

  onLight(channels[state][0]);
  onLight(channels[state][1]);

  if (state == LIGHT_PERSON) {
    timeCounterForPersonGreen = 0;
  }
}

void blinkPersonGreen() {
//  int32_t leftTime = STATE_LENGTH[state] - timeCounter;
//  uint32_t targetLeft;
//
//  if(leftTime >= 10000) {
//    targetLeft = 2000;
//  } else {
//    targetLeft = 1000;
//  }
//
//  timeCounterForPersonGreen += millis();
//  if(timeCounterForPersonGreen <= targetLeft) {
//    return;
//  }
//
//  gpioToggle(channels[LIGHT_PERSON][1]);
//  timeCounterForPersonGreen = 0;
}

void onLight(uint8_t ch) {
  if(ch < 100) {
    gpioHigh(ch);
  }
}

void offLight(uint8_t ch) {
  if(ch < 100) {
    gpioLow(ch);
  }
}

