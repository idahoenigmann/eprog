//
// Created by ida on 14.01.21.
//

#ifndef SERIE12_REDUCEDMATRIX_H
#define SERIE12_REDUCEDMATRIX_H


class ReducedMatrix {
protected:
    ReducedMatrix() = default;
    ReducedMatrix(unsigned int coeffLen, double value=0);
    ReducedMatrix(const ReducedMatrix&);
    virtual ~ReducedMatrix();
    ReducedMatrix& operator=(const ReducedMatrix& rhs);
    virtual const double& operator[](int idx) const = 0;
    virtual double& operator[](int idx) = 0;
    int size() const;
private:
    unsigned int coeff_len{};
    double* coeff{nullptr};
};


#endif //SERIE12_REDUCEDMATRIX_H
