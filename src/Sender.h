#pragma once

// Abstract sender class to be implemented by sub-libraries. Sender objects are
// used in combination with switches.
class Sender {
 public:
  // pure virtual factory method
  virtual bool send(const unsigned long code) = 0;
};
