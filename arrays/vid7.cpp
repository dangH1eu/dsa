#include <cstring>
#include <iostream>
#include <string>
using namespace std;

void swap(char &a, char &b) {
  char temp;
  temp = a;
  a = b;
  b = temp;
}

int main() {
  char str[]{"1123"};
  cout << str << endl;
  for (size_t i{0}; i < strlen(str) / 2; i++) {
    swap(str[i], str[strlen(str) - 1 - i]);
  }
  cout << str << endl;

  return 0;
}
