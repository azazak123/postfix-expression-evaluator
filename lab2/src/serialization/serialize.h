#pragma once

#include <cmath>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
class Serialize {
public:
  virtual size_t serialize(unsigned char *&) const = 0;
};
