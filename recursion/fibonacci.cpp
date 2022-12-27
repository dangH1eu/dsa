#include <iostream>
using namespace std;
int fibonacci(int n) {
  int f0{0}, f1{1}, s{0}, i;
  if (n <= 1) {
    return n;
  }
  for (i = 2; i <= n; i++) {
    s = f0 + f1;
    f0 = f1;
    f1 = s;
  }
  return s;
}

int recursive_fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return recursive_fibonacci(n - 2) + recursive_fibonacci(n - 1);
}

int arr[10];

int memoization_fibonacci(int n) {
  if (n <= 1) {
    arr[n] = n;
    return n;
  } else {
    if (arr[n - 2] == -1) {
      arr[n - 2] = memoization_fibonacci(n - 2);
    }
    if (arr[n - 1] == -1) {
      arr[n - 1] = memoization_fibonacci(n - 1);
    }
    return arr[n - 2] + arr[n - 1];
  }
}

int main() {

  for (int i{0}; i < 10; i++) {
    arr[i] = -1;
  }
  cout << fibonacci(8) << endl;
  cout << recursive_fibonacci(8) << endl;
  cout << memoization_fibonacci(8) << endl;
  return 0;
}
