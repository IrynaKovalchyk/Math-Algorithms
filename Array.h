#ifndef EXCEPTIONSLESSON_DYNAMICARRAY_H
#define EXCEPTIONSLESSON_DYNAMICARRAY_H

#include <iostream>
#include "Exception.h"

using namespace std;

template <typename Val>
class Array {
private:
    Val* array;
    int size;
    int counter;
    void increaseArray(){
        Val *newArray = new Val [size + 10];
        for (int j = 0; j < size ; j++) {
            newArray[j] = array[j];
        }
        delete[](array);
        array = newArray;
        size += 10;
    }

public:
    Array(){
        counter = 0;
        size = 10;
        array = new Val[size];
    }

    Array(int size) : size(size){
        array = new Val[size];
        counter = 0;
    }

    void add(Val val){
        if(counter == size){
            increaseArray();
        }
        array[counter++] = val;
    }

    void remove(Val delElement){
        for (int i = 0; i < counter; i++ ){
            if (delElement == array[i]) {
                for (int j = i; j < counter; j++){
                    array[j] = array[j+1];
                }
            }
        }
        counter --;
    }



    void sort(){
        for(int i = 0; i < counter; i++){
            for(int j =0; j < counter - i - 1; j++){
                if(array[j] > array[j+1]){
                    swap(array[j],array[j+1]);
                }
            }
        }
    }

    Val& operator[](int index){
        if(index > counter || index < 0){
            throw Exceptoin(index);
        }
        return array[index];
    }

    friend ostream&operator<<(ostream& output, Array& array){
        for(int i = 0; i < array.counter; i++){
            output << array.array[i] << " ";
        }
        output << endl;
        return output;
    }

    friend istream&operator>>(istream& input, Array& array){
        Val temp;
        int t_size;
        cout << "Enter size: ";
        input >> t_size;
        for (int i = 0; i < t_size; i++){
            input  >> temp;
            array.add(temp);
        }
        return input;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool operator < (Array & right){
        return size < right.size;
    };
};

#endif //EXCEPTIONSLESSON_DYNAMICARRAY_H