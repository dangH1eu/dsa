#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *first{nullptr};

void create(int *a, int n) {
  int i;
  Node *t, *last;

  first = new Node;

  first->data = a[0];
  first->next = nullptr;

  last = first;

  for (i = 1; i < n; i++) {

    t = new Node;

    t->data = a[i];
    t->next = nullptr;

    last->next = t;
    last = t;
  }
}

void display(Node *p) {
  while (p != nullptr) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int count(Node *p) {
  int l{0};
  while (p) {
    l++;
    p = p->next;
  }
  return l;
}

int sum(Node *p) {
  int s{0};
  while (p != nullptr) {
    s += p->data;
    p = p->next;
  }
  return s;
}

int user_max(Node *p) {
  int max = p->data;

  while (p) {
    if (p->data > max) {
      max = p->data;
    }
    p = p->next;
  }
  return max;
}

Node *search(Node *p, int key) {
  Node *q;

  while (p != nullptr) {
    if (key == p->data) {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return nullptr;
}

void insert(Node *p, int index, int x) {

  Node *t;
  int i;

  if (index < 0 || index > count(p)) {
    return;
  }
  t = new Node;
  t->data = x;

  if (index == 0) {
    t->next = first;
    first = t;
  } else {
    for (i = 0; i < index - 1; i++) {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

void sorted_insert(Node *p, int x) {
  Node *t, *q;
  q = nullptr;

  t = new Node;
  t->data = x;
  t->next = nullptr;

  if (first == nullptr) {
    first = t;
  } else {
    while (p && p->data < x) {
      q = p;
      p = p->next;
    }
    if (p == first) {
      t->next = first;
      first = t;
    } else {
      t->next = q->next;
      q->next = t;
    }
  }
}
int main() {
  // Node *temp;
  int a[]{10, 20, 30, 40, 50};

  // count array elements
  // int n;
  // n = sizeof(a) / sizeof(a[0]);

  //
  create(a, 5);
  display(first);
  // cout << "\nlength is " << count(first) << endl;
  // cout << "sum is " << sum(first) << endl;
  // cout << "max is " << user_max(first) << endl;

  // temp = search(first, 15);
  // if (temp) {
  //   cout << "key is found " << temp->data << endl;
  // } else {
  //   cout << "key is not found " << endl;
  // }
  // display(first);

  // insert at 0
  // insert(first, 0, 10);
  // display(first);

  // insert at last element
  // insert(first, 9, 100);
  // display(first);

  sorted_insert(first, 15);
  display(first);
  return 0;
}
