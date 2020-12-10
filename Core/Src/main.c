/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_MIDI.h"
#include "usbd_midi_if.h"
#include "i2c-lcd.h"
#include "keypad.h"
#include "shift_register.h"
#include "ssd1306.h"
#include "fonts.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */
const char *note_to_string[NUM_SEMITONES] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
Keypad  keypad = {.rows_port   = GPIOA,
		          .row_pins[0] = GPIO_PIN_5,
				  .row_pins[1] = GPIO_PIN_4,
				  .row_pins[2] = GPIO_PIN_3,
				  .row_pins[3] = GPIO_PIN_2,
				  .cols_port   = GPIOB,
				  .col_pins[0] = GPIO_PIN_12,
				  .col_pins[1] = GPIO_PIN_13,
				  .col_pins[2] = GPIO_PIN_14,
				  .col_pins[3] = GPIO_PIN_15};

/* Variables relevant to the menu system */
Mode       curr_mode         = MODE_KEYPAD;
Enc1Var    enc_1_var         = ENC_KB_VAR_OCTAVE;
Enc2Var    enc_2_var         = ENC_KB_VAR_VELOCITY;

char       note_char[5]      = {0}; /* For displaying note to lcd */
char       value_label[3];          /* Buffer for displaying variables in menu */
char       note_disp[2];
char       midi_note_disp[3];

/* Variables relevant to midi data */
uint8_t    midi_channel             = 0;
uint8_t    last_note_pressed        = 0;

uint8_t    kb_vars[KB_VAR_N]        = {5, 100};     /* Octave, velocity */
uint8_t    prev_kb_vars[KB_VAR_N]   = {0, 0};

uint8_t    seq_vars[SQ_VAR_N]      = {120, 50, 1, 0}; /* BPM, length, playing, step*/
uint8_t    prev_seq_vars[SQ_VAR_N] = {0};

uint8_t    sequence[8]  = {69, 71, 72, 74, 76, 77, 79, 80};
uint8_t    prev_seq[8] = {69, 71, 72, 74, 76, 77, 79, 80};

/* Flags for interrupt routines */
volatile bool enc_btn_isr_flag  = false;
volatile bool enc_btn2_isr_flag = false;
volatile bool seq_tim_isr_flag  = false;

volatile bool step_changed = false;

volatile bool seq_note_on = false;
volatile bool seq_note_off = false;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	/* USER CODE BEGIN 1 */
	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	//  MX_USB_DEVICE_Init();
	MX_I2C1_Init();
	/* USER CODE BEGIN 2 */
	gpio_init(); //  remember to comment out MX_USB_DEVICE_Init(); if MX regenerates it

	init_peripherals();
	sequencer_timer_init();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
		handle_encoder_btn_1(); // Toggles play state
		handle_encoder_btn_2(); // Toggles modes
		handle_encoder_1();
		handle_encoder_2();

		switch(curr_mode)
		{
			case MODE_KEYPAD:
			{
				state_keypad();
				break;
			}
			case MODE_SEQUENCER:
			{
				state_sequencer();
				break;
			}
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

void gpio_init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* Init onboard led pin */
	GPIO_InitStruct.Pin = OB_LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(OB_LED_PORT, &GPIO_InitStruct);
}

void init_peripherals(void)
{
  	/* Init keypad */
	keypad_init(&keypad);
	keypad_set_key_up_handler(&keypad, key_up_handler);
	keypad_set_key_down_handler(&keypad, key_down_handler);

	/* Init usb midi device */
	USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS);
	USBD_RegisterClass(&hUsbDeviceFS, &USBD_MIDI);
	USBD_MIDI_RegisterInterface(&hUsbDeviceFS, &USBD_Interface_fops_FS);
	USBD_Start(&hUsbDeviceFS);

	HAL_Delay(2000);/* Wait for usb to initialize */

	/* Init oled */
	ssd1306_Init();
	HAL_Delay(1000);
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();
	HAL_Delay(1000);

	update_menu();

	/* Init rotary encoder*/
	encoder_timer_init();
	encoder_button_it_init();

	/* Init encoder timer values */
	TIM2->CNT = kb_vars[KB_VAR_OCTAVE]*2;
	TIM3->CNT = kb_vars[KB_VAR_VELOCITY]*2;
}


/********************************
 *** Oled and menu functions ****
 ********************************/
void update_menu(void)
{
	switch (curr_mode)
	{
		case MODE_KEYPAD:
		{
			draw_keypad_main_screen();
			break;
		}

		case MODE_SEQUENCER:
		{
			draw_sequencer_main_screen();
			break;
		}
	}
}


void draw_keypad_main_screen(void)
{
	ssd1306_Fill(Black);

	ssd1306_SetCursor(0, OLED_ROW_1);
	ssd1306_WriteString((char *)note_disp, Font_11x18, White);

	ssd1306_SetCursor(0, OLED_ROW_2);
	ssd1306_WriteString("Vel:", Font_11x18, White);

	itoa(kb_vars[KB_VAR_VELOCITY], value_label, 10);
	ssd1306_SetCursor(44, OLED_ROW_2);
	ssd1306_WriteString(value_label, Font_11x18, White);

	ssd1306_SetCursor(0, OLED_ROW_3);
	ssd1306_WriteString("Oct:", Font_11x18, White);

	itoa(kb_vars[KB_VAR_OCTAVE], value_label, 10);
	ssd1306_SetCursor(44, OLED_ROW_3);
	ssd1306_WriteString(value_label, Font_11x18, White);

	ssd1306_UpdateScreen();
}


/* Draw the rectangle representing current step */
void draw_sequencer_step(uint8_t step)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			ssd1306_DrawPixel(j + step*16, i + SEQ_FR_TOP, White);
		}
	}
}


void draw_sequencer_main_screen(void)
{
	ssd1306_Fill(Black); /* Clear screen*/

	/* Draw text labels */
	ssd1306_SetCursor(0, OLED_ROW_1);
	ssd1306_WriteString("BPM:", Font_11x18, White);

	itoa(seq_vars[SQ_VAR_BPM], value_label, 10);
	ssd1306_SetCursor(44, OLED_ROW_1);
	ssd1306_WriteString(value_label, Font_11x18, White);

	ssd1306_SetCursor(0, OLED_ROW_2);
	ssd1306_WriteString("Len:", Font_11x18, White);

	itoa(seq_vars[SQ_VAR_LENGTH], value_label, 10);
	ssd1306_SetCursor(44, OLED_ROW_2);
	ssd1306_WriteString(value_label, Font_11x18, White);

	ssd1306_SetCursor(88, OLED_ROW_1);

	if(seq_vars[SQ_VAR_PLAYING])
	{
		/* Draw triangle for play symbol */
		/* Draw top part of triangle */
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < y; x++)
			{
				ssd1306_DrawPixel(x + 99, y, White);
			}
		}
		/* Draw bottom part of triangle*/
		int width = 0;
		for (int y = 8; y > 0; y--)
		{
			for (int x = 0; x < y; x++)
			{
				ssd1306_DrawPixel(x + 99, width + 8, White);
			}
			width++;
		}
	}
	else
	{
		/* Draw square for stop */
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				ssd1306_DrawPixel(j + 99, i, White);
			}
		}
	}

	/* Draw note val of current step */
	ssd1306_SetCursor(88, OLED_ROW_2);
	ssd1306_WriteString((char *)midi_note_disp, Font_11x18, White);

	/* Draw sequencer frame */

	/* Draw top horizontal line */
	for (int i = 0; i < 128; i++){ssd1306_DrawPixel(i, 1 + SEQ_FR_TOP, White);}

	/* Draw bottom horizontal line */
	for (int i = 16; i < 18; i++)
	{
		for (int j = 0; j < 128; j++){ssd1306_DrawPixel(j, i + SEQ_FR_TOP, White);}
	}

	/* Draw vertical lines */
	for(int line = 0; line < 17; ++line)
	{
		for (int i = 0; i < 16; i++){ssd1306_DrawPixel(line*16, i + SEQ_FR_TOP, White);}
	}

	/* Draw final vertical line */
	for (int i = 0; i < 16; i++){ssd1306_DrawPixel(127, i + SEQ_FR_TOP, White);}

	draw_sequencer_step(seq_vars[SQ_VAR_STEP]);

	ssd1306_UpdateScreen();
}


/*****************************
 ****** State functions ******
 *****************************/
void state_keypad(void)
{
	keypad_scan(&keypad);
}

/* Loop through sequencer values on timer overflow */
void state_sequencer(void)
{
	if(seq_vars[SQ_VAR_PLAYING])
	{
		if(seq_tim_isr_flag)
		{
			if(!seq_note_on)
			{
				if(seq_vars[SQ_VAR_STEP] < N_SEQ_STEPS-1)
				{
					seq_vars[SQ_VAR_STEP]++;
				}
				else
				{
					seq_vars[SQ_VAR_STEP] = 0;
				}
				prev_seq_vars[SQ_VAR_STEP] = seq_vars[SQ_VAR_STEP];

				midi_note_on(midi_channel, sequence[seq_vars[SQ_VAR_STEP]], kb_vars[KB_VAR_VELOCITY]);

				/* Copy note to string for oled display*/
				itoa(sequence[seq_vars[SQ_VAR_STEP]], midi_note_disp, 10);
				//strcpy(note_disp, note_to_string[ind]);
				update_menu();
				TIM4->ARR = (BPM_TO_MS(seq_vars[SQ_VAR_BPM]*2));// / MAX_NOTE_LEN) * seq_vars[SQ_VAR_LENGTH];
				TIM4->CNT = 0;
				seq_note_on = true;
			}
			else
			{

				midi_note_off(midi_channel, sequence[prev_seq_vars[SQ_VAR_STEP]], kb_vars[KB_VAR_VELOCITY]);
				HAL_GPIO_TogglePin(OB_LED_PORT, OB_LED_PIN);
				TIM4->ARR = (BPM_TO_MS(seq_vars[SQ_VAR_BPM]*2));// / MAX_NOTE_LEN) * seq_vars[SQ_VAR_LENGTH];
				TIM4->CNT = 0;
				seq_note_on = false;
			}
			seq_tim_isr_flag = false;
		}
	}
	else if(!seq_vars[SQ_VAR_PLAYING])
	{
		// Copy note to string for oled display
		itoa(sequence[seq_vars[SQ_VAR_STEP]], midi_note_disp, 10);
		update_menu();
	}
}


/***************************
 **** Keypad functions *****
 ***************************/
void key_up_handler(const char key)
{
	midi_note_off(midi_channel, last_note_pressed, kb_vars[KB_VAR_VELOCITY]);
}

void key_down_handler(const char key)
{
	HAL_Delay(100); /* Debounce */

	int base_note = kb_vars[KB_VAR_OCTAVE] * NUM_SEMITONES;
	int ind       = key % NUM_SEMITONES;

	/* Copy note to string for oled display*/
	strcpy(note_disp, note_to_string[ind]);

	last_note_pressed = key + base_note;
	midi_note_on(midi_channel, key + base_note, kb_vars[KB_VAR_VELOCITY]);
	update_menu();
}


/*******************************
 ***** Sequencer functions *****
 *******************************/

volatile uint16_t seq_timer_cnt = 0;

/* Sequencer timer */
void TIM4_IRQHandler(void)
{
	if (TIM4->SR & TIM_SR_UIF)
	{
		seq_tim_isr_flag = true;
		//seq_note_on = true;
		TIM4->CNT = 0;
		TIM4->SR &= ~(TIM_SR_UIF);
	}
}

/* APB1 clock 48MHz*/
void sequencer_timer_init(void)
{
	/* Main sequencer timer*/
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	TIM4->CR1 &= ~(TIM_CR1_CEN);

	// Setup to trigger at 1ms interval
	TIM4->CNT = 0;
	TIM4->PSC = 48000;
	TIM4->ARR = BPM_TO_MS(seq_vars[SQ_VAR_BPM]*2);

	TIM4->DIER |= TIM_DIER_UIE; // Enable the hardware interrupt.

	NVIC_EnableIRQ(TIM4_IRQn);
	NVIC_SetPriority(TIM4_IRQn, 3);
	TIM4->CR1 |= TIM_CR1_CEN; /* Enable timer */
}


void sequencer_update_bpm(void)
{
	if(prev_seq_vars[SQ_VAR_BPM] != seq_vars[SQ_VAR_BPM])
	{
		TIM4->ARR = (BPM_TO_MS(seq_vars[SQ_VAR_BPM]*2));// / MAX_NOTE_LEN) * seq_vars[SQ_VAR_LENGTH];
		TIM4->CNT = 0;
	}
}


/*****************************
 ***** Encoder functions *****
 *****************************/
void encoder_timer_init(void)
{
	/* Enable clocks */
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPBEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* Setup encoder timer 1 */
	TIM2->ARR = 0xFFFF;
	TIM2->CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0 );  /* Map chans to timer inputs */
	TIM2->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);         /* Trigger on rising edge */
	TIM2->SMCR |= TIM_SMCR_SMS_0;                           /* Set encoder mode */
	TIM2->CR1 |= TIM_CR1_CEN ;                              /* Enable timer */

	/* Enable clocks */
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	/* Setup encoder timer 2 */
	TIM3->ARR = 0xFFFF;
	TIM3->CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0 );  /* Map chans to timer inputs */
	TIM3->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);         /* Trigger on rising edge */
	TIM3->SMCR |= TIM_SMCR_SMS_0;                           /* Set encoder mode */
	TIM3->CR1 |= TIM_CR1_CEN ;                              /* Enable timer */
}


/* For handling encoder 1 button */
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & EXTI_PR_PR14)
	{
		enc_btn_isr_flag = true;
		EXTI->PR |= EXTI_PR_PR14;
	}
}

/* For handling encoder 2 button */
void EXTI1_IRQHandler(void)
{
	if(EXTI->PR & EXTI_PR_PR1)
	{
		enc_btn2_isr_flag = true;
		EXTI->PR |= EXTI_PR_PR1;
	}
}

void encoder_button_it_init(void)
{
	/* Init button 1*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = ENC_BTN_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(ENC_BTN_PORT, &GPIO_InitStruct);

	AFIO->EXTICR[3] |= AFIO_EXTICR4_EXTI14_PC;

	EXTI->IMR |= EXTI_IMR_MR14;
	EXTI->RTSR |= EXTI_RTSR_TR14;

	NVIC_EnableIRQ(EXTI15_10_IRQn);
	NVIC_SetPriority(EXTI15_10_IRQn, 0);

	/* Init button 2*/
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	GPIO_InitStruct.Pin = ENC2_BTN_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(ENC2_BTN_PORT, &GPIO_InitStruct);

	AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI1_PB;

	EXTI->IMR |= EXTI_IMR_MR1;
	EXTI->RTSR |= EXTI_RTSR_TR1;

	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_SetPriority(EXTI1_IRQn, 0);
}

/* This button is used to toggle play/stop in sequencer mode */
void handle_encoder_btn_1(void)
{
	if(enc_btn_isr_flag)
	{
		if(curr_mode == MODE_SEQUENCER)
		{
			if(seq_vars[SQ_VAR_PLAYING])
			{
				seq_vars[SQ_VAR_PLAYING] = 0;
				enc_1_var = ENC_SQ_VAR_STEP;
				enc_2_var = ENC_SQ_VAR_NOTE;

				/* Reset timers to previous values */
				TIM2->CNT = seq_vars[SQ_VAR_STEP]*2;
				TIM3->CNT = seq_vars[seq_vars[SQ_VAR_STEP]]*2;
			}
			else
			{
				seq_vars[SQ_VAR_PLAYING] = 1;
				enc_1_var = ENC_SQ_VAR_LENGTH;
				enc_2_var = ENC_SQ_VAR_TEMPO;

				/* Reset timers to previous values */
				TIM2->CNT = prev_seq_vars[SQ_VAR_LENGTH]*2;
				TIM3->CNT = prev_seq_vars[SQ_VAR_BPM]*2;
			}
		}
		update_menu();
		enc_btn_isr_flag = false;
	}
}

/* This button is used for toggling modes*/
void handle_encoder_btn_2(void)
{
	if(enc_btn2_isr_flag)
	{
		switch(curr_mode)
		{
			case MODE_KEYPAD:
			{
				seq_vars[SQ_VAR_STEP] = 0;
				seq_vars[SQ_VAR_PLAYING] = 0;

				enc_1_var = ENC_SQ_VAR_STEP;
				enc_2_var = ENC_SQ_VAR_NOTE;

				/* Reset timers to previous values */
				TIM2->CNT = prev_seq_vars[SQ_VAR_STEP]*2;
				TIM3->CNT = prev_seq[prev_seq_vars[SQ_VAR_STEP]]*2;

				curr_mode = MODE_SEQUENCER;
				break;
			}
			case MODE_SEQUENCER:
			{
				seq_vars[SQ_VAR_STEP] = 0;
				seq_vars[SQ_VAR_PLAYING] = 0;

				enc_1_var = ENC_KB_VAR_OCTAVE;
				enc_2_var = ENC_KB_VAR_VELOCITY;

				/* Reset timers to previous values */
				TIM2->CNT = prev_kb_vars[KB_VAR_OCTAVE]*2;
				TIM3->CNT = prev_kb_vars[KB_VAR_VELOCITY]*2;

				curr_mode = MODE_KEYPAD;
				break;
			}
		}
		update_menu();
		enc_btn2_isr_flag = false;
	}
}


void update_encoder(TIM_TypeDef *TIMx, uint8_t min, uint8_t max, uint8_t *curr_val, uint8_t *prev_val)
{
	assert(TIMx == TIM2 || TIMx == TIM3);

	TIMx->ARR = max*2;       // Set max timer value
	*curr_val = TIMx->CNT/2; // Increments twice per click so divide by 2

	if(*prev_val != *curr_val)
	{
		/* THIS IS DIRTY */
		if(curr_mode == MODE_SEQUENCER && enc_1_var == ENC_SQ_VAR_STEP && TIMx == TIM2)
		{
			TIM3->CNT = prev_seq[*curr_val]*2;
			sequence[*curr_val] = TIM3->CNT;
		}

		if(curr_mode == MODE_SEQUENCER && enc_1_var == ENC_SQ_VAR_LENGTH && TIMx == TIM2)
		{
			sequencer_update_bpm();
		}

		if(curr_mode == MODE_SEQUENCER && enc_2_var == ENC_SQ_VAR_TEMPO && TIMx == TIM3)
		{
			sequencer_update_bpm();
		}

		update_menu();
	}

	*prev_val = *curr_val;
}


void handle_encoder_1(void)
{
	switch(enc_1_var)
	{
		case ENC_KB_VAR_OCTAVE:
		{
			update_encoder(TIM2, 0, MAX_MIDI_OCTAVES, &kb_vars[KB_VAR_OCTAVE], &prev_kb_vars[KB_VAR_OCTAVE]);
			break;
		}
		case ENC_SQ_VAR_LENGTH:
		{
			update_encoder(TIM2, 1, MAX_NOTE_LEN, &seq_vars[SQ_VAR_LENGTH], &prev_seq_vars[SQ_VAR_LENGTH]);
			break;
		}
		case ENC_SQ_VAR_STEP:
		{
			update_encoder(TIM2, 0, N_SEQ_STEPS, &seq_vars[SQ_VAR_STEP], &prev_seq_vars[SQ_VAR_STEP]);
			break;
		}
	}
}


void handle_encoder_2(void)
{
	switch(enc_2_var)
	{
		case ENC_KB_VAR_VELOCITY:
		{
			update_encoder(TIM3, 0, MAX_VELOCITY, &kb_vars[KB_VAR_VELOCITY], &prev_kb_vars[KB_VAR_VELOCITY]);
			break;
		}
		case ENC_SQ_VAR_TEMPO:
		{
			update_encoder(TIM3, MIN_BPM, MAX_BPM, &seq_vars[SQ_VAR_BPM], &prev_seq_vars[SQ_VAR_BPM]);
			break;
		}
		case ENC_SQ_VAR_NOTE:
		{
			update_encoder(TIM3, 0, MAX_MIDI_NOTE, &sequence[seq_vars[SQ_VAR_STEP]], &prev_seq[seq_vars[SQ_VAR_STEP]]);
			break;
		}
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
