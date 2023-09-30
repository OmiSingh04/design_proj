#include <Adafruit_MPU6050.h>
#include <Wire.h>

//this is how we will interact with the MPU6050 module
Adafruit_MPU6050 mpu;

//this struct will store information about 
sensors_event_t acc;
sensors_event_t gyro, temp;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Wire.begin(5, 18);
  while(!mpu.begin()){
    Serial.println("MPU6050 not connected");
    delay(1000);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("MPU6050 ready!");
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
    mpu.getEvent(&acc, &gyro, &temp);

    float roll = atan2(acc.acceleration.y, acc.acceleration.z);
    float pitch = asin(acc.acceleration.x / 9.8);


    Serial.print("Acc - roll ");
    Serial.print(roll * 57296.0 / 1000);
    Serial.print(" pitch ");
    Serial.println(pitch * 57296.0 / 1000);

    delay(500);
  

}


/*

  PIN A5 - connected to SCL (Serial Clock)
  PIN A4 - connected to SDA (Serial Data)

*/
