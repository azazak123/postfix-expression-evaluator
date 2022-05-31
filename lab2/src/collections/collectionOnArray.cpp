#pragma once
#include "collectionOnArray.h"

template <typename T> CollectionOnArray<T>::CollectionOnArray() {
  this->capacity = 16;
  this->storage = new T[2 * this->capacity];
};

template <typename T>
CollectionOnArray<T>::CollectionOnArray(const size_t capacity) {
  this->capacity = capacity;
  this->storage = new T[2 * capacity];
}

template <typename T>
CollectionOnArray<T>::CollectionOnArray(const CollectionOnArray<T> &s) {
  this->capacity = s.capacity;
  this->size = s.size;
  this->storage = new T[this->capacity];

  for (int i = 0; i < this->size; ++i) {
    this->storage[i] = s.storage[i];
  }
}

template <typename T> CollectionOnArray<T>::~CollectionOnArray() {
  delete[] storage;
}

template <typename T> void CollectionOnArray<T>::push(const T value) {
  size += 1;

  if (size == capacity + 1) {
    capacity *= 2;
    T *new_storage = new T[capacity];
    for (int i = 0; i < size; ++i) {
      new_storage[i] = storage[i];
    }
    delete[] storage;
    storage = new_storage;
  }

  storage[size - 1] = value;
}

template <typename T> Maybe<T> CollectionOnArray<T>::pop() {
  if (size > 0) {
    size -= 1;
    return Maybe<T>::Just(storage[size]);
  } else
    return Maybe<T>::Nothing();
}

template <typename T> size_t CollectionOnArray<T>::len() const { return size; };

template <typename T>
Maybe<bool> CollectionOnArray<T>::set(size_t index, T value) {
  if (index >= size)
    return Maybe<bool>::Nothing();

  storage[index] = value;

  return Maybe<bool>::Just(true);
};

template <typename T>
Maybe<T> CollectionOnArray<T>::operator[](size_t index) const {
  if (index >= size)
    return Maybe<T>::Nothing();
  else
    return Maybe<T>::Just(storage[index]);
}

template <typename T> void CollectionOnArray<T>::clear() { size = 0; }

template <typename T> const T *CollectionOnArray<T>::get_storage() const {
  return storage;
}