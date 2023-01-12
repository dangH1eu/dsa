#include <iostream>
using namespace std;

int main() {
  int arr1[3][4] = {{1, 2, 3, 4}, {2, 12, 11, 11}, {9, 6, 7, 4}};

  cout << "arr1: " << endl;
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      cout << arr1[i][j] << " ";
    }
    cout << endl;
  }

  cout << "arr2: " << endl;
  int *arr2[3];
  arr2[0] = new int[4];
  arr2[1] = new int[4];
  arr2[2] = new int[4];

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      cout << arr2[i][j] << " ";
    }
    cout << endl;
  }

  cout << "arr3: " << endl;
  int **arr3;
  arr3 = new int *[3];
  arr3[0] = new int[4];
  arr3[1] = new int[4];
  arr3[2] = new int[4];

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      cout << arr3[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
