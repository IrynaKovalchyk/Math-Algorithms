#include <iostream>
using namespace std;

#include "LinkedList.h"

template <class T>
void print(T val){
    cout << val << endl;
}


int main() {
    LinkedList<int> linkedList;

    linkedList.add(2);
    linkedList.add(3);
    linkedList.add(4);
    cout << linkedList << endl;


    return 0;
}