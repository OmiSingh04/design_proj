#include <Arduino.h>
#include <BluetoothSerial.h>
extern BluetoothSerial bt_serial;

void debug_write(String s){
    bt_serial.println(s);
}