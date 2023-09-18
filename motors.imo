#define RIGHT_MOTOR_STEP_PIN 21
#define RIGHT_MOTOR_DIRECTION_PIN 15

#define LEFT_MOTOR_STEP_PIN 19
#define LEFT_MOTOR_DIRECTION_PIN 18

#define RIGHT_SLEEP_PIN 33
#define LEFT_SLEEP_PIN 32

#define RPM 60

unsigned long stepper_pulse_interval =  (long) 150 / RPM; // i made this formula uwu.



//for any rpm, find a way to get the pulse characteristics
void sleep_motors(bool val_left, bool val_right){
  digitalWrite(LEFT_SLEEP_PIN, (val_left) ? LOW : HIGH);
  digitalWrite(RIGHT_SLEEP_PIN, (val_right) ? LOW : HIGH);
}


void step(int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(RIGHT_MOTOR_STEP_PIN, HIGH);
    delay(stepper_pulse_interval);
    digitalWrite(RIGHT_MOTOR_STEP_PIN, LOW);
    delay(stepper_pulse_interval);

    digitalWrite(LEFT_MOTOR_STEP_PIN, HIGH);
    delay(stepper_pulse_interval);
    digitalWrite(LEFT_MOTOR_STEP_PIN, LOW);
    delay(stepper_pulse_interval);
  }
}

void rotate_right() {
  //to turn the robot +90 degrees.
  //The logic is simple (for now) just lock one wheel. Move the other.
  //based on wheel diameter, i have to decide the number of steps to rotate it, while making one of these sleep.

  sleep_motors(false, true);
  step(100);
  sleep_motors(false, false);

}

void rotate_left() {
  //to turn the robot -90 degrees.
  //The logic is opposite of rotate_90_negative. Lock and move the opposite wheels.

  sleep_motors(true, false);
  step(100);
  sleep_motors(false, false);


}

void set_direction_forward(){
  digitalWrite(LEFT_MOTOR_DIRECTION_PIN, HIGH);
  digitalWrite(RIGHT_MOTOR_DIRECTION_PIN, LOW);
}

void setup() {
  Serial.begin(11520);
  //2 Stepper MOTORS, CONTROLLED VIA 4 PINS OF THE MICROCONTROLLER.

  pinMode(LEFT_SLEEP_PIN, OUTPUT);
  pinMode(RIGHT_SLEEP_PIN, OUTPUT);
  

  pinMode(RIGHT_MOTOR_DIRECTION_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_STEP_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_DIRECTION_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_STEP_PIN, OUTPUT);

  Serial.println("Setup");

  sleep_motors(false, false);

  
  //moving forward
  /*
  set_direction_forward();
  for(int i = 0; i < 2; i++){
    step(200);
  }
  */
  

  //rotate_right();
  //half rotations
  //move the robot left
  rotate_left();

}


void loop() {


}
