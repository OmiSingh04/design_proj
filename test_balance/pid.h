#ifndef _PID_H_
#define _PID_H_
void set_param(double kp, double ki, double kd);//tuning parameters.
double generate_control(double angle);//the angle parameter 
#endif