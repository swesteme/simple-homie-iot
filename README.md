# Simple Homie IOT Esp8266 wrapper library
[![Build Status](https://travis-ci.org/swesteme/simple-homie-iot.svg?branch=develop)](https://travis-ci.org/swesteme/simple-homie-iot)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/swesteme/simple-homie-iot/develop/LICENSE)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)
__________

This small library is just a distilled part of code from my use of the great Homie IOT Esp8266 library by Marvin Roger and Ian Hubbertz.

You may use it if you have ESPs switching things on and off with custom sensors like Infrared or Radio controls. 

**Note:** this is only the base library. For this to become useful, install any of the depending libraries: [simple-homie-iot-rc433](https://github.com/swesteme/simple-homie-iot-rc433), [simple-homie-iot-ir](https://github.com/swesteme/simple-homie-iot-ir) or [simple-homie-iot-capacitivebutton](https://github.com/swesteme/simple-homie-iot-capacitivebutton).

## Why not put it all in one package? Can I combine the libraries?
The reason why all the different types of sensors and transmitters are not in this base package but distributed among the other dependent libraries is simply to save space on the ESP devices. If all sensors can be used in one library, all the wrapped libraries also have to be compiled for the device.

However, nobody keeps you from combining all the depending libraries in one sketch or project. If your ESP is connected to an infrared sensor and an RC 433MHz transmitter, go ahead and use both of the depending libraries. That's what they are made for.

## Basics
All of the items created by this library or any of the depending libraries are created as Homie "nodes". The Homie functionality is found in this base library, the depending libraries wrap different kinds of sensors and transmitters around the respective hardware libraries.


Basic Type | Implemented in | MQTT topic | Description
--- | --- | --- | ---
`Sender` | `RcReceiver` | | Senders are used to send signals using transmitter parts in a circuit, e.g. an infrared transmitter or an RC 433MHz transmitter. They are most useful in `Switch` instances to transmit codes for their `on` and `off` states.
`Receiver` | `RcReceiver`, `IrReceiver` | `homie/<firmware-id>/remotecontrol/receiver` and `homie/<firmware-id>/infrared/receiver` | Receiver objects are used to fetch signals from sensors like infrared or RC 433MHz sensors, as well as capacitive buttons. `RemoteButton` instances take a `Receiver` object to detect whether a remote button has been switched `on` or `off`.
`RemoteButton` | `RcRemoteButton`, `IrRemoteButton` | `homie/<firmware-id>/<button-id>/state` | Button instances react on codes they are told to recognize from a designated `Receiver` instance. The `on` and `off` states are signalled via MQTT.
`Switch` | `Switch` | command:`homie/<firmware-id>/<switch-id>/switch/set`, state:`homie/<firmware-id>/<switch-id>/switch` | A switch object is toggled using MQTT topics and sends specific codes for `on` and `off` state using a sender instance.
`KillConfigNode` | `KillConfigNode` | `homie/<firmware-id>/killconfig/switch/set` | The kill config node is used to reset a homie configuration and reboot the ESP device.

## Example
A simple example containing only the `killconfig` Homie node. It can be signalled via MQTT to erase the Homie configuration on device and reboot into AccessPoint mode. **Further examples can be found in the depending libraries' READMEs (see above).**

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
    Simple Homie IOT wrapper
```

## Communication
- If you **have found a bug**, open an issue.
- If you **have a feature request**, open an issue.
- If you **want to contribute**, submit a pull request.

## License
The library is available under the MIT license. See the LICENSE file for more info.

Copyright (c) 2020 Sebastian Westemeyer