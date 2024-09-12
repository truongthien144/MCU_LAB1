/*
 * ex8.c
 *
 *  Created on: Sep 10, 2024
 *      Author: TruongThien
 */
#include "ex7.h"
#include "ex8.h"
void displayLED(int hour, int min){
	if (hour <= 0 || hour > 12 || min < 0 || min > 59){
		return;//Invalid input
	}

	clearAllClock();

	if (hour == 1){
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
	}
	if (hour == 2){
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET);
	}
	if (hour == 3){
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, RESET);
	}
	if (hour == 4){
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, RESET);
	}
	if (hour == 5){
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, RESET);
	}
	if (hour == 6){
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, RESET);
	}
	if (hour == 7){
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, RESET);
	}
	if (hour == 8){
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, RESET);
	}
	if (hour == 9){
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, RESET);
	}
	if (hour == 10){
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, RESET);
	}
	if (hour == 11){
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
	}
	if (hour == 12){
		HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, RESET);
	}

	if (min >= 0 && min < 5){
		HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, RESET);
	}
	if (min >= 5 && min < 10){
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET);
	}
	if (min >= 10 && min < 15){
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET);
	}
	if (min >= 15 && min < 20){
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, RESET);
	}
	if (min >= 20 && min < 25){
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, RESET);
	}
	if (min >= 25 && min < 30){
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, RESET);
	}
	if (min >= 30 && min < 35){
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, RESET);
	}
	if (min >= 35 && min < 40){
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, RESET);
	}
	if (min >= 40 && min < 45){
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, RESET);
	}
	if (min >= 45 && min < 50){
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, RESET);
	}
	if (min >= 50 && min < 55){
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, RESET);
	}
	if (min >= 55){
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET);
	}
}

void setNumberOnClock(int num){
	if (num < 0 || num > 11) {
		return;//Invalid input
	}
	displayLED(num, num);
}

