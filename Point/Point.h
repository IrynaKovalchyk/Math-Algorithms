#ifndef HUITAZTOCHKAMU_POINT_H
#define HUITAZTOCHKAMU_POINT_H

#include <iostream>
#include <limits.h>
#include "HoolaHoop.h"

class HoolaHoop;

using namespace std;

class Point {
private:
    int amountCoordinates;
    double *array;
    string name;
public:
    Point();
    Point(const Point &point);
    Point(const string &name);
    Point(int amountCoordinates);
    Point(int amountCoordinates, double *array);
    Point(int amountCoordinates, const string &name);
    Point(int amountCoordinates, double *array, const string &name);

    int getAmountCoordinates() const;
    void setAmountCoordinates(int amountCoordinates);
    double *getArray() const;
    void setArray(double *array);
    const string &getName() const;
    void setName(const string &name);

    bool checkForEqualAmountOfCoor(Point point);
    double findDistanceToBegin();
    double findDistanceBetween(const Point &point);

    friend istream &operator>>(istream &is, Point &point);
    friend ostream &operator<<(ostream &os, Point &point);

    Point operator+(const Point &pointToAdd);
    Point operator*(const Point &pointToMul);
    Point operator=(const Point &pointToAssign);

    bool operator<(Point &pointToCheck);
    bool operator>(Point &pointToCheck);
    bool belongsTo(HoolaHoop hoop);

    virtual ~Point();
};

#endif //HUITAZTOCHKAMU_POINT_H