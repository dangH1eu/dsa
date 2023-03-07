#include <iostream>
using namespace std;

void insertion_sort(int *a, int n) {
  int i, j, x;
  for (i = 1; i < n; i++) {
    j = i - 1;
    x = a[i];
    while (j >= 0 && a[j] > x) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = x;
  }
}
int main() {
  int a[]{11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
  int n = 10;

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
  insertion_sort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
