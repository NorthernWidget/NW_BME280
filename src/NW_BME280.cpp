/******************************************************************************
NW_BME280.cpp — NW_BME280
Northern Widget interface for the Bosch BME280 temperature, humidity,
and pressure sensor.

Bobby Schulz @ Northern Widget LLC

Distributed as-is; no warranty is given.
******************************************************************************/

#include "NW_BME280.h"

BME::BME()
{
}

bool BME::begin(uint8_t ADR_)
{
	ADR = ADR_;
	return Sensor.begin(ADR);
}

float BME::getPressure()
{
	return Sensor.readPressure() * 0.01;  // Pa → mBar
}

float BME::getHumidity()
{
	return Sensor.readHumidity();
}

float BME::getTemperature()
{
	return Sensor.readTemperature();
}

String BME::getHeader()
{
	return "Pressure Atmos [mBar],Humidity [%],Temp Atmos [C],";
}

String BME::getString()
{
	return String(getPressure()) + "," + String(getHumidity()) + "," + String(getTemperature()) + ",";
}

//The streaming forms of the two above: the same bytes, written into any Print
//rather than composed. A logger passes the open file. See
//LIBRARY-DESIGN.md section 14. getHeader() and getString() are left as they
//are, because printing them through a String would need NW_StringPrint and
//this library does not depend on NW_Core.
size_t BME::printDataHeader(Print& out)
{
	return out.print("Pressure Atmos [mBar],Humidity [%],Temp Atmos [C],");
}

size_t BME::printDataRow(Print& out)
{
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
	dtostrf(getPressure(),    1, 2, tmp); offset += snprintf(buf + offset, 10, "%s,", tmp);
	dtostrf(getHumidity(),    1, 2, tmp); offset += snprintf(buf + offset, 10, "%s,", tmp);
	dtostrf(getTemperature(), 1, 2, tmp); offset += snprintf(buf + offset, 10, "%s,", tmp);
	return offset;
}

void BME::endRawReadings() {}

// ── PascalCase aliases (deprecated) ───────────────────────────────────────────

float BME::GetPressure()     { return getPressure(); }
float BME::GetHumidity()     { return getHumidity(); }
float BME::GetTemperature()  { return getTemperature(); }
String BME::GetHeader()      { return getHeader(); }
String BME::GetString()      { return getString(); }
