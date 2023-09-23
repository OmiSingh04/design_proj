#include <BluetoothSerial.h>

extern BluetoothSerial bt_serial;

void debug_write(char* msg){
    for(char ch = *msg; ch != NULL; ch = *(++msg)){
        bt_serial.write(ch);
    }
}