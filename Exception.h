
#ifndef ARRAY_EXCEPTION_H
#define ARRAY_EXCEPTION_H

#include <iostream>
using namespace std;

class Exceptoin{
private:
    int index;
public:
    Exceptoin(const int &index);
    string what();
};

#endif //ARRAY_EXCEPTION_H
