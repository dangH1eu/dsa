#include <iostream>
using namespace std;

int power(int m, int n) {
  if (n == 0)
    return 1;
  return power(m, n - 1) * m;
}

int uPower(int m, int n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return uPower(m * m, n / 2);
  } else {
    return m * uPower(m * m, (n - 1) / 2);
  }
}
int main() {
  int i = uPower(3, 10);
  cout << i << endl;
  return 0;
}
