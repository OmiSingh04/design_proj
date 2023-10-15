#include "gyro.h"
#include "debug.h"
#include <Wire.h>
#include <MPU6050_light.h>

static MPU6050 mpu(Wire);

int init_mpu(void){
	
	Wire.begin(SDA, SCL);
	byte status = mpu.begin();
	debug_write(String(status));
	if(status!=0)
		return false;
	debug_write("Init:5 seconds before calculating offsets.");
	delay(5000);
	debug_write("Init:Calculating offsets");
	// mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
	mpu.calcOffsets(); // gyro and accelero
	debug_write("Init:MPU6050 Connected.");
	return 1;
}

//actually... the acceleration values will be distorted a lot...
//hmm, we could probably stick the chip at like the bottom. i need to minimize acceleration from the bot.
//the only acceleration values i need to generate are ones from gravity...
//is this where we use filters? Im very bad at that stuff...

//anyway this is probably worth a shot. But i DONT WANT IT TO FAIL
//to minimize acceleration, i need to minimize height from the ground. fuck it

void update(double* pitch){
	// put your main code here, to run repeatedly:
	mpu.update();
	*pitch = mpu.getAngleY();
}