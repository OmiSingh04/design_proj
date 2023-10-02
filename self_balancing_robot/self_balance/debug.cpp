#include <BluetoothSerial.h>

extern BluetoothSerial bt_serial;

void debug_write(String s){
    bt_serial.println(s);
}

void debug_write_f(float pitch){
    String pitch_s = String(pitch, 3);
    bt_serial.println(pitch_s);
}