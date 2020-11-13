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
#include <stdbool.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* The mode represents the method used to send
 * midi data to the host computer
 */
typedef enum
{
	MODE_KEYPAD,
	MODE_SEQUENCER
}Mode;

/*
 *  Each mode has a main and options screen.
 *  The main screen displays the current relevant values for each mode.
 *  The options screen is used for navigation and setting of the various values.
 */
typedef enum
{
	SC_MAIN,
	SC_OPTIONS
}Screen;

/* This is used to control what value is currently being changed by the encode r*/
typedef enum
{
	ENC_KB_OPTIONS,
	ENC_KB_VAR_OCTAVE,
	ENC_KB_VAR_VELOCITY,
	ENC_SQ_OPTIONS,
	ENC_SQ_VAR_TEMPO,
	ENC_SQ_VAR_LENGTH,
	ENC_SQ_VAR_STEP
}EncoderVar;

/* The variable for the keyboard and sequencer modes are both stored in arrays.
 * The two following enums are used for indexing these arrays
 */
typedef enum
{
	KB_VAR_OCTAVE,
	KB_VAR_VELOCITY,
	KB_VAR_NOTE,
	KB_VAR_N
}KbVars;

typedef enum
{
	SQ_VAR_BPM,
	SQ_VAR_LENGTH,
	SQ_VAR_PLAYING,
	SQ_VAR_STEP,
	SQ_VAR_N
}SequencerVars;

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define BPM_TO_MS(bpm) ((60000)/(bpm))
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void gpio_init(void);
void init_peripherals(void);

void state_change(void);
void state_keypad(void);
void state_sequencer(void);

/* Handler functions for keypad state changes */
void key_up_handler(const char key);
void key_down_handler(const char key);

/* Sequencer functions */
void sequencer_timer_init(void);
void sequencer_timer_start(void);
void sequencer_timer_stop(void);
void sequencer_update_bpm(void);

void encoder_timer_init(void);
void encoder_button_it_init(void);

/* Handles the mapping of what value the encoder is controlling */
void handle_encoder(void);
void handle_encoder_2(void);
/* Updates a variable from the timer count value
 * and wraps values around at the limits */
void update_encoder(uint8_t min, uint8_t max, uint8_t *curr_val, uint8_t *prev_val);
void update_encoder2(uint8_t min, uint8_t max, uint8_t *curr_val, uint8_t *prev_val);
void handle_encoder_btn(void);
void handle_encoder_btn_2(void);

/* Redraw the menu */
void update_menu(void);
void draw_keypad_main_screen(void);
void draw_keypad_options_screen(void);
void draw_sequencer_main_screen(void);
void draw_sequencer_options_screen(void);

void draw_sequencer_step(uint8_t step);

long map(long x, long in_min, long in_max, long out_min, long out_max);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */
/* Pin defines*/
#define OB_LED_PORT      GPIOC
#define OB_LED_PIN       GPIO_PIN_13

#define ENC_BTN_PORT     GPIOC
#define ENC_BTN_PIN      GPIO_PIN_14

#define ENC2_BTN_PORT    GPIOB
#define ENC2_BTN_PIN     GPIO_PIN_1

#define MODE_SEL_SW_PORT GPIOB
#define MODE_SEL_SW_PIN  GPIO_PIN_11

#define MAX_MIDI_OCTAVES 10
#define MAX_MIDI_NOTE    127
#define MAX_VELOCITY     127

#define NUM_SEMITONES    12
#define NUM_BUTTONS      16

#define MIN_BPM          50
#define MAX_BPM          200

/* Offset depends on font used*/
#define OLED_ROW_1       0
#define OLED_ROW_2       20
#define OLED_ROW_3       40

/* Set the top position of the sequencer frame */
#define SEQ_FR_TOP       44

/* Defines for menu options */
#define N_MODES          2
#define N_KB_OPTS        3
#define N_SEQ_OPTS       3
#define N_SEQ_STEPS      8
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
