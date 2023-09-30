#include <BluetoothSerial.h>

extern BluetoothSerial bt_serial;

void debug_write(String s){
    bt_serial.println(s);
}

void debug_write_roll_pitch(float roll, float pitch){
    String roll_s = String(roll, 3);
    String pitch_s = String(pitch, 3);
    String s = String(roll_s +  ", "  + pitch_s);
    bt_serial.println(s);
}
