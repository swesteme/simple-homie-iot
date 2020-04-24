#pragma once

#include <Homie.h>

class KillConfigNode : public HomieNode {

  public:
    // constructor
    KillConfigNode();

  private:
    // common input handler method
    bool inputHandler(const HomieRange& range, const String& value);

  private:
    // callback lambda
    const HomieInternals::PropertyInputHandler& propertyInputHandler;
};

