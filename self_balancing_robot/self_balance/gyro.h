#ifndef _GYRO_H_
#define _GYRO_H_
#include <MPU6050_light.h>

#define SDA 5 
#define SCL 18
int init_mpu(void);
void update(float*);
#endif