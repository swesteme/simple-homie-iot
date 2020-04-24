#include <Arduino.h>
#include <KillConfigNode.h>

// Homie node receiving the signal to kill the Homie configuration and reboot.
KillConfigNode killConfigNode;

void setup() {
  Serial.begin(115200);
  Serial << endl << "Start setup..." << endl;

  // inititalise Homie library
  Homie_setFirmware("livingroom", "1.0.0");
  Homie.setup();

  Serial << "Finished setup." << endl;
}

void loop() {
  // run homie loop
  Homie.loop();
}
