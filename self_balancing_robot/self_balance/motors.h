#ifndef MOTORS_H_
#define MOTORS_H_

//must change the pins!!!
#define RIGHT_MOTOR_STEP_PIN 21
#define RIGHT_MOTOR_DIRECTION_PIN 15

#define LEFT_MOTOR_STEP_PIN 19
#define LEFT_MOTOR_DIRECTION_PIN 18

void setup_motors();
void set_direction(int, int);
void step(int, double);

//at what rate is my control being generated?
#endif