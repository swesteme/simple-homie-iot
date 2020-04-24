#pragma once

#include <Homie.h>

class Sender;

class Switch : public HomieNode {
 public:
  // constructor
  Switch(Sender* sender, const char* id, const char* name, unsigned long code,
         unsigned long offCode);

 private:
  // common input handler method
  bool inputHandler(const HomieRange& range, const String& value);
  // send method with error handling (repetition)
  void send(const unsigned long code, const char* resetValue);

 private:
  // callback lambda
  const HomieInternals::PropertyInputHandler& propertyInputHandler;
  // sender pointer
  Sender* sender;
  // switch on code
  unsigned long code;
  // switch off code
  unsigned long offCode;
};
