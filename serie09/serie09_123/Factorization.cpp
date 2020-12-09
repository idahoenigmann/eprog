//
// Created by ida on 09.12.20.
//

#include "Factorization.h"

Factorization::Factorization(unsigned int number) {
    IntVector prime_numbers = IntVector(number);

    int idx = 0;
    int* prime_factors_tmp = new int[prime_numbers.getLength()];
    int* multiplicity_tmp = new int[prime_numbers.getLength()];

    for (int i=0; i < prime_numbers.getLength(); i++) {
        if (number % prime_numbers.getCoefficient(i) == 0) {
            prime_factors_tmp[idx] = prime_numbers.getCoefficient(i);
            multiplicity_tmp[idx] = (int)(number / prime_numbers.getCoefficient(i));
            idx++;
        }
    }

    prime_factors = new unsigned int[idx];
    multiplicities = new unsigned int[idx];
    cnt_prime_factors = idx;

    for (int i=0; i < idx; i++) {
        prime_factors[i] = prime_factors_tmp[i];
        multiplicities[i] = multiplicity_tmp[i];
    }

    delete[] prime_factors_tmp;
    delete[] multiplicity_tmp;
}

Factorization::~Factorization() {
    delete[] prime_factors;
    delete[] multiplicities;
    cnt_prime_factors = 0;
}

unsigned int Factorization::recomposeInteger() {
    unsigned int res = 0;
    for (int i=0; i < cnt_prime_factors; i++) {
        res += prime_factors[i] * multiplicities[i];
    }
    return res;
}

void Factorization::setNumber(unsigned int number) {
    IntVector prime_numbers = IntVector(number);

    int idx = 0;
    int* prime_factors_tmp = new int[prime_numbers.getLength()];
    int* multiplicity_tmp = new int[prime_numbers.getLength()];

    for (int i=0; i < prime_numbers.getLength(); i++) {
        if (number % prime_numbers.getCoefficient(i) == 0) {
            prime_factors_tmp[idx] = prime_numbers.getCoefficient(i);
            multiplicity_tmp[idx] = (int)(number / prime_numbers.getCoefficient(i));
            idx++;
        }
    }

    prime_factors = new unsigned int[idx];
    multiplicities = new unsigned int[idx];
    cnt_prime_factors = idx;

    for (int i=0; i < idx; i++) {
        prime_factors[i] = prime_factors_tmp[i];
        multiplicities[i] = multiplicity_tmp[i];
    }

    delete[] prime_factors_tmp;
    delete[] multiplicity_tmp;
}
