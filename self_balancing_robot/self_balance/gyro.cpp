#include "gyro.h"
#include "debug.h"
#include <Wire.h>
#include <MPU6050.h>

static MPU6050 mpu;
static int16_t accX, accY, accZ, gyroX, gyroY, gyroZ;

int init_mpu(void){
	Wire.begin(SDA, SCL);
	debug_write("I2C SDA and SCL set to ");
	mpu.initialize();
	
	if(!mpu.testConnection()){
		debug_write("MPU6050 Not Found!!! Please connect and RST the controller");
		return 0;
	}
	debug_write("MPU6050 Connected.");
	return 1;
}

//actually... the acceleration values will be distorted a lot...
//hmm, we could probably stick the chip at like the bottom. i need to minimize acceleration from the bot.
//the only acceleration values i need to generate are ones from gravity...
//is this where we use filters? Im very bad at that stuff...

//anyway this is probably worth a shot. But i DONT WANT IT TO FAIL
//to minimize acceleration, i need to minimize height from the ground. fuck it

void update(float* pitch){

	mpu.getMotion6(&accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ);

  //SOLDER THE CHIP PROPERLY - can get you nan values, and then idk what this will do.
	*pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * 180.0 / M_PI;

}
