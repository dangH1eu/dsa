#include <iostream>
using namespace std;

void display(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void insertion_sort(int *a, int n) {
  int i, j, x;
  for (i = 1; i < n; i++) {

    j = i - 1;
    x = a[i]; // x chua phan tu dang xet

    // di chuyen cac phan tu de tim vi tri chen
    while (j >= 0 && a[j] > x) {
      a[j + 1] = a[j];
      j--;
    }
    // dua phan tu trong x vao vi tri
    a[j + 1] = x;
  }
}
int main() {
  int a[]{11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
  int n = 10;

  cout << "day ban dau" << endl;
  display(a, n);

  cout << "day sau khi sap xep" << endl;
  insertion_sort(a, n);
  display(a, n);
  return 0;
}
