#ifndef _GYRO_H_
#define _GYRO_H_
#include <MPU6050_light.h>

#define SDA 32 
#define SCL 33 
int init_mpu(void);
void update(double*);
#endif