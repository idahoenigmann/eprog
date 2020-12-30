//
// Created by ida on 21.12.20.
//

#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial(unsigned int degree, double coefficient) {
    this->degree_ = degree;
    this->coefficients = new double[degree];
    for(int i{0}; i < degree; i++) {
        (*this)[i] = coefficient;
    }
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

Polynomial::Polynomial(const Polynomial &other) {
    this->degree_ = other.degree();
    this->coefficients = new double[degree()];
    for(int i{0}; i < degree(); i++) {
        (*this)[i] = other[i];
    }
}

Polynomial& Polynomial::operator=(const Polynomial &rhs) {
    if (this != &rhs) {
        if (rhs.degree() != degree()) {
            delete[] coefficients;
            degree_ = rhs.degree();
            coefficients = new double[degree()];
        }
        for (int i{0}; i < degree(); i++) {
            (*this)[i] = rhs[i];
        }
    }
    return *this;
}

unsigned int Polynomial::degree() const {
    return degree_;
}

const double& Polynomial::operator[](unsigned int idx) const {
    if (idx >= degree()) {
        throw logic_error("Index out of bound.");
    }
    return coefficients[idx];
}

double& Polynomial::operator[](unsigned int idx) {
    if (idx >= degree()) {
        throw logic_error("Index out of bound.");
    }
    return coefficients[idx];
}

bool Polynomial::operator==(const Polynomial &other) {
    if (other.degree() != degree()) {
        return false;
    }
    double accuracy = 0.01;
    for (int i{0}; i < degree(); i++) {
        if (fabs(other[i] - (*this)[i]) > accuracy) {
            return false;
        }
    }
    return true;
}

double Polynomial::operator()(int k, double x) const {
    Polynomial tmp{(*this)(k)};
    return tmp(x);
}

double Polynomial::operator()(double x) const {
    double res{0};
    for (int i{0}; i < degree(); i++) {
        res += (*this)[i] * x;
    }
    return res;
}

Polynomial Polynomial::operator()(int k) const {
    Polynomial res(MAX(degree() - 1, 1), 0);
    for (int i{1}; i < degree(); i++) {
        res[i - 1] = (*this)[i] * i;
    }
    return res;
}

double Polynomial::computeIntegral(double alpha, double beta) const {
    if (beta <= alpha) {
        throw logic_error("Beta may not be smaller than alpha.");
    }

    double res{0};

    for (int i{0}; i < degree(); i++) {
        res += (*this)[i] * (pow(beta, i + 1) - pow(alpha, i + 1)) / (i + 1);
    }

    return res;
}

std::ostream& operator<<(ostream &stream, const Polynomial& polynomial) {
    if (polynomial.degree() >= 1) {
        stream << ((polynomial[0] < 0) ? "- " : "") << fabs(polynomial[0]);
        for (int i{1}; i < polynomial.degree(); i++) {
            stream << ((polynomial[i] < 0) ? " - " : " + ") << fabs(polynomial[i]) << "x^" << i;
        }
    }
    return stream;
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
    Polynomial res(MAX(p1.degree(), p2.degree()),0);
    for (int i{0}; i < p1.degree(); i++) {
        res[i] += p1[i];
    }
    for (int i{0}; i < p2.degree(); i++) {
        res[i] += p2[i];
    }
    return res;
}

Polynomial operator+(const Polynomial& p, double d) {
    if (p.degree() >= 1) {
        Polynomial res(p);

        res[0] += d;
        return res;
    } else {
        return Polynomial(1, d);
    }
}

Polynomial operator+(double d, const Polynomial& p) {
    return p + d;
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
    Polynomial res(p1.degree() + p2.degree(),1);
    for (int i{0}; i < p1.degree(); i++) {
        res[i] *= p1[i];
    }
    for (int i{0}; i < p2.degree(); i++) {
        res[i] *= p2[i];
    }
    return res;
}

Polynomial operator*(const Polynomial& p, double d) {
    Polynomial res(p);

    for (int i{0}; i < p.degree(); i++) {
        res[i] *= d;
    }

    return res;
}

Polynomial operator*(double d, const Polynomial& p) {
    return p * d;
}