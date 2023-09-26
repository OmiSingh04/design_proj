#ifndef _PID_H_
#define _PID_H_
void set_param(int kp, int ki, int kd);//tuning parameters.
void update(float gyro_x);//the current value
#endif