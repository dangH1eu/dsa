#include <iostream>
using namespace std;
int func(int n) {
  if (n > 100) {
    return n - 10;
  }
  return func(func(n + 11));
}

int main() {
  int i;
  i = func(100);
  cout << i << " ";
  return 0;
}
