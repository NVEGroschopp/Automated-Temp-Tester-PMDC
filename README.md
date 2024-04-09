# Automated Temperature Tester PMDC

## Overview
The Automated Temperature Tester PMDC project utilizes an Arduino Nano 33 BLE, a K-Type Thermocouple, a Max6675.h Breakout Board, a slip ring, and a 3D printed fixture. This document serves as a comprehensive guide for assembly, wiring, and usage of the automated temperature test labview program.

## Components
- Arduino Nano 33 BLE
- K-Type Thermocouple
- Max6675 Breakout Board (https://a.co/d/3DE7FEz)
- Slip Ring (https://a.co/d/8gP0RlK)
- BLED112 USB Dongle (https://www.digikey.com/short/ch5m7prf)
- Customized Shims for Bearing
- Customized Shims for Different Frame Size
- 3D Printed Fixtures

## Description
This automated tester device serves as transmitter that sending temperature data through air using Bluetooth Low Energy module to the host labview program (Eng lab computer/Desktop/Automated Temp Test/PM Automated Temperature Test Final).

## Wiring Diagram
![Wiring Diagram Automated Temp Test](image/Wiring%20Diagram%20Automated%20Temp%20Test_bb.png)


## Installation and Setup
1. Assemble the components according to the diagram and assembly print(referece X-20604 for assembly prints).
2. Upload the Arduino sketch to the Arduino Nano 33 BLE.
3. Attach thermocouple to the armature winding.
4. Feed thermocouple through the bearing and attach yellow to positive + read to negetive - on the breakout board.
5. Attach device at the end of the modular shaft.

## Usage
1. Start with adjusting PID for the brake.
2. Select correct model for the brake and send configuration.
3. Enter correct addresses for each device (see below) and check all physical connections.

![Device Address](image/Device%20Address.PNG)

Note: MAC address for the temperature sensor maybe different 
## Troubleshooting
If you encounter any issues during setup or usage, refer to the following troubleshooting steps:
- 
- 
- 


## Conclusion


