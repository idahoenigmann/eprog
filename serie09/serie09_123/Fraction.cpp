//
// Created by ida on 09.12.20.
//

#include "Fraction.h"

using namespace std;

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw logic_error("Division by zero!");
    }

    if (denominator < 0) {
        this->numerator = -numerator;
        this->denominator = -denominator;
    } else {
        this->numerator = numerator;
        this->denominator = denominator;
    }
}
