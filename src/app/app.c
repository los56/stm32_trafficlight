/*
 * app.c
 *
 *  Created on: Jun 22, 2024
 *      Author: cream
 */

#include "app.h"

#include "counter_display.h"
#include "light_controller.h"

static int current = 22;

void count(void);

void appInit(void) {
  lightInit();
  displayOn(current);
}

void appMain(void) {
  while(1) {
    lightLoop();
    displayUpdate(getLeftTime() / 1000);
  }
}


