#include <iostream>
using namespace std;

void display(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void insertion_sort(int *a, int n) {
  int i, j, tam;
  for (i = 1; i < n; i++) {

    tam = a[i]; // x chua phan tu dang xet
    j = i - 1;

    // di chuyen cac phan tu de tim vi tri chen
    while (j > -1 && a[j] > tam) {
      a[j + 1] = a[j];
      j--;
    }
    // dua phan tu trong x vao vi tri
    a[j + 1] = tam;
  }
}

void insertion_sort_desc(int *a, int n) {
  int i, j, tam;
  for (i = 1; i < n; i++) {

    tam = a[i]; // x chua phan tu dang xet
    j = i - 1;

    // di chuyen cac phan tu de tim vi tri chen
    while (j > -1 && a[j] < tam) {
      a[j + 1] = a[j];
      j--;
    }
    // dua phan tu trong x vao vi tri
    a[j + 1] = tam;
  }
}
int main() {
  int a[]{11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
  int n = 10;

  cout << "day ban dau" << endl;
  display(a, n);

  cout << "sap xep tang dan" << endl;
  insertion_sort(a, n);
  display(a, n);

  cout << "sap xep giam dan" << endl;
  insertion_sort_desc(a, n);
  display(a, n);
  return 0;
}
