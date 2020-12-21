#include <iostream>

#include "Polynomial.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    Polynomial p1(3, 1);
    Polynomial p2(p1);

    p2 = p1;

    cout << p1.degree() << endl;
    cout << p2.degree() << endl;

    cout << p1[1] << endl;

    p1[1] = -25.5;

    cout << p1 << endl;

    return 0;
}
