#include "Switch.h"
#include "Sender.h"

#define SW_SWITCH "switch"
#define SW_TRUE String("true")
#define SW_FALSE String("false")

/**
 * Constructor.
 */
Switch::Switch(Sender* sender, const char* id, const char* name,
               unsigned long code, unsigned long offCode)
    : HomieNode(id, id, SW_SWITCH),
      propertyInputHandler([&](const HomieRange& range, const String& value) {
        return inputHandler(range, value);
      }),
      sender(sender),
      code(code),
      offCode(offCode) {
  // set up property with method "Switch::inputHandler" as callback
  advertise(SW_SWITCH).settable(propertyInputHandler);
}

/**
 * Input handler method.
 */
bool Switch::inputHandler(const HomieRange& range, const String& value) {
  // boolean value is represented by "true" and "false"
  if (value != SW_TRUE && value != SW_FALSE) {
    return false;
  }

  if (value == SW_TRUE) {
    // send rc control code
    send(code, SW_FALSE.c_str());
  } else {
    // send rc control code
    send(offCode, SW_TRUE.c_str());
  }

  return true;
}

void Switch::send(const unsigned long code, const char* resetValue) {
  // send control code
  if (!sender->send(code)) {
    // set up value in MQTT topic
    setProperty(SW_SWITCH).send(resetValue);
  }
}
