// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

std::string infx2pstfx(std::string inf) {
  string pst = "";
    stack<char> s;

    for (char c : inf) {
        if (isalnum(c)) {
            pst += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                pst += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                pst += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        pst += s.top();
        s.pop();
    }
  return std::string("");
}

int eval(std::string pref) {
  stack<int> s;

    for (char c : post) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (c) {
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
