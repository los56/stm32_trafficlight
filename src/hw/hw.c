/*
 * hw.c
 *
 *  Created on: Jun 22, 2024
 *      Author: cream
 */


#include "hw.h"





void hwInit(void) {
  bspInit();

  gpioInit();
}
