#include <iostream>
using namespace std;

void display(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void merge(int *a, int low, int mid, int high) {
  int i, j, k;
  i = low;
  j = mid + 1;
  k = low;
  int b[100];

  while (i <= mid && j <= high) {
    if (a[i] < a[j]) {
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];
    }
  }

  for (; i <= mid; i++) {
    b[k++] = a[i];
  }
  for (; j <= high; j++) {
    b[k++] = a[j];
  }

  for (int i = low; i <= high; i++) {
    a[i] = b[i];
  }
}

void iterative_merge_sort(int *a, int n) {
  int p;
  int low;
  int high;
  int mid;
  int i;
  for (p = 2; p <= n; p = p * 2) {
    for (i = 0; i + p - 1 <= n; i = i + p) {
      low = i;
      high = i + p - 1;
      mid = (low + high) / 2;
      merge(a, low, mid, high);
    }
  }
  if (p / 2 < n) {
    merge(a, 0, p / 2 - 1, n);
  }
}

void recursive_merge_sort(int *a, int low, int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    recursive_merge_sort(a, low, mid);
    recursive_merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}
int main() {
  int a[]{11, 13, 7, 2, 6, 9, 4, 5, 10, 3, 1};
  int n = 11;

  // display(a, n);
  // iterative_merge_sort(a, n);
  // display(a, n);

  display(a, n);
  iterative_merge_sort(a, n);
  display(a, n);
  return 0;
}
