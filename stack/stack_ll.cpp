#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

int empty(Node *s) {
  if (s == nullptr) {
    return 1;
  } else {
    return 0;
  }
}
void push(Node *&s, int x) {
  Node *t;
  t = new Node;

  if (t == nullptr) {
    cout << "stack is full\n";
  } else {
    t->data = x;
    t->next = s;
    s = t;
  }
}

int pop(Node *&s) {
  Node *t;
  int x = -1;
  if (empty(s)) {
    cout << "stack is empty\n";
  } else {
    t = s;
    x = t->data;
    s = s->next;
    delete t;
  }
  return x;
}

void display(Node *s) {
  Node *p;
  p = s;
  while (p != nullptr) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}
int main() {
  Node *top = nullptr;

  push(top, 10);
  push(top, 20);
  push(top, 30);

  display(top);

  cout << pop(top);
  return 0;
}
