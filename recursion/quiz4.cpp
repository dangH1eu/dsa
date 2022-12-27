#include <iostream>
using namespace std;
int foo(int n) {
  int x{1}, k;
  if (n == 1)
    return x;
  for (k = 1; k < n; ++k) {
    x = x + foo(k) * foo(n - k);
  }
  return x;
}
int main() {
  cout << foo(5);
  return 0;
}
