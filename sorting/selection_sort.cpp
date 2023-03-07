#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void selection_sort(int *a, int n) {
  int i, j, m;

  for (i = 0; i < n - 1; i++) {
    m = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[m]) {
        m = j;
      }
      swap(a[i], a[m]);
    }
  }
}
int main() {
  int a[]{11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
  int n = 10;

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
  selection_sort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
