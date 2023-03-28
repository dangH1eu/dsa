#include <iostream>
using namespace std;

void display(int *a, int n) {
  for (int i{0}; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void bubble_sort(int *a, int n) {
  for (int i{0}; i < n - 1; i++) {
    for (int j{0}; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
  }
}

int binary_search(int *a, int left, int right, int key) {
  if (left > right) {
    return -1;
  } else {
    int mid = (left + right) / 2;
    if (a[mid] == key) {
      return mid;
    } else if (a[mid] > key) {
      return binary_search(a, left, mid - 1, key);
    } else {
      return binary_search(a, mid + 1, right, key);
    }
  }
}

int main() {
  int *a;
  int n;
  do {
    cout << "nhap n: ";
    cin >> n;
  } while (n <= 0);

  a = new int[n];
  for (int i{0}; i < n; i++) {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
  cout << "day vua nhap la: " << endl;
  display(a, n);

  cout << "day duoc sap xep la: " << endl;
  bubble_sort(a, n);
  display(a, n);

  int k;
  cout << "nhap k: ";
  cin >> k;

  if (binary_search(a, 0, n - 1, k) == -1) {
    cout << "khong xuat hien trong day";
  } else {
    cout << "co xuat hien trong day tai " << binary_search(a, 0, n - 1, k);
  }
  return 0;
}
