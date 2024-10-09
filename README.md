# digital plant basd on : OLED Display with LDR, Touch Sensor, and Moisture Sensor

## Overview
This project uses an Adafruit SSD1306 OLED display to show smiley or sad faces based on LDR (Light Dependent Resistor) and touch sensor input. Additionally, it monitors the moisture levels using a moisture sensor and displays the percentage on the screen. A heart shape is displayed when the touch sensor is triggered.

## Features
- Displays a smiley face when a human is detected and moisture level is adequate.
- Displays a sad face if no human is detected or moisture is low.
- Touch sensor interaction to display a message and a heart shape.
- Continuous monitoring of soil moisture levels with percentage display.

## Components Used
- **Adafruit SSD1306 OLED Display**
- **LDR (Light Dependent Resistor) Sensor**
- **Touch Sensor**
- **Moisture Sensor**

## Pin Configuration
| Component          | Pin          |
|--------------------|--------------|
| OLED Display (I2C) | Default I2C  |
| LDR Sensor         | Pin 2        |
| Touch Sensor       | Pin 3        |
| Moisture Sensor    | A0 (Analog)  |

## Setup Instructions
1. **Connect the components** as per the pin configuration table.
2. **Upload the code** to your Arduino.
3. **Monitor the Serial Output** for moisture levels and observe the OLED for visual feedback.

## Usage
- The OLED will show a smiley face when the LDR detects a human and moisture levels are high.
- If moisture is low, a sad face is displayed.
- If the touch sensor is pressed, a heart shape and a message ("hellooo!!") are shown.

## Libraries Required
- Adafruit GFX Library
- Adafruit SSD1306 Library

Install the required libraries using the Arduino Library Manager.

## License
This project is licensed under the MIT License.
