//
// Created by ida on 09.12.20.
//

#ifndef SERIE09_123_FRACTION_H
#define SERIE09_123_FRACTION_H

#include <stdexcept>

class Fraction {
public:
    Fraction() = default;
    Fraction(int numerator, int denominator);
private:
    int numerator = 0;
    unsigned int denominator = 1;
};


#endif //SERIE09_123_FRACTION_H
