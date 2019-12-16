#ifndef HUITAZTOCHKAMU_HOOLAHOOP_H
#define HUITAZTOCHKAMU_HOOLAHOOP_H

#include "Point.h"

using namespace std;

class HoolaHoop{
private:
    int size;
    double *array;
    double innerRadius;
    double externalRadius;
public:
    HoolaHoop();
    HoolaHoop(int size, double *array, double innerRadius, double externalRadius);

    double getInnerRadius() const;
    void setInnerRadius(double innerRadius);
    double getExternalRadius() const;
    void setExternalRadius(double externalRadius);
    int getSize() const;
    void setSize(int size);
    double *getArray() const;
    void setArray(double *array);

    friend istream &operator>>(istream &is, HoolaHoop &hoop);
    friend ostream &operator<<(ostream &os, HoolaHoop &hoop);

    virtual ~HoolaHoop();
};

#endif //HUITAZTOCHKAMU_HOOLAHOOP_H