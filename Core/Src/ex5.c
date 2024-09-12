/*
 * ex5.c
 *
 *  Created on: Sep 10, 2024
 *      Author: TruongThien
 */
#include "ex5.h"
void display7SEG2(int num, int way){
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
		if (way == 0){
			// Set the GPIO pins according to the 7-segment pattern for the digit
			HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, (segments & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, (segments & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, (segments & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, (segments & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, (segments & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, (segments & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, (segments & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
		}
		if (way == 1){
			// Set the GPIO pins according to the 7-segment pattern for the digit
			HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, (segments & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, (segments & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, (segments & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, (segments & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, (segments & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_13_GPIO_Port, LED_13_Pin, (segments & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_14_GPIO_Port, LED_14_Pin, (segments & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
		}
}

void exercise5_run(int* stage, int* count, int* count_ops){
    int GREEN_TIME = 3000; // Time for green light in milliseconds
    int YELLOW_TIME = 2000; // Time for yellow light in milliseconds
    int RED_TIME = 5000; // Time for red light in milliseconds

    switch (*stage){
        case 1: // North-South Green, East-West Red
            if (*count <= 0){
                *count = YELLOW_TIME;
                *stage = 2;
                HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 1); // Turn off North-South Green
                HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 0); // Turn on North-South Yellow
            }
            break;
        case 2: // North-South Yellow, East-West Red
            if (*count <= 0){
                *count = RED_TIME;
                *count_ops = GREEN_TIME;
                *stage = 3;
                HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 1); // Turn off North-South Yellow
                HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0); // Turn on North-South Red
                HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 0); // Turn on East-West Green
                HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1); // Turn off East-West Red
            }
            break;
        case 3: // North-South Red, East-West Green
            if (*count_ops <= 0){
                *count_ops = YELLOW_TIME;
                *stage = 4;
                HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1); // Turn off East-West Green
                HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 0); // Turn on East-West Yellow
            }
            break;
        case 4: // North-South Red, East-West Yellow
            if (*count <= 0){
                *count = GREEN_TIME;
                *count_ops = RED_TIME;
                *stage = 1;
                HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, 0); // Turn on North-South Green
                HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, 1); // Turn off North-South Yellow
                HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1); // Turn on North-South Red
                HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1); // Turn off East-West Green
                HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1); // Turn off East-West Yellow
                HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0); // Turn off East-West Red
            }
            break;
    }

    // Update the 7-segment displays
    display7SEG2(*count / 1000, 0); // Display remaining time for the North-South direction
    display7SEG2(*count_ops / 1000, 1); // Display remaining time for the East-West direction
}


