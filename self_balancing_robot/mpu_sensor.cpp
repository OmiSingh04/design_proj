#include <Adafruit_MPU6050.h>


//this is how we will interact with the MPU6050 module
Adafruit_MPU6050 mpu;

//this struct will store information about 
sensors_event_t acc;
sensors_event_t gyro, temp;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  while(!mpu.begin()){
    Serial.println("MPU6050 not connected");
    delay(1000);
  }
  Serial.println("MPU6050 ready!");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
    mpu.getEvent(&acc, &gyro, &temp);

    Serial.print("Gyro - X ");
    Serial.print(gyro.gyro.x);
    Serial.print(" Y ");
    Serial.print(gyro.gyro.y);
    Serial.print(" Z ");
    Serial.println(gyro.gyro.z);

    delay(2000);
  

}


/*

  PIN A5 - connected to SCL (Serial Clock)
  PIN A4 - connected to SDA (Serial Data)

*/
