#include <iostream>
using namespace std;

int fact(int n) {
  if (n == 0)
    return 1;
  return fact(n - 1) * n;
}

int nCr(int n, int r) {
  int num, den;
  num = fact(n);
  den = fact(r) * fact(n - r);
  return num / den;
}

int recursive_nCr(int n, int r) {
  if (n == r || r == 0)
    return 1;
  return recursive_nCr(n - 1, r - 1) + recursive_nCr(n - 1, r);
}
int main() {
  cout << nCr(5, 4) << endl;
  cout << recursive_nCr(5, 4) << endl;
  return 0;
}
