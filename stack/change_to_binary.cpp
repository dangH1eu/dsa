#include <iostream>
using namespace std;

const int MAX = 100;
struct Stack {
  int e[MAX];
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

int push(Stack &s, int x) {
  if (full(s))
    return 0;
  else {
    s.top++;
    s.e[s.top] = x;
    return 1;
  }
}

int pop(Stack &s, int &x) {
  if (empty(s))
    return 0;
  else {
    x = s.e[s.top];
    s.top--;
    return 1;
  }
}

void change_to_binary(Stack &s, unsigned long n) {
  int r;
  do {
    r = n % 2;
    n = n / 2;
  } while (push(s, r) && n > 0);
}

void display(Stack s) {
  int r;
  cout << "\nma nhi phan: ";
  while (pop(s, r)) {
    cout << r;
  }
  cout << endl;
}
int main() {
  unsigned long n;
  Stack s;
  init_stack(s);
  cout << "nhap n: ";
  cin >> n;
  change_to_binary(s, n);
  display(s);
}
