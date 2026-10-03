/******************************************************************************
NW_BME280.cpp — NW_BME280
Northern Widget interface for the Bosch BME280 temperature, humidity,
and pressure sensor.

Bobby Schulz @ Northern Widget LLC

Distributed as-is; no warranty is given.
******************************************************************************/

#include "NW_BME280.h"

BME::BME() {
}

bool BME::begin(uint8_t ADR_) {
  ADR = ADR_;
  return Sensor.begin(ADR);
}

float BME::getPressure() {
  return Sensor.readPressure() * 0.01;  // Pa → mBar
}

float BME::getHumidity() {
  return Sensor.readHumidity();
}

float BME::getTemperature() {
  return Sensor.readTemperature();
}

//The columns a logger writes, streamed straight into the file. No row is
//composed in RAM; see LIBRARY-DESIGN.md section 14.
size_t BME::printDataHeader(Print& out) {
  return out.print("Pressure Atmos [mBar],Humidity [%],Temp Atmos [C],");
}

size_t BME::printDataRow(Print& out) {
  size_t n = 0;
  n += out.print(getPressure());
  n += out.print(',');
  n += out.print(getHumidity());
  n += out.print(',');
  n += out.print(getTemperature());
  n += out.print(',');
  return n;
}

void BME::beginRawReadings() {}

uint16_t BME::takeRawReading(char* buf, uint16_t offset) {
  char tmp[10];
  dtostrf(getPressure(), 1, 2, tmp);
  offset += snprintf(buf + offset, 10, "%s,", tmp);
  dtostrf(getHumidity(), 1, 2, tmp);
  offset += snprintf(buf + offset, 10, "%s,", tmp);
  dtostrf(getTemperature(), 1, 2, tmp);
  offset += snprintf(buf + offset, 10, "%s,", tmp);
  return offset;
}

void BME::endRawReadings() {}

// ── PascalCase aliases (deprecated) ───────────────────────────────────────────
