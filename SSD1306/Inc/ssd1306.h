/*
 * ssd1306.h
 *
 *  Created on: Jul 23, 2025
 *      Author: letam
 */

#ifndef INC_SSD1306_H_
#define INC_SSD1306_H_

#include "stdint.h"
#include "string.h"
#include "stdio.h"
#include "stm32f1xx.h"

#define SSD1306_ADDR			(0x3C << 1)
#define SSD1306_COMMAND_CB		(0x00)
#define SSD1306_DATA_CB			(0x40)

extern I2C_HandleTypeDef hi2c1;

void ssd1306_Init();
void ssd1306_GoToPage(uint8_t page);
void ssd1306_PageIndentedBy(uint8_t num);
void ssd1306_PutChar(uint8_t c);
void ssd1306_PutString(uint8_t *str);
void ssd1306_ClearScreen();

#endif /* INC_SSD1306_H_ */
