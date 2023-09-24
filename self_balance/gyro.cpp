#include "gyro.h"
#include "debug.h"
#include <Wire.h>
#include <Adafruit_MPU6050.h>

static Adafruit_MPU6050 mpu;

int init_mpu(void){
    Wire.begin(SDA, SCL);
    debug_write("I2C SDA and SCL set to ");
    if(!mpu.begin()){
        debug_write("MPU6050 Not Found!!! Please connect and RST the controller");
        return 0;
    }

    debug_write("MPU6050 Connected.");
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    debug_write("Gyro Range Set to +- 250 deg/sec");
    return 1;
}


void update(float* gyroX, float* gyroY, float* gyroZ){
    sensors_event_t g, a, t;
    mpu.getEvent(&a, &g, &t);

    *gyroX = g.gyro.x;
    *gyroY = g.gyro.y;
    *gyroZ = g.gyro.z;
}