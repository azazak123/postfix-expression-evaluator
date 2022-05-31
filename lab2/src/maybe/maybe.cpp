#pragma once
#include "maybe.h"

template <typename T> Maybe<T> Maybe<T>::Just(T value) {
  Maybe<T> m = Maybe();
  m.just = true;
  m.value = value;
  return m;
}

template <typename T> Maybe<T> Maybe<T>::Nothing() {
  Maybe<T> m = Maybe();
  m.just = false;
  T temp;
  m.value = temp;
  return m;
}

template <typename T>
// template <typename U>
Maybe<T> Maybe<T>::fmap(const function<T(T)> f) const {
  if (just)
    return Just(f(value));
  else
    return Nothing();
}

template <typename T> bool Maybe<T>::is_just() const { return just; };

template <typename T> T Maybe<T>::get() const { return value; };

template <typename T> T Maybe<T>::get_or(T _value) const {
  return is_just() ? value : _value;
};