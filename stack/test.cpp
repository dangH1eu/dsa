#include <iostream>
using namespace std;

const int MAX = 100;
struct Hocsinh {
  int mahs;
  string hoten;
  int tuoi;
  double diemtb;
};

struct Stack {
  Hocsinh e[MAX];
  int top;
};

void init_stack(Stack &s) { s.top = -1; }

int empty(Stack s) {
  if (s.top == -1) {
    return true;
  } else {
    return false;
  }
}

int full(Stack s) {
  if (s.top == MAX - 1) {
    return true;
  } else {
    return false;
  }
}

int push(Stack &s, item x) {
  if (full(s))
    return 0;
  else {
    s.top++;
    s.e[s.top] = x;
    return 1;
  }
}

int pop(Stack &s, item &y) {
  if (empty(s))
    return 0;
  else {
    y = s.e[s.top];
    s.top--;
    return 1;
  }
}
int main() {}
