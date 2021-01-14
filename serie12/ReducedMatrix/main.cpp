//
// Created by ida on 14.01.21.
//

#include <iostream>
#include "ReducedMatrix.h"

using namespace std;

int main() {
    LowerTriangularMatrix lm(4);

    cout << lm.size() << endl;

    int tmp{1};
    for (int i{0}; i < 4; i++) {
        for (int j{0}; j <= i; j++) {
            lm(i, j) = tmp;
            tmp++;
        }
    }

    for (int i{0}; i < 4; i++) {
        for (int j{0}; j <= i; j++) {
            cout << lm(i, j) << ", ";
        }
        cout << endl;
    }

    return 0;
}