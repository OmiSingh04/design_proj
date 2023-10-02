#include <Wire.h>
#include <Kalman.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin(5, 18);
  mpu.initialize();
}

void loop() {
  int16_t accX, accY, accZ;
  int16_t gyroX, gyroY, gyroZ;

  mpu.getMotion6(&accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ);

  // Calculate pitch and roll angles using accelerometer data
  float accPitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * 180.0 / M_PI;

  // Calculate gyro-based roll and pitch angles
  Serial.print(", Acc Pitch: ");
  Serial.print(accPitch);

  delay(10); // Adjust loop delay as needed
}
