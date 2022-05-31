#pragma once
#include "stack.h"

template <typename T>
ElementChangerStack<T>::ElementChangerStack(size_t _index, size_t _size,
                                            Stack<T> *stack) {
  size = _size;
  index = _index;
  initial_s = stack;
}

template <typename T>
ElementChangerStack<T> &ElementChangerStack<T>::operator=(Stack<T> s) {
  for (int i = 0; i < size && s[i].is_just(); ++i) {
    if (i + index == initial_s->len()) {
      initial_s->push(s[i].get());
    } else {
      initial_s->set(i + index, s[i].get());
    }
  }
  return *this;
}