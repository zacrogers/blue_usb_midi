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
#include <stdbool.h>

#define N_ROWS 4
#define N_COLS 4

typedef void (*key_handler) (const char key);

typedef struct
{
	GPIO_TypeDef* rows_port;
	GPIO_TypeDef* cols_port;

	uint16_t      row_pins[N_ROWS];
	uint16_t      col_pins[N_COLS];

	uint8_t       key_map[N_ROWS][N_COLS];

	uint8_t       keys_up[4][4];
	bool          keys_state[4][4];
	bool          keys_prev_state[4][4];

	key_handler   key_up_handler;
	key_handler   key_down_handler;
}Keypad;

void keypad_init(Keypad *kp);
void keypad_init_keymap(Keypad *kp, uint8_t **map);

/* Use this when just returning the pressed key*/
char keypad_read(Keypad *kp);

/* Use this when using handler functions */
void keypad_scan(Keypad *kp);
void keypad_set_key_up_handler(Keypad *kp, key_handler handler);
void keypad_set_key_down_handler(Keypad *kp, key_handler handler);

#endif /* INC_KEYPAD_H_ */
