[![DOI](https://zenodo.org/badge/DOI/10.5281/zenodo.6338662.svg)](https://doi.org/10.5281/zenodo.6338662)

# NW_BME280

[**API Documentation**](https://docs.northernwidget.com/NW_BME280/)

Northern Widget interface for the [Bosch BME280](https://www.bosch-sensortec.com/products/environmental-sensors/humidity-sensors-bme280/) temperature, humidity, and pressure sensor.

This library wraps the [Adafruit BME280 Library](https://github.com/adafruit/Adafruit_BME280_Library) to provide the standard Northern Widget sensor API, used across all NW sensor libraries and supported natively by the [Margay](https://github.com/NorthernWidget/Margay_Library) and [Okapi](https://github.com/NorthernWidget-Skunkworks/Okapi_Library) data loggers.

## Dependencies

- [Adafruit BME280 Library](https://github.com/adafruit/Adafruit_BME280_Library)

## API

```cpp
#include <NW_BME280.h>

BME sensor;

bool  begin(uint8_t address = 0x77);  // returns false if sensor not found

float getPressure();     // atmospheric pressure, mBar
float getHumidity();     // relative humidity, %
float getTemperature();  // temperature, °C

String getHeader();      // "Pressure Atmos [mBar],Humidity [%],Temp Atmos [C],"
String getString();      // comma-separated values with trailing comma

// Raw readings interface (NW standard, buffer-based)
void     beginRawReadings();
uint16_t takeRawReading(char* buf, uint16_t offset);  // max 24 bytes per call
void     endRawReadings();
```

## Installation

Install via the [Arduino Library Manager](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/) by searching for **NW_BME280**, or install the [Adafruit BME280 Library](https://github.com/adafruit/Adafruit_BME280_Library) dependency first and then download this library manually.

## Authors

Bobby Schulz, Northern Widget LLC
