#include <Arduino.h>
#include "debug.h"
#include "motors.h"

void setup_motors(){
  pinMode(RIGHT_MOTOR_DIRECTION_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_STEP_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_STEP_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_DIRECTION_PIN, OUTPUT);
  debug_write("Motors are Setup");
}

//since the bot is forever balancing, i wonder if I need the sleep pins. even when rotating the bot, cant just lock 1 wheel.
//Both need to move, one with move rpm and in other direction. I think sleep is just not necessary now.

//there are just too many variables.

//i cant just define a set rpm. I need adjustable motor speed for pid control

//what functions will i need... for stage 1.

//I only need to balance the bot.
//meaning step the motor with a pulse with variable frequency.

//x is 
//1/2x seconds HIGH, 1/2x seconds LOW


void set_direction(int left, int right){
    digitalWrite(RIGHT_MOTOR_DIRECTION_PIN, right);
    digitalWrite(LEFT_MOTOR_DIRECTION_PIN, left);
    debug_write("Set Direction");
}

void step(int count, double frequency){
  if(frequency == 0) return;
  //frequency is a value between -20 and 20
  double pulse_width = 1000.0 / (2 * frequency);

  if(pulse_width > 200)
    return;
  
    for(int i = 0; i < count; i++){
        digitalWrite(LEFT_MOTOR_STEP_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_STEP_PIN, HIGH);
        delay(pulse_width);

        digitalWrite(RIGHT_MOTOR_STEP_PIN, LOW);
        digitalWrite(LEFT_MOTOR_STEP_PIN, LOW);
        delay(pulse_width);
    }
}

//i could probably write a test for whether motors are working or not.