#include "debug.h"

#include <BluetoothSerial.h>

const char* pin = "1234";
const char* device_name = "ESP-32-Stabletron";

BluetoothSerial bt_serial;

void setup_bt(){
    bt_serial.begin(device_name);
    bt_serial.setPin(pin);
}

void setup(){
    Serial.begin(19200);
    setup_bt();
    while(!bt_serial.connected()){
        delay(1000);
    }
    debug_write("Bluetooth Connected!!!!");
    //from this point, all debug info can be directly written through bluetooth.
    //any info received through bt_serial is solely commands for the robot.

}

void loop(){
    
}