#include "debug.h"
#include <BluetoothSerial.h>
#include "pid.h"
#include "motors.h"
#include "gyro.h"


char* device_name = "ESP-32-Stabletron";
char* pin = "1234";

BluetoothSerial bt_serial;
double kp, ki, kd;


void setup_bt(){
    bt_serial.begin(device_name);
    bt_serial.setPin(pin);
}

void setup(){
    Serial.begin(9600);
    setup_bt();

    const char* pin = "1234";//still dont know how this shit is gonna be used.
    const char* device_name = "ESP-32-Stabletron";  

    //wait for the bluetooth connection
    while(!bt_serial.connected()){
        Serial.println("Waiting for bluetooth...");
        delay(1000);
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

    //update the globals - kp, ki and kd
    get_tuning_values();//if in debug mode, get values from application

    set_param(kp, ki, kd);
    setup_motors();
    debug_write("Ready to Departure!");
}

void loop(){
    //read sensor values
    double pitch;
    update(&pitch);

    double control = generate_control(pitch);//based on which way the chip is placed, we will either need pitch or roll
    //the output could be motor speed. + and negative for direction. so i need to translate the output of pid to 
    //i hope i can find the linear relation pretty well.
    //actuate control

    Serial.print(pitch);
    Serial.print(",");
    Serial.print(control);
    Serial.println();
    //more the control, more the frequency, more the rpm.
    //+ control - one direction, - control, other direction
    (control > 0) ? set_direction(HIGH, LOW) : set_direction(LOW, HIGH);
    (control > 0) ? : control = -control;

    step(1, control);//1 step gives 1.8 degree per iteration. how fast or how slow, idk. But im guessing i need multiple steps for it to matter
    //and when the control is being actuated, the delays would effect it wouldnt it?
    //delays can potentially cause poor response
}