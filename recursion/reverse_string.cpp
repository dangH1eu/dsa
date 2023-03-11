#include <iostream>
#include <string>
using namespace std;

void reverse(char s[100]){
    static int i = 0;
    cout << s;
    reverse(s[i+1]);
}

int main(){
    return 0;
}

