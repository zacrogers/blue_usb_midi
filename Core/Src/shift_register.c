/*
 * shift_register.c
 *
 *  Created on: Oct 31, 2020
 *      Author: Zac
 */

#include "shift_register.h"

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


void shift_reg_init(ShiftRegister *reg)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
#ifdef REGISTER_PINS_SAME_PORT
	/* Initialize clocks */
	port_clock_enable(reg->port);

	/* Configure pins as output*/
	GPIO_InitStruct.Pin = reg->data_pin | reg->clock_pin | reg->latch_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(reg->port, &GPIO_InitStruct);
#else
	/* Initialize clocks */
	port_clock_enable(reg->data_port);
	port_clock_enable(reg->clock_port);
	port_clock_enable(reg->latch_port);

	/* Configure pins as output*/
	GPIO_InitStruct.Pin = reg->data_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(reg->data_port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = reg->clock_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(reg->clock_port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = reg->latch_pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(reg->latch_port, &GPIO_InitStruct);
#endif
}


void shift_reg_set(ShiftRegister *reg, uint8_t val)
{
#ifdef REGISTER_PINS_SAME_PORT
	HAL_GPIO_WritePin(reg->port, reg->latch_pin, GPIO_PIN_RESET);

	for(uint8_t bit = 0; bit < N_BITS; ++bit)
	{
		HAL_GPIO_WritePin(reg->port, reg->clock_pin, GPIO_PIN_RESET);

		if(val & (0x01 << bit))
		{
			HAL_GPIO_WritePin(reg->port, reg->data_pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(reg->port, reg->data_pin, GPIO_PIN_RESET);
		}

		HAL_GPIO_WritePin(reg->port, reg->clock_pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(reg->port, reg->latch_pin, GPIO_PIN_SET);

#else

	HAL_GPIO_WritePin(reg->latch_port, reg->latch_pin, GPIO_PIN_RESET);

	for(uint8_t bit = 0; bit < N_BITS; ++bit)
	{
		HAL_GPIO_WritePin(reg->clock_port, reg->clock_pin, GPIO_PIN_RESET);

		if((0x01 << val) & (0x01 << bit))
		{
			HAL_GPIO_WritePin(reg->data_port, reg->data_pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(reg->data_port, reg->data_pin, GPIO_PIN_RESET);
		}

		HAL_GPIO_WritePin(reg->clock_port, reg->clock_pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(reg->latch_port, reg->latch_pin, GPIO_PIN_SET);
#endif
}

void shift_reg_set_point(ShiftRegister *reg, uint8_t val)
{
#ifdef REGISTER_PINS_SAME_PORT
	HAL_GPIO_WritePin(reg->port, reg->latch_pin, GPIO_PIN_RESET);

	for(uint8_t bit = 0; bit < N_BITS; ++bit)
	{
		HAL_GPIO_WritePin(reg->port, reg->clock_pin, GPIO_PIN_RESET);

		if((0x01 << val) & (0x01 << bit))
		{
			HAL_GPIO_WritePin(reg->port, reg->data_pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(reg->port, reg->data_pin, GPIO_PIN_RESET);
		}

		HAL_GPIO_WritePin(reg->port, reg->clock_pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(reg->port, reg->latch_pin, GPIO_PIN_SET);

#else

	HAL_GPIO_WritePin(reg->latch_port, reg->latch_pin, GPIO_PIN_RESET);

	for(uint8_t bit = 0; bit < N_BITS; ++bit)
	{
		HAL_GPIO_WritePin(reg->clock_port, reg->clock_pin, GPIO_PIN_RESET);

		if((0x01 << val) & (0x01 << bit))
		{
			HAL_GPIO_WritePin(reg->data_port, reg->data_pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(reg->data_port, reg->data_pin, GPIO_PIN_RESET);
		}

		HAL_GPIO_WritePin(reg->clock_port, reg->clock_pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(reg->latch_port, reg->latch_pin, GPIO_PIN_SET);
#endif
}

void shift_reg_set_bar(ShiftRegister *reg, uint8_t val)
{
	uint8_t reg_output = 0;
	for(uint8_t i = 0; i < val; ++i){reg_output |= 0x01 << i;}

#ifdef REGISTER_PINS_SAME_PORT
	HAL_GPIO_WritePin(reg->port, reg->latch_pin, GPIO_PIN_RESET);

	for(uint8_t bit = 0; bit < N_BITS; ++bit)
	{
		HAL_GPIO_WritePin(reg->port, reg->clock_pin, GPIO_PIN_RESET);

		if(reg_output & (0x01 << bit))
		{
			HAL_GPIO_WritePin(reg->port, reg->data_pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(reg->port, reg->data_pin, GPIO_PIN_RESET);
		}

		HAL_GPIO_WritePin(reg->port, reg->clock_pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(reg->port, reg->latch_pin, GPIO_PIN_SET);

#else

	HAL_GPIO_WritePin(reg->latch_port, reg->latch_pin, GPIO_PIN_RESET);

	for(uint8_t bit = 0; bit < N_BITS; ++bit)
	{
		HAL_GPIO_WritePin(reg->clock_port, reg->clock_pin, GPIO_PIN_RESET);

		if((0x01 << val) & (0x01 << bit))
		{
			HAL_GPIO_WritePin(reg->data_port, reg->data_pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(reg->data_port, reg->data_pin, GPIO_PIN_RESET);
		}

		HAL_GPIO_WritePin(reg->clock_port, reg->clock_pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(reg->latch_port, reg->latch_pin, GPIO_PIN_SET);
#endif
}

void shift_reg_clear(ShiftRegister *reg)
{
#ifdef REGISTER_PINS_SAME_PORT
	HAL_GPIO_WritePin(reg->port, reg->latch_pin, GPIO_PIN_RESET);

	for(uint8_t bit = 0; bit < N_BITS; ++bit)
	{
		HAL_GPIO_WritePin(reg->port, reg->clock_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(reg->port, reg->data_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(reg->port, reg->clock_pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(reg->port, reg->latch_pin, GPIO_PIN_SET);

#else

	HAL_GPIO_WritePin(reg->latch_port, reg->latch_pin, GPIO_PIN_RESET);

	for(uint8_t bit = 0; bit < N_BITS; ++bit)
	{
		HAL_GPIO_WritePin(reg->clock_port, reg->clock_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(reg->data_port, reg->data_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(reg->clock_port, reg->clock_pin, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(reg->latch_port, reg->latch_pin, GPIO_PIN_SET);
#endif
}



