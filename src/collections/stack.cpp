#pragma once
#include "stack.h"
#include "../file/fileRead.h"
#include "../file/fileWrite.h"
#include "collectionOnArray.h"
#include <cmath>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;

template <typename T> Stack<T>::Stack() : CollectionOnArray<T>(){};

template <typename T>
Stack<T>::Stack(const size_t capacity) : CollectionOnArray<T>(capacity){};

template <typename T>
Stack<T>::Stack(const Stack<T> &s) : CollectionOnArray<T>(s){};

template <typename T> size_t Stack<T>::serialize(unsigned char *&data) const {
  data = new unsigned char[sizeof(this->size) + sizeof(T) * this->size];

  for (int i = 0; i < sizeof(this->size); i++) {
    unsigned char byte = *((unsigned char *)&this->size + i);
    data[i] = byte;
  }

  for (int i = 0; i < sizeof(T) * this->size; i++) {
    data[i + sizeof(this->size)] = *((unsigned char *)this->storage + i);
  }

  return sizeof(this->size) + sizeof(T) * this->size;
};

template <typename T> void Stack<T>::deserialize(const unsigned char *data) {
  size_t len = *(size_t *)(data);
  this->storage = new T[len];
  this->capacity = len;

  for (int i = 0; i < len; i++) {
    T element = *(T *)(data + sizeof(this->size) + sizeof(T) * i);
    this->push(element);
  }
};

template <typename T> Stack<T> &Stack<T>::operator=(Stack<T> &s) {
  this->capacity = s.capacity;
  this->size = s.size;
  if (this->storage)
    delete[] this->storage;
  this->storage = new T[this->capacity];
  for (int i = 0; i < this->size; ++i) {
    this->storage[i] = s.storage[i];
  }

  return *this;
}

template <typename T> T Stack<T>::operator->() { return this->storage; }

template <typename T> ostream &operator<<(ostream &out, Stack<T> &s) {
  for (int i = 0; i < s.size && s[i].is_just(); i++) {
    out << s[i].get();
    if (i + 1 != s.size)
      out << " <- ";
  }
  return out;
};

template <typename T> istream &operator>>(istream &in, Stack<T> &s) {
  size_t size;
  in >> size;

  for (int i = 0; i < size; i++) {
    T value;
    in >> value;
    s.push(value);
  }

  return in;
};

template <typename T> ElementChanger<T> Stack<T>::operator()(size_t index) {

  return ElementChanger<T>(index, this);
}

template <typename T>
ElementChangerStack<T> Stack<T>::operator()(size_t index, size_t size) {

  return ElementChangerStack<T>(index, size, this);
}

template <typename T> void Stack<T>::print() { cout << *this; }