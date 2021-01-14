//
// Created by ida on 14.01.21.
//

#include "ReducedMatrix.h"


ReducedMatrix::ReducedMatrix(unsigned int coeffLen, double value) {
    this->coeff_len = coeffLen;
    coeff = new double[coeffLen * (coeffLen + 1) / 2];

    for (int i{0}; i < coeffLen * (coeffLen + 1) / 2; i++) {
        coeff[i] = value;
    }
}

ReducedMatrix::~ReducedMatrix() {
    delete[] coeff;
}

ReducedMatrix::ReducedMatrix(const ReducedMatrix& other) {
    this->coeff_len = other.coeff_len;
    coeff = new double [coeff_len * (coeff_len + 1) / 2];

    for (int i{0}; i < coeff_len * (coeff_len + 1) / 2; i++) {
        coeff[i] = other[i];
    }
}

ReducedMatrix &ReducedMatrix::operator=(const ReducedMatrix &rhs) {
    if (this != &rhs) {
        if (this->coeff_len != rhs.coeff_len) {
            delete [] coeff;
            this->coeff_len = rhs.coeff_len;
            coeff = new double[coeff_len * (coeff_len + 1) / 2];
        }
        for (int i{0}; i < coeff_len * (coeff_len + 1) / 2; i++) {
            coeff[i] = rhs[i];
        }
    }
    return *this;
}

int ReducedMatrix::size() const {
    return (int)coeff_len;
}
