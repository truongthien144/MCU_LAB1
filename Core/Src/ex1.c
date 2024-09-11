/*
 * ex1.c
 *
 *  Created on: Sep 10, 2024
 *      Author: TruongThien
 */
#include "ex1.h"

int LED_STATUS = LED_OFF;

void init_exercise1(){

}
void led_on(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
}

void led_off(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
}

void exercise1_run(){
	if (LED_STATUS == LED_ON) {
		led_on();
		LED_STATUS = LED_OFF;
	}
	else if (LED_STATUS == LED_OFF) {
		led_off();
		LED_STATUS = LED_ON;
	}
}

