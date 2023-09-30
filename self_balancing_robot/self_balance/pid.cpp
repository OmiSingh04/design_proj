#include "pid.h"

static float kp = 0, kd = 0, ki = 0;
static float setpoint = 0, integral = 0, derivative = 0, proportional = 0;
static float prev_error = 0;

void set_param(int kp_, int ki_, int kd_){
    kp = kp_;//generates a spring-like motion of error around the setpoint
    ki = ki_;//takes cares of... like offsets around the setpoint? 
    kd = kd_;//dampens the spring effect so the angle eventually reaches setpoint.
}


float generate_control(float angle){ //We now input the pitch angle.
    float offset = angle - setpoint;

    proportional = kp * offset; //error scaled directly with kp
    integral += ki * offset;//integral keeps summing up with the error scaled by ki
    derivative = kd * (offset - prev_error);//immediate. i guess since dt is small, we choose a high value of kd

    float control = proportional + integral + derivative;

    prev_error = offset;

    return control;

    //convert control to motor speed.
    //for this i need to work with variable motor speeds.

    //pwm.
}