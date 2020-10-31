/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum
{
	STATE_KEYPAD,
	STATE_SEQUENCER
}State;

typedef enum
{
	MAIN_STATE_KEYPAD,
	MAIN_STATE_SEQUENCER
}MainState;

typedef enum
{
	KP_STATE_ROOT,
	KP_STATE_OCTAVE
}KeypadState;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void gpio_init(void);

void state_change(void);
void state_keypad(void);
void state_sequencer(void);

void key_up_handler(const char key);
void key_down_handler(const char key);

void encoder_timer_init(void);
void encoder_button_it_init(void);
void handle_encoder(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */
#define OB_LED_PORT GPIOC
#define OB_LED_PIN GPIO_PIN_13

#define ENC_BTN_PORT GPIOC
#define ENC_BTN_PIN GPIO_PIN_14

#define MIN_MIDI_NOTE 0
#define MAX_MIDI_NOTE 127

#define MIN_VELOCITY 0
#define MAX_VELOCITY 127

#define NUM_SEMITONES 12
#define NUM_BUTTONS   16

#define N_MENU_OPTS 4
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
