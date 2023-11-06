/**
 * @file main_tx.cpp
 * @author SCOTT CJX
 * @brief Tested Working 
 * @version 1.0.0
 * @date 07-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <Arduino.h>
#include <stdint.h>

#include "board_dfs.h"
#include "NVF_CanBus.h"

#define DELAY_MS            250

MCP_CAN NVFCanI0(BoardDef::CAN_CSN);
NVF_CanBus NVFCan0(&NVFCanI0, 0x0F);
can_frame tx_buf;

uint8_t counter_buf = 0;

void setup()
{
  Serial.begin(115200);
  NVFCan0.setup();
}

void loop()
{
  if (counter_buf == -2) counter_buf = 0;

  tx_buf.data[0] = 0x00 + counter_buf;
  tx_buf.data[1] = 0xFF - counter_buf;

  tx_buf.can_dlc = 2;
  NVFCan0.tx(&tx_buf);
  delay(DELAY_MS);   // send data per 100ms
}