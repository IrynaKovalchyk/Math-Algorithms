#include <iostream>
#include "Stack.h"

int main() {
    Stack <int> stack ;
    stack.push(1);
    stack.push(2);
    stack.push(10);
    stack.pop();
    stack.print();
    cout << stack.Top() << endl;
    return 0;
}