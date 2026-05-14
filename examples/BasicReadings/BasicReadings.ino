/*
 * BasicReadings — NW_BME280
 *
 * Read temperature, relative humidity, and atmospheric pressure from
 * a Bosch BME280 sensor via the Northern Widget BME library.
 *
 * Wiring (I2C):
 *   BME280 VCC → 3.3 V
 *   BME280 GND → GND
 *   BME280 SDA → SDA
 *   BME280 SCL → SCL
 *   BME280 SDO → GND (sets I2C address to 0x76)
 *              → VCC (sets I2C address to 0x77, the default)
 *
 * Northern Widget LLC
 * GNU GPL v3.0
 */

#include <NW_BME280.h>

BME bme;

void setup() {
    Serial.begin(9600);
    while (!Serial) {}

    if (!bme.begin()) {
        Serial.println("BME280 not found. Check wiring and I2C address.");
        while (true) {}
    }

    Serial.println(bme.getHeader());
}

void loop() {
    Serial.println(bme.getString());
    delay(2000);
}
