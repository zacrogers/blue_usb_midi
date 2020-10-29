/*
 * keypad.h
 *
 *  Created on: Oct 28, 2020
 *      Author: Zac
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>

#define N_ROWS 4
#define N_COLS 4

typedef struct
{
	/* Use these if pins are over different ports */
	GPIO_TypeDef* row0_port, row1_port, row2_port, row3_port;
	GPIO_TypeDef* col0_port, col1_port, col2_port, col3_port;

	/* Use use these if rows / cols are on same port */
	GPIO_TypeDef* rows_port;
	GPIO_TypeDef* cols_port;

	uint16_t row0_pin, row1_pin, row2_pin, row3_pin;
	uint16_t col0_pin, col1_pin, col2_pin, col3_pin;

	uint16_t row_pins[N_ROWS];
	uint16_t col_pins[N_COLS];

	uint8_t keys_up[4][4];
	uint8_t key_map[N_ROWS][N_COLS];
}Keypad;

void keypad_init(Keypad *kp);
void keypad_init_keymap(Keypad *kp, uint8_t **map);
char keypad_read(Keypad *kp);

#endif /* INC_KEYPAD_H_ */
