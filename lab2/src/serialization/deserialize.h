#pragma once

class Deserialize {
public:
  virtual void deserialize(const unsigned char *) = 0;
};