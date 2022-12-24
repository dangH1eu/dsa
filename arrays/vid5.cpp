#include <iostream>
using namespace std;


class MyArray {
private:
  int length;
  int data[10];

public:
  MyArray() : length{0}, data{0} {};

  int get(int index) { return this->data[index]; }

  int push(int item) {
    this->data[this->length] = item;
    this->length++;
    return this->length;
  }

  void dl(int index) {
    for(int i = this->data[index] - 1; i < this->length; i++){
      this->data[i] = this->data[i + 1];
    }
    this->length--;
  }

  void output(){
    for(int i = 0; i < this->length; i++){
      cout << this->data[i] << "\t";
    }
  }
};

int main() {
  MyArray ar1;

  ar1.push(1);
  ar1.push(2);
  ar1.push(3);
  ar1.push(4);

  ar1.dl(0);

  ar1.output();
  

  return 0;
}
