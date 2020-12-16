//
// Created by ida on 16.12.20.
//

#ifndef SERIE10_MATRIX_H
#define SERIE10_MATRIX_H

#include <stdexcept>
#include <iostream>
#include <cmath>

class Matrix {
public:
    double getCoefficient(unsigned int row, unsigned int col) const;
    void setCoefficient(double num, unsigned int row, unsigned int col);
    Matrix() = default;
    Matrix(unsigned int dimension, double coeff=0);
    ~Matrix();
    Matrix(const Matrix& matrix);
    Matrix& operator=(const Matrix& matrix);

    void scanMatrix(int dim);
    void printMatrix() const;
    double trace() const;

    double maximumAbsoluteColumnSumNorm() const;
    double maximumAbsoluteRowSumNorm() const;
    double frobeniusNorm() const;
    double maxNorm() const;

    bool isDiagonal() const;
    bool isSymmetric() const;
    bool isSkewSymmetric() const;
    bool isUpperTriangular() const;
    bool isLowerTriangular() const;
private:
    unsigned int dim = 0;
    double* coeff = nullptr;
};


#endif //SERIE10_MATRIX_H
