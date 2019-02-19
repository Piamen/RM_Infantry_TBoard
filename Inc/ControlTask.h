#ifndef __CONTROLTASK_H__
#define __CONTROLTASK_H__

#include "main.h"
#include "stm32f4xx_hal.h"
#include "can.h"
#include "tim.h"
#include "gpio.h"
#include "PID.h"


int16_t Get_CM_SpeedFdb(uint8_t MotorNum);
void Set_CM_Current(uint8_t MotorNum, int16_t current);
void Set_CM_Speed(CAN_HandleTypeDef *hcan, int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq);

extern uint32_t time_tick_1ms;
#endif
