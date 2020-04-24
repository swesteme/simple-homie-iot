#pragma once

#include <Homie.h>
#include <vector>

class RemoteButton;

class Receiver : public HomieNode {
  public:
    // constructor
    Receiver(const char* id, const char* name);

    // check, whether this instance handles the code (and handle it)
    bool handle(unsigned long cmpCode);

    // add a new button to list of buttons
    void addButton(RemoteButton *button);

  protected:
    virtual unsigned long fillReceivedCode() = 0;

    // handle incoming values and loop over all receivers
    virtual void loop();
  private:
    void updateTopic(const bool state);
  
    // list of button nodes
    std::vector<RemoteButton*> buttonNodes;
};

