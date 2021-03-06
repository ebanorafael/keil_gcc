/**
  ******************************************************************************
  * @file    stm32l0xx_hal_tsc.h
  * @author  MCD Application Team
  * @brief   Header file of TSC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32L0xx_HAL_TSC_H
#define __STM32L0xx_HAL_TSC_H

#ifdef __cplusplus
 extern "C" {
#endif

#if defined(TSC)
/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal_def.h"

/** @addtogroup STM32L0xx_HAL_Driver
  * @{
  */

/** @addtogroup TSC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup TSC_Exported_Types TSC Exported Types
  * @{
  */

/** 
  * @brief TSC state structure definition
  */
typedef enum
{
  HAL_TSC_STATE_RESET  = 0x00U, /*!< TSC registers have their reset value */
  HAL_TSC_STATE_READY  = 0x01U, /*!< TSC registers are initialized or acquisition is completed with success */
  HAL_TSC_STATE_BUSY   = 0x02U, /*!< TSC initialization or acquisition is on-going */
  HAL_TSC_STATE_ERROR  = 0x03U  /*!< Acquisition is completed with max count error */
} HAL_TSC_StateTypeDef;

/**
  * @brief TSC group status structure definition
  */
typedef enum
{
  TSC_GROUP_ONGOING   = 0x00U, /*!< Acquisition on group is on-going or not started */
  TSC_GROUP_COMPLETED = 0x01U  /*!< Acquisition on group is completed with success (no max count error) */
} TSC_GroupStatusTypeDef;

/**
  * @brief TSC init structure definition
  */
typedef struct
{
  uint32_t CTPulseHighLength;       /*!< Charge-transfer high pulse length
                                         This parameter can be a value of @ref TSC_CTPulseHL_Config  */
  uint32_t CTPulseLowLength;        /*!< Charge-transfer low pulse length
                                         This parameter can be a value of @ref TSC_CTPulseLL_Config  */
  uint32_t SpreadSpectrum;          /*!< Spread spectrum activation
                                         This parameter can be a value of @ref TSC_CTPulseLL_Config  */
  uint32_t SpreadSpectrumDeviation; /*!< Spread spectrum deviation
                                         This parameter must be a number between Min_Data = 0 and Max_Data = 127 */
  uint32_t SpreadSpectrumPrescaler; /*!< Spread spectrum prescaler
                                         This parameter can be a value of @ref TSC_SpreadSpec_Prescaler */
  uint32_t PulseGeneratorPrescaler; /*!< Pulse generator prescaler
                                         This parameter can be a value of @ref TSC_PulseGenerator_Prescaler */
  uint32_t MaxCountValue;           /*!< Max count value
                                         This parameter can be a value of @ref TSC_MaxCount_Value  */
  uint32_t IODefaultMode;           /*!< IO default mode
                                         This parameter can be a value of @ref TSC_IO_Default_Mode  */
  uint32_t SynchroPinPolarity;      /*!< Synchro pin polarity
                                         This parameter can be a value of @ref TSC_Synchro_Pin_Polarity */
  uint32_t AcquisitionMode;         /*!< Acquisition mode
                                         This parameter can be a value of @ref TSC_Acquisition_Mode  */
  uint32_t MaxCountInterrupt;       /*!< Max count interrupt activation
                                         This parameter can be set to ENABLE or DISABLE. */
  uint32_t ChannelIOs;              /*!< Channel IOs mask */
  uint32_t ShieldIOs;               /*!< Shield IOs mask */
  uint32_t SamplingIOs;             /*!< Sampling IOs mask */
} TSC_InitTypeDef;

/** 
  * @brief TSC IOs configuration structure definition
  */
typedef struct
{
  uint32_t ChannelIOs;  /*!< Channel IOs mask */
  uint32_t ShieldIOs;   /*!< Shield IOs mask */
  uint32_t SamplingIOs; /*!< Sampling IOs mask */
} TSC_IOConfigTypeDef;

/**
  * @brief  TSC handle Structure definition
  */
typedef struct
{
  TSC_TypeDef               *Instance; /*!< Register base address */
  TSC_InitTypeDef           Init;      /*!< Initialization parameters */
  __IO HAL_TSC_StateTypeDef State;     /*!< Peripheral state */
  HAL_LockTypeDef           Lock;      /*!< Lock feature */
} TSC_HandleTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup TSC_Exported_Constants TSC Exported Constants
  * @{
  */

/** @defgroup TSC_CTPulseHL_Config CTPulse High Length
  * @{
  */
#define TSC_CTPH_1CYCLE         0x00000000U                                                     /*!< Charge transfer pulse high during 1 cycle (PGCLK)   */
#define TSC_CTPH_2CYCLES        TSC_CR_CTPH_0                                                   /*!< Charge transfer pulse high during 2 cycles (PGCLK)  */
#define TSC_CTPH_3CYCLES        TSC_CR_CTPH_1                                                   /*!< Charge transfer pulse high during 3 cycles (PGCLK)  */
#define TSC_CTPH_4CYCLES        (TSC_CR_CTPH_1 | TSC_CR_CTPH_0)                                 /*!< Charge transfer pulse high during 4 cycles (PGCLK)  */
#define TSC_CTPH_5CYCLES        TSC_CR_CTPH_2                                                   /*!< Charge transfer pulse high during 5 cycles (PGCLK)  */
#define TSC_CTPH_6CYCLES        (TSC_CR_CTPH_2 | TSC_CR_CTPH_0)                                 /*!< Charge transfer pulse high during 6 cycles (PGCLK)  */
#define TSC_CTPH_7CYCLES        (TSC_CR_CTPH_2 | TSC_CR_CTPH_1)                                 /*!< Charge transfer pulse high during 7 cycles (PGCLK)  */
#define TSC_CTPH_8CYCLES        (TSC_CR_CTPH_2 | TSC_CR_CTPH_1 | TSC_CR_CTPH_0)                 /*!< Charge transfer pulse high during 8 cycles (PGCLK)  */
#define TSC_CTPH_9CYCLES        TSC_CR_CTPH_3                                                   /*!< Charge transfer pulse high during 9 cycles (PGCLK)  */
#define TSC_CTPH_10CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_0)                                 /*!< Charge transfer pulse high during 10 cycles (PGCLK) */
#define TSC_CTPH_11CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_1)                                 /*!< Charge transfer pulse high during 11 cycles (PGCLK) */
#define TSC_CTPH_12CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_1 | TSC_CR_CTPH_0)                 /*!< Charge transfer pulse high during 12 cycles (PGCLK) */
#define TSC_CTPH_13CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_2)                                 /*!< Charge transfer pulse high during 13 cycles (PGCLK) */
#define TSC_CTPH_14CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_2 | TSC_CR_CTPH_0)                 /*!< Charge transfer pulse high during 14 cycles (PGCLK) */
#define TSC_CTPH_15CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_2 | TSC_CR_CTPH_1)                 /*!< Charge transfer pulse high during 15 cycles (PGCLK) */
#define TSC_CTPH_16CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_2 | TSC_CR_CTPH_1 | TSC_CR_CTPH_0) /*!< Charge transfer pulse high during 16 cycles (PGCLK) */
/**
  * @}
  */

/** @defgroup TSC_CTPulseLL_Config CTPulse Low Length
  * @{
  */
#define TSC_CTPL_1CYCLE         0x00000000U                                                      /*!< Charge transfer pulse low during 1 cycle (PGCLK)   */
#define TSC_CTPL_2CYCLES        TSC_CR_CTPL_0                                                    /*!< Charge transfer pulse low during 2 cycles (PGCLK)  */
#define TSC_CTPL_3CYCLES        TSC_CR_CTPL_1                                                    /*!< Charge transfer pulse low during 3 cycles (PGCLK)  */
#define TSC_CTPL_4CYCLES        (TSC_CR_CTPL_1 | TSC_CR_CTPL_0)                                  /*!< Charge transfer pulse low during 4 cycles (PGCLK)  */
#define TSC_CTPL_5CYCLES        TSC_CR_CTPL_2                                                    /*!< Charge transfer pulse low during 5 cycles (PGCLK)  */
#define TSC_CTPL_6CYCLES        (TSC_CR_CTPL_2 | TSC_CR_CTPL_0)                                  /*!< Charge transfer pulse low during 6 cycles (PGCLK)  */
#define TSC_CTPL_7CYCLES        (TSC_CR_CTPL_2 | TSC_CR_CTPL_1)                                  /*!< Charge transfer pulse low during 7 cycles (PGCLK)  */
#define TSC_CTPL_8CYCLES        (TSC_CR_CTPL_2 | TSC_CR_CTPL_1 | TSC_CR_CTPL_0)                  /*!< Charge transfer pulse low during 8 cycles (PGCLK)  */
#define TSC_CTPL_9CYCLES        TSC_CR_CTPL_3                                                    /*!< Charge transfer pulse low during 9 cycles (PGCLK)  */
#define TSC_CTPL_10CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_0)                                  /*!< Charge transfer pulse low during 10 cycles (PGCLK) */
#define TSC_CTPL_11CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_1)                                  /*!< Charge transfer pulse low during 11 cycles (PGCLK) */
#define TSC_CTPL_12CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_1 | TSC_CR_CTPL_0)                  /*!< Charge transfer pulse low during 12 cycles (PGCLK) */
#define TSC_CTPL_13CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_2)                                  /*!< Charge transfer pulse low during 13 cycles (PGCLK) */
#define TSC_CTPL_14CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_2 | TSC_CR_CTPL_0)                  /*!< Charge transfer pulse low during 14 cycles (PGCLK) */
#define TSC_CTPL_15CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_2 | TSC_CR_CTPL_1)                  /*!< Charge transfer pulse low during 15 cycles (PGCLK) */
#define TSC_CTPL_16CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_2 | TSC_CR_CTPL_1 | TSC_CR_CTPL_0)  /*!< Charge transfer pulse low during 16 cycles (PGCLK) */
/**
  * @}
  */

/** @defgroup TSC_SpreadSpec_Prescaler Spread Spectrum Prescaler
  * @{
  */
#define TSC_SS_PRESC_DIV1       0x00000000U   /*!< Spread Spectrum Prescaler Div1 */
#define TSC_SS_PRESC_DIV2       TSC_CR_SSPSC  /*!< Spread Spectrum Prescaler Div2 */
/**
  * @}
  */

/** @defgroup TSC_PulseGenerator_Prescaler Pulse Generator Prescaler
  * @{
  */
#define TSC_PG_PRESC_DIV1       0x00000000U                                         /*!< Pulse Generator HCLK Div1   */
#define TSC_PG_PRESC_DIV2       TSC_CR_PGPSC_0                                      /*!< Pulse Generator HCLK Div2   */
#define TSC_PG_PRESC_DIV4       TSC_CR_PGPSC_1                                      /*!< Pulse Generator HCLK Div4   */
#define TSC_PG_PRESC_DIV8       (TSC_CR_PGPSC_1 | TSC_CR_PGPSC_0)                   /*!< Pulse Generator HCLK Div8   */
#define TSC_PG_PRESC_DIV16      TSC_CR_PGPSC_2                                      /*!< Pulse Generator HCLK Div16  */
#define TSC_PG_PRESC_DIV32      (TSC_CR_PGPSC_2 | TSC_CR_PGPSC_0)                   /*!< Pulse Generator HCLK Div32  */
#define TSC_PG_PRESC_DIV64      (TSC_CR_PGPSC_2 | TSC_CR_PGPSC_1)                   /*!< Pulse Generator HCLK Div64  */
#define TSC_PG_PRESC_DIV128     (TSC_CR_PGPSC_2 | TSC_CR_PGPSC_1 | TSC_CR_PGPSC_0)  /*!< Pulse Generator HCLK Div128 */
/**
  * @}
  */

/** @defgroup TSC_MaxCount_Value Max Count Value
  * @{
  */
#define TSC_MCV_255             0x00000000U                    /*!< 255 maximum number of charge transfer pulses   */
#define TSC_MCV_511             TSC_CR_MCV_0                   /*!< 511 maximum number of charge transfer pulses   */
#define TSC_MCV_1023            TSC_CR_MCV_1                   /*!< 1023 maximum number of charge transfer pulses  */
#define TSC_MCV_2047            (TSC_CR_MCV_1 | TSC_CR_MCV_0)  /*!< 2047 maximum number of charge transfer pulses  */
#define TSC_MCV_4095            TSC_CR_MCV_2                   /*!< 4095 maximum number of charge transfer pulses  */
#define TSC_MCV_8191            (TSC_CR_MCV_2 | TSC_CR_MCV_0)  /*!< 8191 maximum number of charge transfer pulses  */
#define TSC_MCV_16383           (TSC_CR_MCV_2 | TSC_CR_MCV_1)  /*!< 16383 maximum number of charge transfer pulses */
/**
  * @}
  */

/** @defgroup TSC_IO_Default_Mode IO Default Mode
  * @{
  */
#define TSC_IODEF_OUT_PP_LOW    0x00000000U  /*!< I/Os are forced to output push-pull low */
#define TSC_IODEF_IN_FLOAT      TSC_CR_IODEF /*!< I/Os are in input floating              */
/**
  * @}
  */

/** @defgroup TSC_Synchro_Pin_Polarity Synchro Pin Polarity
  * @{
  */
#define TSC_SYNC_POLARITY_FALLING  0x00000000U    /*!< Falling edge only           */
#define TSC_SYNC_POLARITY_RISING   TSC_CR_SYNCPOL /*!< Rising edge and high level  */
/**
  * @}
  */

/** @defgroup TSC_Acquisition_Mode Acquisition Mode
  * @{
  */
#define TSC_ACQ_MODE_NORMAL     0x00000000U /*!< Normal acquisition mode (acquisition starts as soon as START bit is set)                                                              */
#define TSC_ACQ_MODE_SYNCHRO    TSC_CR_AM   /*!< Synchronized acquisition mode (acquisition starts if START bit is set and when the selected signal is detected on the SYNC input pin) */
/**
  * @}
  */

/** @defgroup TSC_interrupts_definition Interrupts definition
  * @{
  */
#define TSC_IT_EOA              TSC_IER_EOAIE /*!< End of acquisition interrupt enable */
#define TSC_IT_MCE              TSC_IER_MCEIE /*!< Max count error interrupt enable    */
/**
  * @}
  */

/** @defgroup TSC_flags_definition Flags definition
  * @{
  */
#define TSC_FLAG_EOA            TSC_ISR_EOAF /*!< End of acquisition flag */
#define TSC_FLAG_MCE            TSC_ISR_MCEF /*!< Max count error flag    */
/**
  * @}
  */

/** @defgroup TSC_Group_definition Group definition
  * @{
  */
#define TSC_GROUP1_IDX          0x0U
#define TSC_GROUP2_IDX          0x1U
#define TSC_GROUP3_IDX          0x2U
#define TSC_GROUP4_IDX          0x3U
#define TSC_GROUP5_IDX          0x4U
#define TSC_GROUP6_IDX          0x5U
#define TSC_GROUP7_IDX          0x6U
#define TSC_GROUP8_IDX          0x7U
#define TSC_NB_OF_GROUPS        0x8U

#define TSC_GROUP1              (uint32_t)(0x1U << TSC_GROUP1_IDX)
#define TSC_GROUP2              (uint32_t)(0x1U << TSC_GROUP2_IDX)
#define TSC_GROUP3              (uint32_t)(0x1U << TSC_GROUP3_IDX)
#define TSC_GROUP4              (uint32_t)(0x1U << TSC_GROUP4_IDX)
#define TSC_GROUP5              (uint32_t)(0x1U << TSC_GROUP5_IDX)
#define TSC_GROUP6              (uint32_t)(0x1U << TSC_GROUP6_IDX)
#define TSC_GROUP7              (uint32_t)(0x1U << TSC_GROUP7_IDX)
#define TSC_GROUP8              (uint32_t)(0x1U << TSC_GROUP8_IDX)

#define TSC_GROUP1_IO1          TSC_IOCCR_G1_IO1 /*!< TSC Group1 IO1 */
#define TSC_GROUP1_IO2          TSC_IOCCR_G1_IO2 /*!< TSC Group1 IO2 */
#define TSC_GROUP1_IO3          TSC_IOCCR_G1_IO3 /*!< TSC Group1 IO3 */
#define TSC_GROUP1_IO4          TSC_IOCCR_G1_IO4 /*!< TSC Group1 IO4 */

#define TSC_GROUP2_IO1          TSC_IOCCR_G2_IO1 /*!< TSC Group2 IO1 */
#define TSC_GROUP2_IO2          TSC_IOCCR_G2_IO2 /*!< TSC Group2 IO2 */
#define TSC_GROUP2_IO3          TSC_IOCCR_G2_IO3 /*!< TSC Group2 IO3 */
#define TSC_GROUP2_IO4          TSC_IOCCR_G2_IO4 /*!< TSC Group2 IO4 */

#define TSC_GROUP3_IO1          TSC_IOCCR_G3_IO1 /*!< TSC Group3 IO1 */
#define TSC_GROUP3_IO2          TSC_IOCCR_G3_IO2 /*!< TSC Group3 IO2 */
#define TSC_GROUP3_IO3          TSC_IOCCR_G3_IO3 /*!< TSC Group3 IO3 */
#define TSC_GROUP3_IO4          TSC_IOCCR_G3_IO4 /*!< TSC Group3 IO4 */

#define TSC_GROUP4_IO1          TSC_IOCCR_G4_IO1 /*!< TSC Group4 IO1 */
#define TSC_GROUP4_IO2          TSC_IOCCR_G4_IO2 /*!< TSC Group4 IO2 */
#define TSC_GROUP4_IO3          TSC_IOCCR_G4_IO3 /*!< TSC Group4 IO3 */
#define TSC_GROUP4_IO4          TSC_IOCCR_G4_IO4 /*!< TSC Group4 IO4 */

#define TSC_GROUP5_IO1          TSC_IOCCR_G5_IO1 /*!< TSC Group5 IO1 */
#define TSC_GROUP5_IO2          TSC_IOCCR_G5_IO2 /*!< TSC Group5 IO2 */
#define TSC_GROUP5_IO3          TSC_IOCCR_G5_IO3 /*!< TSC Group5 IO3 */
#define TSC_GROUP5_IO4          TSC_IOCCR_G5_IO4 /*!< TSC Group5 IO4 */

#define TSC_GROUP6_IO1          TSC_IOCCR_G6_IO1 /*!< TSC Group6 IO1 */
#define TSC_GROUP6_IO2          TSC_IOCCR_G6_IO2 /*!< TSC Group6 IO2 */
#define TSC_GROUP6_IO3          TSC_IOCCR_G6_IO3 /*!< TSC Group6 IO3 */
#define TSC_GROUP6_IO4          TSC_IOCCR_G6_IO4 /*!< TSC Group6 IO4 */

#define TSC_GROUP7_IO1          TSC_IOCCR_G7_IO1 /*!< TSC Group7 IO1 */
#define TSC_GROUP7_IO2          TSC_IOCCR_G7_IO2 /*!< TSC Group7 IO2 */
#define TSC_GROUP7_IO3          TSC_IOCCR_G7_IO3 /*!< TSC Group7 IO3 */
#define TSC_GROUP7_IO4          TSC_IOCCR_G7_IO4 /*!< TSC Group7 IO4 */

#define TSC_GROUP8_IO1          TSC_IOCCR_G8_IO1 /*!< TSC Group8 IO1 */
#define TSC_GROUP8_IO2          TSC_IOCCR_G8_IO2 /*!< TSC Group8 IO2 */
#define TSC_GROUP8_IO3          TSC_IOCCR_G8_IO3 /*!< TSC Group8 IO3 */
#define TSC_GROUP8_IO4          TSC_IOCCR_G8_IO4 /*!< TSC Group8 IO4 */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/

/** @defgroup TSC_Exported_Macros TSC Exported Macros
  * @{
  */

/** @brief Reset TSC handle state.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_TSC_STATE_RESET)

/**
  * @brief Enable the TSC peripheral.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR |= TSC_CR_TSCE)

/**
  * @brief Disable the TSC peripheral.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR &= (uint32_t)(~TSC_CR_TSCE))

/**
  * @brief Start acquisition.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_START_ACQ(__HANDLE__) ((__HANDLE__)->Instance->CR |= TSC_CR_START)

/**
  * @brief Stop acquisition.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_STOP_ACQ(__HANDLE__) ((__HANDLE__)->Instance->CR &= (uint32_t)(~TSC_CR_START))

/**
  * @brief Set IO default mode to output push-pull low.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_SET_IODEF_OUTPPLOW(__HANDLE__) ((__HANDLE__)->Instance->CR &= (uint32_t)(~TSC_CR_IODEF))

/**
  * @brief Set IO default mode to input floating.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_SET_IODEF_INFLOAT(__HANDLE__) ((__HANDLE__)->Instance->CR |= TSC_CR_IODEF)

/**
  * @brief Set synchronization polarity to falling edge.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_SET_SYNC_POL_FALL(__HANDLE__) ((__HANDLE__)->Instance->CR &= (uint32_t)(~TSC_CR_SYNCPOL))

/**
  * @brief Set synchronization polarity to rising edge and high level.
  * @param  __HANDLE__ TSC handle
  * @retval None
  */
#define __HAL_TSC_SET_SYNC_POL_RISE_HIGH(__HANDLE__) ((__HANDLE__)->Instance->CR |= TSC_CR_SYNCPOL)

/**
  * @brief Enable TSC interrupt.
  * @param  __HANDLE__ TSC handle
  * @param  __INTERRUPT__ TSC interrupt
  * @retval None
  */
#define __HAL_TSC_ENABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER |= (__INTERRUPT__))

/**
  * @brief Disable TSC interrupt.
  * @param  __HANDLE__ TSC handle
  * @param  __INTERRUPT__ TSC interrupt
  * @retval None
  */
#define __HAL_TSC_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER &= (uint32_t)(~(__INTERRUPT__)))

/** @brief Check whether the specified TSC interrupt source is enabled or not.
  * @param  __HANDLE__ TSC Handle
  * @param  __INTERRUPT__ TSC interrupt
  * @retval SET or RESET
  */
#define __HAL_TSC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->IER & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

/**
  * @brief Check whether the specified TSC flag is set or not.
  * @param  __HANDLE__ TSC handle
  * @param  __FLAG__ TSC flag
  * @retval SET or RESET
  */
#define __HAL_TSC_GET_FLAG(__HANDLE__, __FLAG__) ((((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__)) ? SET : RESET)

/**
  * @brief Clear the TSC's pending flag.
  * @param  __HANDLE__ TSC handle
  * @param  __FLAG__ TSC flag
  * @retval None
  */
#define __HAL_TSC_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

/**
  * @brief Enable schmitt trigger hysteresis on a group of IOs.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_IOY_MASK__ IOs mask
  * @retval None
  */
#define __HAL_TSC_ENABLE_HYSTERESIS(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOHCR |= (__GX_IOY_MASK__))

/**
  * @brief Disable schmitt trigger hysteresis on a group of IOs.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_IOY_MASK__ IOs mask
  * @retval None
  */
#define __HAL_TSC_DISABLE_HYSTERESIS(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOHCR &= (uint32_t)(~(__GX_IOY_MASK__)))

/**
  * @brief Open analog switch on a group of IOs.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_IOY_MASK__ IOs mask
  * @retval None
  */
#define __HAL_TSC_OPEN_ANALOG_SWITCH(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOASCR &= (uint32_t)(~(__GX_IOY_MASK__)))

/**
  * @brief Close analog switch on a group of IOs.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_IOY_MASK__ IOs mask
  * @retval None
  */
#define __HAL_TSC_CLOSE_ANALOG_SWITCH(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOASCR |= (__GX_IOY_MASK__))

/**
  * @brief Enable a group of IOs in channel mode.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_IOY_MASK__ IOs mask
  * @retval None
  */
#define __HAL_TSC_ENABLE_CHANNEL(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOCCR |= (__GX_IOY_MASK__))

/**
  * @brief Disable a group of channel IOs.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_IOY_MASK__ IOs mask
  * @retval None
  */
#define __HAL_TSC_DISABLE_CHANNEL(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOCCR &= (uint32_t)(~(__GX_IOY_MASK__)))

/**
  * @brief Enable a group of IOs in sampling mode.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_IOY_MASK__ IOs mask
  * @retval None
  */
#define __HAL_TSC_ENABLE_SAMPLING(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOSCR |= (__GX_IOY_MASK__))

/**
  * @brief Disable a group of sampling IOs.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_IOY_MASK__ IOs mask
  * @retval None
  */
#define __HAL_TSC_DISABLE_SAMPLING(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOSCR &= (uint32_t)(~(__GX_IOY_MASK__)))

/**
  * @brief Enable acquisition groups.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_MASK__ Groups mask
  * @retval None
  */
#define __HAL_TSC_ENABLE_GROUP(__HANDLE__, __GX_MASK__) ((__HANDLE__)->Instance->IOGCSR |= (__GX_MASK__))

/**
  * @brief Disable acquisition groups.
  * @param  __HANDLE__ TSC handle
  * @param  __GX_MASK__ Groups mask
  * @retval None
  */
#define __HAL_TSC_DISABLE_GROUP(__HANDLE__, __GX_MASK__) ((__HANDLE__)->Instance->IOGCSR &= (uint32_t)(~(__GX_MASK__)))

/** @brief Gets acquisition group status.
  * @param  __HANDLE__ TSC Handle
  * @param  __GX_INDEX__ Group index
  * @retval SET or RESET
  */
#define __HAL_TSC_GET_GROUP_STATUS(__HANDLE__, __GX_INDEX__) \
((((__HANDLE__)->Instance->IOGCSR & (uint32_t)((uint32_t)1U << ((__GX_INDEX__) + (uint32_t)16U))) == (uint32_t)((uint32_t)1U << ((__GX_INDEX__) + (uint32_t)16U))) ? TSC_GROUP_COMPLETED : TSC_GROUP_ONGOING)

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/** @defgroup TSC_Private_Macros TSC Private Macros
  * @{
  */

#define IS_TSC_CTPH(__VALUE__)          (((__VALUE__) == TSC_CTPH_1CYCLE)   || \
                                         ((__VALUE__) == TSC_CTPH_2CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_3CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_4CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_5CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_6CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_7CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_8CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_9CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_10CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_11CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_12CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_13CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_14CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_15CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_16CYCLES))

#define IS_TSC_CTPL(__VALUE__)          (((__VALUE__) == TSC_CTPL_1CYCLE)   || \
                                         ((__VALUE__) == TSC_CTPL_2CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_3CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_4CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_5CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_6CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_7CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_8CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_9CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_10CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_11CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_12CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_13CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_14CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_15CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_16CYCLES))

#define IS_TSC_SS(__VALUE__)            (((__VALUE__) == DISABLE) || ((__VALUE__) == ENABLE))

#define IS_TSC_SSD(__VALUE__)           (((__VALUE__) == 0U) || (((__VALUE__) > 0U) && ((__VALUE__) < 128U)))

#define IS_TSC_SS_PRESC(__VALUE__)      (((__VALUE__) == TSC_SS_PRESC_DIV1) || ((__VALUE__) == TSC_SS_PRESC_DIV2))

#define IS_TSC_PG_PRESC(__VALUE__)      (((__VALUE__) == TSC_PG_PRESC_DIV1)  || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV2)  || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV4)  || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV8)  || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV16) || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV32) || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV64) || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV128))

#define IS_TSC_MCV(__VALUE__)           (((__VALUE__) == TSC_MCV_255)  || \
                                         ((__VALUE__) == TSC_MCV_511)  || \
                                         ((__VALUE__) == TSC_MCV_1023) || \
                                         ((__VALUE__) == TSC_MCV_2047) || \
                                         ((__VALUE__) == TSC_MCV_4095) || \
                                         ((__VALUE__) == TSC_MCV_8191) || \
                                          ((__VALUE__) == TSC_MCV_16383))

#define IS_TSC_IODEF(__VALUE__)         (((__VALUE__) == TSC_IODEF_OUT_PP_LOW) || ((__VALUE__) == TSC_IODEF_IN_FLOAT))

#define IS_TSC_SYNC_POL(__VALUE__)      (((__VALUE__) == TSC_SYNC_POLARITY_FALLING) || ((__VALUE__) == TSC_SYNC_POLARITY_RISING))

#define IS_TSC_ACQ_MODE(__VALUE__)      (((__VALUE__) == TSC_ACQ_MODE_NORMAL) || ((__VALUE__) == TSC_ACQ_MODE_SYNCHRO))

#define IS_TSC_MCE_IT(__VALUE__)        (((__VALUE__) == DISABLE) || ((__VALUE__) == ENABLE))

#define IS_TSC_GROUP_INDEX(__VALUE__)   (((__VALUE__) == 0U) || (((__VALUE__) > 0U) && ((__VALUE__) < TSC_NB_OF_GROUPS)))

#define IS_TSC_GROUP(__VALUE__)         ((((__VALUE__) & TSC_GROUP1_IO1) == TSC_GROUP1_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP1_IO2) == TSC_GROUP1_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP1_IO3) == TSC_GROUP1_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP1_IO4) == TSC_GROUP1_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP2_IO1) == TSC_GROUP2_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP2_IO2) == TSC_GROUP2_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP2_IO3) == TSC_GROUP2_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP2_IO4) == TSC_GROUP2_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP3_IO1) == TSC_GROUP3_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP3_IO2) == TSC_GROUP3_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP3_IO3) == TSC_GROUP3_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP3_IO4) == TSC_GROUP3_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP4_IO1) == TSC_GROUP4_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP4_IO2) == TSC_GROUP4_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP4_IO3) == TSC_GROUP4_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP4_IO4) == TSC_GROUP4_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP5_IO1) == TSC_GROUP5_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP5_IO2) == TSC_GROUP5_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP5_IO3) == TSC_GROUP5_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP5_IO4) == TSC_GROUP5_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP6_IO1) == TSC_GROUP6_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP6_IO2) == TSC_GROUP6_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP6_IO3) == TSC_GROUP6_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP6_IO4) == TSC_GROUP6_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP7_IO1) == TSC_GROUP7_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP7_IO2) == TSC_GROUP7_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP7_IO3) == TSC_GROUP7_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP7_IO4) == TSC_GROUP7_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP8_IO1) == TSC_GROUP8_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP8_IO2) == TSC_GROUP8_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP8_IO3) == TSC_GROUP8_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP8_IO4) == TSC_GROUP8_IO4))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup TSC_Exported_Functions
  * @{
  */

/** @addtogroup TSC_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
/* Initialization and de-initialization functions *****************************/
HAL_StatusTypeDef HAL_TSC_Init(TSC_HandleTypeDef* htsc);
HAL_StatusTypeDef HAL_TSC_DeInit(TSC_HandleTypeDef *htsc);
void HAL_TSC_MspInit(TSC_HandleTypeDef* htsc);
void HAL_TSC_MspDeInit(TSC_HandleTypeDef* htsc);
/**
  * @}
  */

/** @addtogroup TSC_Exported_Functions_Group2 Input and Output operation functions
  * @{
  */
/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_TSC_Start(TSC_HandleTypeDef* htsc);
HAL_StatusTypeDef HAL_TSC_Start_IT(TSC_HandleTypeDef* htsc);
HAL_StatusTypeDef HAL_TSC_Stop(TSC_HandleTypeDef* htsc);
HAL_StatusTypeDef HAL_TSC_Stop_IT(TSC_HandleTypeDef* htsc);
HAL_StatusTypeDef HAL_TSC_PollForAcquisition(TSC_HandleTypeDef* htsc);
TSC_GroupStatusTypeDef HAL_TSC_GroupGetStatus(TSC_HandleTypeDef* htsc, uint32_t gx_index);
uint32_t HAL_TSC_GroupGetValue(TSC_HandleTypeDef* htsc, uint32_t gx_index);
/**
  * @}
  */

/** @addtogroup TSC_Exported_Functions_Group3 Peripheral Control functions
  * @{
  */
/* Peripheral Control functions ***********************************************/
HAL_StatusTypeDef HAL_TSC_IOConfig(TSC_HandleTypeDef* htsc, TSC_IOConfigTypeDef* config);
HAL_StatusTypeDef HAL_TSC_IODischarge(TSC_HandleTypeDef* htsc, uint32_t choice);
/**
  * @}
  */

/** @addtogroup TSC_Exported_Functions_Group4 Peripheral State and Errors functions
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_TSC_StateTypeDef HAL_TSC_GetState(TSC_HandleTypeDef* htsc);
/**
  * @}
  */

/** @addtogroup TSC_IRQ_Handler_and_Callbacks IRQ Handler and Callbacks
 * @{
 */
/******* TSC IRQHandler and Callbacks used in Interrupt mode */
void HAL_TSC_IRQHandler(TSC_HandleTypeDef* htsc);
void HAL_TSC_ConvCpltCallback(TSC_HandleTypeDef* htsc);
void HAL_TSC_ErrorCallback(TSC_HandleTypeDef* htsc);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#endif /* TSC */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L0xx_HAL_TSC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
