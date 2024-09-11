/*
 * ex2.c
 *
 *  Created on: Sep 10, 2024
 *      Author: TruongThien
 */
#include "ex2.h"
void exercise2_run(int *LED_STATUS, int *count) {
    if (*LED_STATUS == 0) {  // Red Light ON
        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
        HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
        HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

        if (*count >= 5) {
            // After 5 seconds, switch to the next LED
            *LED_STATUS = 1;
            *count = 0;  // Reset count for the next LED
        }
    } else if (*LED_STATUS == 1) {  // Yellow Light ON
        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
        HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
        HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

        if (*count >= 2) {
            // After 2 seconds, switch to the next LED
            *LED_STATUS = 2;
            *count = 0;  // Reset count for the next LED
        }
    } else if (*LED_STATUS == 2) {  // Green Light ON
        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
        HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
        HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);

        if (*count >= 3) {
            // After 3 seconds, switch back to Red LED
            *LED_STATUS = 0;
            *count = 0;  // Reset count for the next cycle
        }
    }
}
