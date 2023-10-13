/*
    Kalman Filter Example for MPU6050. Output for processing.
    Read more: http://www.jarzebski.pl/arduino/rozwiazania-i-algorytmy/odczyty-pitch-roll-oraz-filtr-kalmana.html
    GIT: https://github.com/jarzebski/Arduino-KalmanFilter
    Web: http://www.jarzebski.pl
    (c) 2014 by Korneliusz Jarzebski
*/


#include <Wire.h>
#include <MPU6050.h>
#include "KalmanFilter.h"

#define MPU_SENSITIVITY_2G 16384.0

MPU6050 mpu;

typedef struct x{
  float XAxis;
  float YAxis;
  float ZAxis;
} Vector;

KalmanFilter kalmanX(0.001, 0.003, 0.03);
KalmanFilter kalmanY(0.001, 0.003, 0.03);

float accPitch = 0;
float accRoll = 0;

float kalPitch = 0;
float kalRoll = 0;

void setup() 
{
  Serial.begin(9600);
  Wire.begin(5, 18);

  // Initialize MPU6050
  mpu.initialize();
  if(!mpu.testConnection())
  {
    while(1)
    delay(500);
  }
 
  // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
  mpu.CalibrateGyro();
}

void loop()
{

  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float norm_accx = float(ax) / MPU_SENSITIVITY_2G;
  float norm_accy = float(ax) / MPU_SENSITIVITY_2G;
  float norm_accz = float(ax) / MPU_SENSITIVITY_2G;

  float norm_gx = gx/131;
  float norm_gy = gy/131.0;



  // Calculate Pitch & Roll from accelerometer (deg)
  accPitch = -(atan2(norm_accx, sqrt(norm_accy*norm_accy + norm_accz * norm_accz))*180.0)/M_PI;
  accRoll  = (atan2(norm_accy, norm_accz)*180.0)/M_PI;

  // Kalman filter
  kalPitch = kalmanY.update(accPitch, norm_gy);
  kalRoll = kalmanX.update(accRoll, norm_gx);

  Serial.print(kalPitch);
  Serial.print(":");

  Serial.println();

  delay(1000);
}

