#ifndef MOTORS_H_
#define MOTORS_H_

//must change the pins!!!
#define RIGHT_MOTOR_STEP_PIN 14
#define RIGHT_MOTOR_DIRECTION_PIN 27

#define LEFT_MOTOR_STEP_PIN 13
#define LEFT_MOTOR_DIRECTION_PIN 12

void setup_motors();
void set_direction(int, int);
void step(int, double);

//at what rate is my control being generated?
#endif