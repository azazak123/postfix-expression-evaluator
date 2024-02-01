#pragma once
#include "stack.h"

template <typename T>
ElementChanger<T>::ElementChanger(size_t _index, Stack<T> *stack) {
  initial_s = stack;
  index = _index;
}

template <typename T> ElementChanger<T> &ElementChanger<T>::operator=(T value) {
  if (!initial_s->set(index, value).is_just())
    initial_s->push(value);
  return *this;
}