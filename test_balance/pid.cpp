#include "pid.h"
#include "debug.h"
#include <PID_v1.h>


static double kp = 0, kd = 0, ki = 0;
static double setpoint = 0;
static double input = 0, output = 0;

static PID pid(&input, &output, &setpoint, kp, ki, kd, P_ON_M, DIRECT);

void set_param(double kp_, double ki_, double kd_){
    pid.SetTunings(kp_, ki_, kd_);
    pid.SetMode(AUTOMATIC);
    pid.SetOutputLimits(-20, +20);
}


double generate_control(double angle){ //We now input the pitch angle.
    input = angle;
    pid.Compute();
    return output;
}