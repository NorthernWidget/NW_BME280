#include "BME.h"

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

// ── PascalCase aliases (deprecated) ───────────────────────────────────────────

float BME::GetPressure()     { return getPressure(); }
float BME::GetHumidity()     { return getHumidity(); }
float BME::GetTemperature()  { return getTemperature(); }
String BME::GetHeader()      { return getHeader(); }
String BME::GetString()      { return getString(); }
