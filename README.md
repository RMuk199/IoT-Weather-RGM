# IoT Project Devleopment Assignment 2023

### Table of Contents

 - Project Overview
 - Project Purpose
 - Goals
 - Development Roadmap
 - Setup Information
 - Sensor Specs
 - Screenshots and other info
 - Refrences/Citations

### Project Overview
This project is and IoT devlopment project in which I will construct a simple weather station using node js. The Weather station will use a DHT11 and Raindrops module, and will be capable of measuring termpearture, humidity and weather it is raining. The station will send to a front end webpage and will also include a tranducer output in the form of an LED.

### Project Purpose
The purpose of the project, which is an assignment for a school IoT Course, will be to get a basic reading of the temperature in an area and output that to a front-end webpage

### Goals
- Include 2 working sensors - DHT11 and Raindrops Module
- Create and engaging front-end webpage with Temp, Humidity and Rain information
- Use graphics to convey weather it is raining or not - in the form of raincloud images
- Include a tranducer output to identify when the Raindrops module senses water

### Development Roadmap

- [x] Setup repos - GitHub
- [x] setup ESP32 - Arduino IDE
- [x] Install dependencies - aREST.h and DHT.h
- [x] Test ESP32 - get json data via wifi
- [x] Initialize Node.js environment
- [x] setup server.js with express
- [X] setup DHT11 and Raindrops Module
- [X] Get all data on front-end webpage
- [X] Design webpage using ejs and css
- [X] Final commits and readme completion

### Setup Information
The weather station will be set up using an esp32 and sensors DHT11 and esp32 Raindrops Module. It will use the analog output from the Raindrops module. All interactions with the esp32 will be coded in Aurduino IDE and written in C++, while front end devlopement will be done in VS Code and will be written in Javascript, EJS and CSS. 

### Screenshots & Wiring
Wiring: 

<img src="public/assets/wiring.jpg" alt="wiring" height="200"/>

Coloured wires are used for information sending. Green wire collects anolog outputs from the Raindrops module and is connected to GPIO pin 32. The DHT11 and blue wire are connected to GPIO pin 33. The tranducer output LED is connected to GPIO pin 12. All grey wires are used for power.

Website screenshots:

With Rain

<img src="public/assets/with_rain.png" height="200"/>

Without Rain

<img src="public/assets/without_rain.png" height="200"/>


### References

- [Raindrops Module Information](https://diyi0t.com/rain-sensor-tutorial-for-arduino-and-esp8266/)
- [How to use Javascript in EJS](https://www.geeksforgeeks.org/how-to-use-ejs-in-javascript/)
- [CSS Refresher - w3 Schools](https://www.w3schools.com/Css/)
- [ESP32 Pinout Refrence](https://electropeak.com/learn/full-guide-to-esp32-pinout-reference-what-gpio-pins-should-we-use/#:~:text=The%20ESP32%20microcontroller%20has%20the%20following%20pins%20%3A,UART%20interfaces%2016%20PWM%20channels%202%20I2S%20interfaces)
- [Jetscholar IoT-Weather](https://github.com/jetscholar/IoT-Weather)

