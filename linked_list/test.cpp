#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
} ;

// typedef Node *Tro ;
Node *L;

void init(Node *&L){
    L = nullptr;
}

int empty(Node *L){
    return (L==nullptr);
}

void travel(Node *L){
    Node *Q;
    if(!empty(L)){
        Q = L;
        while(Q != nullptr){

        }
    }
}

int main(){
    return 0;
}
