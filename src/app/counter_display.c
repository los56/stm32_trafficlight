/*
 * counter_display.c
 *
 *  Created on: Jun 22, 2024
 *      Author: cream
 */


#include "counter_display.h"

#define START_CHANNEL_IDX 5
#define END_CHANNEL_IDX 12

static bool showing = false;

void draw(uint16_t value);

void displayOn(uint16_t initValue) {
  showing = true;
  draw(initValue);
}

void displayUpdate(uint16_t value) {
  if (showing) {
    draw(value);
  }
}

void displayOff() {
  draw(0);
  showing = false;
}

void draw(uint16_t value) {
  uint16_t currentValue = value;
  uint16_t digit, mask, pos = START_CHANNEL_IDX;
  int i;

  while (pos <= END_CHANNEL_IDX) {
    digit = currentValue % 10;

    mask = 1;
    for (i = 0;i < 4;i++) {
      if (digit & mask) {
        gpioHigh(pos);
      } else {
        gpioLow(pos);
      }
      mask = mask << 1;
      pos++;
    }

    currentValue /= 10;
  }
}
