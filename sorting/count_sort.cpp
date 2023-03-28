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

int find_max(int *a, int n) {
  int max;
  max = a[0];

  for (int i{0}; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

void count_sort_asc(int *a, int n) {
  int i, j, max;
  int *count;

  max = find_max(a, n);
  count = new int[max + 1];
  for (i = 0; i < max + 1; i++) {
    count[i] = 0;
  }

  for (i = 0; i < n; i++) {
    count[a[i]]++;
  }
  i = 0;
  j = 0;
  while (j < max + 1) {
    if (count[j] > 0) {
      a[i] = j;
      count[j]--;
      i++;
    } else {
      j++;
    }
  }
}
int main() {
  int a[]{11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
  int n = 10;

  cout << "day ban dau" << endl;
  display(a, n);

  cout << "sap xep tang dan" << endl;
  count_sort_asc(a, n);
  display(a, n);

  // cout << "sap xep giam dan" << endl;
  // insertion_sort_desc(a, n);
  // display(a, n);

  return 0;
}
