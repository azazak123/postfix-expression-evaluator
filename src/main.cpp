#include "collections/stack.h"
#include "collections/vec.h"
#include "expression.h"
#include "maybe/maybe.h"
#include <cstdio>
#include <iostream>

int main(int argc, char **argv) {
  Vec<char> str;
  Stack<int> s;

  char command;
  bool run = true;

  while (run) {
    cout << "Commands:" << endl
         << "1:eval" << endl
         << "2:save in file" << endl
         << "3:read from file" << endl
         << "4:clear memory" << endl
         << "5:show  memory" << endl
         << "6:operation with memory" << endl
         << "7:exit" << endl;
    cin >> command;
    switch (command) {
    case '6':
    case '1': {
      str.clear();

      cin >> str;
      cout << "expression:" << str << endl;
      Expression ex = Expression(str, s);

      Maybe<int> ans = ex.eval();
      if (!ans.is_just()) {
        cout << "Bad expression" << endl;
        continue;
      }

      cout << ans.get() << endl;
      break;
    }
    case '2': {
      Vec<char> file;
      cout << "file:";
      cin >> file;
      s.write(file.get_storage());
      break;
    }
    case '3': {
      Vec<char> file;
      cout << "file:";
      cin >> file;

      Stack<int> temp;
      temp.read(file.get_storage());
      s(s.len(), temp.len()) = temp;
      break;
    }
    case '4': {
      s.clear();
      break;
    }
    case '5': {
      cout << s << endl;
      break;
    }
    case '7': {
      run = false;
      break;
    }
    }
  }

  return 0;
}
