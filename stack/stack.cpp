#include <iostream>
using namespace std;

const int MAX = 100;
struct Stack {
  int size = MAX;
  int top;
  int *e;
};

void init_stack(Stack &s) {
  s.top = -1;
  s.e = new int[s.size];
}

int empty(Stack s) {
  if (s.top == -1) {
    return 0;
  } else {
    return 1;
  }
}

int full(Stack s) {
  if (s.top == MAX - 1) {
    return true;
  } else {
    return false;
  }
}

int stack_top(Stack s) {
  if (!empty(s)) {
    return s.e[s.top];
  } else {
    return -1;
  }
}
void display(Stack s) {
  int i;
  for (i = s.top; i >= 0; i--) {
    cout << s.e[i] << " ";
  }
}

int push(Stack &s, int x) {
  if (full(s)) {
    cout << "stack overflow\n";
    return 0;
  } else {
    s.top++;
    s.e[s.top] = x;
    return 1;
  }
}

int pop(Stack &s) {
  int x = -1;
  if (empty(s)) {
    cout << "stack underflow\n";
  } else {
    x = s.e[s.top--];
  }
  return x;
}

int peek(Stack s, int index) {
  int x = -1;
  if (s.top - index + 1 < 0) {
    cout << "invalid index\n";
  }
  x = s.e[s.top - index + 1];
  return x;
}
int main() {
  Stack s;
  init_stack(s);
  push(s, 10);
  push(s, 20);
  push(s, 30);
  push(s, 40);
  push(s, 50);
  push(s, 60);
  cout << peek(s, 1) << endl;
  display(s);
}
