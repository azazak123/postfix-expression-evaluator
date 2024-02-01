#pragma once
#include "collectionOnArray.h"
#include <iostream>
using namespace std;

template <typename T> class Vec : public CollectionOnArray<T> {
public:
  Vec();

  Vec(const size_t);

  Vec(const Vec<T> &);

  template <typename U> friend ostream &operator<<(ostream &, Vec<U> &);

  template <typename U> friend istream &operator>>(istream &, Vec<U> &);

  void print();

  virtual const char *splitter();
};

#include "vec.cpp"