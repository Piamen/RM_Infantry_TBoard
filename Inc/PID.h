#ifndef __PID_H__
#define __PID_H__

typedef struct PID_Regulator_t
{
	float ref;
	float fdb;
	float err[2];//error_now  error_last error_inter
	float kp;
	float ki;
	float kd;
	float componentKp;
	float componentKi;
	float componentKd;
	float componentKpMax;
	float componentKiMax;
	float componentKdMax;
	float output;
	float outputMax;
	float kp_offset;
	float ki_offset;
	float kd_offset;
	void (*Calc)(struct PID_Regulator_t *pid);//定义了一个函数指针，没有返回值，函数名是Calc，形参的类型是 PID_Regulator_t结构体变量的指针 ，所以需要对这个指针进行赋值，表示这个指针指向那个函数 
	void (*Reset)(struct PID_Regulator_t *pid);
}PID_Regulator_t;

#define CHASSIS_MOTOR_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	8.0f,\
	0.0f,\
	0.1f,\
	0,\
	0,\
	0,\
	4900,\
	3500,\
	1500,\
	0,\
	4950,\
	0,\
	0,\
	0,\
}\


void PID_Calc(PID_Regulator_t *pid);
extern PID_Regulator_t CM1SpeedPID;
extern PID_Regulator_t CM2SpeedPID;
extern PID_Regulator_t CM3SpeedPID;
extern PID_Regulator_t CM4SpeedPID;

#endif
