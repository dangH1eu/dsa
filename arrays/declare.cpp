#include <iostream>
using namespace std;

int main() {
    int a[5];
    int *p;
    p = new int[5]; 
    delete []p;
  return 0;
}
