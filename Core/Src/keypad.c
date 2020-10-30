/*
 * keypad.c
 *
 *  Created on: Oct 28, 2020
 *      Author: Zac
 */

#include "keypad.h"

static void port_clock_enable(GPIO_TypeDef *port)
{
	if(port == GPIOA)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	}
	else if(port == GPIOB)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	}
	else if(port == GPIOC)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	}
	else if(port == GPIOD)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	}
	else if(port == GPIOE)
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
	}
}

//static bool check_key_down()
//{
//
//}

void keypad_init(Keypad *kp)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* Initialize clocks */
	port_clock_enable(kp->cols_port);
	port_clock_enable(kp->rows_port);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, kp->row_pins[0] | kp->row_pins[1] | kp->row_pins[2] | kp->row_pins[3], GPIO_PIN_RESET);

	/* Configure cols as input*/
	GPIO_InitStruct.Pin = kp->col_pins[0] | kp->col_pins[1] | kp->col_pins[2] | kp->col_pins[3];
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(kp->cols_port, &GPIO_InitStruct);

	/* Configure rows as output*/
	GPIO_InitStruct.Pin = kp->row_pins[0] | kp->row_pins[1] | kp->row_pins[2] | kp->row_pins[3];
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(kp->rows_port, &GPIO_InitStruct);

	/* Initialize keymap and key state arrays */
	int val = 0;
	for(int row = N_ROWS; row >= 0; row--)
	{
		for(int col = 0; col < N_COLS; ++col)
		{
			kp->key_map[row][col] = val - 4; /* -4 to offset row start val*/
			kp->keys_state[4][4] = 0;
			kp->keys_prev_state[4][4] = 0;
			val++;
		}
	}
}

void keypad_init_keymap(Keypad *kp, uint8_t **map)
{
	for(int row = 0; row < N_ROWS; ++row)
	{
		for(int col = 0; col < N_COLS; ++col)
		{
			kp->key_map[row][col] = map[row][col];
		}
	}
}

char keypad_read(Keypad *kp)
{
	for(uint8_t row = 0; row < N_ROWS; ++row)
	{
		/* Set state of row pins */
		for(uint8_t _row = 0; _row < N_ROWS; ++_row)
		{
			if(row == _row)
			{
				HAL_GPIO_WritePin (kp->rows_port, kp->row_pins[_row], GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin (kp->rows_port, kp->row_pins[_row], GPIO_PIN_SET);
			}
		}

		/* Scan column pins */
		for(uint8_t col = 0; col < N_COLS; ++col)
		{
			if(!HAL_GPIO_ReadPin (kp->cols_port, kp->col_pins[col]))
			{
				while (!(HAL_GPIO_ReadPin (kp->cols_port, kp->col_pins[col])));
				return kp->key_map[row][col];
			}
		}
	}
	return 255;
}

void keypad_scan(Keypad *kp)
{
	uint8_t index = 0;

	for(uint8_t row = 0; row < N_ROWS; ++row)
	{
		/* Set state of row pins */
		for(uint8_t _row = 0; _row < N_ROWS; ++_row)
		{
			if(row == _row)
			{
				HAL_GPIO_WritePin (kp->rows_port, kp->row_pins[_row], GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin (kp->rows_port, kp->row_pins[_row], GPIO_PIN_SET);
			}
		}

		/* Scan column pins to read for key press */
		for(uint8_t col = 0; col < N_COLS; ++col)
		{
			if(!HAL_GPIO_ReadPin (kp->cols_port, kp->col_pins[col]))
			{
				kp->keys_state[row][col] = true;
//				kp->_keys_state |= (0x01 << index);
			}
			else
			{
				kp->keys_state[row][col] = false;
//				kp->_keys_state &= ~(0x01 << index);
			}
		}
		index++;
	}


	/* Trigger handlers if state has changed */
//	index = 0;
//
//	if(kp->_keys_prev_state != kp->_keys_state)
//	{
//		for(uint8_t row = 0; row < N_ROWS; ++row)
//		{
//			for(uint8_t col = 0; col < N_COLS; ++col)
//			{
//				 if(kp->_keys_state & (0x01 << index))
//				 {
//					 kp->key_down_handler(kp->key_map[row][col]);
//				 }
//				 else
//				 {
//					 kp->key_up_handler(kp->key_map[row][col]);
//				 }
//			}
//		}
//		index++;
//	}

	for(uint8_t row = 0; row < N_ROWS; ++row)
	{
		for(uint8_t col = 0; col < N_COLS; ++col)
		{
			 if(kp->keys_prev_state[row][col] != kp->keys_state[row][col])
			 {
				 if(kp->keys_state[row][col])
				 {
					 kp->key_down_handler(kp->key_map[row][col]);
				 }
				 else
				 {
					 kp->key_up_handler(kp->key_map[row][col]);
				 }
			 }
		}
	}

//	kp->_keys_prev_state = kp->_keys_state; /* Copy current state to prev state */

	/* Copy current state to prev state */
	for(uint8_t row = 0; row < N_ROWS; ++row)
	{
		for(uint8_t col = 0; col < N_COLS; ++col)
		{
			 kp->keys_prev_state[row][col] = kp->keys_state[row][col];
		}
	}
}


void keypad_set_key_up_handler(Keypad *kp, key_handler handler)
{
	kp->key_up_handler = handler;
}

void keypad_set_key_down_handler(Keypad *kp, key_handler handler)
{
	kp->key_down_handler = handler;
}


