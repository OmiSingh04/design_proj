#include <Arduino.h>
#include <BluetoothSerial.h>
#include <LittleFS.h>

extern double kp, ki, kd;
extern int scale_control;
extern int step;
extern BluetoothSerial bt_serial;

void debug_write(String s){
    bt_serial.println(s);
}

void get_tuning_values(){

    #if DEBUG_MODE
    //the first 8 * 3 bytes read will be the pid values
    while(!bt.available())
      delay(1000);
    bt.readBytes((uint8_t*) &kp, sizeof(double));
    bt.readBytes((uint8_t*) &ki, sizeof(double));
    bt.readBytes((uint8_t*) &kd, sizeof(double));
    bt.readBytes((uint8_t*) &step, sizeof(int));
    bt.readBytes((uint8_t*) &scale_control, sizeof(int));

    #else
    //get it from the file storage.



    #endif

}