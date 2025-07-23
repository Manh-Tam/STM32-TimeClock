/*
 * RTC.c
 *
 *  Created on: Jul 17, 2025
 *      Author: letam
 */

#include "RTC.h"


static uint8_t BCD_to_Decimal(uint8_t bcd)
{
	return (bcd >> 4) * 10 + (bcd & 0xf);
}

static uint8_t Decimal_to_BCD(uint8_t dec)
{
	return ((dec / 10) << 4 | (dec % 10));
}

void RTC_Init(DateTime_HandleTypeDef *hdt, I2C_HandleTypeDef *hi2c)
{
	hdt->hi2c = hi2c;
//	hdt->dateTime.second = 0;
//	SetTime(hdt);
}

void GetTime(DateTime_HandleTypeDef *hdt)
{
	uint8_t data[7];
	HAL_I2C_Mem_Read(hdt->hi2c, DEVICE_ADDR, 0x00, 1, data, sizeof(data), 1000);
	hdt->dateTime.second = BCD_to_Decimal(data[0]);
	hdt->dateTime.minute = BCD_to_Decimal(data[1]);
	hdt->dateTime.hour = BCD_to_Decimal(data[2]);
	hdt->dateTime.day = BCD_to_Decimal(data[3]);
	hdt->dateTime.date = BCD_to_Decimal(data[4]);
	hdt->dateTime.month = BCD_to_Decimal(data[5]);
	hdt->dateTime.year = BCD_to_Decimal(data[6]);
}

void SetTime(DateTime_HandleTypeDef *hdt)
{
	uint8_t data[7];
	data[0] = Decimal_to_BCD(hdt->dateTime.second);
	data[1] = Decimal_to_BCD(hdt->dateTime.minute);
	data[2] = Decimal_to_BCD(hdt->dateTime.hour);
	data[3] = Decimal_to_BCD(hdt->dateTime.day);
	data[4] = Decimal_to_BCD(hdt->dateTime.date);
	data[5] = Decimal_to_BCD(hdt->dateTime.month);
	data[6] = Decimal_to_BCD(hdt->dateTime.year);
	HAL_I2C_Mem_Write(hdt->hi2c, DEVICE_ADDR, 0x00, 1, data, sizeof(data), 1000);
}
