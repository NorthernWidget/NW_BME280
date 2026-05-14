/******************************************************************************
BME.h — NW_BME280
Northern Widget interface for the Bosch BME280 temperature, humidity,
and pressure sensor.

Bobby Schulz @ Northern Widget LLC

Wraps the Adafruit BME280 library to provide the Northern Widget sensor
API: begin(), getHeader(), and getString(). Returns atmospheric pressure
in mBar, relative humidity in %, and temperature in °C.

Distributed as-is; no warranty is given.
******************************************************************************/

#ifndef BME_h
#define BME_h

#include "Arduino.h"
#include <Adafruit_BME280.h>

class BME
{
	public:
		BME();
		bool begin(uint8_t ADR_ = 0x77);
		float getPressure();
		float getHumidity();
		float getTemperature();
		String getString();
		String getHeader();
		// PascalCase aliases — deprecated, use camelCase versions above
		[[deprecated("Use getPressure()")]]    float GetPressure();
		[[deprecated("Use getHumidity()")]]    float GetHumidity();
		[[deprecated("Use getTemperature()")]] float GetTemperature();
		[[deprecated("Use getString()")]]      String GetString();
		[[deprecated("Use getHeader()")]]      String GetHeader();
	private:
		Adafruit_BME280 Sensor;
		uint8_t ADR = 0x77;
};

#endif
