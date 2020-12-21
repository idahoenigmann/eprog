//
// Created by ida on 21.12.20.
//

#ifndef SERIE11_POLYNOMIAL_H
#define SERIE11_POLYNOMIAL_H

#include <stdexcept>
#include <iostream>
#include <cmath>

class Polynomial {
public:
    Polynomial(unsigned int degree, double coefficient);
    ~Polynomial();
    Polynomial(const Polynomial &other);
    Polynomial& operator=(const Polynomial &rhs);

    unsigned int degree() const;

    double& operator[](unsigned int idx);
    const double& operator[](unsigned int idx) const;
private:
    unsigned int degree_ = 0;
    double* coefficients = nullptr;
};

std::ostream& operator<<(std::ostream& stream, const Polynomial& polynomial);


#endif //SERIE11_POLYNOMIAL_H
