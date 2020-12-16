//
// Created by ida on 16.12.20.
//

#ifndef SERIE10_MATRIX_H
#define SERIE10_MATRIX_H

#include <stdexcept>

class Matrix {
public:
    double getCoefficient(unsigned int row, unsigned int col) const;
    void setCoefficient(double num, unsigned int row, unsigned int col);
    Matrix() = default;
    Matrix(unsigned int dimension, double coeff=0);
    ~Matrix();
    Matrix(const Matrix& matrix);
    Matrix& operator=(const Matrix& matrix);
private:
    unsigned int dim = 0;
    double* coeff = nullptr;
};


#endif //SERIE10_MATRIX_H
