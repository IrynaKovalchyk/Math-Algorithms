#include <iostream>
#include "Array.h"

using namespace std;

template <class T>
void print(T val){
    cout << val << endl;
}



int main() {

    Array<string> array(3);

    array.add("one");
    array.add("two");
    array.add("three");
    array.add("four");
    array.add("five");
    array.add("six");
    array.add("seven");
    array.add("eight");
    array.add("nine");
    array.add("ten");

   // cin >> array;
    array.sort();
    array.remove("three");
    print(array);
    return 0;
}