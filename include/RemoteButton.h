#pragma once

#include <Homie.h>

class Receiver;

typedef enum matchResult {
  STATE_NO_MATCH, STATE_ON, STATE_OFF
} ResultState;

class RemoteButton : public HomieNode {
  public:
    // constructor
    RemoteButton(Receiver *receiverNode, const char* id, const char* name, unsigned long code);

    // check, whether this instance handles the code (and handle it)
    bool handle(unsigned long cmpCode);

    // get configured code for this button
    unsigned long getCode() const;

  protected:
    virtual ResultState checkCode(unsigned long cmpCode) const = 0;

  private:
    void updateTopic(const bool state);
    // switch code
    unsigned long code;
};


