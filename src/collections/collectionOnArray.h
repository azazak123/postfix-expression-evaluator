#pragma once
#include "../maybe/maybe.h"
#include "collection.h"

template <typename T> class CollectionOnArray : public Collection<T> {
protected:
  size_t size = 0;
  size_t capacity = 0;
  T *storage;

public:
  CollectionOnArray();

  CollectionOnArray(const size_t);

  CollectionOnArray(const CollectionOnArray<T> &);

  virtual void push(const T);

  virtual Maybe<T> pop();

  virtual Maybe<T> operator[](size_t) const;

  virtual size_t len() const;

  virtual Maybe<bool> set(size_t, T);

  virtual ~CollectionOnArray();

  virtual void clear();

  virtual const T *get_storage() const;
};

#include "collectionOnArray.cpp"