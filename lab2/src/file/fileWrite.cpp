#pragma once
#include "fileWrite.h"
#include <bits/types/FILE.h>
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>

inline Maybe<bool> FileWrite::write(const char *filename) {
  unsigned char *data;
  size_t len = serialize(data);

  FILE *myfile = fopen(filename, "wb");

  if (!myfile)
    return Maybe<bool>::Nothing();

  fwrite(data, len, 1, myfile);

  fclose(myfile);

  return Maybe<bool>::Just(true);
}