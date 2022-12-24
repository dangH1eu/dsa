#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<char> strings{'a', 'b', 'c', 'd'};

  // push_back
  strings.push_back('e');

  // pop_back
  strings.pop_back();
  strings.pop_back();


  strings.insert(strings.begin(), 'x');

  strings.insert(strings.begin() + 2, 'l');
  for (unsigned int i = 0; i < strings.size(); i++) {
    cout << strings[i] << "\t";
  }

  return 0;
}
