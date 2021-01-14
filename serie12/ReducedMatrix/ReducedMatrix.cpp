//
// Created by ida on 14.01.21.
//

#include "ReducedMatrix.h"

using namespace std;

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

const double &ReducedMatrix::operator[](int idx) const {
    if (idx >= coeff_len * (coeff_len + 1) / 2) {
        throw logic_error("index out of bounds.");
    }
    return coeff[idx];
}

double &ReducedMatrix::operator[](int idx) {
    if (idx >= coeff_len * (coeff_len + 1) / 2) {
        throw logic_error("index out of bounds.");
    }
    return coeff[idx];
}

double &LowerTriangularMatrix::operator()(int row, int col) {
    if (row >= size() || col >= size()) {
        throw logic_error("index out of bound");
    }
    if (row < col) {
        return zero;            // Note: value of zero could be changed by this method
    }
    return (*this)[(row) * (row + 1) / 2 + (col)];
}

const double &LowerTriangularMatrix::operator()(int row, int col) const {
    if (row >= size() || col >= size()) {
        throw logic_error("index out of bound");
    }
    if (row < col) {
        return const_zero;
    }
    return (*this)[(row) * (row + 1) / 2 + (col)];
}

double &SymmetricMatrix::operator()(int row, int col) {
    if (row >= size() || col >= size()) {
        throw logic_error("index out of bound");
    }
    if (row < col) {
        return (*this)[(col) * (col + 1) / 2 + (row)];
    } else {
        return (*this)[(row) * (row + 1) / 2 + (col)];
    }
}

const double &SymmetricMatrix::operator()(int row, int col) const {
    if (row >= size() || col >= size()) {
        throw logic_error("index out of bound");
    }
    if (row < col) {
        return (*this)[(col) * (col + 1) / 2 + (row)];
    } else {
        return (*this)[(row) * (row + 1) / 2 + (col)];
    }
}
