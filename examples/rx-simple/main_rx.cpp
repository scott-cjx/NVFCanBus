/**
 * @file main_rx.cpp
 * @author Scott CJX
 * @brief Tested Working 
 * @version 1.0.0
 * @date 07-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <Arduino.h>

#include "board_dfs.h"
#include "NVF_CanBus.h"

MCP_CAN NVFCanI0(BoardDef::CAN_CSN);
NVF_CanBus NVFCan0(&NVFCanI0, 0x01);
can_frame rx_buf;

void setup()
{
  Serial.begin(115200);
  NVFCan0.setup();
}

void loop()
{
  if (NVFCan0.taskLoopRecv(&rx_buf))
  {
      Serial.print(rx_buf.can_id, HEX);
      Serial.print(": ");
      Serial.print(rx_buf.can_dlc);
      Serial.print("->");

    for (int i = 0; i < rx_buf.can_dlc; i++)
    {
      Serial.print(rx_buf.data[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}