/*
    __bargraph3_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __bargraph3_driver.h
@brief    BarGraph3 Driver
@mainpage BarGraph3 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   BARGRAPH3
@brief      BarGraph3 Click Driver
@{

| Global Library Prefix | **BARGRAPH3** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **okt 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _BARGRAPH3_H_
#define _BARGRAPH3_H_

/** 
 * @macro T_BARGRAPH3_P
 * @brief Driver Abstract type 
 */
#define T_BARGRAPH3_P    const uint8_t*

/** @defgroup BARGRAPH3_COMPILE Compilation Config */              /** @{ */

   #define   __BARGRAPH3_DRV_SPI__                            /**<     @macro __BARGRAPH3_DRV_SPI__  @brief SPI driver selector */
//  #define   __BARGRAPH3_DRV_I2C__                            /**<     @macro __BARGRAPH3_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __BARGRAPH3_DRV_UART__                           /**<     @macro __BARGRAPH3_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup BARGRAPH3_VAR Variables */                           /** @{ */

extern const uint8_t _BARGRAPH3_INCREASE_LED;
extern const uint8_t _BARGRAPH3_CONTROL_ONE_LED;

extern const uint8_t _BARGRAPH3_DIRECTION_TOP_TO_BOTTOM;
extern const uint8_t _BARGRAPH3_DIRECTION_BOTTOM_TO_TOP;

extern const uint8_t _BARGRAPH3_DEVICE_ENABLE;
extern const uint8_t _BARGRAPH3_DEVICE_DISABLE;

extern const uint8_t _BARGRAPH3_LED_0;
extern const uint8_t _BARGRAPH3_LED_1;
extern const uint8_t _BARGRAPH3_LED_2;
extern const uint8_t _BARGRAPH3_LED_3;
extern const uint8_t _BARGRAPH3_LED_4;
extern const uint8_t _BARGRAPH3_LED_5;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup BARGRAPH3_INIT Driver Initialization */              /** @{ */

#ifdef   __BARGRAPH3_DRV_SPI__
void bargraph3_spiDriverInit(T_BARGRAPH3_P gpioObj, T_BARGRAPH3_P spiObj);
#endif
#ifdef   __BARGRAPH3_DRV_I2C__
void bargraph3_i2cDriverInit(T_BARGRAPH3_P gpioObj, T_BARGRAPH3_P i2cObj, uint8_t slave);
#endif
#ifdef   __BARGRAPH3_DRV_UART__
void bargraph3_uartDriverInit(T_BARGRAPH3_P gpioObj, T_BARGRAPH3_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void bargraph3_gpioDriverInit(T_BARGRAPH3_P gpioObj);
                                                                       /** @} */
/** @defgroup BARGRAPH3_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for enable the chip
 */
void bargraph3_enable(uint8_t state);

/**
 * @brief Functions for reset the chip
 */
void bargraph3_reset();

/**
 * @brief Functions for set PWM
 */
void bargraph3_setPWM(uint8_t state);

/**
 * @brief Displays function
 *
 * @param[in] ctrl     Led control (INCREASE_LED or CONTROL_ONE_LED)
 * @param[in] dir      Display direction (TOP_TO_BOTTOM or BOTTOM_TO_TOP)
 * @param[in] counter  BarGraph display counter (0..5)
 */
void bargraph3_display(uint8_t ctrl, uint8_t dir, uint8_t counter);





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_BarGraph3_STM.c
    @example Click_BarGraph3_TIVA.c
    @example Click_BarGraph3_CEC.c
    @example Click_BarGraph3_KINETIS.c
    @example Click_BarGraph3_MSP.c
    @example Click_BarGraph3_PIC.c
    @example Click_BarGraph3_PIC32.c
    @example Click_BarGraph3_DSPIC.c
    @example Click_BarGraph3_AVR.c
    @example Click_BarGraph3_FT90x.c
    @example Click_BarGraph3_STM.mbas
    @example Click_BarGraph3_TIVA.mbas
    @example Click_BarGraph3_CEC.mbas
    @example Click_BarGraph3_KINETIS.mbas
    @example Click_BarGraph3_MSP.mbas
    @example Click_BarGraph3_PIC.mbas
    @example Click_BarGraph3_PIC32.mbas
    @example Click_BarGraph3_DSPIC.mbas
    @example Click_BarGraph3_AVR.mbas
    @example Click_BarGraph3_FT90x.mbas
    @example Click_BarGraph3_STM.mpas
    @example Click_BarGraph3_TIVA.mpas
    @example Click_BarGraph3_CEC.mpas
    @example Click_BarGraph3_KINETIS.mpas
    @example Click_BarGraph3_MSP.mpas
    @example Click_BarGraph3_PIC.mpas
    @example Click_BarGraph3_PIC32.mpas
    @example Click_BarGraph3_DSPIC.mpas
    @example Click_BarGraph3_AVR.mpas
    @example Click_BarGraph3_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __bargraph3_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */