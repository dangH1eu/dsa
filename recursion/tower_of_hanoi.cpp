#include <iostream>
using namespace std;

// tower a, tower b, tower c
void toh(int n, int a, int b, int c) {
  if (n > 0) {
    toh(n - 1, a, c, b);
    cout << "(" << a << ", " << c << ")" << endl;
    toh(n - 1, b, a, c);
  }
}
int main() {
  toh(3, 1, 2, 3);
  return 0;
}
