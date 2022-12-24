#include <iostream>
using namespace std;
int fact(int n) {
  if (n == 0) {
    return 1;
  }
  return fact(n - 1) * n;
}
int Ifact(int n) {
  int f{1};
  int i;
  for (i = 1; i <= n; i++) {
    f *= i;
  }
  return f;
}

int main() {
  int i;
  i = Ifact(8);
  cout << i << endl;
  return 0;
}
