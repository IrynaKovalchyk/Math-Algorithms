#ifndef STACK_STACK_H
#define STACK_STACK_H
//last in, first out
#include "iostream"
using namespace std;

template <typename  Val>
class Stack {
private:
    Val* stack;
    int size;
    int top;

    void increseStack(){
        Val *newStack = new Val [size + 10];
        for(int i =0; i < size; i++){
            newStack[i] = stack[i];
        }
        delete[] stack;
        stack = newStack;
        size += 10;
    }
public:
    Stack() {
        size = 10;
        top = 0;
        stack = new Val[size];
    }
    Stack(int size) : size(size) {
        stack = new Val[size];
        top = 0;
    }

    void push(Val value){
        if(top == size){
            increseStack();
        }
        stack[top++] = value;
    }

    bool isEmpty(){
        return top == 0;
    }


    void pop(){
        if(!isEmpty()){
            top--;
        }
    }

    Val Top(){
        int temp = top;
        return stack[--temp];
    }

    void print (){
        for(int i=0; i<top+2; i++) {
            cout << Top() << " ";
            pop();
        }
    }

};


#endif //STACK_STACK_H
