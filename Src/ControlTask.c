#include "ControlTask.h"

ChassisSpeed_Ref_t ChassisSpeedRef;
uint32_t time_tick_1ms = 0;//1ms定时计数，系统会在指定的毫秒时刻进行不同的控制
int16_t CM_Current[5];
extern int16_t spd1, spd2, spd3, spd4;

void Control_Task(void)
{
	time_tick_1ms++;//每进一次中断就计数一次
	if(time_tick_1ms%4 == 0)         //每4ms对底盘进行一次控制	
	{
		control();
		Set_CM_Speed(&hcan2, CM_Current[1],  CM_Current[2], CM_Current[3],  CM_Current[4]);
	}
	
}

int16_t Get_CM_SpeedFdb(uint8_t MotorNum)
{
	switch(MotorNum)
	{
		case 1:
			return spd1;
			break;
		case 2:
			return spd2;
			break;
		case 3:
			return spd3;
			break;
		case 4:
			return spd4;
			break;
	}
}


void Set_CM_Current(uint8_t MotorNum, int16_t current)
{
	CM_Current[MotorNum] = current;
}


void Set_CM_Speed(CAN_HandleTypeDef *hcan, int16_t cm1_iq, int16_t cm2_iq, int16_t cm3_iq, int16_t cm4_iq)
{
	uint8_t Data[8];
	uint32_t flag;
	CAN_TxHeaderTypeDef Header;

	Header.StdId = 0x200;
	Header.RTR = CAN_RTR_DATA;
	Header.IDE = CAN_ID_STD;
	Header.DLC = 8;
	Data[0] = (uint8_t)(cm1_iq >> 8);
	Data[1] = (uint8_t)cm1_iq;
	Data[2] = (uint8_t)(cm2_iq >> 8);
	Data[3] = (uint8_t)cm2_iq;
	Data[4] = (uint8_t)(cm3_iq >> 8);
	Data[5] = (uint8_t)cm3_iq;
	Data[6] = (uint8_t)(cm4_iq >> 8);
	Data[7] = (uint8_t)cm4_iq;
	HAL_CAN_AddTxMessage(&hcan2, &Header, Data, &flag);
}
