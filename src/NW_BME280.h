/******************************************************************************
NW_BME280.h — NW_BME280
Northern Widget interface for the Bosch BME280 temperature, humidity,
and pressure sensor.

Bobby Schulz @ Northern Widget LLC

Wraps the Adafruit BME280 library to provide the Northern Widget sensor
API: begin(), printDataHeader(), printDataRow(), and the raw readings interface.
Returns atmospheric pressure in mBar, relative humidity in %, and
temperature in °C.

Distributed as-is; no warranty is given.
******************************************************************************/

#ifndef NW_BME280_h
#define NW_BME280_h

#include "Arduino.h"
#include <Adafruit_BME280.h>

class BME {
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

  /** @brief Print the Northern Widget columns into any Print: a File to reach the card, Serial to reach the monitor.
		    @return Bytes printed: "Pressure Atmos [mBar],Humidity [%],Temp Atmos [C]," */
  size_t printDataHeader(Print& out);

  /** @brief Print pressure, humidity and temperature in printDataHeader()'s order, each followed by a comma. Takes no reading. */
  size_t printDataRow(Print& out);

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

private:
  Adafruit_BME280 Sensor;
  uint8_t ADR = 0x77;
};

#endif
