#include "debug.h"
#include <BluetoothSerial.h>
#include "pid.h"
#include "gyro.h"
const char* pin = "1234";//still dont know how this shit is gonna be used.
const char* device_name = "ESP-32-Stabletron";

BluetoothSerial bt_serial;

double pitch;

void setup_bt(){
    bt_serial.begin(device_name);
    bt_serial.setPin(pin);
}

void setup(){
    Serial.begin(9600);
    setup_bt();

    //wait for the bluetooth connection
    while(!bt_serial.connected()){
        delay(1000);
        Serial.println("Connecting...");
    }

    debug_write("Init:Bluetooth Connected!!!!");
    //from this point, all debug info can be directly written through bluetooth.
    //any info received through bt_serial is solely commands for the robot.

    if(!init_mpu()){//dont run.
        debug_write("Error:MPU6050 not found!");
        while(1) delay(1000);
    }

    //accept parameters from the application.
    //4 values - ki, kp, kd, and scale_control

    

    set_param(1, 0, 0.5);//idk have to change...

    debug_write("Ready to Departure!");

}

void loop(){

    //read sensor values
    update(&pitch);
    //generate control
    double control = generate_control(pitch);//based on which way the chip is placed, we will either need pitch or roll
    debug_write("pitch:" + String(pitch) + ",control:" + String(control));

    Serial.print(pitch);
    Serial.print(",");
    Serial.print(control);
    Serial.println();

    delay(100);
    
}