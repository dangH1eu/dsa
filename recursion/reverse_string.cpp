#include <cstring>
#include <iostream>
#include <string>
using namespace std;

void reverse(char *str) {
  if (*str == '\0') {
    return;
  } else {
    reverse(str + 1);
    cout << *str;
  }
}

void reverse2(string str) {
  if (str.size() == 0) {
    return;
  }
  reverse2(str.substr(1));
  cout << str[0];
}
int main() {
  // char str[100];
  // cout << "nhap chuoi: ";
  // cin.getline(str, 255);
  // reverse(str);

  string str2;
  cout << "nhap chuoi: ";
  fflush(stdin);
  getline(cin, str2);

  reverse2(str2);

  return 0;
}
