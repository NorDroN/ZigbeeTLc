/*
 * sensor.h
 *
 *  Created on: 14 нояб. 2023 г.
 *      Author: pvvx
 */

#ifndef SRC_SENSORS_H_
#define SRC_SENSORS_H_

#if defined(SENSOR_TYPE)
#if SENSOR_TYPE == SENSOR_SHTXX
#include "sensors_shtxx.h"
#elif SENSOR_TYPE == SENSOR_CHT8305
#include "sensor_cht8305.h"
#else
#error "Define USE_SENSOR!"
#endif
#endif

void adc_channel_init(ADC_InputPchTypeDef p_ain); // in adc_drv.c
u16 get_adc_mv(void); // in adc_drv.c
void battery_detect(void);

#endif /* SRC_SENSORS_H_ */
