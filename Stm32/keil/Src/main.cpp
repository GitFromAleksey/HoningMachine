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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "DigitalOut.hpp"
#include "DigitalInput.hpp"
#include "machine.hpp"
#include "Controller.hpp"
#include "ByteReceiver.hpp"
#include "ProtocolDetector.hpp"
#include "ByteSender.hpp"
#include "ProtocolFormer.hpp"
#include "ProtocolFormer.hpp"
#include "../Interfaces/iProcess.hpp"
#include "KeyBoard.hpp"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
// digital outputs
#define DO_PORT_MACHINE_PWR_SWITCH					GPIOB
#define DO_PIN_MACHINE_PWR_SWITCH						GPIO_PIN_15 // TODO этот вывод управления не нужен

#define DO_PORT_VERTICAL_FEED_MOTOR_SW	GPIOB
#define DO_PIN_VERTICAL_FEED_MOTOR_SW		GPIO_PIN_13 // контактор К1 - двигатель подачи 

#define DO_PORT_ROTATE_MOTOR_TOOL_SW		GPIOB
#define DO_PIN_ROTATE_MOTOR_TOOL_SW			GPIO_PIN_11 // контактор К2 - двигатель вращения

#define DO_PORT_TOOL_LIFT_UP_SW					GPIOB
#define DO_PIN_TOOL_LIFT_UP_SW					GPIO_PIN_10 // ЭММ1 - электромагнит подачи вверх

#define DO_PORT_TOOL_LIFT_DOWN_SW				GPIOB
#define DO_PIN_TOOL_LIFT_DOWN_SW				GPIO_PIN_1 // ЭММ2 - электромагнит подачи вниз

																										// TODO ЭММ3(Ручное управление) нужно добавить для ручного управления

// digital inputs
#define DI_PORT_UPPER_TOOL_TIP					GPIOB
#define DI_PIN_UPPER_TOOL_TIP						GPIO_PIN_0 // верхний концевик

#define DI_PORT_LOWER_TOOL_TIP					GPIOB
#define DI_PIN_LOWER_TOOL_TIP						GPIO_PIN_12 // нижний концевик
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
volatile uint16_t adcDmaData[2];  // указатель на этот массив передается в DMA
#define POSITION_SENSOR		adcDmaData[0]  // ADC_IN0(PA0) - датчик положения
#define CURRENT_SENSOR		adcDmaData[1]  // ADC_IN1(PA1) - датчик тока
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

uint8_t huart1Data;
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
#define I_PROCESS_ARRAY_SIZE	16
uint8_t iProcessArrCnt = 0;
iProcess* ProcessesArr[I_PROCESS_ARRAY_SIZE];

cDigitalOut MachinePowerSwitch;
cDigitalOut VerticalFeedMotorSwitch;
cDigitalOut RotatedMotorToolSwitch;
cDigitalOut ToolLiftUpSwitch;
cDigitalOut ToolLiftDownSwich;

cDigitalInput KeyMacinePwrOnOff(GPIOA, GPIO_PIN_8, false);

cDigitalInput UpperToolTip(DI_PORT_UPPER_TOOL_TIP, DI_PIN_UPPER_TOOL_TIP, true);
cDigitalInput LowerToolTip(DI_PORT_LOWER_TOOL_TIP, DI_PIN_LOWER_TOOL_TIP, true);

cAnalogInput ToolPositionSensor;
cAnalogInput CurrentSensor;

cMachine machine;
cController controller;
cKeyBoard KeyBoard;

cByteReceiver ByteReceiver(50);
cProtocolDetector ProtocolDetector(&ByteReceiver, &controller);
cByteSender ByteSender(50);
cProtocolFormer ProtocolFormer(&ByteSender);

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_DMA_Init(void);
static void MX_NVIC_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
void DO_SwitchCallback(void *port, uint16_t pinNumber, bool hi_lo);
bool DIO_CheckStateCallback(void *port, uint16_t pinNumber);
bool GetByteCallback(uint8_t *data);
bool SetByteCallback(uint8_t *data);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
bool AddToProcessArray(iProcess* proc)
{
	if(iProcessArrCnt < I_PROCESS_ARRAY_SIZE)
	{
		if(proc != NULL)
		{
			ProcessesArr[iProcessArrCnt++] = proc;
			return true;
		}
		else
		{ 
			return false; 
		}
	}
	else
	{ 
		return false;
	}
}
void RunProcesses() // TODO оформить в отдельный класс
{
	if(iProcessArrCnt >= I_PROCESS_ARRAY_SIZE)
		iProcessArrCnt = 0;
	if(ProcessesArr[iProcessArrCnt] != NULL)
		ProcessesArr[iProcessArrCnt]->run();
	iProcessArrCnt++;
}
void SetupDigitalOut()
{
	MachinePowerSwitch.Init(DO_PORT_MACHINE_PWR_SWITCH, DO_PIN_MACHINE_PWR_SWITCH, true);
	MachinePowerSwitch.SetDoSwitchCallback(DO_SwitchCallback);
	MachinePowerSwitch.SetCheckStateCallback(&DIO_CheckStateCallback);
	
	VerticalFeedMotorSwitch.Init(DO_PORT_VERTICAL_FEED_MOTOR_SW, DO_PIN_VERTICAL_FEED_MOTOR_SW, true);
	VerticalFeedMotorSwitch.SetDoSwitchCallback(DO_SwitchCallback);
	VerticalFeedMotorSwitch.SetCheckStateCallback(&DIO_CheckStateCallback);

	RotatedMotorToolSwitch.Init(DO_PORT_ROTATE_MOTOR_TOOL_SW, DO_PIN_ROTATE_MOTOR_TOOL_SW, true);
	RotatedMotorToolSwitch.SetDoSwitchCallback(DO_SwitchCallback);
	RotatedMotorToolSwitch.SetCheckStateCallback(&DIO_CheckStateCallback);
	
	ToolLiftUpSwitch.Init(DO_PORT_TOOL_LIFT_UP_SW, DO_PIN_TOOL_LIFT_UP_SW, true);
	ToolLiftUpSwitch.SetDoSwitchCallback(DO_SwitchCallback);
	ToolLiftUpSwitch.SetCheckStateCallback(&DIO_CheckStateCallback);

	ToolLiftDownSwich.Init(DO_PORT_TOOL_LIFT_DOWN_SW, DO_PIN_TOOL_LIFT_DOWN_SW, true);
	ToolLiftDownSwich.SetDoSwitchCallback(DO_SwitchCallback);
	ToolLiftDownSwich.SetCheckStateCallback(&DIO_CheckStateCallback);
	
//	AddToProcessArray(&DO);
	AddToProcessArray(&MachinePowerSwitch);
	AddToProcessArray(&VerticalFeedMotorSwitch);
	AddToProcessArray(&RotatedMotorToolSwitch);
	AddToProcessArray(&ToolLiftUpSwitch);
	AddToProcessArray(&ToolLiftDownSwich);
}
void SetupDigitalInput()
{
	KeyMacinePwrOnOff.SetCheckStateCallback(DIO_CheckStateCallback);
	KeyMacinePwrOnOff.SetDebounceCntValue(0xFF);

	UpperToolTip.SetCheckStateCallback(DIO_CheckStateCallback);
	UpperToolTip.SetDebounceCntValue(0xFF);
	
	LowerToolTip.SetCheckStateCallback(DIO_CheckStateCallback);
	LowerToolTip.SetDebounceCntValue(0xFF);
	
	AddToProcessArray(&KeyMacinePwrOnOff);
	AddToProcessArray(&UpperToolTip);
	AddToProcessArray(&LowerToolTip);
}
void SetupAnalogInput()
{
	AddToProcessArray(&ToolPositionSensor);
	AddToProcessArray(&CurrentSensor);
//ToolPositionSensor;
//CurrentSensor;
}
void SetupMachine()
{
	t_MachineInitStruct setupMachine;

	setupMachine.MachinePowerSwitch = &MachinePowerSwitch;
	setupMachine.VerticalFeedMotorSwitch = &VerticalFeedMotorSwitch;
	setupMachine.RotatedMotorToolSwitch = &RotatedMotorToolSwitch;
	setupMachine.ToolLiftUpSwitch = &ToolLiftUpSwitch;
	setupMachine.ToolLiftDownSwich = &ToolLiftDownSwich;

	setupMachine.UpperToolTip = &UpperToolTip;
	setupMachine.LowerToolTip = &LowerToolTip;

	setupMachine.ToolPositionSensor = &ToolPositionSensor;
	setupMachine.CurrentSensor = &CurrentSensor;
	
	machine.Init(setupMachine);
	
	AddToProcessArray(&machine);
}
void SetupController()
{
	controller.AddMachine(&machine);
	controller.AddView(&ProtocolFormer);
	controller.SetGetTicksCallback(HAL_GetTick);
	
	AddToProcessArray(&controller);
}
void SetupUart()
{
	//ByteReceiver.SetByteCallback(GetByteCallback);
	ByteSender.SetSendByteCallback(SetByteCallback);
	
	AddToProcessArray(&ByteReceiver);
	AddToProcessArray(&ProtocolDetector);
	
	AddToProcessArray(&ByteSender);
	AddToProcessArray(&ProtocolFormer);
}
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
	MX_DMA_Init();
	MX_ADC1_Init();
  MX_USART1_UART_Init();
  /* Initialize interrupts */
//  MX_NVIC_Init();
	
  /* USER CODE BEGIN 2 */
	SetupDigitalOut();
	SetupDigitalInput();
	SetupAnalogInput();
	SetupMachine();
	SetupController();
	SetupUart();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcDmaData, 2);
	
	uint32_t ticks = HAL_GetTick();
	
	HAL_UART_Receive_IT(&huart1, &huart1Data, 1);
	
  while (1)
  {

		RunProcesses();
		
		if((HAL_GetTick() - ticks) > 500)
		{
			ticks = HAL_GetTick();
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
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV8;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* ADC1_2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(ADC1_2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(ADC1_2_IRQn);
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 2;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_2;
	sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}
/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

}
/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
	
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
	
	// TODO сделать отдельную функцию для конфигурации дискретных входов и выходов
	// digital outputs config
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DO_PORT_MACHINE_PWR_SWITCH, DO_PIN_MACHINE_PWR_SWITCH, GPIO_PIN_RESET);

  /*Configure GPIO pin : PB15 */
  GPIO_InitStruct.Pin = DO_PIN_MACHINE_PWR_SWITCH;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	HAL_GPIO_WritePin(DO_PORT_TOOL_LIFT_DOWN_SW, DO_PIN_TOOL_LIFT_DOWN_SW, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(DO_PORT_TOOL_LIFT_UP_SW, DO_PIN_TOOL_LIFT_UP_SW, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DO_PORT_ROTATE_MOTOR_TOOL_SW, DO_PIN_ROTATE_MOTOR_TOOL_SW, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DO_PORT_VERTICAL_FEED_MOTOR_SW, DO_PIN_VERTICAL_FEED_MOTOR_SW, GPIO_PIN_RESET);

  /*Configure GPIO pin : PB */
  //GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13;
	GPIO_InitStruct.Pin = DO_PIN_TOOL_LIFT_DOWN_SW | DO_PIN_TOOL_LIFT_UP_SW |
	DO_PIN_ROTATE_MOTOR_TOOL_SW | DO_PIN_VERTICAL_FEED_MOTOR_SW;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
  // digital inputs config
  GPIO_InitStruct.Pin = DI_PIN_UPPER_TOOL_TIP;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = DI_PIN_LOWER_TOOL_TIP;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/* USER CODE BEGIN 4 */
void DO_SwitchCallback(void *port, uint16_t pinNumber, bool hi_lo)
{
	HAL_GPIO_WritePin((GPIO_TypeDef*)port, pinNumber, (GPIO_PinState) (hi_lo)?(GPIO_PIN_SET):(GPIO_PIN_RESET));
}
bool DIO_CheckStateCallback(void *port, uint16_t pinNumber)
{
	return (HAL_GPIO_ReadPin((GPIO_TypeDef *)port, pinNumber) == GPIO_PIN_SET) ? (true) : (false);
}
bool GetByteCallback(uint8_t *data)
{
	return (HAL_UART_Receive(&huart1, data, 1, 0x1) == HAL_OK);
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	// при отправке байта HAL_UART_Transmit вызывается __HAL_LOCK и надо бы подождать
	// отправки байта.
	uint8_t _hal_locked_timeout = 0xFF;
	while((huart1.Lock == HAL_LOCKED) && (_hal_locked_timeout-- > 0));
	if(huart1.Lock == HAL_LOCKED) // но если что-то подзависло, то после таймаута
		__HAL_UNLOCK(&huart1);			// принудительно разблокируем __HAL_UNLOCK
	ByteReceiver.QueueAddData(huart1Data);
	HAL_UART_Receive_IT(&huart1, &huart1Data, 1);
}
bool SetByteCallback(uint8_t *data)
{
	// это проверка передатчика на занятость
	if(huart1.Instance->SR & USART_SR_RXNE_Msk)
		return false;
	// шлем по одному байту
	return (HAL_UART_Transmit(&huart1, data, 1, 0x1) == HAL_OK);	
}
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{

	if(&hadc1 == hadc)
	{
		//HAL_ADC_Stop_DMA(&hadc1);

		ToolPositionSensor.SetDataFromADC(POSITION_SENSOR);
		CurrentSensor.SetDataFromADC(CURRENT_SENSOR);
		
		HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcDmaData, 2);
	}
//	DO.Toggle();
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
