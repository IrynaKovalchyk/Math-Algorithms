#include <cmath>
#include "Point.h"

Point::Point() : amountCoordinates(0), name(""){}
Point::Point(const string &name) : name(name) {}
Point::Point(int amountCoordinates) : amountCoordinates(amountCoordinates) {
    array = new double[amountCoordinates];
}
Point::Point(int amountCoordinates, double *array) : amountCoordinates(amountCoordinates) {
    Point::array = new double[amountCoordinates];
    for (int i = 0; i < amountCoordinates; i++) {
        Point::array[i] = array[i];
    }
}
Point::Point(int amountCoordinates, const string &name) : amountCoordinates(amountCoordinates), name(name) {}
Point::Point(int amountCoordinates, double *array, const string &name) :
        amountCoordinates(amountCoordinates), name(name) {
    Point::array = new double[amountCoordinates];
    for (int i = 0; i < amountCoordinates; i++) {
        Point::array[i] = array[i];
    }
}
Point::Point(const Point &point) {
    amountCoordinates = point.amountCoordinates;
    Point::array = new double[amountCoordinates];
    for (int i = 0; i < amountCoordinates; i++) {
        array[i] = point.array[i];
    }
    name = point.name;
}

int Point::getAmountCoordinates() const {
    return amountCoordinates;
}
void Point::setAmountCoordinates(int amountCoordinates) {
    Point::amountCoordinates = amountCoordinates;
}
double *Point::getArray() const {
    return array;
}
void Point::setArray(double *array) {
    Point::array = array;
}
const string &Point::getName() const {
    return name;
}
void Point::setName(const string &name) {
    Point::name = name;
}

bool Point::checkForEqualAmountOfCoor(Point point) {
    if (point.amountCoordinates == amountCoordinates) {
        return true;
    }
    return false;
}
double Point::findDistanceToBegin() {
    double distance = 0;
    for (int i = 0; i < amountCoordinates; i++) {
        distance += pow(array[i],2);
    }
    distance = sqrt(distance);
    return distance;
}
double Point::findDistanceBetween(const Point &point) {
    int difference;
    double distance = 0;
    double temp;
    if (amountCoordinates < point.amountCoordinates) {
        difference = point.amountCoordinates - amountCoordinates;
        for (int i = 0; i < amountCoordinates; i++) {
            temp = array[i] - point.array[i];
            temp = pow(temp, 2);
            distance += temp;
        }
        for (int i = amountCoordinates - difference; i < point.amountCoordinates; i++) {
            distance += pow(point.array[i],2);
        }
    }
    else {
        difference = amountCoordinates - point.amountCoordinates;
        for (int i = 0; i < point.amountCoordinates; i++) {
            temp = array[i] - point.array[i];
            temp = pow(temp, 2);
            distance += temp;
        }
        for (int i = point.amountCoordinates - difference; i < amountCoordinates; i++) {
            distance += pow(array[i],2);
        }
    }
    distance = sqrt(distance);
    return distance;
}
bool Point::belongsTo(HoolaHoop hoop) {
    Point center(hoop.getSize(), hoop.getArray());
    double distance = findDistanceBetween(center);
    if ((distance <= hoop.getExternalRadius()) && (distance >= hoop.getInnerRadius())) {
        return true;
    }
    return false;
}

istream &operator>>(istream &is, Point &point) {
    if (&is == &cin) {
        cout     << "Enter name: ";
        is       >> point.name;
        cout     << "Enter amount of coordinates in "
                 << point.name
                 << ": ";
        is       >> point.amountCoordinates;
        cout     << "Enter ";
        for (int i = 0; i < point.amountCoordinates; i++) {
            cout << i + 1
                 << " coordinate: ";
            is   >> point.array[i];
        }
        return is;
    }
    is     >> point.name
           >> point.amountCoordinates;
    point.array = new double[point.amountCoordinates];
    for (int i = 0; i < point.amountCoordinates; i++) {
        is >> point.array[i];
        point.array[i] = round(point.array[i] * 100) / 100;
    }
    return is;
}
ostream &operator<<(ostream &os, Point &point) {
    if (point.array == nullptr) {
        os << "Object is empty!\n";
        return os;
    }
    os     << "Amount of coordinates in "
           << point.name
           << " is "
           << point.amountCoordinates
           << ", coordinates are "
           << '(';
    for (int i = 0; i < point.amountCoordinates - 1; i++) {
        os << point.array[i]
           << "; ";
    }
    os     << point.array[point.amountCoordinates - 1]
           << ").\n";
    return os;
}

Point Point::operator+(const Point &pointToAdd) {
    Point temp;
    if (checkForEqualAmountOfCoor(pointToAdd)) {
        temp = *this;
        temp.name.insert(temp.name.begin(), '(');
        temp.name += '+';
        temp.name += pointToAdd.name;
        temp.name += ')';
        for (int i = 0; i < pointToAdd.amountCoordinates; i++) {
            temp.array[i] += pointToAdd.array[i];
        }
        return temp;
    }
    else {
        throw (string)"Inappropriate data!";
        return temp;
    }
}
Point Point::operator=(const Point &pointToAssign) {
    amountCoordinates = pointToAssign.amountCoordinates;
    array = new double[amountCoordinates];
    for (int i = 0; i < amountCoordinates; i++) {
        array[i] = pointToAssign.array[i];
    }
    name = pointToAssign.name;
    return *this;
}
Point Point::operator*(const Point &pointToMul) {
    Point temp;
    int difference;
    if (temp.amountCoordinates > pointToMul.amountCoordinates) {
        temp = *this;
        temp.name.insert(temp.name.begin(), '(');
        temp.name += '*';
        temp.name += pointToMul.name;
        temp.name += ')';
        difference = temp.amountCoordinates - pointToMul.amountCoordinates;
        for (int i = 0; i < difference; i++) {
            temp.array[i] *= pointToMul.array[i];
        }
        for (int i = amountCoordinates - difference; i < amountCoordinates; i++) {
            temp.array[i] = 0;
        }
        return temp;
    }
    else if (pointToMul.amountCoordinates > amountCoordinates) {
        temp = pointToMul;
        temp.name.insert(temp.name.begin(), '(');
        temp.name += '*';
        temp.name += name;
        temp.name += ')';
        difference = pointToMul.amountCoordinates - temp.amountCoordinates;
        for (int i = 0; i < difference; i++) {
            temp.array[i] *= array[i];
        }
        for (int i = temp.amountCoordinates - difference; i < temp.amountCoordinates; i++) {
            temp.array[i] = 0;
        }
        return temp;
    }
    temp = *this;
    temp.name.insert(temp.name.begin(), '(');
    temp.name += '*';
    temp.name += pointToMul.name;
    temp.name += ')';
    for (int i = 0; i < temp.amountCoordinates; i++) {
        temp.array[i] *= pointToMul.array[i];
    }
    return temp;
}

bool Point::operator<(Point &pointToCheck) {
    if (findDistanceToBegin() < pointToCheck.findDistanceToBegin()) {
        return true;
    }
    return false;
}
bool Point::operator>(Point &pointToCheck) {
    if (findDistanceToBegin() > pointToCheck.findDistanceToBegin()) {
        return true;
    }
    return false;
}

Point::~Point() {
    if (array != nullptr) {
        delete[] array;
    }
    else {
        cout << "array is nullptr";
    }
}