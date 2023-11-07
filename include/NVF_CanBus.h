/**
 * @file NVF_CanBus.h
 * @author Scott CJX (scottcjx.w@gmail.com)
 * @brief Tested Working
 * @version 1.0.0
 * @date 07-11-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NVF_CANBUS_H_
#define NVF_CANBUS_H_

#include <stdint.h>
#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

struct can_frame
{
  uint32_t can_id = 0xFF;
  uint8_t can_dlc;
  uint8_t data[8];
};

class NVF_CanBus
{
private:
  uint32_t thisCanID;
  MCP_CAN *CAN;

public:
  NVF_CanBus(MCP_CAN *CAN, ul canId);
  bool setup();
  bool tx(can_frame *);
  bool taskLoopRecv(can_frame *);
};

#endif /* !NVF_CANBUS_H_ */