/*
 * shift_register.h
 *
 *  Created on: Oct 31, 2020
 *      Author: Zac
 */

#ifndef INC_SHIFT_REGISTER_H_
#define INC_SHIFT_REGISTER_H_

#include "stm32f1xx_hal.h"
#include <stdint.h>

#define REGISTER_PINS_SAME_PORT /* If all pins on the shift register are on the same port uncomment this */
#define N_BITS 8

typedef struct
{
#ifdef REGISTER_PINS_SAME_PORT
	GPIO_TypeDef* port;
#else
	GPIO_TypeDef* data_port;
	GPIO_TypeDef* clock_port;
	GPIO_TypeDef* latch_port;
#endif
	uint16_t data_pin;
	uint16_t clock_pin;
	uint16_t latch_pin;
}ShiftRegister;


void shift_reg_init(ShiftRegister *reg);
void shift_reg_set(ShiftRegister *reg, uint8_t val);
void shift_reg_set_point(ShiftRegister *reg, uint8_t val);
void shift_reg_set_bar(ShiftRegister *reg, uint8_t val);
void shift_reg_clear(ShiftRegister *reg);

#endif /* INC_SHIFT_REGISTER_H_ */
