# Simple Homie IOT Esp8266 wrapper library
[![Build Status](https://travis-ci.org/swesteme/simple-homie-iot.svg?branch=develop)](https://travis-ci.org/swesteme/simple-homie-iot)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/swesteme/simple-homie-iot/develop/LICENSE)
__________

This small library is just a distilled part of code from my use the great Homie IOT Esp8266 library by Marvin Roger and Ian Hubbertz.

You may use it if you have ESPs switching things on and off with custom sensors like Infrared or Radio controls. 

**Note:** this is only the base library. For this to become useful, install any of the depending libraries: `simple-homie-radio`, `simple-homie-infrared` or `simple-homie-capacitivebutton`.

## Example
A simple example containing only the `killconfig` Homie node. It can be signalled via MQTT to erase the Homie configuration on device and reboot into AccessPoint mode.

```
#include <Arduino.h>
#include <KillConfigNode.h>

// Homie node receiving the signal to kill the Homie configuration and reboot.
KillConfigNode killConfigNode;

void setup() {
  Serial.begin(115200);
  Serial << endl << "Start setup..." << endl;

  // inititalize Homie library
  Homie_setFirmware("livingroom", "1.0.0");
  Homie.setup();

  Serial << "Finished setup." << endl;
}

void loop() {
  // run homie loop
  Homie.loop();
}
```

## Installation
Install the library by adding it to your project's platformio.ini:

```
lib_deps =
    simple-homie-iot
```
