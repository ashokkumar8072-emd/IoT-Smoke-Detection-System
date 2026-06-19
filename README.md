# IoT Smoke Detection System using ESP32 and ThingSpeak

## Project Overview

The IoT Smoke Detection System is a smart safety monitoring project designed to detect smoke using an MQ2 gas sensor. The system is built around an ESP32 microcontroller and provides real-time alerts through an LED, buzzer, and LCD display. In addition, the sensor data is transmitted to the ThingSpeak cloud platform for remote monitoring and data visualization.

This project demonstrates the integration of Embedded Systems and Internet of Things (IoT) technologies for safety and monitoring applications.

---

## Objectives

- Detect smoke in real time using the MQ2 sensor.
- Provide immediate visual and audio alerts.
- Display system status on an LCD screen.
- Upload sensor data to the ThingSpeak cloud platform.
- Enable remote monitoring through an IoT dashboard.

---

## Components Used

1. ESP32 Development Board
2. MQ2 Smoke/Gas Sensor
3. 16x2 LCD Display with I2C Module
4. LED
5. Buzzer
6. Breadboard
7. Jumper Wires
8. USB Cable
9. Wi-Fi Connection

---

## Circuit Connections

| Component | ESP32 Pin |
|------------|------------|
| MQ2 AO | GPIO34 |
| MQ2 VCC | 5V |
| MQ2 GND | GND |
| LED Anode (+) | GPIO25 |
| LED Cathode (-) | GND |
| Buzzer (+) | GPIO26 |
| Buzzer (-) | GND |
| LCD SDA | GPIO21 |
| LCD SCL | GPIO22 |
| LCD VCC | 5V |
| LCD GND | GND |

---

## Working Principle

1. The MQ2 sensor continuously monitors the surrounding air for smoke concentration.
2. The ESP32 reads the analog value from the MQ2 sensor.
3. If the sensor value exceeds the predefined threshold:
   - The LED turns ON.
   - The buzzer is activated.
   - The LCD displays "SMOKE DETECTED".
4. If the smoke level is below the threshold:
   - The LED remains OFF.
   - The buzzer remains OFF.
   - The LCD displays "SAFE".
5. The ESP32 sends the sensor readings to the ThingSpeak cloud platform every 15 seconds.
6. Users can monitor the smoke level remotely through the ThingSpeak dashboard.

---

## ThingSpeak Configuration

### Channel Name
IoT Smoke Detection System

### Fields

Field 1: Smoke Value

Field 2: Smoke Status

Smoke Status Values:
- 0 = Safe
- 1 = Smoke Detected

---

## Features

- Real-time smoke detection
- LED alert indication
- Buzzer alarm system
- LCD status display
- Cloud data logging
- Remote monitoring using ThingSpeak
- Wi-Fi enabled IoT connectivity

---
## Project Images

### Circuit Diagram
![Circuit Diagram](./circuit%20diagram.png)
##image
![Output](./image%20(2).jpeg)
## Results

The system successfully detected smoke and generated immediate alerts through the LED and buzzer. The LCD displayed warning messages when smoke was detected. Sensor data was transmitted to the ThingSpeak cloud platform and visualized through real-time graphs. The project demonstrated reliable operation and effective integration of embedded hardware with cloud-based IoT services.

---

## Applications

- Home Fire Safety Systems
- Smart Buildings
- Industrial Safety Monitoring
- Laboratories
- Warehouses
- Educational IoT Projects

---

## Future Enhancements

- SMS Alert System
- Email Notifications
- Mobile Application Integration
- Temperature and Humidity Monitoring
- Multi-Sensor Fire Detection
- AI-Based Fire Prediction System
- Emergency Notification System

---

## Project Images

Addedd screenshots of:
- Circuit Diagram
- Wokwi Simulation
- LCD Output
- ThingSpeak Dashboard

---

## Conclusion

This project successfully implements an IoT-based smoke detection and alert system using ESP32 and ThingSpeak. The system provides real-time monitoring, local alert generation, and cloud-based data visualization, making it a practical solution for safety and environmental monitoring applications.

---

## Author

Ashok Kumar  
B.E. Electronics and Communication Engineering (ECE)  
Ramco institute of technology
