# Arduino Ultrasonic Radar Scanner

A real-time obstacle detection system built using an Arduino Uno, HC-SR04 ultrasonic sensor, and SG90 servo motor.

The servo continuously sweeps the ultrasonic sensor across an angle, allowing the system to scan its surroundings and detect objects at different positions

## Features
 
- 📡 Real-time obstacle detection using the HC-SR04 ultrasonic sensor
- 🔄 180° servo-based radar scanning
- 🖥️ Live radar visualization using Processing
- 📺 Real-time angle and distance displayed on a 16×2 I²C LCD
- 🟢 Green LED indicates a safe distance
- 🔴 Red LED indicates a nearby obstacle
- 🔊 Audible proximity alerts using a buzzer
- 📡 Real-time HTML dashboard displaying live sensor data and visualizing object movement
  
## Components Used
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Breadboard
- Jumper Wires
- USB Cable
- LED's

## Software

- Arduino IDE
- HTML/CSS/JavaScript Dashboard

## Pin Connections

| Component       | Arduino Pin |
|-----------------|-------------|
| HC-SR04 Trigger | D7          | 
| HC-SR04 Echo    | D6          |
| Servo (SG90)    | D9          |
| Green LED       | D4          | 
| Red LED         | D5          | 
| Buzzer          | D3          |
| LCD(SDA)        | A4          |
| LCD(SCL)        | A5          |  

## What I Learned
- Servo motor control using PWM
- Ultrasonic distance measurement
- Timing using pulseIn()
- Real-time sensor scanning
- Integrating multiple peripherals
- Debugging hardware and software together
  
## 🔌 Wiring Diagram

![Circuit Diagram Using TinkerCad](images/UPDATEIMAGE.png)

## HTML
- 💻 Source: [Radar Live HTML](frontend/radar_live.html)
