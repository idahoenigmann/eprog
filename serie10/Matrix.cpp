//
// Created by ida on 16.12.20.
//

#include "Matrix.h"

using namespace std;

double Matrix::getCoefficient(unsigned int row, unsigned int col) const{
    if (row >= dim || col >= dim) {
        throw logic_error("Index out of bounds.");
    }

    return coeff[col*dim+row];
}

void Matrix::setCoefficient(double num, unsigned int row, unsigned int col) {
    if (row >= dim || col >= dim) {
        throw logic_error("Index out of bounds.");
    }

    this->coeff[col*dim+row] = num;
}

Matrix::Matrix(unsigned int dimension, double coeff) {
    dim = dimension;
    this->coeff = new double[dim*dim];

    for (unsigned int i=0; i < dim; i++) {
        for (unsigned int j=0; j < dim; j++) {
            setCoefficient(coeff, i, j);
        }
    }
}

Matrix::~Matrix() {
    delete[] coeff;
}

Matrix::Matrix(const Matrix &matrix) {
    dim = matrix.dim;
    coeff = new double[dim*dim];

    for (unsigned int i=0; i < dim; i++) {
        for (unsigned int j=0; j < dim; j++) {
            setCoefficient(matrix.getCoefficient(i, j), i, j);
        }
    }
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this == &matrix) {
        return *this;
    }

    if (matrix.dim != dim) {
        dim = matrix.dim;
        delete[] coeff;
        coeff = new double[matrix.dim * matrix.dim];
    }

    for (unsigned int i=0; i < dim; i++) {
        for (unsigned int j=0; j < dim; j++) {
            setCoefficient(matrix.getCoefficient(i, j), i, j);
        }
    }

    return *this;
}
