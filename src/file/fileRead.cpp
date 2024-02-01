#pragma once
#include "fileRead.h"
#include "../maybe/maybe.h"
#include <cstddef>
#include <cstdio>
#include <fstream>

inline Maybe<bool> FileRead::read(const char *filename) {
  FILE *myfile = fopen(filename, "rb");

  if (!myfile)
    return Maybe<bool>::Nothing();

  int len = 0;
  while (fgetc(myfile) != EOF) {
    len += 1;
  }

  fseek(myfile, 0, SEEK_SET);

  unsigned char *data = new unsigned char[len];
  fread(data, len, 1, myfile);
  fclose(myfile);

  this->deserialize(data);

  return Maybe<bool>::Just(true);
}