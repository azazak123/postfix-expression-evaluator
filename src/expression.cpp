#include "expression.h"

Expression::Expression(Vec<char> &_expression, Stack<int> &_memory)
    : expression(_expression), memory(_memory){};

Maybe<bool> Expression::validate() {
  char op = expression[expression.len() - 1].get();
  if (op != '+' && op != '-' && op != '*' && op != '/') {
    return Maybe<bool>::Nothing();
  } else {
    return Maybe<bool>::Just(true);
  }
};

Maybe<int> Expression::eval() {
  if (!validate().is_just())
    return Maybe<int>::Nothing();

  int numbers = 0;

  bool op = false;

  for (int i = 0; i < expression.len(); i++) {
    switch (expression[i].get()) {
    case '+': {
      int a2 = memory.pop().get_or(0);
      int a1 = memory.pop().get_or(0);
      memory.push(a1 + a2);
      numbers = 0;
      op = true;
      break;
    }
    case '-': {
      int a2 = memory.pop().get_or(0);
      int a1 = memory.pop().get_or(0);
      memory.push(a1 - a2);
      numbers = 0;
      op = true;
      break;
    }
    case '*': {
      int a2 = memory.pop().get_or(1);
      int a1 = memory.pop().get_or(1);
      memory.push(a1 * a2);
      numbers = 0;
      op = true;
      break;
    }
    case '/': {
      int a2 = memory.pop().get_or(1);
      int a1 = memory.pop().get_or(1);
      memory.push(a1 / a2);
      numbers = 0;
      op = true;
      break;
    }
    default:
      numbers += 1;
      if (numbers > 2 || (op && numbers > 1)) {
        int index = memory.len() - 1;
        memory.set(index, memory[index].get() * 10 + expression[i].get() - '0');
        numbers = 2;
        continue;
      }
      memory.push(expression[i].get() - '0');
    }
  }

  return Maybe<int>::Just(memory[memory.len() - 1].get());
}