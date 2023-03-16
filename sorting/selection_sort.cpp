#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void display(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void selection_sort_ascending(int *a, int n) {
  int i, j, min;

  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    //
    swap(a[i], a[min]);
  }
}

void selection_sort_descending(int *a, int n) {
  int i, j, max;

  for (i = 0; i < n - 1; i++) {
    max = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] > a[max]) {
        max = j;
      }
    }
    swap(a[i], a[max]);
  }
}

int main() {
  int a[]{11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
  int n = 10;

  cout << "day ban dau" << endl;
  display(a, n);

  cout << "day tang dan" << endl;
  selection_sort_ascending(a, n);
  display(a, n);

  cout << "day giam dan" << endl;
  selection_sort_descending(a, n);
  display(a, n);

  return 0;
}
