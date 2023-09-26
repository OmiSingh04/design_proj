#include "pid.h"

static float kp = 0f, kd = 0f, ki = 0f;
static float setpoint = 0, integral = 0, derivative = 0, proportional = 0;
static float prev_error = 0;

void set_param(int kp_, int ki_, int kd_){
    kp = kp_;
    ki = ki_;
    kd = kd_;
}

float update(float gyro_x){//no way just this much will actually work.
    float offset = gyro_x - setpoint;

    proportional = kp * offset; //error scaled directly with kp
    integral += ki * offset;//integral keeps summing up with the error scaled by ki
    derivative = kd * (offset - prev_error);//immediate. i guess since dt is small, we choose a high value of kd

    float control = proportional + integral + derivative;

    prev_error = offset;

    return control;//how do i convert this to motor speed?
}