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

//actually... the acceleration values will be distorted a lot...
//hmm, we could probably stick the chip at like the bottom. i need to minimize acceleration from the bot.
//the only acceleration values i need to generate are ones from gravity...
//is this where we use filters? Im very bad at that stuff...

//anyway this is probably worth a shot. But i DONT WANT IT TO FAIL
//to minimize acceleration, i need to minimize height from the ground. fuck it

void update(float* roll, float* pitch){
	sensors_event_t g, a, t;
	mpu.getEvent(&a, &g, &t);


  //SOLDER THE CHIP PROPERLY - can get you nan values, and then idk what this will do.
	*roll = atan2(a.acceleration.y, a.acceleration.z);
	*pitch = asin(a.acceleration.x / 9.81f);

}
