#include "main.h"

#include "PID.h"
#include "ControlTask.h"
#include "RemoteTask.h"
/**
  * @brief  set chassis motor speed
  * @param  speed1 refers to left  front motor speed
  * @param  speed2 refers to right front motor speed
  * @param  speed3 refers to right back  motor speed
  * @param  speed4 refers to left  back  motor speed
	* @author HCl
  * @retval none
  */

void SetMotorSpeed(int speed1, int speed2, int speed3, int speed4)
{
	CM1SpeedPID.ref = speed1;
	CM2SpeedPID.ref = -speed2;
	CM3SpeedPID.ref = -speed3;
	CM4SpeedPID.ref = speed4;
}

/*
  获取电机转速方法
  Get_CM_SpeedFdb(uint8_t MotorNum);
  MotorNum为电机编号，同SetMotorSpeed的编号
	返回值为16位整形
*/

/*
  设置电机转速方法
  Set_CM_Current(uint8_t MotorNum, int16_t current);
  MotorNum为电机编号，同SetMotorSpeed的编号
  current为需要设置的电流值
  无返回值
*/

/*
	遥控器数据使用方法
	RC_CtrlData.rc.RightX				右摇杆X方向，值从364到1684变化，静止值为1024
	RC_CtrlData.rc.RightY       同RightX
	RC_CtrlData.rc.LeftX        同RightX
	RC_CtrlData.rc.LeftY        同RightX
	RC_CtrlData.rc.LeftSwitch   值为1、2、3
	RC_CtrlData.rc.RightSwitch  值为1、2、3
*/

void setup()
{
	// put your setup code here, to run once:
	
}

void loop()
{
	// put your main code here, to run repeatedly:
	
}

//4ms运行一次
void control(void)
{
	
}
