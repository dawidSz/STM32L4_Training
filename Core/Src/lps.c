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
#define LPS25HB_CTRL_REG1 		0x10
#define LPS25HB_CTRL_REG2 		0x11
#define LPS25HB_CTRL_REG3 		0x12
#define LPS25HB_CTRL_REG4 		0x13
#define LPS25HB_PRESS_OUT_XL 	0x28
#define LPS25HB_PRESS_OUT_L 	0x29
#define LPS25HB_PRESS_OUT_H 	0x2A
#define LPS25HB_TEMP_OUT_L 		0x2B
#define LPS25HB_TEMP_OUT_H 		0x2C

#define LPS25HB_CTRL_REG1_PD 	0x80
#define LPS25HB_CTRL_REG1_ODR2 	0x40
#define LPS25HB_CTRL_REG1_ODR1 	0x20
#define LPS25HB_CTRL_REG1_ODR0 	0x10

static uint8_t lps_read_reg(uint8_t reg);
static void lps_write_reg(uint8_t reg, uint8_t value);
static float lps_get_temperature_celsius(void);
static float lps_get_pressure_pa(void);

void lps_Init(void)
{
	uint8_t who_am_i = lps_read_reg(LPS25HB_WHO_AM_I);

	printf("Searching... ");

	if (who_am_i == 0xB4)
	{
		printf("Found: LPS25DF\n");
	}
	else
	{
		printf("Error: (0x%02X)\n", who_am_i);
	}

	/* Turn on 25Hz measurement. */
	lps_write_reg(LPS25HB_CTRL_REG1, LPS25HB_CTRL_REG1_PD | LPS25HB_CTRL_REG1_ODR2);
	HAL_Delay(100U);

	printf("T = %f\n deg. Celsius", lps_get_temperature_celsius());
	printf("P = %f\n hPa", lps_get_pressure_pa());
}

static float lps_get_temperature_celsius(void)
{
	int16_t temp = 0;

	HAL_I2C_Mem_Read(
		  &hi2c1,
		  LPS25HB_ADDR,
		  LPS25HB_TEMP_OUT_L | 0x80,
		  1,
		  (uint8_t*)&temp,
		  sizeof(temp),
		  HAL_MAX_DELAY
	);

	return  temp / 100.0f;
}

static float lps_get_pressure_pa(void)
{
	int32_t pressure = 0;

	HAL_I2C_Mem_Read(
		&hi2c1,
		LPS25HB_ADDR,
		LPS25HB_PRESS_OUT_XL | 0x80,
		1,
		(uint8_t*)&pressure,
		3,
		HAL_MAX_DELAY
	);

	return pressure / 4096.0f;
}

static void lps_write_reg(uint8_t reg, uint8_t value)
{
	HAL_I2C_Mem_Write(&hi2c1, LPS25HB_ADDR, reg, 1, &value, sizeof(value), HAL_MAX_DELAY);
}

static uint8_t lps_read_reg(uint8_t reg)
{
	uint8_t value = 0;
	HAL_I2C_Mem_Read(&hi2c1, LPS25HB_ADDR, reg, 1, &value, sizeof(value), HAL_MAX_DELAY);
	return value;
}
