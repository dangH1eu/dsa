#include <iostream>
using namespace std;
int sum(int n) {
  if (n == 0)
    return 0;
  return sum(n - 1) + n;
}

int iSum(int n) {
  int s{0};
  int i;
  for (i = 1; i <= n; i++) {
    s += i;
  }
  return s;
}

int main() {
  int i;
  i = iSum(5);
  cout << i << " ";
  return 0;
}
