#include <BluetoothSerial.h>

extern BluetoothSerial bt_serial;

void debug_write(String s){
    bt_serial.println(s);
}

void debug_write_gyro_values(float x, float y, float z){
    String sx = String(x, 3);
    String sy = String(y, 3);
    String sz = String(z, 3);
    String s = String(sx +  ", "  + sy + ", " + sz);
    bt_serial.println(s);
}