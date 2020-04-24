#include "KillConfigNode.h"

#define SW_SWITCH "switch"
#define SW_TRUE "true"
#define SW_FALSE "false"

/**
 * Constructor.
 */
KillConfigNode::KillConfigNode()
    : HomieNode("killconfig", "killconfig", SW_SWITCH),
      propertyInputHandler([&](const HomieRange& range, const String& value) {
        return inputHandler(range, value);
      }) {
  // set up property with method "Switch::inputHandler" as callback
  advertise(SW_SWITCH).settable(propertyInputHandler);
  // switching callback topic is: "homie/livingroom/killconfig/switch/set"
}

/**
 * Input handler method.
 */
bool KillConfigNode::inputHandler(const HomieRange& range,
                                  const String& value) {
  // boolean value is represented by "true" and "false"
  if (value != SW_TRUE && value != SW_FALSE) {
    return false;
  }

  if (value == SW_TRUE) {
    // reset value in MQTT topic
    setProperty(SW_SWITCH).send(SW_FALSE);

    Homie.reset();
    delay(1000);
    ESP.restart();
  }

  return true;
}
