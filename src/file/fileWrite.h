#pragma once
#include "../maybe/maybe.h"
#include "../serialization/serialize.h"
#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;

class FileWrite : public Serialize {
public:
  virtual Maybe<bool> write(const char *);
};

#include "fileWrite.cpp"