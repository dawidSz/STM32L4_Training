/*
 * lps.c
 *
 *  Created on: 24 lip 2026
 *      Author: dawid
 */

#include "i2c.h"
#include <stdio.h>

#define LPS25HB_ADDR			0xBA
#define LPS25HB_WHO_AM_I 		0x0F
#define LPS25HB_CTRL_REG1 		0x20
#define LPS25HB_CTRL_REG2 		0x21
#define LPS25HB_CTRL_REG3 		0x22
#define LPS25HB_CTRL_REG4 		0x23
#define LPS25HB_PRESS_OUT_XL 	0x28
#define LPS25HB_PRESS_OUT_L 	0x29
#define LPS25HB_PRESS_OUT_H 	0x2A
#define LPS25HB_TEMP_OUT_L 		0x2B
#define LPS25HB_TEMP_OUT_H 		0x2C

static uint8_t lps_read_reg(uint8_t reg);

void lps_Init(void)
{
	uint8_t who_am_i = lps_read_reg(LPS25HB_WHO_AM_I);

	printf("Searching... ");

	if (who_am_i == 0xB4)
	{
		printf("Found: LPS25HB\n");
	}
	else
	{
		printf("Error: (0x%02X)\n", who_am_i);
	}
}


static uint8_t lps_read_reg(uint8_t reg)
{
	uint8_t value = 0;
	HAL_I2C_Mem_Read(&hi2c1, LPS25HB_ADDR, reg, 1, &value, sizeof(value), HAL_MAX_DELAY);
	return value;
}
