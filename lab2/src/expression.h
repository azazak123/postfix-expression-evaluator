#pragma once
#include "collections/stack.h"
#include "collections/vec.h"
#include "maybe/maybe.h"

class Expression {
private:
  Vec<char> &expression;
  Stack<int> &memory;

public:
  Expression(Vec<char> &, Stack<int> &);
  virtual Maybe<bool> validate();
  virtual Maybe<int> eval();
};