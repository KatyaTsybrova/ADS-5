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
  std::string pst = "";
    TStack<char, 100> s;

    for (int i = 0; i < inf.length(); i++) {
        if (isalnum(inf[i]) {
            pst += inf[i];
          if (i != inf.length() - 1) {
            pst += " "; 
          }
        } else if (inf[i] == '(') {
            s.push(inf[i]);
        } else if (inf[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                pst += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && checkEl(s.top()) >= checkEl(inf[i])) {
                pst += s.top();
                s.pop();
            }
            s.push(inf[i]);
        }
    }

    while (!s.empty()) {
        pst += s.top();
        s.pop();
    }
  return std::string("");
}

int eval(std::string pref) {
  std::string time = "";
  TStack<int, 100> s;

    for (int i = 0; i < pref.length(); i++) {
        if (isdigit(pref[i])) {
            s.push(pref[i] - '0');
        } else {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (pref[i]) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }
    return s.top();
}
