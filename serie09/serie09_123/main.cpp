#include <iostream>

#include "utils.h"
#include "IntVector.h"
#include "Factorization.h"
#include "Fraction.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    {
        IntVector vector;
        cout << vector.getLength() << endl;
        try {
            vector.setCoefficient(0, 1);
        } catch (logic_error &error) {
            cout << error.what() << endl;
        }
    }

    {

    }
    {
        IntVector vector = IntVector((unsigned int) 3, 42);
        cout << vector.getLength() << endl;
        cout << vector.getCoefficient(0) << ", ";
        cout << vector.getCoefficient(1) << ", ";
        cout << vector.getCoefficient(2) << endl;
        try {
            cout << vector.getCoefficient(3) << endl;
        } catch (logic_error &error) {
            cout << error.what() << endl;
        }
    }

    {
        IntVector vector = IntVector(42);
        cout << "prime numbers <= 42: ";
        for (int i = 0; i < vector.getLength(); i++) {
            cout << vector.getCoefficient(i) << ", ";
        }
        cout << endl;
    }

    {
        Factorization factorization = Factorization(8);
        cout << factorization.recomposeInteger() << endl;
        factorization.setNumber(42);
        cout << factorization.recomposeInteger() << endl;
    }

    {
        cout << gcd(12, 4) << endl;
        cout << gcd(42, 5) << endl;

        cout << lcm(8 * 3, 8 * 5) << endl;
    }

    {
        Fraction a = Fraction(20, 10);
        a.reduce();

        Fraction b = Fraction(2, 3);
        b.reduce();

        Fraction res = addFractions(a, b);
        cout << res.getDenominator() << "/" << res.getNumerator() << endl;

    }

    return 0;
}
