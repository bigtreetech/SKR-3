/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../platforms.h"

#ifdef HAL_STM32

#include "../../inc/MarlinConfig.h"

#if ENABLED(SDIO_SUPPORT)

#include "sdio.h"

#include <stdint.h>
#include <stdbool.h>

#include <stm32h7xx.h>

#define MSD_OK                   0x00
#define MSD_ERROR                0x01


uint8_t waitingRxTask = 0;
uint8_t waitingTxTask = 0;

SD_HandleTypeDef hsd;

void HAL_SD_TxCpltCallback(SD_HandleTypeDef *hsdio)
{
  waitingTxTask = 0;
}

void HAL_SD_RxCpltCallback(SD_HandleTypeDef *hsdio)
{
  waitingRxTask = 0;
}

extern "C" void SDMMC1_IRQHandler(void)
{
  HAL_SD_IRQHandler(&hsd);
}

#define SD_TIMEOUT              1000 // ms

/**
  * @brief  Reads block(s) from a specified address in an SD card, in polling mode.
  * @param  pData: Pointer to the buffer that will contain the data to transmit
  * @param  ReadAddr: Address from where data is to be read
  * @param  NumOfBlocks: Number of SD blocks to read
  * @param  Timeout: Timeout for read operation
  * @retval SD status
  */
uint8_t SDIO_ReadBlocks(uint32_t *pData, uint32_t ReadAddr, uint32_t NumOfBlocks) 
{
  uint32_t Timeout = HAL_GetTick() + SD_TIMEOUT; // ms

  while(HAL_SD_GetCardState(&hsd) != HAL_SD_CARD_TRANSFER)
  {
    if (HAL_GetTick() >= Timeout)
    {
      return MSD_ERROR;
    }
  }

  waitingRxTask = 1;
  HAL_StatusTypeDef stat = HAL_SD_ReadBlocks_DMA(&hsd, (uint8_t *)pData, ReadAddr, NumOfBlocks);
  if (stat != HAL_OK) {
    return MSD_ERROR;
  }

  Timeout = HAL_GetTick() + SD_TIMEOUT;
  while(waitingRxTask)
  {
    if (HAL_GetTick() >= Timeout)
    {
      return MSD_ERROR;
    }
  }

  return MSD_OK;
}

/**
  * @brief  Writes block(s) to a specified address in an SD card, in polling mode.
  * @param  pData: Pointer to the buffer that will contain the data to transmit
  * @param  WriteAddr: Address from where data is to be written
  * @param  NumOfBlocks: Number of SD blocks to write
  * @param  Timeout: Timeout for write operation
  * @retval SD status
  */
uint8_t SDIO_WriteBlocks(uint32_t *pData, uint32_t WriteAddr, uint32_t NumOfBlocks)
{
  uint32_t Timeout = HAL_GetTick() + SD_TIMEOUT; // ms

  while(HAL_SD_GetCardState(&hsd) != HAL_SD_CARD_TRANSFER)
  {
    if (HAL_GetTick() >= Timeout)
    {
      return MSD_ERROR;
    }
  }

  waitingTxTask = 1;
  HAL_StatusTypeDef stat = HAL_SD_WriteBlocks_DMA(&hsd, (uint8_t *)pData, WriteAddr, NumOfBlocks);
  if (stat != HAL_OK) {
    return MSD_ERROR;
  }

  Timeout = HAL_GetTick() + SD_TIMEOUT;
  while(waitingTxTask)
  {
    if (HAL_GetTick() >= Timeout)
    {
      return MSD_ERROR;
    }
  }

  return MSD_OK;
}

uint8_t tryInit(void)
{
  uint8_t sd_state = MSD_OK;
  /* HAL SD initialization */
  hsd.Instance = SDMMC1;
  hsd.Init.ClockEdge = SDMMC_CLOCK_EDGE_RISING;
  hsd.Init.ClockPowerSave = SDMMC_CLOCK_POWER_SAVE_DISABLE;
  hsd.Init.BusWide = SDMMC_BUS_WIDE_1B;
  hsd.Init.HardwareFlowControl = SDMMC_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd.Init.ClockDiv = 1; // 48MHz / 2div = 24Mhz
  /* HAL SD initialization */
  sd_state = HAL_SD_Init(&hsd);

  /* Configure SD Bus width (4 bits mode selected) */
  if (sd_state == MSD_OK)
  {
    /* Enable wide operation */
    if (HAL_SD_ConfigWideBusOperation(&hsd, SDMMC_BUS_WIDE_4B) != HAL_OK)
    {
      sd_state = MSD_ERROR;
    }
  }

  return sd_state;
}

uint8_t SDIO_InitSD(void)
{
  uint8_t sd_state = MSD_OK;
  
  GPIO_InitTypeDef gpio;

  __HAL_RCC_SDMMC1_FORCE_RESET();
  delay(10);
  __HAL_RCC_SDMMC1_RELEASE_RESET();
  delay(10);
  HAL_SD_DeInit(&hsd);

  __HAL_RCC_SDMMC1_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  gpio.Speed = GPIO_SPEED_HIGH;
  gpio.Mode = GPIO_MODE_AF_PP;
  gpio.Alternate = GPIO_AF12_SDIO1;

  gpio.Pull = GPIO_PULLUP;
  gpio.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11;
  HAL_GPIO_Init(GPIOC, &gpio);

  gpio.Pull = GPIO_NOPULL;
  gpio.Pin = GPIO_PIN_12;  
  HAL_GPIO_Init(GPIOC, &gpio);

  gpio.Pull = GPIO_PULLUP;
  gpio.Pin = GPIO_PIN_2;
  HAL_GPIO_Init(GPIOD, &gpio);


  NVIC_EnableIRQ(SDMMC1_IRQn);
  sd_state = tryInit();

  return sd_state;
}

bool SDIO_Init() {
  uint8_t res = SDIO_InitSD();

  if(res == MSD_OK)
    return true;
  else
    return false;
}

bool SDIO_ReadBlock(uint32_t block, uint8_t *dst) {
  uint8_t res = SDIO_ReadBlocks((uint32_t *)dst, block, 1);

  if (res == MSD_OK)
    return true;
  else
    return false;
}

bool SDIO_WriteBlock(uint32_t block, const uint8_t *src) {
  uint8_t res = SDIO_WriteBlocks((uint32_t *)src, block, 1);

  if (res == MSD_OK)
    return true;
  else
    return false;
}

bool SDIO_IsReady() {
  return hsd.State == HAL_SD_STATE_READY;
}

uint32_t SDIO_GetCardSize() {
  return (uint32_t)(hsd.SdCard.BlockNbr) * (hsd.SdCard.BlockSize);
}

#endif // SDIO_SUPPORT
#endif // HAL_STM32
