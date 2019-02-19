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
  ��ȡ���ת�ٷ���
  Get_CM_SpeedFdb(uint8_t MotorNum);
  MotorNumΪ�����ţ�ͬSetMotorSpeed�ı��
	����ֵΪ16λ����
*/

/*
  ���õ��ת�ٷ���
  Set_CM_Current(uint8_t MotorNum, int16_t current);
  MotorNumΪ�����ţ�ͬSetMotorSpeed�ı��
  currentΪ��Ҫ���õĵ���ֵ
  �޷���ֵ
*/

/*
	ң��������ʹ�÷���
	RC_CtrlData.rc.RightX				��ҡ��X����ֵ��364��1684�仯����ֵֹΪ1024
	RC_CtrlData.rc.RightY       ͬRightX
	RC_CtrlData.rc.LeftX        ͬRightX
	RC_CtrlData.rc.LeftY        ͬRightX
	RC_CtrlData.rc.LeftSwitch   ֵΪ1��2��3
	RC_CtrlData.rc.RightSwitch  ֵΪ1��2��3
*/

void setup()
{
	// put your setup code here, to run once:
	
}

void loop()
{
	// put your main code here, to run repeatedly:
	
}

//4ms����һ��
void control(void)
{
	
}
