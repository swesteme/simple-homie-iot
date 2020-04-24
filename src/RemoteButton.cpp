#include "RemoteButton.h"
#include "Receiver.h"

#define SW_STATE "state"

RemoteButton::RemoteButton(Receiver* receiverNode, const char* id,
                           const char* name, unsigned long code)
    : HomieNode(id, id, SW_STATE), code(code) {
  // set up property, state topic is like "homie/livingroom/button1/state"
  advertise(SW_STATE);
  // add own pointer to list of buttons to be handled by receiver
  receiverNode->addButton(this);
}

unsigned long RemoteButton::getCode() const { return code; }

void RemoteButton::updateTopic(const bool state) {
  // set up value in MQTT topic
  setProperty(SW_STATE).send(state ? "ON" : "OFF");
}

bool RemoteButton::handle(unsigned long cmpCode) {
  ResultState checkResult = checkCode(cmpCode);

  if (checkResult == STATE_NO_MATCH) {
    return false;
  }

  updateTopic(checkResult == STATE_ON);

  return true;
}
