/*
 * ex4.c
 *
 *  Created on: Sep 10, 2024
 *      Author: TruongThien
 */
#include "ex4.h"

//void init_exercise4(){
//	HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
//	HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
//	HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
//
//	HAL_GPIO_TogglePin(LED_4_GPIO_Port, LED_4_Pin);
//	HAL_GPIO_TogglePin(LED_5_GPIO_Port, LED_5_Pin);
//	HAL_GPIO_TogglePin(LED_6_GPIO_Port, LED_6_Pin);
//	HAL_GPIO_TogglePin(LED_7_GPIO_Port, LED_7_Pin);
//}

void  display7SEG(int num){
	const uint8_t segmentPatterns[10] = {
	        0b11000000, // 0
	        0b11111001, // 1
	        0b10100100, // 2
	        0b10110000, // 3
	        0b10011001, // 4
	        0b10010010, // 5
	        0b10000010, // 6
	        0b11111000, // 7
	        0b10000000, // 8
	        0b10010000  // 9
	};

	if (num < 0 || num > 9){
		return;// Handle invalid input
	}

	uint8_t segments = segmentPatterns[num];

	// Set the GPIO pins according to the 7-segment pattern for the digit
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, (segments & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, (segments & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, (segments & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, (segments & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, (segments & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, (segments & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, (segments & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

