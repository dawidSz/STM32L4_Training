/*
 * ws2812b.h
 *
 *  Created on: 28 lip 2026
 *      Author: dawid
 */

#ifndef INC_WS2812B_H_
#define INC_WS2812B_H_

#include "stm32l476xx.h"

void ws2812b_init(void);
void ws2812b_set_color(uint32_t led, uint8_t red, uint8_t green, uint8_t blue);
void ws2812b_update(void);
void ws2812b_wait(void);

#endif /* INC_WS2812B_H_ */
