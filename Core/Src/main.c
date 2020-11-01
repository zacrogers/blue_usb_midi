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
#include <stdbool.h>
#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_MIDI.h"
#include "usbd_midi_if.h"
#include "i2c-lcd.h"
#include "keypad.h"
#include "shift_register.h"
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

/* Strings for menu labels */
const char *mode_labels[N_MODES]   = {"Keypad", "Sequencer"};
const char *kb_labels[N_KB_OPTS]   = {"Octave", "Velocity"};
const char *seq_labels[N_SEQ_OPTS] = {"Tempo", "Length", "Set Step Note"};

const char *play_labels[N_MODES]   = {"PLAY", "STOP"};
const char *back_label = "Back";
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
		          .row_pins[0] = GPIO_PIN_7,
				  .row_pins[1] = GPIO_PIN_6,
				  .row_pins[2] = GPIO_PIN_5,
				  .row_pins[3] = GPIO_PIN_4,
				  .cols_port   = GPIOA,
				  .col_pins[0] = GPIO_PIN_3,
				  .col_pins[1] = GPIO_PIN_2,
				  .col_pins[2] = GPIO_PIN_8,
				  .col_pins[3] = GPIO_PIN_9}; /* PA0 and PA1 need to be used for encoder */

I2C_LCD lcd = {.address = (0x27 << 1),
			   .columns = 16,
			   .lines   = 2,
			   .mode    = LCD_MODE_4BIT,
			   .i2c_bus = &hi2c1};

ShiftRegister shift_reg = {.port      = GPIOB,
		                   .data_pin  = GPIO_PIN_0,
		                   .latch_pin = GPIO_PIN_1,
		                   .clock_pin = GPIO_PIN_10};

Mode curr_mode = MODE_KEYPAD;
Screen screen = SC_OPTIONS;
EncoderVar curr_enc_var = ENC_KB_OPTIONS;
bool updating_menu_var = false;

uint8_t kb_vars[N_KB_OPTS] = {10, 100};
uint8_t prev_kb_vars[N_KB_OPTS] = {0, 0};

uint8_t seq_vars[N_SEQ_OPTS] = {0};
uint8_t prev_seq_vars[N_SEQ_OPTS] = {0};

char    value_label[3]; /* Buffer for displaying variables in menu */

int     sequence[8]  = {69, 71, 72, 74, 76, 77, 79, 80};
uint8_t midi_channel = 0;
char    note_char[5] = {0}; /* For displaying note to lcd */
char    last_key     = 255; /* Store pressed key */
char    key          = 0;   /* Store key */
uint8_t base_note    = 0;  /* Base note for midi transmission*/
uint8_t last_note_pressed = 0;
int     encoder_val  = 0;
int     prev_encoder_val  = 0;
char    enc_cnt[6];

int toggle = 1;
uint8_t curr_octave = 0;
uint8_t midi_velocity = 100;
volatile bool enc_btn_isr_flag = false;

uint8_t cursor_pos = 0;

uint8_t prev_menu_pos = 0;
uint8_t curr_menu_pos = 0;


uint8_t shift_reg_val = 0;
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

  	/* Init keypad */
	keypad_init(&keypad);
	keypad_set_key_up_handler(&keypad, key_up_handler);
	keypad_set_key_down_handler(&keypad, key_down_handler);

	/* Init usb midi device */
	USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS);
	USBD_RegisterClass(&hUsbDeviceFS, &USBD_MIDI);
	USBD_MIDI_RegisterInterface(&hUsbDeviceFS, &USBD_Interface_fops_FS);
	USBD_Start(&hUsbDeviceFS);

	HAL_Delay(1000);/* Wait for usb to initialize */

	/* Init lcd */
	LCD_Init(&lcd);
	LCD_SetCursor(&lcd, 0, 1);
	LCD_DisableCursor(&lcd);

	LCD_SetCursor(&lcd, 0, 0);
	update_menu();

	/* Init rotary encoder*/
	encoder_timer_init();
	encoder_button_it_init();

	/* Init shift register */
	shift_reg_init(&shift_reg);
	shift_reg_set(&shift_reg, shift_reg_val);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
		/* Handle encoder push button */
		handle_encoder();

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

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = OB_LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(OB_LED_PORT, &GPIO_InitStruct);
}

void update_menu(void)
{
	switch (curr_mode)
	{
		case MODE_KEYPAD:
		{
			if(screen == SC_MAIN)
			{
				LCD_SetCursor(&lcd, 0, 0);
				LCD_SendString(&lcd, "Note:");
				LCD_SetCursor(&lcd, 0, 5);
				LCD_SendString(&lcd, (char *)note_to_string[key]);

				LCD_SetCursor(&lcd, 0, 8);
				LCD_SendString(&lcd, "Vel:");
				itoa(midi_velocity, value_label, 10);
				LCD_SetCursor(&lcd, 0, 12);
				LCD_SendString(&lcd, value_label);

				LCD_SetCursor(&lcd, 1, 0);
				LCD_SendString(&lcd, "Oct:");
				itoa(curr_octave, value_label, 10);
				LCD_SetCursor(&lcd, 1, 4);
				LCD_SendString(&lcd, value_label);
			}
			else if(screen == SC_OPTIONS)
			{
				LCD_SetCursor(&lcd, 0, 0);
				LCD_SendString(&lcd, (char *)mode_labels[MODE_KEYPAD]);
				LCD_SetCursor(&lcd, 1, 0);
				if(updating_menu_var)
					LCD_SendString(&lcd, "*");
				else
					LCD_SendString(&lcd, ">");

				/* Clear bottom row */
				LCD_SetCursor(&lcd, 1, 1);
				LCD_SendString(&lcd, "               ");

				if(curr_menu_pos <= N_KB_OPTS)
				{
					LCD_SetCursor(&lcd, 1, 1);
					LCD_SendString(&lcd, (char *)kb_labels[curr_menu_pos]);

					itoa(kb_vars[curr_menu_pos], value_label, 10);
					LCD_SetCursor(&lcd, 1, 11);
					LCD_SendString(&lcd, value_label);
				}
				else
				{
					LCD_SetCursor(&lcd, 1, 1);
					LCD_SendString(&lcd, (char *)back_label);
				}
			}
			break;
		}

		case MODE_SEQUENCER:
		{
			if(screen == SC_MAIN)
			{

			}
			else if(screen == SC_OPTIONS)
			{

				if(curr_menu_pos <= N_KB_OPTS)
				{

				}
				else
				{

				}
			}

			break;
		}
	}
}


void state_keypad(void)
{
	keypad_scan(&keypad);
}

void state_sequencer(void)
{
	for(int i = 0; i < 8; ++i)
	{
		midi_note_on(midi_channel, sequence[i], 127);
		HAL_Delay(1000);
		midi_note_off(midi_channel, sequence[i], 127);
		HAL_Delay(1000);
	}
}

void key_up_handler(const char key)
{
	midi_note_off(midi_channel, last_note_pressed, kb_vars[KB_VAR_VELOCITY]);
}

void key_down_handler(const char key)
{
	LCD_SetCursor(&lcd, 0, 5);
	LCD_SendString(&lcd, "  ");
	HAL_Delay(100);

	int base_note = kb_vars[KB_VAR_OCTAVE] * NUM_SEMITONES;
	int note_val = key + ((base_note < 127) ? 127 : base_note); // limit upper note to 12
	int ind = key % NUM_SEMITONES;

	char note_disp[2];
	strcpy(note_disp, note_to_string[ind]);

	itoa(note_val, note_char, 10);
	LCD_SetCursor(&lcd, 0, 5);
	LCD_SendString(&lcd, note_disp);

	last_note_pressed = key + base_note;
	midi_note_on(midi_channel, key + base_note, kb_vars[KB_VAR_VELOCITY]);
}

void encoder_timer_init(void)
{
	/* Enable clocks */
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPBEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	TIM2->ARR = 0xFFFF;
	TIM2->CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0 );  /* Map chans to timer inputs */
	TIM2->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);         /* Trigger on rising edge */
	TIM2->SMCR |= TIM_SMCR_SMS_0;                           /* Set encoder mode */
	TIM2->CR1 |= TIM_CR1_CEN ;                              /* Enable timer */
}

/* For handling encoder button */
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & EXTI_PR_PR14)
	{
		enc_btn_isr_flag = true;
		handle_encoder_btn();
		EXTI->PR |= EXTI_PR_PR14;
	}
}

void encoder_button_it_init(void)
{
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
}

void handle_encoder_btn(void)
{
	if(enc_btn_isr_flag)
	{
		HAL_GPIO_TogglePin(OB_LED_PORT, OB_LED_PIN);
		switch(curr_mode)
		{
			case MODE_KEYPAD:
			{
				if(screen == SC_OPTIONS)
				{
					if(!updating_menu_var)
					{
						if(curr_menu_pos == KB_VAR_OCTAVE)
						{
							curr_enc_var = ENC_KB_VAR_OCTAVE;
						}
						else if(curr_menu_pos == KB_VAR_VELOCITY)
						{
							curr_enc_var = ENC_KB_VAR_VELOCITY;
						}
						updating_menu_var = true;
					}
					else
					{
						curr_enc_var = ENC_KB_OPTIONS;
						updating_menu_var = false;
					}
				}
				break;
			}
			case MODE_SEQUENCER:
			{
				break;
			}
		}
		update_menu();
		enc_btn_isr_flag = false;
	}
}

void update_encoder(uint8_t min, uint8_t max, uint8_t *curr_val, uint8_t *prev_val)
{
	*curr_val = TIM2->CNT/2;

	if(*prev_val != *curr_val)
	{
		update_menu();
	}

	if(*curr_val >= max && *prev_val == min)
	{
		TIM2->CNT = min;
		*curr_val = 0;
	}
	else if(*curr_val >= max)
	{
		TIM2->CNT = 0;
		curr_menu_pos = 0;
	}

	*prev_val = *curr_val;
}

void handle_encoder(void)
{
	switch(curr_enc_var)
	{
		case ENC_KB_OPTIONS:
		{
			update_encoder(0, 3, &curr_menu_pos, &prev_menu_pos);
			break;
		}
		case ENC_KB_VAR_OCTAVE:
		{
			update_encoder(0, MAX_MIDI_OCTAVES, &kb_vars[KB_VAR_OCTAVE], &prev_kb_vars[KB_VAR_OCTAVE]);
			break;
		}
		case ENC_KB_VAR_VELOCITY:
		{
			update_encoder(0, MAX_VELOCITY, &kb_vars[KB_VAR_VELOCITY], &prev_kb_vars[KB_VAR_VELOCITY]);
			break;
		}
		case ENC_SQ_OPTIONS:
		{
			break;
		}
		case ENC_SQ_VAR_TEMPO:
		{
			break;
		}
		case ENC_SQ_VAR_LENGTH:
		{
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
