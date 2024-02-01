#pragma once
#include "../maybe/maybe.h"
#include "../serialization/deserialize.h"
#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;

class FileRead : Deserialize {
public:
  virtual Maybe<bool> read(const char *);
};

#include "fileRead.cpp"