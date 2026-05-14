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

		/** @brief Initialize the BME280. @param ADR_ I2C address (default 0x77).
		    @return true if sensor found and initialized successfully. */
		bool begin(uint8_t ADR_ = 0x77);

		/** @brief Atmospheric pressure. @return Pressure in mBar. */
		float getPressure();

		/** @brief Relative humidity. @return Humidity in %. */
		float getHumidity();

		/** @brief Air temperature. @return Temperature in °C. */
		float getTemperature();

		/** @brief Northern Widget CSV header string.
		    @return "Pressure Atmos [mBar],Humidity [%],Temp Atmos [C]," */
		String getHeader();

		/** @brief Northern Widget CSV data string.
		    @return Comma-separated pressure, humidity, temperature with trailing comma. */
		String getString();

		// PascalCase aliases — deprecated, use camelCase versions above
		[[deprecated("Use getPressure()")]]    float GetPressure();
		[[deprecated("Use getHumidity()")]]    float GetHumidity();
		[[deprecated("Use getTemperature()")]] float GetTemperature();
		[[deprecated("Use getHeader()")]]      String GetHeader();
		[[deprecated("Use getString()")]]      String GetString();

	private:
		Adafruit_BME280 Sensor;
		uint8_t ADR = 0x77;
};

#endif
