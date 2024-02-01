#pragma once
#include "../file/fileRead.h"
#include "../file/fileWrite.h"
#include "collectionOnArray.h"
#include <cstddef>
#include <iostream>
using namespace std;

template <typename T> class ElementChanger;
template <typename T> class ElementChangerStack;

template <typename T>
class Stack : public FileWrite, public FileRead, public CollectionOnArray<T> {
public:
  Stack();

  Stack(const size_t);

  Stack(const Stack<T> &);

  T operator->();

  Stack<T> &operator=(Stack<T> &);

  virtual size_t serialize(unsigned char *&) const;

  virtual void deserialize(const unsigned char *);

  template <typename U> friend ostream &operator<<(ostream &, Stack<U> &);

  template <typename U> friend istream &operator>>(istream &, Stack<U> &);

  ElementChanger<T> operator()(size_t);

  ElementChangerStack<T> operator()(size_t, size_t);

  void print();
};

template <typename T> class ElementChanger {
private:
  size_t index;
  Stack<T> *initial_s;

public:
  ElementChanger<T>(size_t, Stack<T> *);
  ElementChanger<T> &operator=(T);
};

template <typename T> class ElementChangerStack {
private:
  size_t index;
  size_t size;
  Stack<T> *initial_s;

public:
  ElementChangerStack<T>(size_t, size_t, Stack<T> *);
  ElementChangerStack<T> &operator=(Stack<T>);
};

#include "elementChanger.cpp"
#include "elementChangerStack.cpp"
#include "stack.cpp"