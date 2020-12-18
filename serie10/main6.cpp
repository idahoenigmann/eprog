#include <iostream>

#include "Matrix.h"
#include "vector.hpp"

using namespace std;

Vector solveU(const Matrix& U, const Vector& b) {
    if (!U.isUpperTriangular()) {
        throw logic_error("Matrix has to be upper triangular.");
    }
    if (U.getDimension() != b.size()) {
        throw logic_error("Matrix size does not match Vector size.");
    }

    for (int i{0}; i < b.size(); i++) {
        if (U.getCoefficient(i, i) == 0) {
            throw logic_error("The diagonal can't have 0 entries.");
        }
    }

    Vector res(b.size());

    for (int i{b.size() - 1}; i >= 0; i--) {
        double tmp{b[i]};

        for (int j{i}; j < b.size(); j++) {
            tmp -= U.getCoefficient(i,j) * res[j];
        }

        res[i] = tmp / U.getCoefficient(i, i);
    }
    return res;
}

/* computational complexity: O(n^2) */

int main() {

    {
       Matrix matrix;
       matrix.scanMatrix(3);

       Vector vector(3);
       vector[0] = 3;
       vector[1] = 2;
       vector[2] = 1;

       Vector res{solveU(matrix, vector)};

       for (int i{0}; i < 3; i++) {
           cout << res[i] << ", ";
       }
       cout << endl;
    }

    return 0;
}