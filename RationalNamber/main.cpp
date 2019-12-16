#include <iostream>
#include <fstream>
#include "RationalNum.h"
#include <iterator>

using  namespace std;

int global_size = 0;

void sort(RationalNumber * arrayOfRationals, int size){
    for(int i = 0; i < size; i++){
        for(int j =0; j < size - i - 1; j++){
            if(arrayOfRationals[j] > arrayOfRationals[j+1]){
                swap(arrayOfRationals[j],arrayOfRationals[j+1]);
            }
        }
    }
}

RationalNumber* readFromFile(){
    ifstream file("../input.txt");
    if(!file.is_open()){
        cout << "Wrong path" << endl;
        return nullptr;
    }
    int size;
    file >> size;
    global_size = size;
    RationalNumber* numbers = new RationalNumber[size];

    for(int i=0 ;i<size; i++){
        file >> numbers[i];
    }

    return numbers;
}

int main() {
    RationalNumber * arrayOfRationals = readFromFile();

    int size = global_size;

    cout << "Mass unsorted: " << endl;
    for (int i = 0; i < size ; ++i) {
        cout << arrayOfRationals[i];
    }

    sort(arrayOfRationals, size);


    cout << endl;
    cout << "Mass sorted: " <<endl;
    for (int i = 0; i < size ; ++i) {
        cout << arrayOfRationals[i];
    }


    RationalNumber summ(0, 0);
    for (int i = 1; i < size - 1; i++){
        summ = summ + arrayOfRationals[i];
    }

    cout << endl;
    cout << "Summ is: " << summ << endl;

    RationalNumber toMult(3,2);

    for(int i=0 ;i<size; i++){
        if(i%2 == 0){
            arrayOfRationals[i] = arrayOfRationals[i] * toMult;
        }
        if(i%2 != 0){
            arrayOfRationals[i] = arrayOfRationals[i] / toMult;
        }
    }

    cout << "Mass after operations on 3/2: " <<endl;
    for (int i = 0; i < size ; ++i) {
        cout << arrayOfRationals[i];
    }


    return 0;
}