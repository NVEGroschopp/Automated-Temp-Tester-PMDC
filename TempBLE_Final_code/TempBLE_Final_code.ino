#include <ArduinoBLE.h>           // Bluetooth Library
#include "max6675.h"              // Breakout board Libray by Adafruit

// Initalizing global variables for sensor data to pass onto BLE
int thermoSO = 12;
int thermoCS = 11;
int thermoCLK = 13;

String t;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoSO);
// BLE Service Name
BLEService customService("180C");

// BLE Characteristics
// Syntax: BLE<DATATYPE>Characteristic <NAME>(<UUID>, <PROPERTIES>, <DATA LENGTH>)

BLEStringCharacteristic ble_temperature("2A57", BLERead | BLENotify, 13);


// Function prototype
void readValues();

void setup()
{
    // Initalizing all the sensors
    delay(2000);
    
    if (!BLE.begin())
    {
        while (1);
    }

    // Setting BLE Name
    BLE.setLocalName("Arduino Temperature Sensor");
    
    // Setting BLE Service Advertisment
    BLE.setAdvertisedService(customService);
    
    // Adding characteristics to BLE Service Advertisment
    
    customService.addCharacteristic(ble_temperature);

    // Adding the service to the BLE stack
    BLE.addService(customService);

    // Start advertising
    BLE.advertise();
}

void loop()
{
    // Variable to check if cetral device is connected
    BLEDevice central = BLE.central();
    if (central)
    {
        while (central.connected())
        {
            delay(200);
            
            // Read values from sensors
            readValues();

            // Writing sensor values to the characteristic
            
            ble_temperature.writeValue(t);
        }
    }
}

void readValues()
{
    // Reading raw sensor values from three sensors
    float x;
    float temperature = thermocouple.readCelsius();

    // Saving sensor values into a user presentable way with units
    t = String(temperature);
}
