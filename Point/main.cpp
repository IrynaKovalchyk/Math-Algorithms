#include <iostream>
#include <fstream>
#include "Point.h"

using namespace std;

int main() {
    fstream file("../input.txt");
    if (!file.is_open()) {
        cout << "file can`t opened";
        return 0;
    }
    Point center;
    Point result;
    Point checker;
    HoolaHoop hoop;
    file >> center
         >> checker
         >> hoop;
    file.close();
    cout << center;
    cout << checker;
    cout << center;
    cout << result;
    result = center * checker;
    cout << result;
    if (center.belongsTo(hoop)) {
        cout << "Center belongs to hoop!\n";
    }
    else {
        cout << "Center doesn't belong to hoop!\n";
    }
    cout << "f"<<center.findDistanceBetween(checker)<< endl;
    cout << "g"<<center.findDistanceToBegin()<< endl;
    return 0;
}