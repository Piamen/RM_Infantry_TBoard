
#include "PID.h"

PID_Regulator_t CM1SpeedPID = CHASSIS_MOTOR_SPEED_PID_DEFAULT;//底盘电机1的速度PID
PID_Regulator_t CM2SpeedPID = CHASSIS_MOTOR_SPEED_PID_DEFAULT;//底盘电机2的速度PID
PID_Regulator_t CM3SpeedPID = CHASSIS_MOTOR_SPEED_PID_DEFAULT;//底盘电机3的速度PID
PID_Regulator_t CM4SpeedPID = CHASSIS_MOTOR_SPEED_PID_DEFAULT;//底盘电机4的速度PID


void PID_Calc(PID_Regulator_t *pid)
{
	static float SUM=0;
  float dError,Error;
	
	Error=pid->ref-pid->fdb;
	SUM+=Error;
	dError=pid->err[0]-pid->err[1];
	pid->err[1]=pid->err[0];
	pid->err[0]=Error;
	
	pid->output=pid->kp*Error+ pid->ki*SUM+pid->kd*dError;              //+ (0.4f)*pid->err[1] ;// +(*pid->err[1]);//+ (pid->ki)*(pid->err[0]) + (pid->kd)*(pid->err[0]);
	
	if(pid->output > 15000)
		pid->output = 15000;
	else if(pid->output < -15000)
		   pid->output = -15000;
}
