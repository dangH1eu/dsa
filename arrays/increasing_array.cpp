#include <cstddef>
#include <iostream>
using namespace std;

int main() {
  int *a;
  int *b;
  a = new int[5];
  a[0] = 3;
  a[1] = 5;
  a[2] = 7;
  a[3] = 9;
  a[4] = 11;

  b = new int[10];

  for (int i{0}; i < 5; i++) {
    b[i] = a[i];
  }
  delete[] a;
    a=b;
    b=NULL;
  for (int i{0}; i < 5; i++) {
    cout << a[i] << endl;
  }

  delete[] a;
  // delete []b;
  return 0;
}
