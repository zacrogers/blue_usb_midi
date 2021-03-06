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


/* These are used to control what value is currently being changed by the encoders */
typedef enum
{
	ENC_KB_VAR_OCTAVE,
	ENC_SQ_VAR_LENGTH,
	ENC_SQ_VAR_STEP
}Enc1Var;

typedef enum
{
	ENC_KB_VAR_VELOCITY,
	ENC_SQ_VAR_TEMPO,
	ENC_SQ_VAR_NOTE
}Enc2Var;

/* The variable for the keyboard and sequencer modes are both stored in arrays.
 * The two following enums are used for indexing these arrays
 */
typedef enum
{
	KB_VAR_OCTAVE,
	KB_VAR_VELOCITY,
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
#define BPM_TO_MS(bpm) (((60000)/(bpm)))
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void gpio_init(void);
void init_peripherals(void);

/* State functions */
void state_keypad(void);
void state_sequencer(void);

/* Handler functions for keypad state changes */
void key_up_handler(const char key);
void key_down_handler(const char key);

/* Sequencer functions */
void sequencer_timer_init(void);
void sequencer_update_bpm(void);

/* Encoder functions */
void encoder_timer_init(void);
void encoder_button_it_init(void);

/* Handles the mapping of what value the encoders are controlling */
void handle_encoder_1(void);
void handle_encoder_2(void);

/* Updates the given encoder values from the given timer */
void update_encoder(TIM_TypeDef *TIMx, uint8_t min, uint8_t max, uint8_t *curr_val, uint8_t *prev_val);

void handle_encoder_btn_1(void);
void handle_encoder_btn_2(void);

/* Oled drawing functions */
void update_menu(void);
void draw_keypad_main_screen(void);
void draw_sequencer_main_screen(void);
void draw_sequencer_step(uint8_t step);

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

#define MAX_MIDI_OCTAVES 10
#define MAX_MIDI_NOTE    127
#define MAX_VELOCITY     127
#define MAX_NOTE_LEN     10
#define MIN_NOTE_LEN     1

#define NUM_SEMITONES    12
#define NUM_BUTTONS      16

#define MIN_BPM          50
#define MAX_BPM          200

/* Offset depends on font used */
#define OLED_ROW_1       0
#define OLED_ROW_2       20
#define OLED_ROW_3       40

/* Set the top position of the sequencer frame */
#define SEQ_FR_TOP       44

/* Number of sequencer steps */
#define N_SEQ_STEPS      8

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
