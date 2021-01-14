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

    SymmetricMatrix sm(3);

    cout << sm.size() << endl;

    /*tmp = 1;
    for (int i{0}; i < 3; i++) {
        for (int j{0}; j <= i; j++) {
            sm(i, j) = tmp;
            tmp++;
        }
    }*/

    sm(0, 0) = 1;
    sm(1, 0) = 0;
    sm(1, 1) = 1;
    sm(2, 0) = 0;
    sm(2, 1) = 0;
    sm(2, 2) = 1;

    for (int i{0}; i < 3; i++) {
        for (int j{0}; j < 3; j++) {
            cout << sm(i, j) << ", ";
        }
        cout << endl;
    }

    cout << sm.powerIteration(0.001) << endl;

    return 0;
}