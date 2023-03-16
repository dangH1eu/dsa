#include <cstdint>
#include <iostream>
using namespace std;

void display(int *a, int n) {
  for (int i = 0; i < n; i++) {
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

int partition(int *a, int low, int high) {
  int pivot = a[low];
  int i, j;
  i = low;
  j = high;

  do {
    do {
      i++;
    } while (a[i] <= pivot);

    do {
      j--;
    } while (a[j] > pivot);

    if (i < j) {
      swap(a[i], a[j]);
    }
  } while (i < j);
  swap(a[low], a[j]);
  return j;
}

void quick_sort(int *a, int low, int high) {
  int j;
  if (low < high) {
    j = partition(a, low, high);
    quick_sort(a, low, j);
    quick_sort(a, j + 1, high);
  }
}

int main() {
  int a[]{11, 13, 7, 2, 6, 9, 4, 5, 10, 3, INT32_MAX};
  int n = 11;

  display(a, n - 1);
  quick_sort(a, 0, n - 1);
  display(a, n - 1);
  return 0;
}
