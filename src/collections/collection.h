#pragma once
#include "../maybe/maybe.h"

template <typename T> class Collection {
public:
  virtual void push(const T) = 0;

  virtual Maybe<T> pop() = 0;

  virtual Maybe<T> operator[](size_t) const = 0;

  virtual size_t len() const = 0;

  virtual Maybe<bool> set(size_t, T) = 0;

  virtual void clear() = 0;
};