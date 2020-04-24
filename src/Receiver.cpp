#include "Receiver.h"
#include "RemoteButton.h"

#define SW_RECEIVER "receiver"

#include <cstdlib>

Receiver::Receiver(const char* id, const char* name)
    : HomieNode(id, id, SW_RECEIVER) {
  // set up property, state topic is like "homie/livingroom/button1/receiver"
  advertise(SW_RECEIVER);
}

void Receiver::addButton(RemoteButton* button) {
  // keep receiver in list of receivers
  buttonNodes.push_back(button);
}

// handle incoming values and loop over all receivers
void Receiver::loop() {
  HomieNode::loop();

  // get value from receiver
  unsigned long code = fillReceivedCode();

  if (code == 0) {
    return;
  }

  // convert unsigned long to string for MQTT topic
  char cstr[16];
  itoa(code, cstr, 10);

  Serial.println(cstr);

  // set up value in MQTT topic
  setProperty(SW_RECEIVER).send(cstr);

  for (RemoteButton* recPtr : buttonNodes) {
    if (recPtr->handle(code)) {
      break;
    }
  }
}
