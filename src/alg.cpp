// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

static int checkEl(char el) {
  if (el == '(') {
    return 0;
  } else if (el == ')') {
    return 1;
  } else if ((el == '+') || (el == '-')) {
    return 2;
  } else if ((el == '*') || (el == '/')) {
    return 3;
  } else {
    throw "Unknown Symbol!";
  }
}

std::string infx2pstfx(std::string inf) {
  std::string postfix = "";
  TStack<char, 100> s;

  for (int i = 0; i < inf.length(); i++) {
    if (isdigit(inf[i])) {
      postfix += inf[i];
      if (i != inf.length() - 1) {
        postfix += " ";
      }
    } else if (inf[i] == '(') {
      s.push(inf[i]);
    } else if (s.empty()) {
      s.push(inf[i]);
    } else if (inf[i] == ')') {
      if (s.empty()) {
        break;
      } else if (s.top() == '(') {
        break;
      }
      postfix += s.top();
      s.pop();
      if (i != inf.length() - 1) {
        postfix += " ";
      }
    }
    s.pop();
  } else if (checkEl(inf[i]) > checkEl(s.top())) {
    s.push(inf[i]);
  } else {
    while (true) {
      if (s.empty()) {
        break;
      } else if (!(checkEl(inf[i]) <= checkEl(s.top()))) {
        break;
      }
      postfix += s.top();
      s.pop();
      if (i != inf.length() - 1) {
        postfix += " ";
      }
    }
    s.push(inf[i]);
  }
}
while (!s.empty()) {
  postfix += " ";
  postfix += s.top();
  s.pop();
}
return postfix;            
}

int eval(std::string pref) {
  std::string time = "";
  TStack<int, 100> operands;

  for (int i = 0; i < pref.length(); i++) {
    if (isdigit(pref[i])) {
      time += pref[i];
    } else if (time.length() && pref[i] == ' ') {
      ints.push(atoi(time.c_str()));
      time = "";
    } else {
      switch (pref[i]) {
        case '+': {
          int two = operands.pop();
          int one = operands.pop();
          operands.push(one + two);
          break;
        }
        case '-': {
          int two = operands.pop();
          int one = operands.pop();
          operands.push(one - two);
          break;
        }
        case '*': {
          int two = operands.pop();
          int one = operands.pop();
          operands.push(one * two);
          break;
        }
        case '/': {
          int two = operands.pop();
          int one = operands.pop();
          operands.push(one / two);
          break;
        }
      }
    }
  }
  return operands.pop();
}
