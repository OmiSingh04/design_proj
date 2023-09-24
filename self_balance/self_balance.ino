#include "debug.h"
#include <BluetoothSerial.h>
#include "gyro.h"
const char* pin = "1234";
const char* device_name = "ESP-32-Stabletron";

BluetoothSerial bt_serial;

float gyroX, gyroY, gyroZ;

void setup_bt(){
    bt_serial.begin(device_name);
    bt_serial.setPin(pin);
}

void setup(){
    Serial.begin(19200);
    setup_bt();

    while(!bt_serial.connected())
        delay(1000);

    debug_write("Bluetooth Connected!!!!");
    //from this point, all debug info can be directly written through bluetooth.
    //any info received through bt_serial is solely commands for the robot.

    if(!init_mpu()){//dont run.
        while(1) delay(1000);
    }


}

void loop(){
    update(&gyroX, &gyroY, &gyroZ);
    debug_write_gyro_values(gyroX, gyroY, gyroZ);

}