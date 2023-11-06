/**
 * @file board_dfs.h
 * @author Scott CJX (scottcjx.w@gmail.com)
 * @brief 
 * @version 0.1
 * @date 16-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdint.h>
#include <Arduino.h>

namespace BoardDef
{
    #if !defined(BOARD_UNO) && !defined(BOARD_BLUEPILL) && !defined(BOARD_PICO)
        const uint16_t CAN_CSN      = 1;
        const uint16_t CAN_CSN2     = 1;
        const uint16_t ANALOG_PIN   = 1;
    #endif

    #ifdef BOARD_UNO
    // Tested Working
    const uint16_t CAN_CSN      = 10;
    const uint16_t CAN_CSN2     = 9;
    const uint16_t ANALOG_PIN   = 0;
    #endif
    
    #ifdef BOARD_BLUEPILL
    // Tested Working
    //                          (arduino::MbedSPI) {miso, mosi, sck}
    #define SPI                 (arduino::MbedSPI) {PA7, PA6, PA5}
    const uint16_t CAN_CSN      = PA4;
    const uint16_t CAN_CSN2     = PA3;
    const uint16_t ANALOG_PIN   = PA0;
    #endif

    #ifdef BOARD_PICO
    // WIP
    //                          (arduino::MbedSPI) {rx, tx, sck}
    #define SPI                 (arduino::MbedSPI) {3, 4, 2}
    const uint16_t CAN_CSN      = 5;
    const uint16_t CAN_CSN2     = 6;
    const uint16_t ANALOG_PIN   = 0;
    #define Serial              SerialUSB
    #endif
};

