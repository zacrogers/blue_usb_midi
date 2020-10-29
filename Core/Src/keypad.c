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

void keypad_init(Keypad *kp)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	port_clock_enable(kp->cols_port);
	port_clock_enable(kp->rows_port);

	/* Configure cols as input*/
	for(int col = 0; col < N_COLS; ++col)
	{
		GPIO_InitStruct.Pin |= kp->col_pins[col];
	}
	GPIO_InitStruct.Pin = kp->col0_pin | kp->col1_pin | kp->col2_pin | kp->col3_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(kp->cols_port, &GPIO_InitStruct);

	/* Configure rows as output*/
	for(int row = 0; row < N_ROWS; ++row)
	{
		GPIO_InitStruct.Pin |= kp->row_pins[row];
	}
//	GPIO_InitStruct.Pin = kp->row0_pin | kp->row1_pin | kp->row2_pin | kp->row3_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(kp->rows_port, &GPIO_InitStruct);

	/* Initialize keymap*/
	int val = 0;
	for(int row = 0; row < N_ROWS; ++row)
	{
		for(int col = 0; col < N_COLS; ++col)
		{
			kp->key_map[row][col] = val + 69;
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
			if(0x1 && (1 << row))
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
				return kp->key_map[row][col];
			}
		}
	}
}
