/*
 * ex6.c
 *
 *  Created on: Sep 10, 2024
 *      Author: TruongThien
 */
#include "ex6.h"
void testLED(int num){
	if (num <= 0 || num > 12) {
		return;// Invalid input
	}

	clearAllClock();

	if (num == 1){
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
	}
	if (num == 2){
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET);
	}
	if (num == 3){
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, RESET);
	}
	if (num == 4){
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, RESET);
	}
	if (num == 5){
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, RESET);
	}
	if (num == 6){
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, RESET);
	}
	if (num == 7){
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, RESET);
	}
	if (num == 8){
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, RESET);
	}
	if (num == 9){
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, RESET);
	}
	if (num == 10){
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, RESET);
	}
	if (num == 11){
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
	}
	if (num == 12){
		HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, RESET);
	}
}
