//
// Created by ida on 09.12.20.
//

#ifndef SERIE09_123_FACTORIZATION_H
#define SERIE09_123_FACTORIZATION_H

#include "IntVector.h"

class Factorization {
public:
    Factorization() = default;
    Factorization(unsigned int number);
    ~Factorization();
    unsigned int recomposeInteger();
    void setNumber(unsigned int number);
private:
    unsigned int cnt_prime_factors = 0;
    unsigned int* prime_factors = nullptr;
    unsigned int* multiplicities = nullptr;
};


#endif //SERIE09_123_FACTORIZATION_H
