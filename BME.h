
#ifndef BME_h
#define BME_h

#include "Arduino.h"
#include <Adafruit_BME280.h>

class BME
{
	public:
		BME();
		uint8_t begin(uint8_t ADR_ = 0x77); //use default address
		//
		float getPressure();
		float getHumidity();
		float getTemperature();
		String getString();
		String getHeader();
		// PascalCase aliases — deprecated, use camelCase versions above
		[[deprecated("Use getPressure()")]]  float GetPressure();
		[[deprecated("Use getHumidity()")]]  float GetHumidity();
		[[deprecated("Use getTemperature()")]] float GetTemperature();
		[[deprecated("Use getString()")]]    String GetString();
		[[deprecated("Use getHeader()")]]    String GetHeader();
	private:
		Adafruit_BME280 Sensor;
		uint8_t ADR = 0x77; //Default global sensor address 
};

#endif
