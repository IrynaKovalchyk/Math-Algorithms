#include "HoolaHoop.h"

HoolaHoop::HoolaHoop() : size(0), innerRadius(0), externalRadius(0){}
HoolaHoop::HoolaHoop(int size, double *array, double innerRadius, double externalRadius) : size(size),
                                                                                        innerRadius(innerRadius),
                                                                                        externalRadius(
                                                                                                externalRadius) {
    HoolaHoop::array = new double[size];
    for (int i = 0; i < size; i++) {
        HoolaHoop::array[i] = array[i];
    }
}

istream &operator>>(istream &is, HoolaHoop &hoop) {
    is     >> hoop.size;
    hoop.array = new double[hoop.size];
    for (int i = 0; i < hoop.size; i++) {
        is >> hoop.array[i];
    }
    is     >> hoop.innerRadius
           >> hoop.externalRadius;
    return is;
}
ostream &operator<<(ostream &os, HoolaHoop &hoop) {
    os     << "Amount of coordinates in center of hoop is "
           << hoop.size
           << ", coordinates are "
           << '(';
    for (int i = 0; i < hoop.size - 1; i++) {
        os << hoop.array[i]
           << "; ";
    }
    os     << hoop.array[hoop.size - 1]
           << ").\n"
           << "Inner radius is "
           << hoop.innerRadius
           << ", external radius is "
           << hoop.externalRadius
           << endl;
    return os;
}

double HoolaHoop::getInnerRadius() const {
    return innerRadius;
}
void HoolaHoop::setInnerRadius(double innerRadius) {
    HoolaHoop::innerRadius = innerRadius;
}
double HoolaHoop::getExternalRadius() const {
    return externalRadius;
}
void HoolaHoop::setExternalRadius(double externalRadius) {
    HoolaHoop::externalRadius = externalRadius;
}
int HoolaHoop::getSize() const {
    return size;
}
void HoolaHoop::setSize(int size) {
    HoolaHoop::size = size;
}
double *HoolaHoop::getArray() const {
    return array;
}
void HoolaHoop::setArray(double *array) {
    HoolaHoop::array = array;
}

HoolaHoop::~HoolaHoop() {
    delete[] array;
}
