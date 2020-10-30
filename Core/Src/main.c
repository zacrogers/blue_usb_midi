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
#include <stdlib.h>
#include <stdbool.h>
#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_MIDI.h"
#include "usbd_midi_if.h"
#include "i2c-lcd.h"
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
const char *note_to_string[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
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

State   state       = STATE_KEYPAD;
State   prev_state  = STATE_SEQUENCER;

int     sequence[8]  = {69, 71, 72, 74, 76, 77, 79, 80};
uint8_t midi_channel = 0;
char    note_char[5] = {0}; /* For displaying note to lcd */
char    last_key     = 255; /* Store pressed key */
char    key          = 0;   /* Store key */
uint8_t base_note    = 0;  /* Base note for midi transmission*/
int     encoder_val  = 0;
int     prev_encoder_val  = 0;
char    enc_cnt[6];

int toggle = 1;
uint8_t curr_octave = 0;

volatile bool enc_btn_isr_flag = false;
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
	LCD_SetCursor(&lcd, 0, 0);
	LCD_DisableCursor(&lcd);
	LCD_SendString(&lcd, "Note:");
	LCD_SetCursor(&lcd, 1, 0);
	LCD_SendString(&lcd, "Enc:");

	encoder_timer_init();
	encoder_button_it_init();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
		/* Handle encoder push button */
		if(enc_btn_isr_flag)
		{
			if(toggle)
			{
//				state = STATE_SEQUENCER;
				LCD_SetCursor(&lcd, 0, 9);
				LCD_SendString(&lcd, "SEQ");
				HAL_GPIO_WritePin(OB_LED_PORT, OB_LED_PIN, 1);
				toggle = 0;
			}
			else
			{
//				state = STATE_KEYPAD;
				LCD_SetCursor(&lcd, 0, 9);
				LCD_SendString(&lcd, "KEY");
				HAL_GPIO_WritePin(OB_LED_PORT, OB_LED_PIN, 0);
				toggle = 1;
			}
			enc_btn_isr_flag = false;
		}

		handle_encoder();

		switch(state)
		{
			case STATE_KEYPAD:
			{
				state_keypad();
				break;
			}
			case STATE_SEQUENCER:
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

void state_change(void)
{
	switch(state)
	{
		case STATE_KEYPAD:
		{
			state = STATE_SEQUENCER;
			LCD_SetCursor(&lcd, 0, 8);
			LCD_SendString(&lcd, "SEQ");
			break;
		}
		case STATE_SEQUENCER:
		{
			state = STATE_KEYPAD;
			LCD_SetCursor(&lcd, 0, 8);
			LCD_SendString(&lcd, "KEY");
			break;
		}
	}
}

void state_keypad(void)
{
	keypad_scan(&keypad);
//	key = keypad_read(&keypad);
//
//	if (key!=0xFF && key != last_key)
//	{
//		int note_val = key + ((encoder_val < 127) ? 127 : encoder_val); // limit upper note to 127
//
//		itoa(note_val, note_char, 10);
//		LCD_SetCursor(&lcd, 0, 5);
//		LCD_SendString(&lcd, note_char);
//
//		if(note_val < 9)
//		{
//			LCD_SetCursor(&lcd, 0, 6);
//			LCD_SendString(&lcd, "  ");
//		}
//
//		midi_note_on(midi_channel, note_val, 127);
//		HAL_Delay(250);
//		midi_note_off(midi_channel, note_val, 127);
//	}
//	last_key = key;
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
	midi_note_off(midi_channel, key + encoder_val, 127);
}

void key_down_handler(const char key)
{

	LCD_SetCursor(&lcd, 0, 5);
	LCD_SendString(&lcd, "  ");
	HAL_Delay(100);
	int note_val = key + ((encoder_val < 127) ? 127 : encoder_val); // limit upper note to 12

	int ind = key % NUM_SEMITONES;

	char note_disp[2];
	strcpy(note_disp, note_to_string[ind]);

	itoa(note_val, note_char, 10);
	LCD_SetCursor(&lcd, 0, 5);
	LCD_SendString(&lcd, note_disp);

//	if(note_val < 9)
//	if(ind < 9)
//	{
//		LCD_SetCursor(&lcd, 0, 6);
//		LCD_SendString(&lcd, "  ");
//	}

	midi_note_on(midi_channel, key + encoder_val, 127);
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
void ENCODER_BTN_ISR(void)
{
	if(EXTI->PR & EXTI_PR_PR14)
	{
		enc_btn_isr_flag = true;
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

void handle_encoder(void)
{
	/* Encoder increments twice per tick so divide by 2 */
	encoder_val = TIM2->CNT/2 * NUM_SEMITONES;

	/*
	 *  Set upper and lower limits for encoder values
	 *  Values are shifted due to dividing encoder_val by 2
	 */
	if(encoder_val == 0xFFFF>>1 && prev_encoder_val == 0)
	{
		TIM2->CNT = 0;
		encoder_val = 0;
	}
	else if(encoder_val >= MAX_MIDI_NOTE)
	{
		TIM2->CNT = MAX_MIDI_NOTE << 1;
		encoder_val = MAX_MIDI_NOTE;
	}
	itoa(encoder_val, enc_cnt, 10);
	LCD_SetCursor(&lcd, 1, 4);
	LCD_SendString(&lcd, enc_cnt);
	LCD_SendString(&lcd, "  ");
	prev_encoder_val = encoder_val;

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
