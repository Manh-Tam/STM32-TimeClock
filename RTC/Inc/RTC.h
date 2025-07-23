/*
 * RTC.h
 *
 *  Created on: Jul 17, 2025
 *      Author: letam
 */

#ifndef INC_RTC_H_
#define INC_RTC_H_
#include "stm32f1xx.h"


#define DEVICE_ADDR	(0x68 << 1)

typedef struct
{
	uint8_t second;
	uint8_t minute;
	uint8_t hour;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}DateTime;

typedef struct
{
	DateTime dateTime;
	I2C_HandleTypeDef *hi2c;
}DateTime_HandleTypeDef ;

void RTC_Init(DateTime_HandleTypeDef *hdt, I2C_HandleTypeDef *hi2c);
void GetTime(DateTime_HandleTypeDef *hdt);
void SetTime(DateTime_HandleTypeDef *hdt);


#endif /* INC_RTC_H_ */
