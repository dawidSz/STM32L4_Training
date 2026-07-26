/*
 * lps.h
 *
 *  Created on: 24 lip 2026
 *      Author: dawid
 */

#ifndef INC_LPS_H_
#define INC_LPS_H_

void lps_init(void);
float lps_get_temperature_celsius(void);
float lps_get_pressure_pa(void);
void lps_set_calib(uint16_t value);

#endif /* INC_LPS_H_ */
