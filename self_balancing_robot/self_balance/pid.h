#ifndef _PID_H_
#define _PID_H_
void set_param(int kp, int ki, int kd);//tuning parameters.
float generate_control(float angle);//the angle parameter 
#endif