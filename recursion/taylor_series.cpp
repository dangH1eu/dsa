#include <iostream>
using namespace std;

double taylor(int x, int n) {
  static double tu{1}, mau{1};
  double i;
  if (n == 0) {
    return 1;
  }
  i = taylor(x, n - 1);
  tu *= x;
  mau *= n;
  return i + tu / mau;
}

int main() {
  cout << taylor(4, 10) << endl;
  return 0;
}
