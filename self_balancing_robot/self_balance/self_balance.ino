#include "debug.h"
#include <BluetoothSerial.h>
#include "pid.h"
#include "motors.h"
#include "gyro.h"
const char* pin = "1234";//still dont know how this shit is gonna be used.
const char* device_name = "ESP-32-Stabletron";

BluetoothSerial bt_serial;

float roll, pitch;

void setup_bt(){
    bt_serial.begin(device_name);
    bt_serial.setPin(pin);
}

void setup(){
    Serial.begin(19200);
    setup_bt();

    //wait for the bluetooth connection
    while(!bt_serial.connected())
        delay(1000);

    debug_write("Bluetooth Connected!!!!");
    //from this point, all debug info can be directly written through bluetooth.
    //any info received through bt_serial is solely commands for the robot.

    if(!init_mpu()){//dont run.
        while(1) delay(1000);
    }

    set_param(0.5, 100, 2);//idk have to change...

    setup_motors();

    debug_write("Ready to Departure!");

}

void loop(){

    //read sensor values
    update(&roll, &pitch);
    debug_write_roll_pitch(roll, pitch);

    //generate control
    float control = generate_control(pitch);//based on which way the chip is placed, we will either need pitch or roll

    //the output could be motor speed. + and negative for direction. so i need to translate the output of pid to 
    float scale_control = 0.5;
    //i hope i can find the linear relation pretty well.
    //actuate control

    //more the control, more the frequency, more the rpm.
    //+ control - one direction, - control, other direction

    (control > 0) ? set_direction(HIGH, LOW) : set_direction(LOW, HIGH);    

    step(1, scale_control * control);
    //delays can potentially cause poor response
}