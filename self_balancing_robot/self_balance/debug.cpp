#include <Arduino.h>
#include <BluetoothSerial.h>

extern double kp, ki, kd;
extern BluetoothSerial bt_serial;

void debug_write(String s){
    bt_serial.println(s);
}

void get_tuning_values(){

    //the first 8 * 3 bytes read will be the pid values
      while(!bt_serial.available())
        delay(1000);
      bt_serial.readBytes((uint8_t*) &kp, sizeof(double));
      bt_serial.readBytes((uint8_t*) &ki, sizeof(double));
      bt_serial.readBytes((uint8_t*) &kd, sizeof(double));
      Serial.println("Debug Mode");

}