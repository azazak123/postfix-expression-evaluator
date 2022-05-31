#pragma once
#include "functor.h"

template <typename T> class Maybe : public Functor<T, Maybe<T>> {
private:
  T value;
  bool just;

public:
  bool is_just() const;
  static Maybe<T> Just(T);
  static Maybe<T> Nothing();
  Maybe<T> fmap(const function<T(T)>) const;
  T get() const;
  T get_or(T value) const;
};

#include "maybe.cpp"