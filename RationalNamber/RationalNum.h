#ifndef GUK4_RATIONALNUMBERS_H
#define GUK4_RATIONALNUMBERS_H

#include <iostream>

using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;
public:
    RationalNumber();
    RationalNumber(int numerator, int denominator);
    RationalNumber(const RationalNumber &number);

    int getNumerator() const;
    void setNumerator(int numerator);
    int getDenominator() const;
    void setDenominator(int denominator);

    RationalNumber operator+(RationalNumber rational);
    RationalNumber operator*(RationalNumber rational);
    RationalNumber operator-(RationalNumber rational);
    RationalNumber operator/(RationalNumber rational);
//    RationalNumber operator/(int numToDivide);
    RationalNumber operator=(RationalNumber rationalNumber);
    bool operator==(RationalNumber rationalNumber);
    bool operator<(RationalNumber rationalNumber);
    bool operator>(RationalNumber rationalNumber);
    void abbreviation();

    friend istream &operator>>(istream &is, RationalNumber &rationalNumber);
    friend ostream &operator<<(ostream &os, RationalNumber &rationalNumber);
};

#endif //GUK4_RATIONALNUMBERS_H