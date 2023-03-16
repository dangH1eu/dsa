#include <iostream>
using namespace std;

template <typename T> void func_swap(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

void bubble_sort(int *a, int n) {
  int flag;
  int i, j;

  for (i = 0; i < n - 1; i++) {
    flag = 0;
    for (j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        func_swap<int>(a[j], a[j + 1]);
        flag = 1;
      }
    }
    //
    if (flag == 0) {
      break;
    }
  }
}

void bubble_sort_2(int *a, int n) {
  int i, j;
  int flag;

  for (i = 0; i < n - 1; i++) {
    flag = 0;
    for (j = n - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        func_swap<int>(a[j], a[j - 1]);
        flag = 1;
      }
    }

    if (flag == 0) {
      break;
    }
  }
}

void display(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int a[]{3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
  int n = 10;
  int b[]{4, 8, 10, 5, 12};
  int m = 5;
  // int a[]{3, 7, 9, 10};
  // int n = 4;

  display(a, n);
  bubble_sort(a, n);
  display(a, n);

  display(b, m);
  bubble_sort_2(b, m);
  display(b, m);

  return 0;
}
