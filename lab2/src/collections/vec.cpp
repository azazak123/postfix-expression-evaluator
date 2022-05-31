#pragma once
#include "vec.h"

template <typename T> Vec<T>::Vec() : CollectionOnArray<T>(){};

template <typename T>
Vec<T>::Vec(const size_t capacity) : CollectionOnArray<T>(capacity){};

template <typename T> Vec<T>::Vec(const Vec<T> &s) : CollectionOnArray<T>(s){};

template <typename T> const char *Vec<T>::splitter() { return ", "; };

template <typename T> ostream &operator<<(ostream &out, Vec<T> &s) {
  out << "[";
  for (int i = 0; i < s.size && s[i].is_just(); i++) {
    out << s[i].get();
    if (i + 1 != s.size)
      out << s.splitter();
  }
  out << "]";
  return out;
};

template <typename T> istream &operator>>(istream &in, Vec<T> &s) {
  char c;
  T temp;

  in >> temp;
  s.push(temp);
  while (in.peek() != '\n') {
    char t = in.peek();
    in >> temp;
    s.push(temp);
  }

  return in;
};
