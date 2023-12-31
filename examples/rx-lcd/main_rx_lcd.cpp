/**
 * @file main_rx_lcd.cpp
 * @author Scott CJX (scottcjx.w@gmail.com)
 * @brief Tested Working
 * @version 1.0.0
 * @date 07-11-2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include "board_dfs.h"
#include "NVF_CanBus.h"

MCP_CAN NVFCanI0(BoardDef::CAN_CSN);
NVF_CanBus NVFCan0(&NVFCanI0, 0x01);

LiquidCrystal_I2C lcd(0x27, 16, 2);
can_frame rx_buf;

void setup()
{
  Serial.begin(115200);
  NVFCan0.setup();

  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("NVF 2");
  delay(500);
  lcd.clear();
}

void loop()
{
  if (NVFCan0.taskLoopRecv(&rx_buf))
  {
    Serial.print(rx_buf.can_id, HEX);
    Serial.print(": ");
    Serial.print(rx_buf.can_dlc);
    Serial.print("->");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(rx_buf.can_id, HEX);
    lcd.print(": ");
    lcd.print(rx_buf.can_dlc);
    lcd.print("->");

    for (int i = 0; i < rx_buf.can_dlc; i++)
    {
      Serial.print(rx_buf.data[i], HEX);
      Serial.print(" ");
      lcd.print(rx_buf.data[i], HEX);
      lcd.print(" ");
    }
    Serial.println();
    lcd.print("&");
  }
}
