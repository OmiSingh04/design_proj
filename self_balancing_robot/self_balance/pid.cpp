#include "pid.h"
#include "debug.h"
#include <PID_v1.h>

extern double kp, ki, kd;//the only reason this line is here is to initialize pid object
static double setpoint = 0;
static double input = 0, output = 0;

static PID pid(&input, &output, &setpoint, kp, ki, kd, DIRECT);

void set_param(double kp_, double ki_, double kd_){
    pid.SetTunings(kp_, ki_, kd_);
    pid.SetOutputLimits(-90, +90);
    pid.SetMode(AUTOMATIC);
}

double generate_control(double angle){ //We now input the pitch angle.
    input = angle;
    pid.Compute();
    return output;
}