#include "RationalNum.h"

RationalNumber::RationalNumber() {
    numerator = 0;
    denominator = 0;
}
RationalNumber::RationalNumber(int numerator, int denominator) : numerator(numerator),
                                                                 denominator(denominator) {

}
RationalNumber::RationalNumber(const RationalNumber &number) {
    numerator = number.numerator;
    denominator = number.denominator;
}

int RationalNumber::getNumerator() const {
    return numerator;
}
void RationalNumber::setNumerator(int numerator) {
    RationalNumber::numerator = numerator;
}
int RationalNumber::getDenominator() const {
    return denominator;
}
void RationalNumber::setDenominator(int denominator) {
    RationalNumber::denominator = denominator;
}

RationalNumber RationalNumber::operator+(RationalNumber rational) {
    if (numerator == 0){
        *this = rational;
        return *this;
    }
    else if (rational.numerator == 0){
        return *this;
    }

    numerator *= rational.denominator;
    rational.numerator *= denominator;
    numerator += rational.numerator;
    denominator *= rational.denominator;
    return *this;
}

RationalNumber RationalNumber::operator*(RationalNumber rational){
    RationalNumber temp;
    if (numerator == 0){
        return temp;
    }
    else if (rational.numerator == 0){
        return temp;
    }
    temp = *this;
    temp.numerator = temp.numerator * rational.numerator;
    temp.denominator = temp.denominator * rational.denominator;
    return temp;
}

RationalNumber RationalNumber::operator-(RationalNumber rational) {
    RationalNumber temp = *this;//створюємо тимчасову змінну і надаємо її полям значення полів змінної,
    // від якої будемо віднімати
    if ((rational.numerator == 0)){
        return temp;
    }
    else if (temp.numerator == 0){
        rational.numerator = rational.numerator * (-1);
        return rational;
    }
    temp.numerator = temp.numerator * rational.denominator;
    rational.numerator = rational.numerator * temp.denominator;
    temp.denominator = temp.denominator * rational.denominator;
    temp.numerator =temp.numerator - rational.numerator;
    return temp;
}

RationalNumber RationalNumber::operator/(RationalNumber rational) {
    RationalNumber temp = *this;
    if (temp.numerator == 0) {
        return temp;
    } else if (rational.denominator == 0) {
        temp.numerator = 0;
        temp.denominator = 0;
        return temp;
    }
    temp.numerator *= rational.denominator;

    temp.denominator *= rational.numerator;
    return temp;
}

//RationalNumber RationalNumber::operator/(int numToDivide) {
//    RationalNumber temp = *this;
//       if (numToDivide == 0){
//        return temp;
//    }
//    temp.denominator *= numToDivide;
//    return temp;
//}

RationalNumber RationalNumber::operator=(RationalNumber rationalNumber) {
    numerator = rationalNumber.numerator;
    denominator = rationalNumber.denominator;
    return *this;
}


bool RationalNumber::operator==(RationalNumber rationalNumber) {
    if (numerator == rationalNumber.numerator) {
        if (denominator == rationalNumber.denominator) {
            return true;
        }
    }
    return false;
}
bool RationalNumber::operator<(RationalNumber rationalNumber) {
    RationalNumber temp = *this;
    temp.numerator *= rationalNumber.denominator;
    rationalNumber.numerator *= temp.denominator;
    if (temp.numerator < rationalNumber.numerator) {
        return true;
    }
    return false;
}

bool RationalNumber::operator>(RationalNumber rationalNumber) {
    RationalNumber temp = *this;
    temp.numerator *= rationalNumber.denominator;
    rationalNumber.numerator *= temp.denominator;
    if (temp.numerator > rationalNumber.numerator) {
        return true;
    }
    return false;
}

void RationalNumber::abbreviation() {//метод, який зводить дріб до виду нескоротнього
    while (numerator % 2 == 0 && denominator % 2 == 0){
        numerator /= 2;
        denominator /= 2;
    }

    while (numerator % 3 == 0 && denominator % 3 == 0){
        numerator /= 3;
        denominator /= 3;
    }

    while (numerator % 5 == 0 && denominator % 5 == 0){
        numerator /= 5;
        denominator /= 5;
    }

    while (numerator % 7 == 0 && denominator % 7 == 0){
        numerator /= 7;
        denominator /= 7;
    }
//    for (int i = 2; i < numerator + 1; i++) {
//        if ((numerator % i == 0) && (denominator % i == 0)) {
//            numerator = numerator / i;
//            denominator = numerator / i;
//            i = 1;
//        }
//    }
}

istream &operator>>(istream &input, RationalNumber &rationalNumber) {
    input >> rationalNumber.numerator
          >> rationalNumber.denominator;
    return input;
}

ostream &operator<<(ostream &output, RationalNumber &rationalNumber) {

    if (rationalNumber.numerator != 0) {
        rationalNumber.abbreviation();
        output << "Number is "
           << rationalNumber.numerator
           << '/'
           << rationalNumber.denominator
           << endl;
    }
    else {
        output << "Number is 0" << endl;
    }
    return output;
}