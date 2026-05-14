/******************************************************************************
NW_BME280.h — NW_BME280
Northern Widget interface for the Bosch BME280 temperature, humidity,
and pressure sensor.

Bobby Schulz @ Northern Widget LLC

Wraps the Adafruit BME280 library to provide the Northern Widget sensor
API: begin(), getHeader(), getString(), and the raw readings interface.
Returns atmospheric pressure in mBar, relative humidity in %, and
temperature in °C.

Distributed as-is; no warranty is given.
******************************************************************************/

#ifndef NW_BME280_h
#define NW_BME280_h

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

		/** @brief Prepare for raw reading collection. */
		void beginRawReadings();

		/** @brief Take one raw reading and write CSV data into buf at offset.
		    Writes: pressure [mBar], humidity [%], temperature [°C], each followed by a comma.
		    Max bytes written per call: 24.
		    @param buf Caller-managed destination buffer.
		    @param offset Starting write position in buf.
		    @return New offset after writing. */
		uint16_t takeRawReading(char* buf, uint16_t offset);

		/** @brief End raw reading collection. */
		void endRawReadings();

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
