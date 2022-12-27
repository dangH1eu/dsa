#include <iostream>
using namespace std;

double e(int x, int n) {
  double s = 1;
  int i;
  double tu = 1;
  double mau = 1;
  for (i = 1; i <= n; i++) {
    tu *= x;
    mau *= i;
    s += tu / mau;
  }
  return s;
}

int main() {
  cout << e(1, 10) << endl;
  return 0;
}
