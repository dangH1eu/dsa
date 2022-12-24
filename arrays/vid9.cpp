#include <iostream>
using namespace std;

void mergeArr(int *c, int *a, int *b, int &k) {
  k = 0;
  for (int i{0}; i < 3; i++) {
    c[k] = a[i];
    k++;
  }
  for (int i{0}; i < 3; i++) {
    c[k] = b[i];
    k++;
  }
}

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void sortArr(int *a, int k) {
  for (int i{0}; i < k - 1; i++) {
    for (int j = i + 1; j < k; j++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
}

int main() {
  int k;
  int a[100]{29, 13, 24};
  int b[100]{1, 5, 2};
  int c[100];

  for (int i{0}; i < 3; i++) {
    cout << a[i] << "\t";
  }
  cout << endl;
  for (int i{0}; i < 3; i++) {
    cout << b[i] << "\t";
  }
  mergeArr(c, a, b, k);

  cout << endl;
  for (int i{0}; i < k; i++) {
    cout << c[i] << "\t";
  }
  sortArr(c, k);
  cout << endl;
  for (int i{0}; i < k; i++) {
    cout << c[i] << "\t";
  }
  return 0;
}
