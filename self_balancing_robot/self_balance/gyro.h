#ifndef _GYRO_H_
#define _GYRO_H_
#include <Adafruit_MPU6050.h>

#define SDA 14
#define SCL 15
int init_mpu(void);
void update(float*, float*);
#endif