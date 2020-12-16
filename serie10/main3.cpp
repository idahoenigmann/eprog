#include <iostream>

#include "Matrix.h"

using namespace std;

int main() {

    {
        Matrix m;
        m.scanMatrix(2);
        m.printMatrix();
        cout << "maximumAbsoluteColumnSumNorm = " << m.maximumAbsoluteColumnSumNorm() << endl;
        cout << "maximumAbsoluteRowSumNorm = " << m.maximumAbsoluteRowSumNorm() << endl;
        cout << "frobeniusNorm = " << m.frobeniusNorm() << endl;
        cout << "maxNorm = " << m.maxNorm() << endl;
    }

    return 0;
}