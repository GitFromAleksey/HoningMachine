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
#include <stdio.h>
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
#include "array.hpp"
#include "States/AllStates.hpp"
#include "cKeysReader.h"
#include "cKeyHandler.h"
#include "cKeyBind.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
// digital outputs. Для добавления выхода нужно его добавить в MX_GPIO_Init()
#define DO_PORT_MACHINE_PWR_SWITCH        GPIOB
#define DO_PIN_MACHINE_PWR_SWITCH         GPIO_PIN_15 // TODO этот вывод управления не нужен
#define DO_MACHINE_PWR_SWITCH_INVERSION   true

#define DO_PORT_VERTICAL_FEED_MOTOR_SW        GPIOB
#define DO_PIN_VERTICAL_FEED_MOTOR_SW         GPIO_PIN_13 // контактор К1 - двигатель подачи 
#define DO_VERTICAL_FEED_MOTOR_SW_INVERSION   true

#define DO_PORT_ROTATE_MOTOR_TOOL_SW      GPIOB
#define DO_PIN_ROTATE_MOTOR_TOOL_SW       GPIO_PIN_11 // контактор К2 - двигатель вращения
#define DO_ROTATE_MOTOR_TOOL_SW_INVERSION true

#define DO_PORT_TOOL_LIFT_UP_SW           GPIOB
#define DO_PIN_TOOL_LIFT_UP_SW            GPIO_PIN_10 // ЭММ1 - электромагнит подачи вверх
#define DO_TOOL_LIFT_UP_SW_INVERSION      true

#define DO_PORT_TOOL_LIFT_DOWN_SW         GPIOB
#define DO_PIN_TOOL_LIFT_DOWN_SW          GPIO_PIN_1 // ЭММ2 - электромагнит подачи вниз
#define DO_TOOL_LIFT_DOWN_SW_INVERSION    true

// TODO ЭММ3(Ручное управление) нужно добавить для ручного управления

// digital inputs. Для добавления входа нужно его добавить в MX_GPIO_Init()
#define DI_PORT_UPPER_TOOL_TIP            GPIOB
#define DI_PIN_UPPER_TOOL_TIP             GPIO_PIN_0 // верхний концевик
#define DI_UPPER_TOOL_TIP_INVERSION       true

#define DI_PORT_MIDDLE_TOOL_TIP           GPIOB
#define DI_PIN_MIDDLE_TOOL_TIP            GPIO_PIN_2 // средний концевик
#define DI_MIDDLE_TOOL_TIP_INVERSION      true

#define DI_PORT_LOWER_TOOL_TIP            GPIOB
#define DI_PIN_LOWER_TOOL_TIP             GPIO_PIN_12 // нижний концевик
#define DI_LOWER_TOOL_TIP_INVERSION       true


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define ADC_CHANNEL_SUMM        2u
volatile uint16_t               adcDmaData[ADC_CHANNEL_SUMM];  // указатель на этот массив передается в DMA
#define ADC_POSITION_SENSOR     adcDmaData[0]  // ADC_IN0(PA0) - датчик положения
//#define ADC_CURRENT_SENSOR      adcDmaData[1]  // ADC_IN1(PA1) - датчик тока TODO временно отключен
#define ADC_STOP_DMA            HAL_ADC_Stop_DMA(&hadc1);
#define ADC_START_DMA           HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcDmaData[0], ADC_CHANNEL_SUMM);
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

uint8_t huart1Data;
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
//#define NEW_POC_ARR // TODO тестирование нового механизма планировщика(тестирование провалил)

#ifndef NEW_POC_ARR
#define I_PROCESS_ARRAY_SIZE  17
uint8_t iProcessArrCnt = 0;
iProcess* ProcessesArr[I_PROCESS_ARRAY_SIZE];
#else
cArray<iProcess> _ProcessesArr; // TODO для замены ProcessesArr. Пока тестируется
#endif

cDigitalOut MachinePowerSwitch;
cDigitalOut VerticalFeedMotorSwitch;
cDigitalOut RotatedMotorToolSwitch;
cDigitalOut ToolLiftUpSwitch;
cDigitalOut ToolLiftDownSwich;

//cDigitalInput KeyMacinePwrOnOff(GPIOA, GPIO_PIN_8, false);

cDigitalInput UpperToolTip(DI_PORT_UPPER_TOOL_TIP, DI_PIN_UPPER_TOOL_TIP, DI_UPPER_TOOL_TIP_INVERSION);
cDigitalInput LowerToolTip(DI_PORT_LOWER_TOOL_TIP, DI_PIN_LOWER_TOOL_TIP, DI_LOWER_TOOL_TIP_INVERSION);
cDigitalInput MiddleToolTip(DI_PORT_MIDDLE_TOOL_TIP, DI_PIN_MIDDLE_TOOL_TIP, DI_MIDDLE_TOOL_TIP_INVERSION);

cAnalogInput ToolPositionSensor;
cAnalogInput CurrentSensor;

cMachine machine;
cController controller;
//cKeyBoard KeyBoard;

cByteReceiver ByteReceiver(50);
cProtocolDetector ProtocolDetector(&ByteReceiver, &controller);
cByteSender ByteSender(50);
cProtocolFormer ProtocolFormer(&ByteSender);

// кнопки
// ряды матрицы(дискретные выходы)
cDigitalOut KeyRow_0;
cDigitalOut KeyRow_1;
cDigitalOut KeyRow_2;
cDigitalOut KeyRow_3;
// колонки матрицы(дискретные входы)
cDigitalInput KeyCol_0;
cDigitalInput KeyCol_1;
cDigitalInput KeyCol_2;
cDigitalInput KeyCol_3;

cKeysReader Keyboard; // класс опроса дискретных входов
cKeyHandler KeyHandler; // класс обработки нажатий клавиш
cKeyBind KeysArray[4*4]; // массив кнопок, привязанных к действиям станка
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void GPIO_DIO_Init(GPIO_TypeDef *port, uint16_t pin, bool isOutput);
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
#ifdef NEW_POC_ARR
  _ProcessesArr.AddItem(proc);
  return true;
#else
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
#endif
}
// ----------------------------------------------------------------------------
void RunProcesses() // TODO оформить в отдельный класс
{
#ifdef NEW_POC_ARR
  iProcess *proc = _ProcessesArr.GetNextItem();
  if(proc != 0)
    proc->run();
#else
  if(iProcessArrCnt >= I_PROCESS_ARRAY_SIZE)
    iProcessArrCnt = 0;
  if(ProcessesArr[iProcessArrCnt] != NULL)
    ProcessesArr[iProcessArrCnt]->run();
  iProcessArrCnt++;
#endif
}
// ----------------------------------------------------------------------------
void SetupDigitalOut()
{
  MachinePowerSwitch.Init(DO_PORT_MACHINE_PWR_SWITCH, DO_PIN_MACHINE_PWR_SWITCH, DO_MACHINE_PWR_SWITCH_INVERSION);
  MachinePowerSwitch.SetDoSwitchCallback(DO_SwitchCallback);
  MachinePowerSwitch.SetCheckStateCallback(&DIO_CheckStateCallback);
  
  VerticalFeedMotorSwitch.Init(DO_PORT_VERTICAL_FEED_MOTOR_SW, DO_PIN_VERTICAL_FEED_MOTOR_SW, DO_VERTICAL_FEED_MOTOR_SW_INVERSION);
  VerticalFeedMotorSwitch.SetDoSwitchCallback(DO_SwitchCallback);
  VerticalFeedMotorSwitch.SetCheckStateCallback(&DIO_CheckStateCallback);

  RotatedMotorToolSwitch.Init(DO_PORT_ROTATE_MOTOR_TOOL_SW, DO_PIN_ROTATE_MOTOR_TOOL_SW, DO_ROTATE_MOTOR_TOOL_SW_INVERSION);
  RotatedMotorToolSwitch.SetDoSwitchCallback(DO_SwitchCallback);
  RotatedMotorToolSwitch.SetCheckStateCallback(&DIO_CheckStateCallback);
  
  ToolLiftUpSwitch.Init(DO_PORT_TOOL_LIFT_UP_SW, DO_PIN_TOOL_LIFT_UP_SW, DO_TOOL_LIFT_UP_SW_INVERSION);
  ToolLiftUpSwitch.SetDoSwitchCallback(DO_SwitchCallback);
  ToolLiftUpSwitch.SetCheckStateCallback(&DIO_CheckStateCallback);

  ToolLiftDownSwich.Init(DO_PORT_TOOL_LIFT_DOWN_SW, DO_PIN_TOOL_LIFT_DOWN_SW, DO_TOOL_LIFT_DOWN_SW_INVERSION);
  ToolLiftDownSwich.SetDoSwitchCallback(DO_SwitchCallback);
  ToolLiftDownSwich.SetCheckStateCallback(&DIO_CheckStateCallback);

  AddToProcessArray(&MachinePowerSwitch);
  AddToProcessArray(&VerticalFeedMotorSwitch);
  AddToProcessArray(&RotatedMotorToolSwitch);
  AddToProcessArray(&ToolLiftUpSwitch);
  AddToProcessArray(&ToolLiftDownSwich);
}
// ----------------------------------------------------------------------------
void SetupDigitalInput()
{
//  KeyMacinePwrOnOff.SetCheckStateCallback(DIO_CheckStateCallback);
//  KeyMacinePwrOnOff.SetDebounceCntValue(0xFF);

  UpperToolTip.SetCheckStateCallback(DIO_CheckStateCallback);
  UpperToolTip.SetDebounceCntValue(0xFF);
  
  MiddleToolTip.SetCheckStateCallback(DIO_CheckStateCallback);
  MiddleToolTip.SetDebounceCntValue(0xFF);
  
  LowerToolTip.SetCheckStateCallback(DIO_CheckStateCallback);
  LowerToolTip.SetDebounceCntValue(0xFF);
  
  AddToProcessArray(&UpperToolTip);
  AddToProcessArray(&LowerToolTip);
  AddToProcessArray(&MiddleToolTip);
}
// ----------------------------------------------------------------------------
void SetupAnalogInput()
{
  AddToProcessArray(&ToolPositionSensor);
  AddToProcessArray(&CurrentSensor);
}
// ----------------------------------------------------------------------------
void SetupMachine()
{
  t_MachineInitStruct setupMachine;

  setupMachine.MachinePowerSwitch = &MachinePowerSwitch;
  setupMachine.VerticalFeedMotorSwitch = &VerticalFeedMotorSwitch;
  setupMachine.RotatedMotorToolSwitch = &RotatedMotorToolSwitch;
  setupMachine.ToolLiftUpSwitch = &ToolLiftUpSwitch;
  setupMachine.ToolLiftDownSwich = &ToolLiftDownSwich;

  setupMachine.UpperToolTip = &UpperToolTip;
  setupMachine.MiddleToolTip = &MiddleToolTip;
  setupMachine.LowerToolTip = &LowerToolTip;

  setupMachine.ToolPositionSensor = &ToolPositionSensor;
  setupMachine.CurrentSensor = &CurrentSensor;
  
  machine.Init(setupMachine);
  
  AddToProcessArray(&machine);
}
// ----------------------------------------------------------------------------
void SetupController()
{
  controller.AddMachine(&machine);
  controller.AddView(&ProtocolFormer);
  controller.SetGetTicksCallback(HAL_GetTick);
  
  AddToProcessArray(&controller);
}
// ----------------------------------------------------------------------------
void SetupUart()
{
  //ByteReceiver.SetByteCallback(GetByteCallback);
  ByteSender.SetSendByteCallback(SetByteCallback);
  
  AddToProcessArray(&ByteReceiver);
  AddToProcessArray(&ProtocolDetector);
  
  AddToProcessArray(&ByteSender);
  AddToProcessArray(&ProtocolFormer);
}
// ----------------------------------------------------------------------------
void SetupKeyboard(void)
{
// конфигурация дискретных выходов(рядов) матрицы клавиатуры
  // конфигурация портов выхода
  GPIO_DIO_Init(GPIOA, GPIO_PIN_11, true);
  GPIO_DIO_Init(GPIOA, GPIO_PIN_12, true);
  GPIO_DIO_Init(GPIOB, GPIO_PIN_4, true);
  GPIO_DIO_Init(GPIOB, GPIO_PIN_5, true);
  // привязка дискретных выходов к портам
  KeyRow_0.Init(GPIOA, GPIO_PIN_11, false);
  KeyRow_1.Init(GPIOA, GPIO_PIN_12, false);
  KeyRow_2.Init(GPIOB, GPIO_PIN_4, false);
  KeyRow_3.Init(GPIOB, GPIO_PIN_5, false);
  // привязка callbak функции для управления портом
  KeyRow_0.SetDoSwitchCallback(DO_SwitchCallback);
  KeyRow_1.SetDoSwitchCallback(DO_SwitchCallback);
  KeyRow_2.SetDoSwitchCallback(DO_SwitchCallback);
  KeyRow_3.SetDoSwitchCallback(DO_SwitchCallback);
  
// конфигурация дискретных входов(колонок) матрицы клавиатуры
  // конфигурация портов входов
  GPIO_DIO_Init(GPIOB, GPIO_PIN_6, false);
  GPIO_DIO_Init(GPIOB, GPIO_PIN_7, false);
  GPIO_DIO_Init(GPIOB, GPIO_PIN_8, false); // TODO виснет при замыкании с GPIOA, GPIO_PIN_12
  GPIO_DIO_Init(GPIOB, GPIO_PIN_9, false);
  // привязка дискретных входов к портам
  KeyCol_0.Init(GPIOB, GPIO_PIN_6, false);
	KeyCol_0.SetDebounceCntValue(5);
  KeyCol_1.Init(GPIOB, GPIO_PIN_7, false);
	KeyCol_1.SetDebounceCntValue(5);
  KeyCol_2.Init(GPIOB, GPIO_PIN_8, false);
	KeyCol_2.SetDebounceCntValue(5);
  KeyCol_3.Init(GPIOB, GPIO_PIN_9, false);
	KeyCol_3.SetDebounceCntValue(5);
	
  // привязка callbak функции для чтения состояния порта
  KeyCol_0.SetCheckStateCallback(DIO_CheckStateCallback);
  KeyCol_1.SetCheckStateCallback(DIO_CheckStateCallback);
  KeyCol_2.SetCheckStateCallback(DIO_CheckStateCallback);
  KeyCol_3.SetCheckStateCallback(DIO_CheckStateCallback);
  
  // привязка клавиатуры к дискретным входам/выходам для осуществления опроса
  Keyboard.SetRowOutput(&KeyRow_0, 0);
  Keyboard.SetRowOutput(&KeyRow_1, 1);
  Keyboard.SetRowOutput(&KeyRow_2, 2);
  Keyboard.SetRowOutput(&KeyRow_3, 3);

  Keyboard.SetColInput(&KeyCol_0, 0);
  Keyboard.SetColInput(&KeyCol_1, 1);
  Keyboard.SetColInput(&KeyCol_2, 2);
  Keyboard.SetColInput(&KeyCol_3, 3);

  Keyboard.AddKeyHandler(&KeyHandler); // привязка к клавиатуре обработчика нажатий


// привязка кнопок к контроллеру
	uint8_t i = 0;
	// 0-й ряд кнопок
	KeysArray[i++].Init(0, 0, verticalFeedMotorOn, &controller);
	KeysArray[i++].Init(0, 1, toolLiftDown, &controller);
	KeysArray[i++].Init(0, 2, pressKey3, &controller);
	KeysArray[i++].Init(0, 3, pressKey4, &controller);
	// 1-й ряд кнопок
	KeysArray[i++].Init(1, 0, toolRotateStop, &controller);
	KeysArray[i++].Init(1, 1, toolLiftStop, &controller);
	KeysArray[i++].Init(1, 2, verticalFeedMotorOff, &controller);
	KeysArray[i++].Init(1, 3, pressKey8, &controller);
	// 2-й ряд кнопок
	KeysArray[i++].Init(2, 0, toolRotateRun, &controller);
	KeysArray[i++].Init(2, 1, toolLiftUp, &controller);
	KeysArray[i++].Init(2, 2, machinePowerOn, &controller);
	KeysArray[i++].Init(2, 3, machinePowerOff, &controller);
	// 3-й ряд кнопок
	KeysArray[i++].Init(3, 0, verticalFeedMotorOn, &controller);
	KeysArray[i++].Init(3, 1, verticalFeedMotorOff, &controller);
	KeysArray[i++].Init(3, 2, toolLiftUp, &controller);
	KeysArray[i++].Init(3, 3, toolLiftDown, &controller);
  
// добавляем массив кнопок в обработчик нажатий кнопок
  KeyHandler.AddKeysArray(KeysArray, i);
}
// ----------------------------------------------------------------------------
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
  SetupKeyboard();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adcDmaData, 2);
  
  uint32_t ticks = HAL_GetTick();
  
  HAL_UART_Receive_IT(&huart1, &huart1Data, 1);
  
  while(1)
  {
    RunProcesses();
    Keyboard.run(); // TODO добавить в планировщик RunProcesses()
    
    if((HAL_GetTick() - ticks) > 500)
    {
      ticks = HAL_GetTick();
    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
// ----------------------------------------------------------------------------
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
// ----------------------------------------------------------------------------
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
// ----------------------------------------------------------------------------
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
  // TODO тут отключил токовый канал, так как DMA как-то нестабильно работает совместно с прерываниями по UART
  // с работой DMA нужно отдельно разобраться
//  sConfig.Channel = ADC_CHANNEL_1;
//  sConfig.Rank = ADC_REGULAR_RANK_2;
//  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES_5;
//  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
//  {
//    Error_Handler();
//  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}
// ----------------------------------------------------------------------------
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
// ----------------------------------------------------------------------------
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
// ----------------------------------------------------------------------------
// TODO заготовка для инициализации дискретных входов/выходов
// нужно переделать инициализацию всех дискретных входов/выходов
static void GPIO_DIO_Init(GPIO_TypeDef *port, uint16_t pin, bool isOutput)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(isOutput)
  {
    GPIO_InitStruct.Pin = pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  }
  else
  {
    GPIO_InitStruct.Pin = pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  }
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}
// ----------------------------------------------------------------------------
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

  GPIO_InitStruct.Pin = DI_PIN_MIDDLE_TOOL_TIP;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = DI_PIN_LOWER_TOOL_TIP;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  // кнопка вкл/выкл станка
  GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
}
// ----------------------------------------------------------------------------
/* USER CODE BEGIN 4 */
// callback для вкл/выкл дискретных выходов
void DO_SwitchCallback(void *port, uint16_t pinNumber, bool hi_lo)
{
  HAL_GPIO_WritePin((GPIO_TypeDef*)port, pinNumber, (GPIO_PinState) (hi_lo)?(GPIO_PIN_SET):(GPIO_PIN_RESET));
}
// ----------------------------------------------------------------------------
// callback для запроса состояния на выводах
bool DIO_CheckStateCallback(void *port, uint16_t pinNumber)
{
  return (HAL_GPIO_ReadPin((GPIO_TypeDef *)port, pinNumber) == GPIO_PIN_SET) ? (true) : (false);
}
// ----------------------------------------------------------------------------
// callback для запроса принятых байтов по UART
bool GetByteCallback(uint8_t *data)
{
  return (HAL_UART_Receive(&huart1, data, 1, 0x1) == HAL_OK);
}
// ----------------------------------------------------------------------------
// 
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  // FIXME это костыль пришлось сделать, потому что при выполнении этой функции
  // по какой-то причине каналы АЦП менются местами.
  ADC_STOP_DMA;
  
  // при отправке байта HAL_UART_Transmit вызывается __HAL_LOCK и надо бы подождать
  // отправки байта.
  uint8_t _hal_locked_timeout = 0xFF;
  while((huart1.Lock == HAL_LOCKED) && (_hal_locked_timeout > 0))
    --_hal_locked_timeout;
  if(huart1.Lock == HAL_LOCKED) // но если что-то подзависло, то после таймаута
    __HAL_UNLOCK(&huart1);      // принудительно разблокируем __HAL_UNLOCK
  ByteReceiver.QueueAddData(huart1Data);
  HAL_UART_Receive_IT(&huart1, &huart1Data, 1);
  
  ADC_START_DMA; // FIXME это продолжение костыля в начале функции
}
// ----------------------------------------------------------------------------
bool SetByteCallback(uint8_t *data)
{
  // это проверка передатчика на занятость
  if(huart1.Instance->SR & USART_SR_RXNE_Msk)
    return false;
  // шлем по одному байту
  return (HAL_UART_Transmit(&huart1, data, 1, 0x1) == HAL_OK);  
}
// ----------------------------------------------------------------------------
// callback окончания преобразования АЦП
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  if(&hadc1 == hadc)
  {
    //HAL_ADC_Stop_DMA(&hadc1);

    ToolPositionSensor.SetDataFromADC(ADC_POSITION_SENSOR);
//    CurrentSensor.SetDataFromADC(ADC_CURRENT_SENSOR); // TODO пока отключил
    
    ADC_START_DMA;
  }
}
// ----------------------------------------------------------------------------
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
// ----------------------------------------------------------------------------
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
